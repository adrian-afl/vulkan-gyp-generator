export const distTsHeaders = `const vsnative = require("../bin/addon-" + process.platform + ".node");
import { Membuf, BaseMembuf, isMembuf, getMembufScratchBuffer } from "./membuf";
export { Membuf, BaseMembuf, isMembuf, getMembufScratchBuffer } from "./membuf";
import { initArray } from "./initArray";
export { initArray } from "./initArray";

export class char extends BaseMembuf {
  public constructor(value = 0) {
    super(1);
    this.view.setInt8(0, value);
  }

  public toNumber = (): number => this.view.getInt8(0);
}

export class uchar extends BaseMembuf {
  public constructor(value = 0) {
    super(1);
    this.view.setUint8(0, value);
  }

  public toNumber = (): number => this.view.getInt8(0);
}

export class int8_t extends BaseMembuf {
  public constructor(value = 0) {
    super(1);
    this.view.setInt8(0, value);
  }

  public toNumber = (): number => this.view.getInt8(0);
}

export class int16_t extends BaseMembuf {
  public constructor(value = 0) {
    super(2);
    this.view.setInt16(0, value, true);
  }

  public toNumber = (): number => this.view.getInt16(0, true);
}

export class int32_t extends BaseMembuf {
  public constructor(value = 0) {
    super(4);
    this.view.setInt32(0, value, true);
  }

  public toNumber = (): number => this.view.getInt32(0, true);
}

export class int64_t extends BaseMembuf {
  public constructor(value = 0) {
    super(8);
    this.view.setBigInt64(0, BigInt(value), true);
  }


  public toBigInt = (): bigint => this.view.getBigInt64(0, true);
}

export class uint8_t extends BaseMembuf {
  public constructor(value = 0) {
    super(1);
    this.view.setUint8(0, value);
  }

  public toNumber = (): number => this.view.getUint8(0);
}

export class uint16_t extends BaseMembuf {
  public constructor(value = 0) {
    super(2);
    this.view.setUint16(0, value, true);
  }

  public toNumber = (): number => this.view.getUint16(0, true);
}

export class uint32_t extends BaseMembuf {
  public constructor(value = 0) {
    super(4);
    this.view.setUint32(0, value, true);
  }

  public toNumber = (): number => this.view.getUint32(0, true);
}

export class uint64_t extends BaseMembuf {
  public constructor(value = 0) {
    super(8);
    this.view.setBigInt64(0, BigInt(value), true);
  }

  public toBigInt = (): bigint => this.view.getBigInt64(0, true);
}

export class ptr64_t extends BaseMembuf {
    public constructor(value = 0) {
        super(8);
        this.view.setBigInt64(0, BigInt(value), true);
    }

    public toBigInt = (): bigint => this.view.getBigInt64(0, true);
}

export class float extends BaseMembuf {
  public constructor(value = 0) {
    super(4);
    this.view.setFloat32(0, value, true);
  }

  public toNumber = (): number => this.view.getFloat32(0, true);
}

export class double extends BaseMembuf {
  public constructor(value = 0) {
    super(8);
    this.view.setFloat64(0, value, true);
  }

  public toNumber = (): number => this.view.getFloat64(0, true);
}

export class size_t extends BaseMembuf {
  public constructor(value = 0) {
    super(8);
    this.view.setBigUint64(0, BigInt(value), true);
  }

  public toBigInt = (): bigint => this.view.getBigUint64(0, true);
}

export class nullptr_t extends BaseMembuf {
  public constructor() {
    super(8);
  }
}


export type VkClearColorValue = float[];
export type VkClearValue = VkClearColorValue | VkClearDepthStencilValue;
export type VkClearValueDeserialized = VkClearValue

export interface ResizeEvent {
  width: number;
  height: number;
}
export interface FocusEvent {
  focused: boolean;
}
export interface CloseEvent {

}
export interface KeydownEvent {
  keyCode: number;
}
export interface KeyupEvent {
  keyCode: number;
}
export interface MousemoveEvent {
  x: number;
  y: number;
  movementX: number;
  movementY: number;
}
export interface MousewheelEvent {
  x: number;
  y: number;
  deltaX: number;
  deltaY: number;
}
export interface MousedownEvent {
  x: number;
  y: number;
  button: number;
}
export interface MouseupEvent {
  x: number;
  y: number;
  button: number;
}
export interface DropEvent {
  paths: string[];
}

export interface VulkanWindow {
  title: string;
  width: number;
  height: number;
  frameBufferWidth: number;
  frameBufferHeight: number;
  devicePixelRatio: number;
  pollEvents(): void;
  focus(): void;
  close(): void;
  enterPointerLock(): void;
  exitPointerLock(): void;
  shouldClose(): boolean;
  createSurface(instance: number | null, surface: number | null): number;
  getRequiredInstanceExtensions(): string[];
  onresize: ((ev: ResizeEvent) => any) | null;
  onfocus: ((ev: FocusEvent) => any) | null;
  onclose: ((ev: CloseEvent) => any) | null;
  onkeydown: ((ev: KeydownEvent) => any) | null;
  onkeyup: ((ev: KeyupEvent) => any) | null;
  onmousemove: ((ev: MousemoveEvent) => any) | null;
  onmousewheel: ((ev: MousewheelEvent) => any) | null;
  onmousedown: ((ev: MousedownEvent) => any) | null;
  onmouseup: ((ev: MouseupEvent) => any) | null;
  ondrop: ((ev: DropEvent) => any) | null;
}

export interface VulkanWindowInitializer {
  width: number;
  height: number;
  title?: string;
  resizable?: boolean;
}

export const createWindow = (options: VulkanWindowInitializer): VulkanWindow => new vsnative.VulkanWindow(options);
export const getMemoryAlignment = (): ArrayBuffer => vsnative.getMemoryAlignment();
 export const allocateString = (str: string): bigint => vsnative.allocateString(str);
 export const allocateStrings = (strs: string[]): bigint => vsnative.allocateStrings(strs);
export const sTypes = vsnative.sTypes;
// export const getAddressFromArrayBuffer = (a: ArrayBuffer): ArrayBuffer => vsnative.getAddressFromArrayBuffer(a);
// export const getArrayBufferFromAddress = (address: ArrayBuffer, size: number): ArrayBuffer => vsnative.getArrayBufferFromAddress(address, size);
// export const allocate = (size: number): ArrayBuffer => vsnative.allocate(size);
// export const free = (buffer: ArrayBuffer): void => vsnative.free(buffer);
export const getScratchBuffer = (): ArrayBuffer => vsnative.getScratchBuffer();
export const getAddressAtScratchBufferOffset = (offset: number): bigint => vsnative.getAddressAtScratchBufferOffset(offset);
export const memsetScratchBufferSlice = (offset: number, srcStart: number, size: number, data: ArrayBuffer): void => vsnative.memsetScratchBufferSlice(offset, srcStart, size, data);
export const memsetScratchBufferMove = (from: number, to: number, size: number): void => vsnative.memsetScratchBufferMove(from, to, size);
export const memsetScratchBufferZero = (offset: number, size: number): void => vsnative.memsetScratchBufferZero(offset, size);
export const memcpyArrayBuffers = (src: ArrayBuffer, srcStart: number, dst: ArrayBuffer, dstStart: number, size: number): void => vsnative.memcpyArrayBuffers(src, srcStart, dst, dstStart, size);

export const VK_MAKE_VERSION = (major: number, minor: number, patch: number): number => vsnative.VK_MAKE_VERSION(major, minor, patch);
export const VK_VERSION_MAJOR = (major: number): number => vsnative.VK_VERSION_MAJOR(major);
export const VK_VERSION_MINOR = (minor: number): number => vsnative.VK_VERSION_MINOR(minor);
export const VK_VERSION_PATCH = (patch: number): number => vsnative.VK_VERSION_PATCH(patch);
export const VK_API_VERSION_1_0: number = vsnative.VK_API_VERSION_1_0;
export const VK_API_VERSION_1_1 : number= vsnative.VK_API_VERSION_1_1;
export const VK_API_VERSION_1_2: number = vsnative.VK_API_VERSION_1_2;
export const VK_API_VERSION_1_3 : number= vsnative.VK_API_VERSION_1_3;

interface StructsMemoryMapEntry {
     structName: string;
     params: StructsMemoryMapParam[];
     total: number;
}

interface StructsMemoryMapParam {
    simpleType: string;
    fullType: string;
    offset: number;
    size: number;
    simpleTypeTS: string;
    isPointer: boolean;
    isDoublePointer: boolean;
    paramName: string;
    optional: boolean;
    modifiers: string[];
    values: string;
}

import * as alimap from "./alignmentValuesMap.json"
const bindata = new Uint32Array(vsnative.getMemoryAlignment());
export const structsMemoryMap: StructsMemoryMapEntry[] = Object.entries(alimap).map((entries) => {
    const structName = entries[0];
    let total = 0;
    const params = Object.entries(entries[1]).map((paramEntries) => {
        const paramName = paramEntries[0];
        const fullType = paramEntries[1].fullType;
        const simpleType = paramEntries[1].simpleType;
        const modifiers = paramEntries[1].modifiers;
        const optional = paramEntries[1].optional;
        const isDoublePointer = paramEntries[1].isDoublePointer;
        const isPointer = paramEntries[1].isPointer;
        const values = paramEntries[1].values;
        const simpleTypeTS = paramEntries[1].simpleTypeTS;
        const offset = bindata[paramEntries[1].offsetIndex * 2];
        const size = bindata[paramEntries[1].sizeIndex * 2];
        total = Math.max(total, offset + size);
        const val: StructsMemoryMapParam = {
            paramName, offset, size, fullType, simpleType,
            modifiers, optional, isDoublePointer, isPointer,
            simpleTypeTS, values
        }
        return val;
    });
    return {
        structName, params, total
    }
})


export const getStructSize = (name: string): number => {
    const res = structsMemoryMap.find((x) => x.structName === name)?.total;
    if(!res){
        throw new Error("Cannot find size for struct " + name);
    }
    return res;
}

export const numberToBuffer = (value: number, type: string): BaseMembuf => {
    switch(type){
        case "int8_t":
            return new int8_t(value);
        case "int16_t":
            return new int16_t(value);
        case "int32_t":
            return new int32_t(value);
        case "int64_t":
            return new int64_t(value);

        case "uint8_t":
            return new uint8_t(value);
        case "uint16_t":
            return new uint16_t(value);
        case "uint32_t":
            return new uint32_t(value);
        case "uint64_t":
            return new uint64_t(value);

        case "float":
            return new float(value);
        case "double":
            return new double(value);
        case "size_t":
            return new size_t(value);
        case "ptr64_t":
            return new ptr64_t(value);
        default:
            return new size_t(value);
    }
}

export const transformParameter = (value: any, type: {
    simple: string,
    isPointer: boolean
  }): number | bigint | null => {
    if(value === null || value === undefined){
        return null;
    }
    if(Array.isArray(value)){
        if(value.length > 0 && typeof value[0] === "string") {
            return allocateStrings(value);
        } else if(value.length > 0 && isMembuf(value[0])) {
          if(value.length > 1){
            if(!Membuf.isContinuousMemory(value as Membuf[])){
                throw new Error("Not continuous memory");
            }
          }
          const bufx = value[0] as Membuf;
          return bufx.allocation.offset;
        } else if(value.length > 0 && isVkSerializable(value[0])) {
          if(value.length > 1){
            if(!Membuf.isContinuousMemory(value.map((x) => x.buffer) as Membuf[])){
                throw new Error("Not continuous memory");
            }
          }
          const bufx = value[0].buffer as Membuf;
          return bufx.allocation.offset;
        }
    } else {
        if(isMembuf(value)) {
            return value.allocation.offset;
        } else if(typeof value === "string") {
            return allocateString(value);
        } else if (typeof value === "number"){
            return numberToBuffer(value, type.simple).allocation.offset;
        } else if (typeof value === "boolean"){
            return numberToBuffer(value ? 1 : 0, 'uint32_t').allocation.offset;
        } else if(isVkSerializable(value)){
          return value.buffer.allocation.offset;
        }
    }
    throw new Error("Unknown value passed to command");
}

const bigzeros = new Membuf(1024 * 512);

export const transformMember = (paramali: StructsMemoryMapParam, paramName: string, value: any): Membuf => {
    if(value === null){
        return bigzeros.slice(0, paramali.size);
    }
    let arbuf: Membuf | null = null;

    if(Array.isArray(value)){
        if(value.length > 0 && typeof value[0] === "string") {
            arbuf = Membuf.fromUint64(allocateStrings(value));
        } else if(value.length > 0 && typeof value[0] === "number") {
            const bufs = value.map((x) => numberToBuffer(x, paramali.simpleType));
            Membuf.reallocateIntoContinuousMemory(bufs);
            arbuf = bufs[0];
        } else if(value.length > 0 && isMembuf(value[0])) {
            if(!Membuf.isContinuousMemory(value as Membuf[])){
                throw new Error("Not continuous memory");
            }
            if(paramali.isPointer){
                arbuf = value[0].reference();
            } else {
                arbuf = value[0];
            }
        } else if(value.length > 0 && isVkSerializable(value[0])) {
            if(!Membuf.isContinuousMemory(value.map((x) => x.buffer) as Membuf[])){
                throw new Error("Not continuous memory");
            }
            if(paramali.isPointer){
                arbuf = value[0].buffer.reference();
            } else {
                arbuf = value[0].buffer;
            }
        } else if(value.length === 0) {
            const check = new Membuf(paramali.size);
            if(paramali.isPointer){
                arbuf = check.reference();
            } else {
                arbuf = check;
            }
        }
    } else {
        if(isMembuf(value)) {
            arbuf = value;
        } else if(typeof value === "string") {
            arbuf = Membuf.fromUint64(allocateString(value));
        } else if (typeof value === "number"){
            arbuf = numberToBuffer(value, paramali.simpleType);
        } else if (typeof value === "boolean"){
            arbuf = numberToBuffer(value ? 1 : 0, 'uint32_t');
        } else if(isVkSerializable(value)){
            if(paramali.isPointer){
                arbuf = value.buffer.reference();
            } else {
                arbuf = value.buffer;
            }
        }
    }

    if(!arbuf){
      throw new Error("Unknown value passed in struct");
    }
    if(arbuf.allocation.size !== paramali.size){
        console.dir({paramName, value, paramali}, {depth:10})
        throw new Error("Alignment")
    }
    return arbuf;
}

export const makeStructBinaryImage = (name: string, data: object): Membuf => {
    const ali = structsMemoryMap.find((e) => e.structName === name);
    if(!ali){
        throw Error('Cannot create struct ' + name);
    }
    if(sTypes[name]){
        const typeddata = data as { "sType": Membuf };
        typeddata.sType = new Membuf(4);
        typeddata.sType.view.setInt32(0, sTypes[name], true);
    }
    const buf = new Membuf(ali.total);
    Object.entries(data).forEach((entry) => {
        const paramName = entry[0];
        const value = entry[1];
        const paramali = ali.params.find((e) => e.paramName ===  paramName);
        if(!paramali){
            throw Error('Cannot create struct ' + ali.structName + '.' + paramName);
        }
        const offset = paramali.offset;
        const size = paramali.size;

        const arbuf = transformMember(paramali, paramName, value);
        buf.copyFromMembuf(arbuf, 0, offset, size);
    });
    return buf;
}

export const recreateStructFromBinary = <T>(name: string, buf: Membuf): T => {
    const ali = structsMemoryMap.find((e) => e.structName === name);
    if(!ali){
        throw Error('Cannot create struct ' + name);
    }
    const result: Record<string, any> = {};
    const view = buf.view;

    for(const param of ali.params){
        switch(param.simpleType){
            case "int8_t":
                result[param.paramName] = view.getInt8(param.offset);
                break;
            case "int16_t":
                result[param.paramName] = view.getInt16(param.offset, true);
                break;
            case "int32_t":
                result[param.paramName] = view.getInt32(param.offset, true);
                break;
            case "int64_t":
                result[param.paramName] = view.getBigInt64(param.offset, true);
                break;
            case "uint8_t":
                result[param.paramName] = view.getUint8(param.offset);
                break;
            case "uint16_t":
                result[param.paramName] = view.getUint16(param.offset, true);
                break;
            case "uint32_t":
                result[param.paramName] = view.getUint32(param.offset, true);
                break;
            case "float":
                result[param.paramName] = view.getFloat32(param.offset);
                break;
            case "double":
                result[param.paramName] = view.getFloat64(param.offset);
                break;
            case "size_t":
                result[param.paramName] = view.getBigUint64(param.offset);
                break;
            default:
                if(param.isPointer && param.simpleType === "uint64_t" ){
                    // pointer!
                    // result[param.paramName] = recreateStructFromPointer(param.fullType,
                    //     buf.slice(param.offset, param.offset + param.size))
                    throw new Error('Not implemented');
                } else if(!param.isPointer && param.simpleType === "uint64_t" ){
                    result[param.paramName] = view.getBigUint64(param.offset, true);
                } else if(!param.isPointer && param.simpleType === "char" ){
                    // pointer!
                    result[param.paramName] = readCString(
                        buf.slice(param.offset, param.offset + param.size),
                        param.size
                    );
                } else if(param.isPointer && param.simpleType === "char" ){
                    // pointer!
                    result[param.paramName] = " temporary placeholder string! "
                } else if(param.isDoublePointer && param.simpleType === "char" ){
                    // pointer!
                    result[param.paramName] = " temporary placeholder string array! "
                } else if(param.fullType.startsWith("Vk") && param.simpleType.startsWith("Vk") ){
                    result[param.paramName] = recreateStructFromBinaryArray(param.fullType,
                        new Membuf(buf.allocation.subAllocation(param.offset, param.offset + param.size)))
                } else {
                    // no idea, defaulting to undefined
                    result[param.paramName] = undefined
                }
        }
    }

    return result as T;
}

export const recreateStructFromBinaryArray = <T>(name: string, buf: Membuf): T[] => {
    const ali = structsMemoryMap.find((e) => e.structName === name);
    if(!ali){
        throw Error('Cannot create struct ' + name);
    }
    const count = buf.allocation.size / ali.total;
    const result: T[] = [];
    for(let i=0; i<count; i++){
        if(i * ali.total + ali.total > buf.allocation.size){
            break;
        }
        result.push(recreateStructFromBinary(name, buf.slice(i * ali.total, i * ali.total + ali.total)));
    }
    return result;
}
//
// export const recreateStructFromPointer = <T>(name: string, ptrbuf: Membuf): T => {
//     const ali = structsMemoryMap.find((e) => e.structName === name);
//     if(!ali){
//         throw Error('Cannot create struct ' + name);
//     }
//     const ab = getArrayBufferFromAddress(ptrbuf, ali.total);
//     return recreateStructFromBinary(name, ab);
// }


export const readCString = (data: Membuf, max: number): string => {
    for(let i=0;i<max;i++){
        if(data.view.getUint8(i) === 0x0){
            return Buffer.from(getMembufScratchBuffer().chunk.getBuffer(), 0, i).toString("utf-8");
        }
    }
    return "#ERROR";
}

export const readCStringArray = (data: Membuf, count: number, max:number): string[] => {
    let lastStart = 0;
    const result: string[] = [];
    for(let i=0;i<max;i++){
        if(data.view.getUint8(i) === 0x0){
            result.push(
                Buffer.from(
                    getMembufScratchBuffer().chunk.getBuffer(),
                    lastStart,
                    lastStart + i)
                .toString("utf-8"));
            lastStart = i + 1;
            count--;
            if(count === 0){
                return result;
            }
        }
    }
    return result;
}

export const vkMapMemoryToArrayBuffer = (input: Omit<vkMapMemoryInputWithDevice, "ppData">): ArrayBuffer => {
    const transformed = Object.fromEntries(Object.entries(input).map((e) => {
        return [e[0], transformParameter(e[1], vkMapMemoryParamsTypes[e[0] as keyof typeof vkMapMemoryParamsTypes])];
    }));
    return vsnative.vts_native_vkMapMemoryToArrayBuffer(transformed);
}


export const setupDebugCallback = (input: {instance: VkInstance; callback: (message: string) => void}): void => {
    preventDeallocation(input.callback)
    vsnative.vts_native_setupDebugCallback(input.instance.allocation.offset, input.callback);
}

const deallocationPreventionPool: any[] = [];
export function preventDeallocation(what: any) { deallocationPreventionPool.push(what); }

export const nullptr = new nullptr_t();
nullptr.view.setBigInt64(0, BigInt(0n), true);

export const isVkSerializable = <T extends object = object, TDeser extends object = object>(test: {isVkSerializable?: boolean}): test is VkSerializable<T, TDeser> => test.isVkSerializable ?? false;
export abstract class VkSerializable<Data extends object, DeserData extends object = object> {
    public buffer: Membuf;
    public readonly isVkSerializable = true;
    protected constructor(private data: Data, private typeName: string){
        this.buffer = makeStructBinaryImage(this.typeName, this.data);
    }

    public update(data: Partial<Data>): void {
        this.data = {...this.data, ...data};
        this.buffer = makeStructBinaryImage(this.typeName, this.data);
    }

    public deserialize(): DeserData {
        return recreateStructFromBinary(this.typeName, this.buffer);
    }
}
`;
