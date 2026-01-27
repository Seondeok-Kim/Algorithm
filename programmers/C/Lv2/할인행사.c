#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int answer = 0;
    int fruit_cnt = 0; 
    for(int i = 0 ; i < number_len ; ++i)
    {
        fruit_cnt += number[i];
    }
    int i = 0;
    
    while((i + fruit_cnt - 1 < discount_len) )
    {
        int* each_fruit_cnt = (int*)malloc(sizeof(int) * number_len); 
        for(int j = 0 ; j < number_len ; ++j)
        {
            each_fruit_cnt[j] = 0;
        }
        for(int j = 0 ; j < fruit_cnt ; ++j)
        {
            for(int k = 0 ; k < want_len ; ++k)
            {
                if(strcmp(discount[i + j], want[k]) == 0)
                {
                    each_fruit_cnt[k]++ ;
                    break;
                }
            }
        }
        bool flag = true;
        for(int j = 0 ; j < number_len ; ++j)
        {
            if(each_fruit_cnt[j] != number[j]) flag = false; 
        }
        if(flag == true) answer++;
        i++;
    }
    return answer;
}
