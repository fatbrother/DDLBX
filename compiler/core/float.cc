#include <gc/gc.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" {

char* Flt_toString(float n) {
    char* str = (char*)GC_MALLOC(12);
    sprintf(str, "%f", n);
    return str;
}

float Flt_parse(char* str) {
    return atof(str);
}

}