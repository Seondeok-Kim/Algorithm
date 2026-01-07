#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    qsort(A, A_len, sizeof(int), cmp_asc);
    qsort(B, B_len, sizeof(int), cmp_asc);
    
    for(int i = 0 ; i < A_len ; ++i)
    { 
        answer += A[i] * B[A_len - (i + 1)];
    }
    
    return answer;
}
