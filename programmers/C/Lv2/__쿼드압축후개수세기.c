#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void quad(int** arr, int x, int y, int size, int* zero_cnt, int* one_cnt)
{
    int first = arr[x][y];
    bool same = true;
    
    for(int i = x; i < x + size ; i++)
    {
        for(int j = y ; j < y + size ; j++)
        {
            if(arr[i][j] != first)
            {
                same = false;
                break;
            }
        }
        if(same == false) break;
    }
    
    if(same == true)
    {
        if(first == 0) (*zero_cnt)++;
        else (*one_cnt)++;
        return;
    }
    int half = size / 2;
    quad(arr, x, y, half, zero_cnt, one_cnt); // 왼쪽 위
    quad(arr, x, y + half, half, zero_cnt, one_cnt); // 왼쪽 아래
    quad(arr, x + half, y, half, zero_cnt, one_cnt); // 오른쪽 위
    quad(arr, x + half, y + half, half, zero_cnt, one_cnt); // 오른쪽 아래
    
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    
    int zero_cnt = 0;
    int one_cnt = 0;
    
    quad(arr, 0, 0, arr_rows, &zero_cnt, &one_cnt);
    answer[0] = zero_cnt;
    answer[1] = one_cnt;
    return answer;
}
