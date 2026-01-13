#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
    int minPress[26];
    for(int i = 0 ; i < 26 ; ++i)
    {
        minPress[i] = INT_MAX;
    }
    for(int i = 0 ; i < keymap_len ; ++i)
    {
        const char *km = keymap[i];
        for(int j = 0 ; km[j] != '\0' ; ++j)
        {
            int idx = km[j] - 'A';
            int press = j+1;
            if(0 <= idx && idx < 26 && press < minPress[idx])
            {
                minPress[idx] = press;
            }
        }
    }
    
    int *answer = (int*) malloc(sizeof(int) * targets_len);
    if(!answer) return NULL;
    for(int i = 0 ; i < targets_len; ++i)
    {
        const char *t = targets[i];
        int sum = 0;
        bool possible = true;
        
        for(int j = 0 ; t[j] != '\0' ; ++j)
        {
            int idx = t[j] - 'A';
            if(idx < 0 || idx >= 26 || minPress[idx] == INT_MAX)
            {
                possible = false;
                break;
            }
            sum += minPress[idx];
        }
        if(possible == true)
        {
            answer[i] = sum;
        }
        else
        {
            answer[i] = -1;
        }
    }
    return answer;
}
