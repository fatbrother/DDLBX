#include <stdio.h>
#include <stdlib.h>

extern "C" {

char* Int_toString(int n) {
    char* str = (char*)malloc(sizeof(char) * 12);
    sprintf(str, "%d", n);
    return str;
}

}