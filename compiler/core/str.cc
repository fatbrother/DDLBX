#include <string.h>
#include <stdlib.h>

extern "C" {

int Str_toInt(char* str) {
    return atoi(str);
}

float Str_toFloat(char* str) {
    return atof(str);
}

char* Str_substring(char* str, int start, int end) {
    char* substr = (char*)malloc(end - start + 1);
    strncpy(substr, str + start, end - start);
    substr[end - start] = '\0';
    return substr;
}

}