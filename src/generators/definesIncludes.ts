import * as fs from "fs";

export function generateDefinesAndIncludes(
  hPath: string,
  defines: Record<string, string>,
  includes: string[]
): void {
  const str =
    Object.entries(defines)
      .map((e) => {
        return `#define ${e[0]} ${e[1]}`;
      })
      .join("\n") +
    "\n\n#include <GLFW/glfw3native.h>\n\n" +
    includes
      .map((e) => {
        return `#include ${e}`;
      })
      .join("\n");
  fs.writeFileSync(hPath, str);
}
