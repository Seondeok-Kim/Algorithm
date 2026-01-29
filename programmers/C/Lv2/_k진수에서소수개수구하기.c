#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char* convert(int n, int k)
{
    char* tmp = (char*)malloc(20 + 1);
    if(n == 0)
    {
        char* zero = (char*)malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        free(tmp);
        return zero;
    }
    int a = n;
    int b = 0;
    int i = 0;
    while(a > 0)
    {
        b = a % k;
        a = a / k;
        tmp[i] = b + '0';
        i++;
    }
    char* result = (char*)malloc(i + 1);
    for(int j = 0 ; j < i ; ++j)
    {
        result[j] = tmp[i - 1 - j];
    }
    result[i] = '\0';
    free(tmp);
    return result;
}


long long* parse_by_zero(char* str, int* out_len)
{
    int len = strlen(str);
    long long* nums = (long long*)malloc(sizeof(int) * len);
    int count = 0;
    
    long long value = 0;
    int in_number = 0; 
    for(int i = 0 ; i <= len ; ++i)
    {
        if(str[i] != '0' && str[i] != '\0')
        {
            value = value * 10 + (str[i] - '0');
            in_number = 1;
        }
        else
        {
            if(in_number == 1)
            {
                nums[count++] = value;
                value = 0;
                in_number = 0;
            }
        }
    }
    *out_len = count;
    return nums;
}

bool find_prime(long long n)
{
    int flag = true;
    if(n <= 1) flag = false;
    else if (n == 2 || n == 3) flag = true;
    else
    {
        for(long long i = 2 ; i * i <= n ; ++i)
        {
            if(n % i == 0)
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}


int solution(int n, int k) {
    int answer = 0;
    
    char* str = convert(n, k);
    
    int cnt = 0;
    long long* nums = parse_by_zero(str, &cnt);
    
    for(int i = 0 ; i < cnt ; ++i)
    {
        if(find_prime(nums[i]) == true)
        {
            answer++;
        }
    }
    
    free(str);
    free(nums);
    
    return answer;
}
