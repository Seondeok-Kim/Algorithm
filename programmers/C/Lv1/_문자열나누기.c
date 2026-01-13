#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* s) {
    int answer = 0;
    int start = 0;
    int last = 0; 
    int len = strlen(s);
    
    while(start < len)
    {
        char c = s[start];
        int cnt_x = 0; // x 개수
        int cnt_y = 0; // x가 아닌 것 개수
        bool flag = false;
        
        for(int i = start ; i < len ; ++i)
        {
            if(c == s[i])
            {
                cnt_x++;
            }
            else
            {
                cnt_y++;
            }
            if(cnt_x == cnt_y)
            {
                start += cnt_x + cnt_y;
                last = start - 1;
                answer += 1;
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            answer += 1;
            break;
        }
    }
    
    
    return answer;
}
