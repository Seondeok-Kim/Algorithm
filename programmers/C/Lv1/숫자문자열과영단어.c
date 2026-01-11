#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    int *buffer = (int*)malloc(sizeof(int) * len);
    int idx = 0;
    char *part = (char*)malloc(len+1);
    int idx1 = 0;
    
    for(int i = 0 ; i < len ; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9') 
        {
            buffer[idx] = s[i] - '0'; 
            idx++;
        }
        else 
        {
            part[idx1] = s[i];
            idx1++;
            part[idx1] = '\0';
            
            if      (strcmp(part, "zero") == 0)  {buffer[idx] = 0; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "one") == 0)   {buffer[idx] = 1; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part,"two") == 0)    {buffer[idx] = 2; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "three") == 0) {buffer[idx] = 3; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part,"four") == 0)   {buffer[idx] = 4; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part,"five") == 0)   {buffer[idx] = 5; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "six") == 0)   {buffer[idx] = 6; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "seven") == 0) {buffer[idx] = 7; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "eight") == 0) {buffer[idx] = 8; idx++; idx1 = 0; part[0] = '\0';}
            else if (strcmp(part, "nine") == 0)  {buffer[idx] = 9; idx++; idx1 = 0; part[0] = '\0';}
        }
    }
    
    for(int i = 0 ; i < idx ; ++i)
    {
        answer = answer * 10 + buffer[i];
    }
    return answer;
}
