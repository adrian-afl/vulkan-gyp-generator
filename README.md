# 🌋What is that project?

The aim is to autogenerate the vulkan gyp binding based on vulkan spec document.

The project is heavily inspired by https://github.com/maierfelix/nvk and I would keep on using nvk,
but it was abandoned, and I thought it would be a fun challenge to reimplement it.
I took it too far and here we are. The project also uses some code parts from nvk, some modified.

# Want to give the result a try?

There is an already generated and compiled wrapper published under `vulkan-node` package.
This package will be upgraded consistently with the newest wrapper, and will always target the latest spec.

Here is the link to NPM page with useful description: https://www.npmjs.com/package/vulkan-node

The published version currently supports Windows x64 and Linux x64 X11. See status below to see what works.

To use it, install the `vulkan-node` package, if on linux install `libglfw3` system package, and that should be enough to get it running.

To use validation layers:
- on Windows, install the official Vulkan SDK
- on Linux, there are many ways but the easiest is to install `vulkan-validationlayers` package most distros offer

# Status

This project is ☢️**highly**☢️ experimental and very prone to weird bugs and inconsistencies. But it works all right if
used carefully.

| Platform           | Generates | Compiles | Works |
|--------------------|-----------|----------|------|
| Win x64            | ✅         | ✅        | ✅    |
| Linux x64 Xlib     | ✅         | ✅        | ✅    |
| Linux x64 Wayland  | ✅         | ✅        | ✅    |
| Mac Arm64 MoltenVK | ✅         | ✅        | ⚠️     |

It turns out, Linux XLib version works just fine on Wayland!
- Xlib on X11 tested on Debian Bookworm XFCE
- Xlib on Wayland tested on Ubuntu 22.04 LTS

Compiling MoltenVK version requires full setup of official Vulkan SDK for Mac which
includes MoltenVK. Another requirement is GLFW3. Those libraries must be correctly set in path or the binding after
generation manually changed to match the installation. After that it compiles and actually
starts and runs but only without window for now. Additionally, instance extension `VK_KHR_portability_enumeration`
must be enabled, and instanceCreateInfo.flags set to include `VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR`. 
There are also some device extensions required but are not required for a base startup, and I need to
confirm other things that are required. I also think 32 bits handles are not correct in MoltenVK. Compiled version for arm64 is included.

# How does it work?

First, xml spec is parsed into meaningful objects in memory representing commands, enums, bitmasks, structs, etc.
Then, that data is used to generate the C++ code for native part of the binding, and typescript code for the node part
of the binding.

### Binary node to native communication with scratch buffer

The structs data are serialized into binary form on the node side, then written to, manually allocated, temporary
memory called scratch buffer, several megabytes in size, which is shared between node and native code.
The scratch buffer is allocated only once at the startup and the allocations within are managed entirely virtually on
the node side.

For most input data, but not for all, node writes the data to that buffer, and relative pointers are sent to the native
side.

There is also possibility to send raw pointers to anywhere using bigints, and null and undefined that resolve to
nullptr.

Then data is then basically reinterpret cast into whatever the spec wants there on the native side.
This is only correct as far as the parser and generator are correct, no other checks are made
and there are a lot of crashes if anything goes even slightly wrong.

### Transactional memory allocations on scratch buffer

To fix potential memory leaks, scratch buffer supports simple transaction rollbacks:

- Before the native call is being made, a checkpoint is saved
- All structs and input data are serialized and written
- The native call is being made
- The checkpoint is restored.

This automatically frees everything that was allocated since the checkpoint was made.

This functionality is also exposed outside, if someone wants to get this kind of control over internal memory systems.

This, along with the scratch buffer idea itself, solves most possible memory leaks.

### Binary native to node communication with scratch buffer

The indirectly written results are always written into some memory on the scratch buffer via a pointer,
that is immediately visible on the node side and can then be used to reconstruct the new data automatically into a
struct object.

### Runtime correct memory layout of all structures

To know exactly what is the memory layout of all the structs, the memory layout is generated in 2 steps:

- First is generated during code generation and is responsible to write node code with alignment data, but instead of
  the alignment values (size, offset), indexes are written.
- Second is kind of part of the first step, and uses the indexes emitted by first step to write native code
  that fills an array on native side with alignment data, obtained with sizeof and offsetof macros, in a way that
  particular indexes in the array match the indexes emitted in the first step.

In runtime, during startup:

- The code generated in second step runs and the alignment array is made available
  via NAPI call, making it accessible directly on the node side.
- Node side then calls this function, reads the data generated with in the first step,
  and finally reconstructs the full alignment data.

This is then used during all data serialization and deserialization.

# How to use the generator?

Example for version 1.3.250.1, win64, the repo already contains necessary config file

- Clone the repo
- `yarn install`
- `yarn cli --config config.win64.1.3.250.1.json`
- `cd generated/1.3.250.1/win64`
- `npm i` - this actually builds, because of node-gyp hooks
- `npm run postbuild`

You can now use the generated binding.

For Linux compilation process, it's easiest to take a look at `Dockerfile_base` and then `Dockerfile`.

If you want to rebuild in the future, the generated project exposes following actions:

- `npm run clean` - runs node-gyp clean
- `npm run build` - runs node-gyp build
- `npm run rebuild` - runs node-gyp rebuild
- `npm run configure` - runs node-gyp configure
- `npm run postbuild` - should run automatically after build, copies the glfw.dll and runs tsc build of the node part of
  the binding

# How to use the generated binding?

Take a look at examples folder and go from there. Examples are using the built
version at `generated/release-vulkan-node`, which is the same as the published `vulkan-node` package

# Todo list

- Measure performance
- Shrink the scratch buffer
- Extensions function pointers loading and calling
- Make memory allocations in both memory managers better
- Generate and compile MoltenVK version
- Add CI, at least with Linux option and manual trigger

# Generator folder structure

- gypTemplate
    - is the template for generated project, with all files that are static
- src
    - generator source code is here
- example
    - example uses of the wrapper and useful vulkan helpers
- generated
    - example already generated projects

# Generated project folder structure

- lib
    - some libraries and include for various platforms, based on what nvk had
- native
    - c++ side of the binding
- node
    - typescript side of the binding 
