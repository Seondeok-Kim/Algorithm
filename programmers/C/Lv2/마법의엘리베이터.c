#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        int n = storey % 10;
        if (n < 5) 
        {
            if(n == 0)
            {
                storey = storey / 10;
            }
            answer += n;
            storey = storey - n;
        }
        else if(n > 5) 
        {    
            answer += (10 - n);
            storey = storey + (10 - n);
        }
        else // n == 5
        {
            int next = (storey / 10) % 10; 
            if(next >= 5)
            {
                answer += 5;
                storey = storey + 5;
            }
            else 
            {
                answer += 5;
                storey = storey - 5;
            }
        }
    }
    
    return answer;
}
