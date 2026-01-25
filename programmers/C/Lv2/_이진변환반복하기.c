#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 1. 이진수에서 0 제거 후 전체 길이 반환
int remove_zero(char *s)
{
    int len = strlen(s);
    int cnt = 0; // 1의 개수 카운트
    for(int i = 0 ; s[i] != '\0' ; ++i)
    {
        if(s[i] == '1')
        {
            cnt++;
        }
    }
    return cnt;
}

// 2. 이진 변환
char* translate_to_bin(int n)
{
    if(n == 0)
    {
        char* bin = (char*)malloc(2);
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }
    char tmp[32];
    int idx = 0;
    
    while(n > 0)
    {
        tmp[idx++] = (n % 2) + '0'; // 3
        n = n / 2;
    }
    
    char* bin = (char*)malloc(idx + 1);
    
    for(int i = 0 ; i < idx ; i++)
    {
        bin[i] = tmp[idx-1-i];
    }
    bin[idx] = '\0';
    
    return bin;
}

int* solution(const char* s) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    char *cur = (char*)malloc(strlen(s) + 1);
    strcpy(cur, s);

    int zero_cnt = 0; // 제거한 0 총합
    int try_cnt = 0; // 변환 횟수
    
    while(strcmp(cur,"1") != 0)
    {
        int len = strlen(cur);
        
        int ones = remove_zero(cur);
        zero_cnt += len - ones;
        
        char* next = translate_to_bin(ones);
        free(cur);
        cur = next;
        try_cnt++;
    }
    
    answer[0] = try_cnt;
    answer[1] = zero_cnt;
    
    return answer;
}
