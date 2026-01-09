#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);
    int i = 0;
    int idx = 0;
    while(i < len)
    {
        if(s[i] == ' ')
        {
            idx = 0;
        }
        else
        {
            if(idx % 2 == 0) 
            {
                answer[i] = toupper(s[i]);
                idx++;
            }
            else
            {
                answer[i] = tolower(s[i]);
                idx++;
            }
        }
        i++;
    }
    return answer;
}
