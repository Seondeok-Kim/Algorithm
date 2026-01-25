#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int jump(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 2;
    
    int f0 = 1;
    int f1 = 2;
    
    for(int i = 2 ; i < n ; ++i)
    {
        int f2 = (f0 + f1) % 1234567;
        f0 = f1; 
        f1 = f2;
    }
    return f1;
}

long long solution(int n) {
    long long answer = 0;
    answer = jump(n) ;
    return answer;
}
