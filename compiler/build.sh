root_path=$(cd `dirname $0`; pwd)

create_parser() {
    echo "Creating parser..."

    mkdir -p src/parser
    mkdir -p include/parser

    btyacc -d parser.y
    lex -o src/parser/token.cc token.l

    mv y.tab.h include/parser/parser.hpp
    mv y.tab.c src/parser/parser.cc

    echo "Parser created"
}

BUILD_TYPE=Release

while getopts "pd" opt; do
    case $opt in
        p)
            create_parser
            ;;
        d)
            BUILD_TYPE=Debug
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            ;;
    esac
done

mkdir -p $root_path/build
mkdir -p $root_path/build/bin

# Build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build ./build --config Release
