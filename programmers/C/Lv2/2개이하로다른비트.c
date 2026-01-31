#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 10진수 -> 2진수
char* dec_to_bin(long long n)
{
    
    if(n == 0)
    {
        char* buf = (char*)malloc(2);
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }

    char tmp[100];
    int idx = 0;
    while(n > 0)
    {
        tmp[idx] = (n % 2) + '0';
        idx++;
        n = n / 2;
    }
    tmp[idx] = '\0';

    char* bin = (char*)malloc(idx + 1);
    for(int i = 0 ; i < idx ; ++i)
    {
        bin[i] = tmp[idx - 1 - i];
    }
    bin[idx] = '\0';
    
    return bin;    
}

// 2진수 -> 10진수
long long bin_to_dec(const char* s)
{
    long long val = 0;
    for(int i = 0 ; s[i] != '\0' ; ++i)
    {
        val = val * 2 + (s[i] - '0');
    }
    return val;
}

// 2진수 내에서 변환
char* bin_to_bin(const char* s)
{
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            char* ss = (char*)malloc(len + 1);
            strcpy(ss, s);

            ss[i] = '1';
            ss[i + 1] = '0';

            return ss;
        }
    }

    char* ss = (char*)malloc(len + 2);
    ss[0] = '1';
    ss[1] = '0';

    for (int i = 1; i < len; i++)
        ss[i + 1] = s[i];

    ss[len + 1] = '\0';
    return ss;
}

long long* solution(long long numbers[], size_t numbers_len) {
    long long* answer = (long long*)malloc(sizeof(long long) * numbers_len);
    
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        if(numbers[i] % 2 == 0) // 짝수인 경우
        {
            answer[i] = numbers[i] + 1;
        }
        else // 홀수인 경우
        {
            char* bin = dec_to_bin(numbers[i]);
            char* next = bin_to_bin(bin);
            answer[i] = bin_to_dec(next);
            free(bin);
            free(next);
        }
    }

    return answer;
}
