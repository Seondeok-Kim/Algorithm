#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char vowels[5] = {'A','E','I','O','U'};
int cnt = 0; // 사전 순서
int answer = 0 ; // 정답
int found = 0; // 찾았는지 여부
char target[6]; // 찾을 단어

void dfs(char *str, int len)
{
    if(found == 1) 
    {
        return;
    }
    
    if(len > 0)
    {
        cnt++;
        if(strcmp(str, target) == 0)
        {
            answer = cnt;
            found = 1;
            return;
        }
    }
    
    if(len == 5)
    {
        return;
    }
    
    for(int i = 0 ; i < 5 ; ++i)
    {
        str[len] = vowels[i];
        str[len+1] = '\0';
        dfs(str, len+1);
    }
}

int solution(const char* word) {
    char tmp[6] = {0};
    strcpy(target, word);
    dfs(tmp, 0);
    
    
    return answer;
}
