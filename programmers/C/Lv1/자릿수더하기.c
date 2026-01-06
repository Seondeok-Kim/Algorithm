#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    char s[n];
    int sum = 0;
    while(n > 0)
    {   // 1234 -> 123 -> 12 -> 1 -> 0
        sum += (n % 10);
        n /= 10;
    }
    answer = sum;
    return answer;
}
