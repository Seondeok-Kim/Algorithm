#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool check_string(const char* s, int len)
{
    bool flag = false;
    char* stack = (char*) malloc(len + 1);
    int top = 0;
    
    for(int i = 0 ; i < len ; ++i)
    {
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            stack[top] = s[i];
            top++;
        }
        else
        {
            if(top == 0)
            {
                free(stack);
                return false;
            }
            else if (s[i] == ']'&& stack[top-1] == '[' || 
                     s[i] == ')'&& stack[top-1] == '(' ||
                     s[i] == '}'&& stack[top-1] == '{')
            {
                top--;
            }
        }
    }
    free(stack);
    if(top ==0) flag = true;
    return flag;
}


int solution(const char* s) {
    int answer = 0;
    int len = strlen(s); // 6
    int n = 0;
    while(n < len)
    {
        char* rotate = (char*)malloc(len + 1);
        for(int i = 0 ; i < len ;++i)
        {
            if(n + i < len)
            {
                rotate[i] = s[n + i];
            }
            else
            {
                rotate[i] = s[n + i - len];
            }
        }
        if(check_string(rotate, len) == true)
        {
            answer++;
        }
        free(rotate);
        n++;
    }
    return answer;
}
