export function parseTypes(xml: any): {
  bitmaskTypeNames: string[];
  handleTypeNames: string[];
  fnptrsTypeNames: string[];
} {
  const bitmaskTypeNames: string[] = xml.registry.types.type
    .filter((e: any) => e["@_category"] === "bitmask")
    .map((xmlenum: any) => xmlenum.name);

  const handleTypeNames: string[] = xml.registry.types.type
    .filter((e: any) => e["@_category"] === "handle")
    .map((xmlenum: any) => xmlenum.name);

  const fnptrsTypeNames: string[] = xml.registry.types.type
    .filter((e: any) => e["@_category"] === "funcpointer")
    .map((xmlenum: any) => xmlenum.name);

  return { bitmaskTypeNames, fnptrsTypeNames, handleTypeNames };
}
