root_path=$(cd `dirname $0`; pwd)

create_parser() {
    echo "Creating parser..."

    mkdir -p src/parser
    mkdir -p include/parser

    bison -o src/parser/parser.cc --header=include/parser/parser.hpp parser.y -Wcounterexamples
    lex -o src/parser/token.cc token.l

    echo "Parser created"
}

DEBUG=false

while getopts "pd" opt; do
    case $opt in
        p)
            create_parser
            ;;
        d)
            DEBUG=true
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            ;;
    esac
done

mkdir -p $root_path/build
mkdir -p $root_path/build/bin

# Build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release
