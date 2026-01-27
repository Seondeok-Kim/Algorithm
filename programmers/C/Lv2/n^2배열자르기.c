#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int* solution(int n, long long left, long long right) {
    int* answer = (int*) malloc(sizeof(int) * (right - left + 1));
    
    for(long long i = left ; i <= right ; ++i)
    {
        answer[i-left] = max(i/n, i%n) + 1; 
    }

    return answer;
}

