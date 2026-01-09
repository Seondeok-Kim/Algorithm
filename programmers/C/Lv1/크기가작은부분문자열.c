#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* t, const char* p) {
    int answer = 0;
    int len1 = strlen(t); // t 길이
    int len2 = strlen(p); // p 길이
    
    for(int i = 0 ; i + len2 <= len1 ; ++i ) // 시작 인덱스
    {
        char part_t[len2 + 1];
        for(int j = 0 ; j < len2 ; ++j) // 부분 인덱스
        {
            part_t[j] = t[i+j];
        }
        part_t[len2] = '\0';
        // 값 비교 
        long long pp = atoll(p);
        long long tt = atoll(part_t);

        if(pp >= tt)
        {   
            answer++;
        }
    }
    
    return answer;
}
