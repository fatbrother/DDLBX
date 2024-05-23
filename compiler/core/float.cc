#include <stdio.h>
#include <stdlib.h>

extern "C" {

char* Flt_toString(float n) {
    char* str = (char*)malloc(sizeof(char) * 12);
    sprintf(str, "%f", n);
    return str;
}

}