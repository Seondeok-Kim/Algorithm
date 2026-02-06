#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// weights_len은 배열 weights의 길이입니다.
long long solution(int weights[], size_t weights_len) {
    long long answer = 0;
    long long all_weights[1001] = {0};
    
    for(int i = 0 ; i < weights_len ; i++)
    {
        all_weights[weights[i]]++;
    }
    
    for(int w = 1 ; w <= 1000 ; w++)
    {
        if(all_weights[w] >= 2)
        {
            answer += all_weights[w] * (all_weights[w] - 1) / 2 ;
        }
    }
    // 2:3
    for(int w = 1; w <= 1000 ; w++)
    {
        if(all_weights[w] == 0) continue;
        if((w * 3) % 2 == 0)
        {
            int other = (w * 3) / 2;
            if(other <= 1000 && other > w)
                answer += all_weights[w] * all_weights[other];
        }
    }
    // 2:4
    for(int w = 1; w <= 1000 ; w++)
    {
        if(all_weights[w] == 0) continue;
        if(w * 2 <= 1000)
        {
            int other = w * 2;
            if(other <= 1000)
                answer += all_weights[w] * all_weights[other];
        }
    }
    // 3:4
    for(int w = 1 ; w <= 1000 ; w++)
    {
        if(all_weights[w] == 0) continue;
        if((w * 4) % 3 == 0)
        {
            int other = (w * 4) / 3;
            if(other <= 1000 && other > w)
                answer += all_weights[w] * all_weights[other];
        }
    }
    
    return answer;
}
