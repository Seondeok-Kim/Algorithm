#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    
    for(int i = 0 ; i < prices_len ; ++i)
    {
        int cnt = 0;
        bool flag = true;
        for(int j = i + 1 ; j < prices_len ; ++j)
        {
            if(flag == true && prices[i] <= prices[j])
            {
                cnt++;
                flag = true;
            }
            else
            {                
                flag = false;
                cnt++;
                break;
            }
        }
        answer[i] = cnt;     
    }
    return answer;
}
