set -ex
sh rebuildDockerX11.sh
sh rebuildWin64.sh
cd generated
node prepareRelease.js
echo "DONE!"
