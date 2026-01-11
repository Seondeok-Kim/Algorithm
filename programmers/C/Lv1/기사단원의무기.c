#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int div_num(int n)
{
    int cnt = 0;
    if (n == 1) return 1;
    else if (n == 2 || n == 3) return 2;
    else if (n == 4) return 3;
    else
    {
        for(int i = 1 ; i*i <= n ; ++i)
        {
            if(n % i == 0)
            {
                if(i * i == n) cnt += 1;
                else cnt += 2;
            }
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    int* arr = (int*)malloc(sizeof(int) * (number + 1));
    for(int i = 1 ; i <= number ; ++i)
    {
        arr[i] = div_num(i);
        if(arr[i] > limit)
        {
            arr[i] = power;
        }
    }
    for(int i = 1 ; i <= number ; ++i)
    {
        answer += arr[i];
    }
    
    return answer;
}
