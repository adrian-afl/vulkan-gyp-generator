const fs = require('fs');
const path = require('path');
const {execSync} = require("child_process");

const outdir = path.resolve("release-vulkan-node");
if(fs.existsSync("release-vulkan-node")) {
    fs.rmSync(outdir, {recursive: true});
}
fs.mkdirSync(outdir);

const platforms = ["win64", "x11"];
const mainPlatform = "win64";
const version = "1.3.250.1";
const indir = path.resolve(version);

fs.cpSync(path.join(indir, mainPlatform, "dist"), path.join(outdir, "dist"), {
    recursive: true,
    errorOnExist: false,
});

fs.cpSync(path.join(indir, "win64", "bin"), path.join(outdir, "bin"), {
    recursive: true,
    errorOnExist: false,
});
fs.cpSync(path.join(indir, "x11", "bin", "addon-linux.node"), path.join(outdir, "bin", "addon-linux.node"));
fs.cpSync(path.join(indir, "wayland", "bin", "addon-linux.node"), path.join(outdir, "bin", "addon-linux-wayland.node"));
fs.cpSync(path.join(indir, 'moltenvk', 'bin', 'addon-darwin.node'), path.join(outdir, "bin", "addon-darwin.node"));

const packageJson = {
    "name": "vulkan-node",
    "description": "Vulkan API wrapper for Node.js with TypeScript support",
    "version": "0.1.1",
    "main": "dist/dist.js",
    "types": "dist/dist.d.ts",
    "author": "Adrian Afl",
    "license": "MIT",
    "keywords": [
        "vulkan",
        "graphics",
        "node",
        "typescript"
    ],
    "files": [
        "dist/**/*",
        "bin/**/*",
    ],
    "dependencies": {}
};

fs.writeFileSync(path.join(outdir, "package.json"), JSON.stringify(packageJson, undefined, 4));

const readmeIn = fs.readFileSync(path.join(indir, mainPlatform, "README.md")).toString('utf-8');
const readmeOut = readmeIn
    .replace("$SPECVERSION$", version)
    .replace("$DATE$", new Date().toUTCString())
    .replace("$COMMIT$", execSync("git rev-parse HEAD").toString().trim())

fs.writeFileSync(path.join(outdir, "README.md"), readmeOut);
