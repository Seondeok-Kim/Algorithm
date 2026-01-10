#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_asc(const void *a, const void *b)
{
    int x = *(int *) a;
    int y = *(int *) b;
    
    if(x > y) return 1;
    else if(x < y) return -1;
    return 0;
}

int* solution(int numbers[], size_t numbers_len) {
    // 1. 모든 조합의 수 구하기
    int cnt = 0;
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        for(int j = i + 1 ; j < numbers_len ; ++j)
        {
            cnt++;
        }   
    }
    // 2. 모든 조합의 합 저장
    int* tmp = (int*)malloc(sizeof(int) * cnt);
    int idx = 0;
    for(int i = 0 ; i < numbers_len ; ++i)
    {
        int sum = 0;
        for(int j = i + 1 ; j < numbers_len ; ++j)
        {
            sum = numbers[i] + numbers[j];
            tmp[idx] = sum;
            idx++;
        }
    }
    
    // 3. 정렬
    qsort(tmp, cnt, sizeof(int), cmp_asc);
    
    //4. 중복제거
    int write = 0;
    for(int read = 0 ; read < cnt ; ++read)
    {
        if(read == 0 || tmp[read] != tmp[read-1])
        {
            tmp[write++]  = tmp[read];
        }
    }
    
    //5. 결과 크기 설정
    size_t *returnSize = (size_t)write;
    
    //tmp 정확한 크기로 줄이기
    int *answer = (int*)realloc(tmp, sizeof(int) * write);
    if(answer == NULL)
    {
        return tmp;    
    }
    
    return answer;
}
