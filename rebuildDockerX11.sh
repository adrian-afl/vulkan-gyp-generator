set -ex
yarn cli --config config.x11.1.3.250.1.json
yarn cli --config config.wayland.1.3.250.1.json
docker build . -f Dockerfile_base -t vulkan-node-x11-builder-base --progress=plain
docker build . -t vulkan-node-x11 --progress=plain --no-cache
cd generated/
docker compose run --rm out
cd ..
