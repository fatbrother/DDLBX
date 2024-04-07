#include "build_in.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <gc/gc.h>

extern "C" void print(int n) {
    printf("%d\n", n);
}

extern "C" void println(int n) {
    printf("%d\n", n);
}

extern "C" int input() {
    int n = 0;
    scanf("%d", &n);
    return n;
}

extern "C" void* malloc_(int n) {
    return GC_MALLOC(n);
}

extern "C" void* calloc_(int n, int m) {
    return GC_MALLOC(n * m);
}

extern "C" void* realloc_(void* ptr, int n) {
    return GC_REALLOC(ptr, n);
}

extern "C" void free_(void* ptr) {
    GC_FREE(ptr);
}
