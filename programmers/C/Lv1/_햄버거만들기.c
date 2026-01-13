#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int idx = 0;
    int *stack = (int*)malloc(sizeof(int) * ingredient_len);
    int top = 0;
    
    for(int i = 0 ; i < ingredient_len ; ++i)
    {
        stack[top] = ingredient[i];
        
        if(top >= 3 
          && stack[top] == 1
          && stack[top - 1] == 3
          && stack[top - 2] == 2
          && stack[top - 3] == 1)
        {
            top -= 4;
            answer += 1;
        }
        top++;
    }
    

    
    return answer;
}
