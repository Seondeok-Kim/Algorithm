#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    char* answer = "Yes";
    int idx1 = 0;
    int idx2 = 0;
    int cnt = 0;
    
    while(cnt < goal_len)
    {
        if(idx1 < cards1_len && strcmp(goal[cnt], cards1[idx1]) == 0)
        {
            cnt++;
            idx1++;
        }
        else if (idx2 < cards2_len && strcmp(goal[cnt], cards2[idx2]) == 0)
        {
            cnt++;
            idx2++;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    return answer;
}
