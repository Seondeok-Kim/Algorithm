#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    bool flag = true;
    for(int i = 1 ; i < n ; ++i)
    {
        if(n % i == 1)
        {
            answer = i;
            break;
        }
    }
    return answer;
}
