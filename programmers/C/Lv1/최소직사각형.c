#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    for(int i = 0 ; i < sizes_rows ; ++i)
    {
        if(sizes[i][0] > sizes[i][1]) 
        {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    int max_w = sizes[0][0];
    int max_h = sizes[0][1];
    for(int i = 1 ; i < sizes_rows ; ++i)
    {
        if(sizes[i][0] > max_w)
        {
            max_w = sizes[i][0];
        }
        if(sizes[i][1] > max_h)
        {
            max_h = sizes[i][1];
        }   
    }
    answer = max_w * max_h;
    return answer;
}
