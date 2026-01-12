#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int a, int b) {
    char* answer = (char*)malloc(4);
    int day[12]   = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char* weekday[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int life = 0;
    
    for(int i = 0 ; i < a-1 ; ++i)
    {
        life += day[i];
    }
    life += (b-1);
    
    int weekday_idx = (life % 7);
    strcpy(answer, weekday[weekday_idx]);
    return answer;
}
