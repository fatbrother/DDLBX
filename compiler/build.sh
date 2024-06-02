root_path=$(cd `dirname $0`; pwd)

mkdir -p $root_path/build
mkdir -p $root_path/build/bin

# Build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release
