#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b)
{
    const char c1 = *(const char*) a;
    const char c2 = *(const char*) b;
    return c2 - c1;
}

char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(s + 1);
    strcpy(answer, s);
    qsort(answer, len, sizeof(char), cmp_desc);
    
    return answer;
}
