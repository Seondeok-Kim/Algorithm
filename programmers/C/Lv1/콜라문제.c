#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a)
    {
        int m = n / a;
        int k = n % a;
        answer += (m * b);
        n = (m * b) + k;
    }
    return answer;
}
