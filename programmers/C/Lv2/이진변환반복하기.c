#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int* solution(const char* s) {
 
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    // 문자열 s 길이
    int len = (int)strlen(s);
    // 제거할 0의 개수
    int cnt_zero = 0;
    // 문자열 s를 변환할 거니까
    char *cur = (char*)malloc(len + 1);
    strcpy(cur,s);
    // 이진 변환 횟수
    int cnt_convert = 0;

    while(!(len == 1 && cur[0] == '1'))
    {
        int one_this = 0;
        int zero_this = 0;
        // step1: cur의 모든 0을 제거
        for(int i = 0 ; i < len ; ++i)
        {
            if(cur[i]  == '0')
            {
                zero_this++;
            }
            else
            {
                one_this++;
            }
        }
        cnt_zero += zero_this; 
        // 남은 1의 개수
        int cnt_one = one_this;
        char buf[32];
        int idx = 0;
        // step2: 0을 제거한 문자열의 길이를 2진수로 변환
        while(cnt_one > 0)
        {
            buf[idx++] = (cnt_one % 2) + '0';
            cnt_one /= 2;
        }
        free(cur);
        cur = (char*)malloc(idx + 1);

        for(int i = 0 ; i < idx ; ++i)
        {
            cur[i] = buf[idx - 1 - i];
        }
        cur[idx] = '\0';
        len = idx;
        cnt_convert++;
    }
    free(cur);
    answer[0] = cnt_convert;
    answer[1] = cnt_zero;
    return answer;
}
