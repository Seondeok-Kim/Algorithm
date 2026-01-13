#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s, const char* skip, int index) {
    int s_len = strlen(s);
    char* answer = (char*)malloc(s_len + 1);
    bool is_skip[26] = {0};
    
    for(int i = 0 ; skip[i] != '\0' ; ++i)
    {
        is_skip[skip[i] - 'a'] = 1;    
    }
    for(int i = 0 ; i < s_len ; ++i)
    {
        char c = s[i];
        int moved = 0;
        while(moved < index)
        {
            if(c == 'z')
            {
                c = 'a';
            }
            else
            {
                c += 1;
            }
            if(is_skip[c-'a'] == 1) continue;
            moved++;
        }
        answer[i] = c;
    }
    answer[s_len] = '\0';
    
    return answer;
}
