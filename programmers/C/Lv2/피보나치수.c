#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fibonacchi(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int f0 = 0;
    int f1 = 1;
    
    for(int i = 2 ; i <= n ; i++)
    {
        int f2 = (f0 + f1) % 1234567;
        f0 = f1;
        f1 = f2;
    }
    return f1;
}

int solution(int n) {
    int answer = 0;
    answer = fibonacchi(n) % 1234567;
    return answer;
}
