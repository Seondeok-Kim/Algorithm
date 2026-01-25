#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 오름차순 정렬 
int cmp_asc(const void* a, const void* b)
{
    int x = *(const int*) a;
    int y = *(const int*) b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

// 최대공약수 구하는 함수
int gcd(int a, int b)
{
    int g = 1;
    for(int n = 1 ; n <= a && n <= b ; n++)
    {
        if(a % n == 0 && b % n == 0)
        {
            g = n;
        }
    }
    return g;
}

// 최소공배수 구하는 함수
int lcm(int a, int b)
{
    int g = gcd(a, b);
    return g * (a / g) * (b / g);
}

int solution(int arr[], size_t arr_len) {
    int answer = 0;
    qsort(arr, arr_len, sizeof(int), cmp_asc);
    if(arr_len == 1) answer = arr[0];
    else if (arr_len == 2)
    {
        answer = lcm(arr[0], arr[1]);
    }
    else 
    {
        answer = lcm(arr[0], arr[1]);
        for(int i = 2 ; i < arr_len ; ++i)
        {
            answer = lcm(answer, arr[i]);
        }
    }
    return answer;
}
