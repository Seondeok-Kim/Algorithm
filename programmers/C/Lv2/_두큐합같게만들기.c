#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int queue1[], size_t queue1_len, int queue2[], size_t queue2_len) {
    int answer = 0;
    int total_len = queue1_len + queue2_len;
    int* queue = (int*)malloc(sizeof(int) * (total_len));
    for(int i = 0 ; i < queue1_len ; ++i)
    {
        queue[i] = queue1[i];
    }
    for(int i = 0 ; i < queue2_len ; ++i)
    {
        queue[queue1_len + i] = queue2[i];
    }

    int base = 0;
    int val = queue1_len - 1;
    
    long long q1_sum = 0;
    long long q2_sum = 0;
    
    for(int i = base ; i <= val ; ++i)
    {
        q1_sum += queue[i];
    }
    for(int i = val + 1 ; i < total_len ; ++i)
    {
        q2_sum += queue[i];
    }
    
    if(((q1_sum + q2_sum) % 2) == 1) return -1;
    
    while(q1_sum != q2_sum && answer <= (total_len * 2))
    {
        if(base > val || val + 1 >= total_len) return -1;
        
        if(q1_sum > q2_sum)
        {
            q1_sum -= queue[base];
            q2_sum += queue[base];
            base++;
        }
        else // q1_sum < q2_sum
        {
            q1_sum += queue[val + 1];
            q2_sum -= queue[val + 1];
            val++;
        }
        answer++;
    }
    if(q1_sum != q2_sum) answer = -1;
    
    return answer;
}
