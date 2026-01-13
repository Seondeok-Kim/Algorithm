#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp_desc(const void* a, const void* b)
{
    const int v1 = *(const int*) a;
    const int v2 = *(const int*) b;

    if(v1 > v2) return -1;
    else if(v1 < v2) return 1;
    return 0;
}

char* solution(const char* X, const char* Y) {
    int len_x = strlen(X);
    int len_y = strlen(Y);
    
    int* array_x = (int*)malloc(sizeof(int) * len_x); // 한자리 정수로 담을 배열 선언
    int* array_y = (int*)malloc(sizeof(int) * len_y); 
    
    for(int i = 0 ; i < len_x ; ++i)
    {
        array_x[i] = X[i] - '0';  
    }
    for(int i = 0 ; i < len_y ; ++i)
    {
        array_y[i] = Y[i] - '0';
    }
    qsort(array_x, len_x, sizeof(int), cmp_desc);
    qsort(array_y, len_y, sizeof(int), cmp_desc);
    
    int buffer_len = (len_x <= len_y) ? len_x : len_y; 
    int* buffer = (int*)malloc(sizeof(int)*buffer_len);
    
    int i = 0;
    int j = 0;
    int idx = 0;
    
    while(i < len_x && j < len_y)
    {
        if(array_x[i] == array_y[j])
        {
            buffer[idx] = array_x[i];
            i++;
            j++;
            idx++;
        }
        else if (array_x[i] > array_y[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    char* answer = (char*)malloc(idx + 1);
    for(int i = 0 ; i < idx ; ++i)
    {
        answer[i] = buffer[i] + '0';
    }
    answer[idx] = '\0';
    if (idx == 0)
    {
        char* answer = (char*)malloc(3);
        answer[0] = '-';
        answer[1] = '1';
        answer[2] = '\0';
        return answer;
    }
    else if(buffer[0] == 0){
        char* answer = (char*)malloc(2);
        answer[0] = '0';
        answer[1] = '\0';
        return answer;
    }
    return answer;
}
