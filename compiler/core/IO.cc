#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern "C" {

void print(char* str) {
    printf("%s", str);
}

void println(char* str) {
    printf("%s\n", str);
}

char* read() {
    char* buffer = (char*)malloc(sizeof(char) * 128);
    scanf("%s", buffer);
    return buffer;
}

}