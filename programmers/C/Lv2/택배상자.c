#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solution(int order[], size_t order_len) {
    int answer = 0;
    int* stack = (int*)malloc(sizeof(int) * order_len);
    int* truck = (int*)malloc(sizeof(int) * order_len);
    
    for(int i = 0 ; i < order_len ; ++i)
        truck[i] = -1;
    
    int n = 1;
    int top = 0;
    int order_idx = 0;
    int truck_idx = 0;
    
    while(n <= order_len)
    {
        stack[top] = n;
        while(top >= 0 && stack[top] == order[order_idx])
        {
            truck[truck_idx] = stack[top];
            top--;
            truck_idx++;
            order_idx++;
        }
        top++;
        n++;
    }
    for(int i = 0 ; i < order_len ; ++i)
    {
        if(truck[i] > -1)
            answer++;
    }
    return answer;
}
