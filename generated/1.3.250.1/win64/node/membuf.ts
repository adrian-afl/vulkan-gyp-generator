import {isArrayBuffer} from "util/types";
import {
    recreateStructFromBinary,
    recreateStructFromBinaryArray, uint64_t, getScratchBuffer, getAddressAtScratchBufferOffset,
    memsetScratchBufferSlice, memsetScratchBufferMove, memsetScratchBufferZero

} from "./dist";
import {initArray} from "./initArray";

class MembufSingleAllocation {
    public suballocs: MembufSingleAllocation[] = [];
    public constructor(
        private readonly chunk: MembufMemoryChunk,
        public allocationId: number,
        public size: number,
        public offset: number,
        public isSubAllocation: boolean = false,
        public transient: boolean = false
    ) {}

    public free(): void {
        if(this.transient){
            return;
        }
      console.log({Freeing: this.allocationId});
      if(!this.isSubAllocation) {
            this.chunk.freeBoundMemory(
              this.allocationId
            );
        }
        this.size = -1;
        this.offset = -1;
        this.suballocs.forEach((x) => x.free() );
    }

    public mapSlice(offset: number, size: number): DataView {
        return new DataView(this.chunk.getBuffer(), this.offset + offset, size);
    }


    public subAllocation(offset: number, size: number): MembufSingleAllocation {
        const suballoc =  new MembufSingleAllocation(this.chunk, this.allocationId, size, this.offset + offset, true);
        this.suballocs.push(suballoc);
        return suballoc;
    }
}

class MembufMemoryChunk {
    private readonly chunkSize: number = 64 * 1024 * 1024;
    public allActiveAllocations: MembufSingleAllocation[];
    private buffer: ArrayBuffer;

    public constructor() {
        this.allActiveAllocations = [];
        this.buffer = getScratchBuffer();
    }

    public free(): void {
        this.allActiveAllocations.forEach((a) => a.free());
       this.buffer = new ArrayBuffer(0);
    }

    public refresh(): void {
        this.buffer = getScratchBuffer();
    }

    public bindMemory(allocationId: number, size: number, offset: number): MembufSingleAllocation {
        const va = new MembufSingleAllocation(this, allocationId, size, offset);
        this.allActiveAllocations.push(va);
        return va;
    }

    public freeBoundMemory(allocationId: number): void {
        this.allActiveAllocations = this.allActiveAllocations.filter(
          (f) => f.allocationId !== allocationId
        );
    }

    // dont use it
    public addBoundMemory(msa: MembufSingleAllocation): void {
        this.allActiveAllocations.push(msa);
    }

    public revertToAllocationId(allocationId: number): void {
        // console.log(`reverting before: ${this.allActiveAllocations.length}`);
        this.allActiveAllocations.filter(
          (f) => !(f.allocationId < allocationId)
        ).forEach((x) => {
            x.offset = -1;
            x.size = -1;
            x.suballocs.forEach((y) => {
                y.offset = -1;
                y.size = -1;
            })
        });
        this.allActiveAllocations = this.allActiveAllocations.filter(
            (f) => f.allocationId < allocationId
        );
        // console.log(`reverting after: ${this.allActiveAllocations.length}`);
    }

    public defragment(): void {
        let cursor = 0;
        let lastEnd = 0;
        const biggestAllocation = this.allActiveAllocations.reduce((prev, cur) => Math.max(prev, cur.size), 0);
        this.allActiveAllocations.sort((a, b) => a.offset - b.offset);
        for(const alloc of this.allActiveAllocations){
            const gap = alloc.offset - lastEnd
            if(gap > 0){
                this.move(alloc, lastEnd);
                alloc.offset = lastEnd;
            }
            lastEnd = alloc.offset + alloc.size;
        }
    }

    public move(alloc: MembufSingleAllocation, newOffset: number): void {
        memsetScratchBufferMove(alloc.offset, newOffset, alloc.size);
        alloc.offset = newOffset;
    }

    public findFreeMemoryOffset(
        size: number,
        outOffset: { result: number }
    ): boolean {
        // if (this.isFreeSpace(0, size)) {
        //     outOffset.result = 0;
        //     return true;
        // }
        // // try the last one for a small performance boost
        //
        // const allocscount = this.allActiveAllocations.length;
        //
        // const a = this.allActiveAllocations[allocscount - 1];
        // if (this.isFreeSpace(a.offset + a.size, size)) {
        //     outOffset.result = a.offset + a.size;
        //     return true;
        // }
        //
        // for (let i = 0; i < allocscount; i++) {
        //     const a = this.allActiveAllocations[i];
        //     if (this.isFreeSpace(a.offset + a.size, size)) {
        //         outOffset.result = a.offset + a.size;
        //         return true;
        //     }
        // }

        // screw it lets do it that way and it will be fine for a moment
        // the buffer is absurdly oversized for anything that usually will land there
        // so it will be fine

        //
        // let trials = 1000;
        // while(trials-- > 0){
        //         const randomOffset = Math.floor((this.chunkSize - size + 0x10000) * Math.random());
        //         if (this.isFreeSpace(randomOffset, size + 0x1000)) {
        //             outOffset.result = randomOffset;
        //             return true;
        //         }
        // }
        // // in case of a disaster defragment
        // this.defragment();
        //
        // // and try just after the last one
        // const allocCount = this.allActiveAllocations.length;
        //
        // const a = this.allActiveAllocations.reduce((prev, cur) => Math.max(prev, cur.offset + cur.size), 0);
        // if (this.isFreeSpace(a + 0x1000, size + 0x1000)) {
        //     outOffset.result = a + 0x1000;
        //     return true;
        // }
        // return false;

        const a = this.allActiveAllocations.reduce((prev, cur) => Math.max(prev, cur.offset + cur.size), 0);
        outOffset.result = a;
       // console.log(outOffset.result);
        return true;
        // if (this.isFreeSpace(a + 0x1000, size)) {
        //   outOffset.result = a + 0x1000;
        //   return true;
        // }
        // // in case of a disaster defragment
        // this.defragment();
        // const b = this.allActiveAllocations.reduce((prev, cur) => Math.max(prev, cur.offset + cur.size), 0);
        // if (this.isFreeSpace(b + 0x1000, size)) {
        //   outOffset.result = b + 0x1000;
        //   return true;
        // }
        // return false;
    }

    public getBuffer(): ArrayBuffer {
        return this.buffer;
    }

    public getTotalAllocatedMemory(): number {
        return this.allActiveAllocations.reduce((prev, cur) => prev + cur.size, 0);
    }

    public geTopAllocatedAddress(): number {
        return this.allActiveAllocations.reduce((prev, cur) => Math.max(prev, cur.size + cur.offset), 0);
    }

    private isFreeSpace(offset: number, size: number): boolean {
        const end = offset + size;
        const allocscount = this.allActiveAllocations.length;
        if (end >= this.chunkSize) {
            return false;
        }
        const requestedStart = offset;
        const requestedEnd = offset + size;

        const isInsideRange = (start: number, end: number, point: number): boolean =>
        {
            return point >= start && point <= end;
        };
        for (let i = 0; i < allocscount; i++) {
            const a = this.allActiveAllocations[i];
            const checkedStart = a.offset;
            const checkedEnd = a.offset + a.size;

            if(isInsideRange(requestedStart, requestedEnd, checkedStart)
              || isInsideRange(requestedStart, requestedEnd, checkedEnd)
              || isInsideRange(checkedStart, checkedEnd, requestedStart)
              || isInsideRange(checkedStart, checkedEnd, requestedEnd)){
                return false;
            }

            // if(requestedEnd >= checkedStart && requestedStart <= checkedEnd){
            //     return false;
            // }
            //

            /*
            req -------[-------]-----
            chk ---[------]----------
            req -------[-------]-----
            chk ---[---------------]-
             */
            // if (requestedStart >= checkedStart && requestedStart < checkedEnd) {
            //     return false;
            // }
            /*
            req ---[------]----------
            chk -------[-------]-----
            req ---[---------------]-
            chk -------[-------]-----
             */
            // if (checkedStart >= requestedStart && checkedStart < requestedEnd) {
            //     // if end of alloc collides
            //     return false;
            // }
        }
        return true;
    }
}

class MembufMemoryManager {
    public readonly chunk: MembufMemoryChunk;
    public lastAllocationId = 0;

    public constructor() {
        this.chunk = new MembufMemoryChunk();
    }

    public revertToAllocationId(allocationId: number){
        this.chunk.revertToAllocationId(allocationId);
        this.lastAllocationId = allocationId;
    }

    public bindBufferMemory(size: number, transient = false): MembufSingleAllocation {
        const offset = { result: 0 };
        const result = this.chunk.findFreeMemoryOffset(size, offset);
        if (result) {
            if(transient){
                return new MembufSingleAllocation(this.chunk, this.lastAllocationId, size, offset.result, false, true);
            }
            return this.chunk.bindMemory(this.lastAllocationId++, size, offset.result);
        }
        throw "out of memory";
    }

    public findFreeMemoryOffset(size: number): number {
        const offset = { result: 0 };
        const result = this.chunk.findFreeMemoryOffset(size, offset);
        if (result) {
            return offset.result;
        }
        throw "out of memory";
    }
}


export const isMembuf = (a: unknown): a is Membuf => {
    const cast = a as {isMemoryBuffer? : boolean};
    return cast && cast.isMemoryBuffer === true;
}

let membufScratchBuffer: MembufMemoryManager | null = null;

export const getMembufScratchBuffer = (): MembufMemoryManager => {
    if(!membufScratchBuffer){
        membufScratchBuffer = new MembufMemoryManager();
    }
    return membufScratchBuffer;
}

export class BaseMembuf {
    public allocation: MembufSingleAllocation;

    public underlyingType: string | null = null;

    public readonly isMemoryBuffer: boolean = true;
    public pointsTo: BaseMembuf | null= null;
    public isRawMembuf = false;
    public view: DataView;

    public constructor(
         bytes: number | ArrayBuffer | MembufSingleAllocation,
         transient = false
    ) {
        if(isArrayBuffer(bytes)){
            this.allocation = getMembufScratchBuffer().bindBufferMemory(bytes.byteLength, transient);
            this.copyFromArrayBuffer(bytes, 0, 0, bytes.byteLength);
            this.view = this.allocation.mapSlice(0, bytes.byteLength);
        } else if(typeof bytes === "number"){
            this.allocation = getMembufScratchBuffer().bindBufferMemory(bytes);
            this.view = this.allocation.mapSlice(0, bytes);
            this.fillWithZero();
        } else if(bytes instanceof MembufSingleAllocation){
            this.allocation = bytes;
            this.view = this.allocation.mapSlice(0, bytes.size);
        } else {
            throw new Error("unexpected value constructing membuf");
        }
    }

    public copyFromArrayBuffer(buf: ArrayBuffer, srcStart: number, dstStart: number, length: number) {
        memsetScratchBufferSlice(this.allocation.offset + dstStart, srcStart, length, buf);
        return this;
    }

    public copyFromMembuf(buf: Membuf, srcStart: number, dstStart: number, length: number) {
        memsetScratchBufferMove(buf.allocation.offset + srcStart, this.allocation.offset + dstStart, length);
        return this;
    }

    public static reallocateIntoContinuousMemory(membufs: (Membuf | BaseMembuf)[]): void {
        const total = membufs.reduce((prev, cur) => prev + cur.allocation.size, 0);
        let written = 0;
        const sb = getMembufScratchBuffer();
        const freeOffset = sb.findFreeMemoryOffset(total);
        for(const mb of membufs){
            sb.chunk.move(mb.allocation, freeOffset + written);
            mb.refreshView();
            written += mb.allocation.size;
        }
    }

    public static joinClone(membufs: (Membuf | BaseMembuf)[]): Membuf {
        const total = membufs.reduce((prev, cur) => prev + cur.allocation.size, 0);
        const result = new Membuf(total);
        let written = 0;
        for(const mb of membufs){
            memsetScratchBufferMove(mb.allocation.offset, result.allocation.offset + written, mb.allocation.size);
            written += mb.allocation.size;
        }
        result.refreshView();
        return result;
    }

    public static isContinuousMemory(membufs: (Membuf | BaseMembuf)[]): boolean {
        for(let i=0;i<membufs.length - 1; i++){
            if(membufs[i].allocation.offset + membufs[i].allocation.size !== membufs[i + 1].allocation.offset){
                return false;
            }
        }
        return true;
    }

    private referenceLevel = 0;

    public fillWithZero(): void {
        memsetScratchBufferZero(this.allocation.offset, this.allocation.size);
    }

    public getReferenceLevel() {
        return this.referenceLevel;
    }

    public slice(offset: number, size: number): Membuf {
        return new Membuf(this.allocation.subAllocation(offset, size));
    }

    public reference(): Membuf {
        const result = new Membuf(8);
        const view = result.allocation.mapSlice(0, 8);
        view.setBigUint64(0, getAddressAtScratchBufferOffset(this.allocation.offset), true);
        result.referenceLevel = this.referenceLevel + 1;
        result.pointsTo = this;
        return result;
    }

    public dereference(size: number): Membuf {
        throw new Error('Not Implemented');
        // const view = this.allocation.mapSlice(0, 8);
        // const offset = view.setBigUint64(getAddressAtScratchBufferOffset(this.allocation.offset));
        // const result = new Membuf(getArrayBufferFromAddress(this.buffer, size));
        // this.free();
        // return result;
    }

    public refreshView(): DataView {
        this.view = this.allocation.mapSlice(0, this.allocation.size);
        return this.view;
    }

    public deserializeSingle<T>(): T {
        if(!this.underlyingType){
            throw new Error("Cannot deserialize without underlying type set");
        }
        return recreateStructFromBinary<T>(this.underlyingType, this);
    }

    public deserializeArray<T>(): T[] {
        if(!this.underlyingType){
            throw new Error("Cannot deserialize without underlying type set");
        }
        return recreateStructFromBinaryArray<T>(this.underlyingType, this);
    }

    public deserializeArrayOfHandles<T = uint64_t>(): T[] {
        return initArray(this.allocation.size / 8,
            (i) => new uint64_t(0).copyFromMembuf(this, i * 8, 0, 8)) as T[];
    }

    public static splitIntoEvenChunks(membuf: Membuf, chunkSize: number, count: number): Membuf[] {
        const result: Membuf[] = [];
        for(let i=0;i<count;i++){
            result[i] = new Membuf(chunkSize);
            result[i].copyFromMembuf(membuf, i * chunkSize, 0, chunkSize);
        }
        return result;
    }

    public static fromInt32(value: number) : Membuf {
        const buf = new Membuf(4);
        buf.allocation.mapSlice(0, 4).setInt32(0, value, true);
        return buf;
    }

    public static fromUint32(value: number) : Membuf {
        const buf = new Membuf(4);
        buf.allocation.mapSlice(0, 4).setUint32(0, value, true);
        return buf;
    }

    public static fromInt64(value: number | bigint) : Membuf {
        const buf = new Membuf(8);
        buf.allocation.mapSlice(0, 8).setBigInt64(0, BigInt(value), true);
        return buf;
    }

    public static fromUint64(value: number | bigint) : Membuf {
        const buf = new Membuf(8);
        buf.allocation.mapSlice(0, 8).setBigUint64(0, BigInt(value), true);
        return buf;
    }

    public static fromFloat(value: number) : Membuf {
        const buf = new Membuf(4);
        buf.allocation.mapSlice(0, 4).setFloat32(0, value, true);
        return buf;
    }

    public static fromDouble(value: number) : Membuf {
        const buf = new Membuf(8);
        buf.allocation.mapSlice(0, 8).setFloat64(0, value, true);
        return buf;
    }

    public setBit(at: number, value: boolean): void {
        const whichByte = Math.floor(at / 8.0);
        const whichBit = at - whichByte * 8;
        const old = this.allocation.mapSlice(0, this.allocation.size).getUint8(whichByte);
        let nv = old;
        if(value){
            const mask = 0x1 << whichBit;
            nv = old | mask;
        } else {
            const mask = ~(0x1 << whichBit);
            nv = old & mask;
        }
        this.allocation.mapSlice(0, this.allocation.size).setUint8(whichByte, nv);
    }

    public getBit(at: number): boolean {
        const whichByte = Math.floor(at / 8.0);
        const whichBit = at - whichByte * 8;
        const v = this.allocation.mapSlice(0, this.allocation.size).getUint8(whichByte);
        const mask = 0x1 << whichBit;
        const isolated = v & mask;
        return ((isolated >> whichBit) & 0x1) === 0x1;
    }

}



export class Membuf extends BaseMembuf {
    public isRawMembuf = true;
}
