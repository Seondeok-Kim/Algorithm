#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool div_num(int n)
{
    int cnt = 0;
    if(n == 1) cnt = 1;
    else if(n == 2 || n == 3) cnt = 2;
    else if (n == 4) cnt =3;
    else if (n > 4)
    {
        for(int i = 1 ; i * i <= n ;++i)
        {
            if(n % i == 0)
            {
                if(i*i == n) cnt += 1;
                else cnt += 2;
            }
        }
    }
    if(cnt == 2) return true;
    else return false;
}

int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for(int i = 0 ; i < nums_len ; ++i)
    {
        for(int j = i+1 ; j < nums_len ; ++j)
        {
            for(int k = j+1 ; k < nums_len ; ++k)
            {
                int n = nums[i] + nums[j] + nums[k];
                if(div_num(n)== true) answer++;
            }
        }
    }
    return answer;
}
