# command 
#   -h: help
#   -i: input file
#   -o: output file

# exit on error
set -e

# default values
input_file=""
output_file_name="a.out"

# parse arguments
while getopts "hi:o:" opt; do
  case $opt in
    h)
      echo "Usage: ddlbx.sh -i <input_file> -o <output_file>"
      exit 0
      ;;
    i)
      input_file=$OPTARG
      ;;
    o)
      output_file=$OPTARG
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

# compile input file
./build/bin/ddlbx $input_file

lib_paths="./build/core/libddlbx_core.a"

# link output file
clang output.o $lib_paths -o $output_file

# remove output.o
rm output.o

# done
exit 0