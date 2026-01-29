#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int numbers[], size_t numbers_len) {
    int* answer = (int*)malloc(sizeof(int) * numbers_len);
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        answer[i] = -1;
    }
    
    int* stack = (int*)malloc(sizeof(int) * numbers_len); // 인덱스 저장
    int top = -1;
    
    
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        while(top >= 0 && numbers[stack[top]] < numbers[i])
        {
            answer[stack[top]] = numbers[i];
            top--;
        }
        stack[++top] = i;
    }
    free(stack);
    return answer;
}
