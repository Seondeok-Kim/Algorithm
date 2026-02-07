#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 시간을 분 단위로 변환
int convert_time_to_min(const char* arr)
{
    int time = (arr[0] - '0') * 10 + (arr[1] - '0'); // 15
    int min = (arr[3] - '0') * 10 + (arr[4] - '0'); // 00
    int clock = time * 60 + min;    
    return clock;
}

int cmp_asc(const void* a, const void* b)
{
    const int* x = *(const int**) a;
    const int* y = *(const int**) b;
    return x[0] - y[0];
}

int solution(const char*** book_time, size_t book_time_rows, size_t book_time_cols) {
    int answer = 0;
    int** time = (int**)malloc(sizeof(int*) * book_time_rows);
    // book_time 전부 분 단위로 변환
    for(int i = 0 ; i < book_time_rows ; ++i)
    {
        time[i] = (int*)malloc(sizeof(int) * book_time_cols);
        time[i][0] = convert_time_to_min(book_time[i][0]);
        time[i][1] = convert_time_to_min(book_time[i][1]) + 10;
        
    }
    // 변환된 book_time 모두 입실 시간 기준으로 오름차순 정렬
    qsort(time, book_time_rows , sizeof(int*), cmp_asc);

    // 가장 빨리 비는 방을 관리
    for(int i = 1 ; i < book_time_rows ; ++i)
    {
        int rooms[1000]; // 방 종료시간 저장 배열
        int roomCount = 0;
        for(int i = 0 ; i < book_time_rows; i++)
        {
            int start = time[i][0];
            int end = time[i][1];
            
            int minIdx = -1;
            int minEnd = 1000000;
            
            for(int r = 0 ; r < roomCount; r++)
            {
                if(rooms[r] < minEnd)
                {
                    minEnd = rooms[r];
                    minIdx = r;
                }
            }
            
            if(minIdx != -1 && minEnd <= start)
            {
                rooms[minIdx] = end;
            }
            else
            {
                rooms[roomCount++] = end;
            }
        }
    
    }
    answer = roomCount;
    return answer;
}
