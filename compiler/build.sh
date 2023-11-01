root_path=$(cd `dirname $0`; pwd)

mkdir -p $root_path/build
mkdir -p $root_path/build/bin
cd $root_path/build

# Build
cmake ..
make

# Test
cd $root_path/build
./ddlbx_test