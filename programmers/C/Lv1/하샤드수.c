#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int m = x;
    while(m > 0)
    {
        int n = m % 10;
        m = m / 10;
        sum += n;
    }
    if(x % sum == 0) answer = true;
    else    answer = false;
    return answer;
}
