#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp_asc(const void* a, const void *b)
{
    const int v1 = *(const *) a;
    const int v2 = *(const *) b;
    if(v1 > v2) return 1;
    else if(v1 < v2) return -1;
    return 0;
}
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    qsort(score, score_len, sizeof(int), cmp_asc);
    
    for(int i = score_len - 1 ; (i - m + 1) >= 0 ; i -= m)
    {
        answer += m * score[i - m + 1];        
    }
    return answer;
}
