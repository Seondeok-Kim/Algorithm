#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s) {
    int len = strlen(s);
    int* answer = (int*)malloc(sizeof(int) * len);
    
    for(int i = 0 ; i < len ; ++i)
    {
        answer[i] = -1;
    }
    
    for(int i = 1 ; i < len ; ++i)
    {
        int idx = -1;
        for(int j = 0 ; j < i ; ++j)
        {
            if(s[i] == s[j])
            {
                idx = i - j;
            }
        }
        answer[i] = idx;
    }
    return answer;
}
