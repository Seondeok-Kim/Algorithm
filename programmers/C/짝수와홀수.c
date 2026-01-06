#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    if(num % 2 != 0) // 짝수일 경우
    {
        char* answer = (char*)malloc(4);
        answer[0] = 'O';
        answer[1] = 'd';
        answer[2] = 'd';
        answer[3] = '\0';
        return answer;
    }
    else
    {
        char* answer = (char*)malloc(5);
        answer[0] = 'E';
        answer[1] = 'v';
        answer[2] = 'e';
        answer[3] = 'n';
        answer[4] = '\0';
        return answer;
    }

}
