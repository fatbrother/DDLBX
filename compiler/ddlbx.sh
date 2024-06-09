# command 
#   -h: help
#   -i: input file
#   -o: output file

# exit on error
set -e

# default values
input_file=""
output_file_name="a.out"

is_emit_llvm=false
is_emit_ast=false

print_help() {
  echo "Usage: ddlbx.sh -i <input_file> [-o <output_file>] [-l] [-a]"
  echo "Options:"
  echo "  -h: help"
  echo "  -i: input file"
  echo "  -o: output file"
  echo "  -l: emit llvm"
  echo "  -a: emit ast"
}

# parse arguments
while getopts "hi:o:la" opt; do
  case $opt in
    h)
      print_help
      exit 0
      ;;
    i)
      input_file=$OPTARG
      ;;
    o)
      output_file=$OPTARG
      ;;
    l)
      is_emit_llvm=true
      ;;
    a)
      is_emit_ast=true
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

# check if input file exists
if [ ! -f $input_file ]; then
  echo "Input file does not exist"
  exit 1
fi

# if emit llvm
if $is_emit_llvm; then
  ./build/bin/ddlbx --ll $input_file
  exit 0
fi

# if emit ast
if $is_emit_ast; then
  ./build/bin/ddlbx --ast $input_file
  exit 0
fi

# compile input file
./build/bin/ddlbx $input_file

lib_paths="./build/core/libddlbx_core.a"

# link output file
clang output.o $lib_paths -o $output_file

# remove output.o
rm output.o

# done
exit 0