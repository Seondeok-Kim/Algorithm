#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long num) {
    long long answer = 0;
    while(num != 1 && answer < 500)
    {
        if(num % 2 == 0) 
        {   
            num /= 2;  
            answer ++;
        }
        else 
        {
            num = (num * 3) + 1; 
            answer++;
        }
    }  
    if(answer >= 500) answer = -1;
    return answer;
}
