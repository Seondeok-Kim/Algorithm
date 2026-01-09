#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int sum = 45;
    int part = 0;
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        part += numbers[i];
    }
    answer = sum - part;
    return answer;
}
