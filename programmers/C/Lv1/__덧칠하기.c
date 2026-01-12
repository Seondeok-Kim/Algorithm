#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0;
    int last = 0;
    
    for(int i = 0 ; i < section_len ; ++i)
    {
        int s = section[i];
        
        if(s > last)
        {
            answer++;
            last = s + m - 1;
        }
    }
    return answer;
}
