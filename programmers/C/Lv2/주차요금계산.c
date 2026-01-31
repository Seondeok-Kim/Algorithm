#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int cmp_asc(const void* a, const void* b)
{
    int x = *(const int*) a;
    int y = *(const int*) b;
    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}


// 시간을 분으로 바꿈
int time_to_min(const char *s)
{
    int time = (s[0] - '0') * 10 + (s[1] - '0');
    int min = (s[3] - '0') * 10 + (s[4] - '0');
    return time * 60 + min;
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    int* car = (int*)malloc(sizeof(int)*records_len);
    
    // 차량 번호 배열에 저장
    for(int i = 0 ; i < records_len ; ++i)
    {
        int car_number = 0;
        for(int j = 6 ; j < 10 ; ++j)
        {
            car_number = car_number * 10 + records[i][j] - '0';
        }
        car[i] = car_number;
    }
    
    // 차량 번호 오름차순 정렬
    qsort(car, records_len, sizeof(int), cmp_asc);
    int* car_no_overlap = (int*)malloc(sizeof(int) * records_len);
    car_no_overlap[0] = car[0];
    int car_cnt = 1;
    // 차량 번호 중복 제거
    for(int i = 1 ; i < records_len ; ++i)
    {
        if(car[i] != car[i-1])
        {
            car_no_overlap[car_cnt] = car[i];
            car_cnt++;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * car_cnt);
    int last_in[10000]; // 마지막 IN 시간
    int total[10000]; // 누적 주차 시간
    
    for(int i = 0 ; i < 10000 ; ++i)
    {
        last_in[i] = -1;
        total[i] = 0;
    }
    // 누적 주차 시간 계산
    for(int i = 0 ; i < records_len ; ++i)
    {
        int t = time_to_min(records[i]);
        int car_number = 0;
        for(int j = 6 ; j < 10 ; ++j)
        {
            car_number = car_number * 10 + records[i][j] - '0';
        }
        
        if(records[i][11] == 'I')
        {
            last_in[car_number] = t;
        }
        else
        {
            total[car_number] += t - last_in[car_number];
            last_in[car_number] = -1;
        }
    }
    
    // 출차 내역이 없는 경우
    for(int i = 0 ; i < 10000 ; ++i)
    {
        int t = time_to_min("23:59");
        if(last_in[i] != -1)
        {
            total[i] += t - last_in[i];
        }
    }
    
    int* time = (int*)malloc(sizeof(int) * car_cnt);
    int idx = 0;
    for(int i = 0 ; i < car_cnt ; ++i)
    {
        int num = car_no_overlap[i];
        time[i] = total[num];
    }
    // 요금 계산
    for(int i = 0 ; i < car_cnt ; ++i)
    {
        if(time[i] <= fees[0])
        {
            answer[i] = fees[1];
        }
        else
        {
            answer[i] = fees[1] + ((time[i] - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
        }
    }
    
    free(time);
    free(car);
    free(car_no_overlap);
    return answer;
}
