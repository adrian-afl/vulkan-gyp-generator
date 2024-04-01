import * as fs from "fs";
import { simplifyTypeNative, simplifyTypeTS, structs } from "../cli";

interface AlignmentValue {
  simpleType: string;
  fullType: string;
  offsetIndex: number;
  sizeIndex: number;
  simpleTypeTS: string;
  isPointer: boolean;
  isDoublePointer: boolean;
  name: string;
  optional: boolean;
  modifiers: string[];
  values: string;
}

const generateAlignmentLines = (): {
  cpp: string;
  valuesmap: Record<string, Record<string, AlignmentValue>>;
} => {
  const lines: string[] = [];
  let i = 0;
  const valuesmap: Record<string, Record<string, AlignmentValue>> = {};
  for (const struct of structs) {
    valuesmap[struct.name] = {};
    const fields = struct.members.map((p) => {
      valuesmap[struct.name][p.name] = {
        fullType: p.type,
        simpleType: simplifyTypeNative(p.type),
        simpleTypeTS: simplifyTypeTS(p.type),
        isPointer: p.isPointer,
        isDoublePointer: p.isDoublePointer,
        name: p.name,
        optional: p.optional,
        modifiers: p.modifiers,
        values: p.values,
        offsetIndex: i++,
        sizeIndex: i++,
      };
      return `alignmentData.push_back(offsetof(${struct.name}, ${p.name}));
alignmentData.push_back(FIELD_SIZEOF(${struct.name}, ${p.name}));`;
    });
    lines.push(fields.join("\n"));
  }
  const def = `
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))
#include <vector>
using namespace std;

vector<size_t> alignmentData = vector<size_t>();
void prepareAlignmentData(){
`;
  return {
    valuesmap,
    cpp:
      def +
      lines.join("\n") +
      `
}

`,
  };
};
export function generateAlignmentHTs(hPath: string, tsPath: string): void {
  const alig = generateAlignmentLines();
  fs.writeFileSync(hPath, alig.cpp);
  fs.writeFileSync(tsPath, JSON.stringify(alig.valuesmap, undefined, 2));
}
