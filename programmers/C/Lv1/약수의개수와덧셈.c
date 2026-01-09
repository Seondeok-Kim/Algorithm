#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int div_num(int n)
{
    int cnt = 0;
    if(n == 1) 
    {
        cnt = 1;
    }
    else if(n == 2 || n == 3) 
    {
        cnt = 2;
    }
    else if (n == 4)
    {
        cnt = 3;
    }
    else // 15 -> 1 3 5 15 16 -> 1 2 4 16
    {
        for(int i = 1 ; i < (n/2) ; ++i)
        {
            if(n % i == 0) 
            {
                if(i * i == n) 
                {
                    cnt += 1;
                }
                else 
                {
                    cnt += 2;
                }
            }        
        }
    }
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    printf("%d", div_num(15));
    for(int i = left ; i <= right ; ++i)
    {
        int cnt = 0;
        cnt = div_num(i);
        if(cnt % 2 == 0)
        {
            answer += i;   
        }
        else
        {
            answer -= i;
        }
    }
    return answer;
}
