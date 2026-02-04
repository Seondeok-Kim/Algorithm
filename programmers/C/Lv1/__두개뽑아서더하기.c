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





#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_asc(const void* a, const void* b)
{
    const int x = *(const int*) a;
    const int y = *(const int*) b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}


int* solution(int numbers[], size_t numbers_len) {
    int cnt = 0;
    // 전체 조합 개수
    for(int i = numbers_len - 1 ; i > 0 ; --i)
    {
        cnt += i;
    }
    // 중복 제거
    int* answer = (int*)malloc(sizeof(int) * cnt);
    // 중복 포함
    int* tmp = (int*)malloc(sizeof(int) * cnt);
    // numbers 길이가 2라면
    if(numbers_len == 2)
    {
        answer[0] = numbers[0] + numbers[1];
        return answer;
    }
    else // numbers 길이가 3 이상
    {
        int n = 0;
        for(int i = 0 ; i < numbers_len ; ++i)
        {
            for(int j = i + 1 ; j < numbers_len ; ++j)
            {
                tmp[n] = numbers[i] + numbers[j];
                n++;
            }
        }
        // 정렬 (중복됨)
        qsort(tmp, cnt, sizeof(int), cmp_asc);
        answer[0] = tmp[0];
        int idx = 1; // 중복 제거 인덱스
        
        for(int i = 1 ; i < cnt-1 ; ++i)
        {
            if(tmp[i-1] != tmp[i])
            {
                answer[idx] = tmp[i];
                idx++;
            }
        }
        if(tmp[cnt-2] != tmp[cnt-1]) answer[idx] = tmp[cnt-1];
    }
    return answer;
}
