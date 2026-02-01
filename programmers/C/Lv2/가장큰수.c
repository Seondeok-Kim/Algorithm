#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp_dsc(const void* a, const void* b)
{
    const char* s1 = *(const char**) a;
    const char* s2 = *(const char**) b;
    
    char ab[40], ba[40];
    sprintf(ab, "%s%s", s1, s2); // 정수 -> 문자열
    sprintf(ba, "%s%s", s2, s1);

    return strcmp(ba, ab);
}

char* solution(int numbers[], size_t numbers_len) {
    char** word = (char**)malloc(sizeof(char*) * numbers_len);
    int len = 0;
    // numbers 내 정수 원소 -> 문자열 원소로 변환
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        char buf[20];
        sprintf(buf,"%d", numbers[i]);
        word[i] = malloc(strlen(buf)+1);
        strcpy(word[i], buf);
    }


    qsort(word, numbers_len, sizeof(char*), cmp_dsc);
    
    if(word[0][0] == '0')
    {
        for(int i = 0 ; i < numbers_len ; ++i) free(word[i]);
        free(word);
        char* answer = (char*)malloc(2);
        answer[0] = '0';
        answer[1] = '\0';
        return answer;
    }

    for(int i = 0 ; i < numbers_len ; ++i)
    {
        len += strlen(word[i]);
    }
    
    char* answer = (char*)malloc(len + 1);
    answer[0] = '\0';
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        strcat(answer, word[i]);
    }
    
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        free(word[i]);
    }
    free(word);
    return answer;
}



