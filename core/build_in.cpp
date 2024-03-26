#include "build_in.hpp"

#include <stdio.h>
#include <stdlib.h>

extern "C" void print(int n) {
    printf("%d\n", n);
}

extern "C" int input() {
    int n = 0;
    scanf("%d", &n);
    return n;
}