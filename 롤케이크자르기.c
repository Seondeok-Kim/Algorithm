#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int topping[], size_t topping_len) {
    int answer = 0;
    
    int right_cnt[10001] = {0};
    int left_cnt[10001] = {0};
    
    int right_kind = 0;
    int left_kind = 0;
    
    for(int i = 0 ; i < topping_len ; ++i)
    {
        if(right_cnt[topping[i]] == 0) 
        {
            right_kind++; 
        }
        right_cnt[topping[i]]++;
    }
    
    for(int i = 0 ; i < topping_len - 1 ; ++i)
    {
        int x = topping[i];
        
        right_cnt[x]--;
        if(right_cnt[x] == 0)
        {
            right_kind--;
        }
        
        if(left_cnt[x] == 0)
        {
            left_kind++;
        }
        left_cnt[x]++;
        
        if(right_kind == left_kind)
        {
            answer++;
        }
    }
    
    return answer;
}
