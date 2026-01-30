#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    
    for(int i = 0 ; i < skill_trees_len ; i++)
    {
        int idx = 0;
        bool valid = true;
        for(int j = 0 ; skill_trees[i][j] != '\0' ; ++j)
        {
            char c = skill_trees[i][j];
            char *p = strchr(skill, c);
            
            if(p != NULL)
            {
                if(skill[idx] == c)
                {
                    idx++;
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }
        if(valid == true) answer++;
    }
    return answer;
}
