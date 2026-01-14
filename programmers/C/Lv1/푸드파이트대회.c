#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    //1. answer 길이 구하기
    int len = 0;
    for(int i = 0 ; i < food_len ; ++i)
    {
        if(i == 0)
        {
            len += food[i];
        }
        else
        {
            if(food[i] % 2 == 0)
            {
                len += food[i];
            }
            else
            {
                len += (food[i] - 1);
            }
        }
    }

    // 정답 담을 메모리 할당
    int idx = 0;
    char* answer = (char*)malloc(len + 1);
    for(int i = 1 ; i < food_len ; ++i)
    {
        int n = food[i] / 2; // 반복 횟수
        for(int j = 0 ; j < n ; ++j)
        {
            answer[idx] = i + '0';
            idx++;
        }
    }
    int idx1 = idx-1;
    for(int i = 0 ; i < food[0] ; ++i)
    {
        answer[idx] = '0';
        idx++;
    }
    
    //4. 대칭으로 원소 추가
    for(int i = idx1 ; i >= 0 ; --i)
    {
        answer[idx] = answer[idx1];
        idx1--;
        idx++;
    }
    answer[len] = '\0';
    return answer;
}
