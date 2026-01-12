#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool equal_str(const char *s, const char *w) // s: babbling, w: word
{
    bool flag = false;
    int n = strlen(w);
    if(strncmp(s, w, n) == 0) flag = true;
    return flag;
}

bool valid_babbling(const char *s) // ayaye
{
    const char *word[4] = { "aya", "ye", "woo", "ma"};
    int prev = -1;
    int idx = 0;
    int len = strlen(s);
    
    while(idx < len)
    {
        int matched = -1; // 매칭 되었는지 안되었는지
        for(int w = 0 ; w < 4 ; ++w)
        {
            if(equal_str(s + idx, word[w]))
            {
                matched = w;
                break;
            }
        }
        
        if(matched == -1) return false; // 어떤 발음도 매칭 안됨
        if(matched == prev) return false; // 같은 발음 연속 사용 금지
        idx += strlen(word[matched]); // 매칭된 단어 길이 만큼 전지
        prev = matched;
    }
    return true;
    
}

int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;

    for(int i = 0 ; i < babbling_len ; ++i)
    {
        if(valid_babbling(babbling[i]))
        {
            answer++;
        }
    }

    
    return answer;
}
