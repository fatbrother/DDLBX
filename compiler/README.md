# DDLBX Compiler

## Environment

OS: Ubuntu 22.04 wsl
CMake: 3.22.1
Clang: 17.0.3
C++ Standard: 17

### Install Dependencies

```bash
sudo apt install -y libzstd-dev
sudo apt install -y libedit-dev
```

## Build

```bash
chmod +x build.sh
./build.sh
```

## Compile DDLBX

```bash
./build/ddlbx {source_file}
clang -c core/build_in.c -o core/build_in.o
clang source_file.o core/build_in.o -o {output_file}
```
