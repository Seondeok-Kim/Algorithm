#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_asc(const void* a, const void* b)
{
    int x = *(const int*) a;
    int y = *(const int*) b;
    
    if(x > y) return 1;
    else if(x < y) return -1;
    return 0;
}
int solution(int elements[], size_t elements_len) {
    int answer = 1;
    int cnt = elements_len * elements_len;
    int *bucket = (int*)malloc(sizeof(int) * cnt); 
    int idx = 0;
    int i = 0; 
    while (i < elements_len)
    {
        int *sub_bucket = (int*) malloc(sizeof(int) * (elements_len + i));
        
        for(int j = 0 ; j < elements_len + i ; ++j)
        {
            if(j < elements_len)
            {
                sub_bucket[j] = elements[j];
            }
            else 
            {
                sub_bucket[j] = sub_bucket[j-elements_len]; 
            }
        }
        
        for(int j = 0 ; j < elements_len ; ++j)
        {
            int sum = sub_bucket[j];
            for(int k = 0 ; k < i ; ++k)
            {
                sum += sub_bucket[j + 1 + k];
            }
            bucket[idx++] = sum;
        }
        i++;
        free(sub_bucket);
    }
    qsort(bucket, idx, sizeof(int), cmp_asc);
    
    for(int j = 1 ; j < idx ; ++j)
    {
        if(bucket[j] != bucket[j-1])
        {
            answer++;
        }
    }
    return answer;
}
