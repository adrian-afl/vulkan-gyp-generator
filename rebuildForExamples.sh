set -ex
yarn cli --config config.win64.1.3.250.1.json
cd generated/1.3.250.1/win64
npm run clean
npm run configure
npm run build
cd ../..
node prepareRelease.js

