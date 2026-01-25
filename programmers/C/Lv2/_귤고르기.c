#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b)
{
    int x = *(const int*) a;
    int y = *(const int*) b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int cmp_dsc(const void *a, const void *b)
{
    int x = *(const int*) a;
    int y = *(const int*) b;
    if (x > y) return -1;
    if (x < y) return 1;
    return 0;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    
    qsort(tangerine, tangerine_len, sizeof(int), cmp_asc);
    
    int* freqs = (int*)malloc(sizeof(int) * tangerine_len);
    int i = 0;
    int idx = 0;
    while(i < tangerine_len)
    {
        int cnt = 0;
        int j = i;
        while(j < tangerine_len && tangerine[j] == tangerine[i])
        {
            cnt++;
            j++;
        }
        i += cnt;
        freqs[idx] = cnt;
        idx++;
    }
    
    qsort(freqs, idx, sizeof(int), cmp_dsc);
    
    int kind = 0;
    int sum = 0;
    while(sum < k)
    {
        sum += freqs[kind];
        kind++;
    }
    answer = kind;
    return answer;
}
