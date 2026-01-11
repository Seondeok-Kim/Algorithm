#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp_desc(const void *a, const void *b)
{
    const int v1 = *(const int*) a; 
    const int v2 = *(const int*) b;
    if(v1 > v2) return -1;
    else if(v1 < v2) return 1;
    return 0;
}

int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(sizeof(int) * score_len);
    // 명예의 전당 하루치
    int* honor = (int*)malloc(sizeof(int) * score_len);
    for(int i = 0 ; i < score_len ; ++i)
    {
        honor[i] = 0;
    }
    int cnt = 0;
    while(cnt < score_len)
    {
        for(int i = 0 ; i < cnt+1 ; ++i) 
        {   
            honor[i] = score[i];   
        }
        qsort(honor, score_len, sizeof(int), cmp_desc);
 
        if (cnt < k-1)
        {
            answer[cnt] = honor[cnt];
        }
        else
        {
            answer[cnt] = honor[k-1];
        }
        cnt++;
    }
    return answer;
}
