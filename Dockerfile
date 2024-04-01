# build for linux!
FROM vulkan-node-x11-builder-base
COPY generated generated

# xlib version
WORKDIR /vulkan/generated/1.3.250.1/x11
RUN rm -rf /vulkan/generated/1.3.250.1/x11/node_modules && \
    rm -rf /vulkan/generated/1.3.250.1/wayland/node_modules && \
    npm install && \
    npm run postbuild

# wayland version
WORKDIR /vulkan/generated/1.3.250.1/wayland
RUN cp -r /vulkan/generated/1.3.250.1/x11/node_modules node_modules && \
    npm run build

CMD cp -r /vulkan/generated/* /out/
