#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    int total_num = (n * (n+1)) / 2;
    int* answer = (int*)malloc(sizeof(int) * total_num);
    int** arr = (int**)malloc(sizeof(int*) * n);
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = (int*)calloc(n, sizeof(int));
    }
    
    int dx[3] = {1, 0, -1};
    int dy[3] = {0, 1, -1};
    
    int x = 0; 
    int y = 0;
    int dir = 0;
    int num = 1;
    
    while(num <= total_num)
    {
        arr[x][y] = num++;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0)
        {
            dir = (dir + 1) % 3 ;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    
    // 수정 3: answer 채우기
    int idx = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            answer[idx++] = arr[i][j];
        }
    }
    
    for(int i = 0 ; i < n ; ++i)
    {
        free(arr[i]);
    }
    free(arr);
    
    return answer;
}
