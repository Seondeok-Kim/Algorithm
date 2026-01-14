#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp_desc(const void* a, const void* b)
{
    const char c1 = *(const char*) a;
    const char c2 = *(const char*) b;
    if(c1 > c2) return -1;
    else if (c1 < c2) return 1;
    return 0;
}

char* solution(const char* s) {    
    int len = strlen(s);
    char* answer = (char*)malloc(len+1);
    strcpy(answer, s);
    qsort(answer, len, sizeof(char), cmp_desc);
    return answer;
}
