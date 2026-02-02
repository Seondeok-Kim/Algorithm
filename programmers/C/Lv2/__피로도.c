#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max = 0;

void dfs(int k, int ** dungeons, int n, bool * visited, int count)
{
    if (count > max) max = count;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == 0 && k >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, n, visited, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    bool visited[8] = {false}; 
    max = 0;
    dfs(k, dungeons, dungeons_rows, visited, 0);
    return max;
}
