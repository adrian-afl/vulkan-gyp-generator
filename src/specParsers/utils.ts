export function arraize(input: any): any[] {
  return Array.isArray(input) ? input : [input];
}
