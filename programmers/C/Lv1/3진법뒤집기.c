#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mul(int n) // n 제곱
{
    int ans = 1;
    if (n == 0) ans  = 1;
    else
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            ans *= 3;
        }
    }
    return ans;
}

int solution(int n) {
    int answer = 0;
    int arr[20];
    int cnt = 0;
    // 1. 3진법 구하기 + 2. 뒤집기
    while (n >= 1)
    {
        arr[cnt] = n % 3;
        n /= 3;
        cnt++;
    }

    // 3. 10진법 구하기
    for(int i = 0 ; i < cnt ; ++i) // cnt = 4
    {
        //printf("%d %d\n", arr[i], mul(i));
        answer += (arr[i] * mul(cnt-1-i));
    }
    return answer;
}
