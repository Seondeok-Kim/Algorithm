#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool solution(const char* s) {
    int top = 0;
    for(int i = 0 ; s[i] != '\0'; ++i)
    {
        if(s[i] == '(')
        {
            top++;
        }
        else
        {
            if(top == 0) return false;
            else top--;
        }
    }
    if(top == 0) return true;
    else return false;
}
