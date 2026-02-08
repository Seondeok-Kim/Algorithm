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

    int rooms[1000]; // 현재 사용 중인 방들의 종료시간 목록
    int roomCount = 0; // 필요한 객실 수
    for(int i = 0 ; i < book_time_rows; i++)
    {
        int start = time[i][0]; // 현재 예약의 시작 
        int end = time[i][1]; // 현재 예약의 종료

        // room 배열에서 종료기간이 가장 작은 방 찾기
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
        // 재사용 가능한지 판단
        if(minIdx != -1 && minEnd <= start)
        {
            rooms[minIdx] = end; // 그 방의 종료시 새 예약의 종료시간으로 바꿈
        }
        else
        {
            rooms[roomCount++] = end; // 불가능하다면 새 방 추가
        }
    }
    
    
    answer = roomCount;
    return answer;
}
