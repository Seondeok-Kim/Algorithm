#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x1, y1;
    int x2, y2;
} Edge;


Edge make_edge(int x1, int y1, int x2, int y2) {
    Edge e;
    if (x1 < x2 || (x1 == x2 && y1 < y2)) {
        e.x1 = x1; e.y1 = y1;
        e.x2 = x2; e.y2 = y2;
    } else {
        e.x1 = x2; e.y1 = y2;
        e.x2 = x1; e.y2 = y1;
    }
    return e;
}

int isVisited(Edge *edges, int size, Edge e) {
    for (int i = 0; i < size; i++) {
        if (edges[i].x1 == e.x1 && edges[i].y1 == e.y1 &&
            edges[i].x2 == e.x2 && edges[i].y2 == e.y2)
            return 1;
    }
    return 0;
}


int solution(const char* dirs) {
    int answer = 0;
    int x = 0 , y = 0;
    int nx, ny;
    
    Edge visited[10000];
    int vSize = 0;
    
    int len = strlen(dirs);
    
    for(int i = 0 ; i < len ; ++i)
    {
        nx = x;
        ny = y;
        
        if(dirs[i] == 'U') ny++;
        else if(dirs[i] == 'D') ny--;
        else if(dirs[i] == 'R') nx++;
        else if(dirs[i] == 'L') nx--;
        
        if(nx < -5 || nx > 5 || ny < -5 || ny > 5)
        {
            continue;
        }
        
        Edge e = make_edge(x,y, nx, ny);
        
        if(isVisited(visited, vSize, e) == 0)
        {
            visited[vSize++] = e;
            answer++;
        }
        
        x = nx;
        y = ny;
    }
        
    
    return answer;
}
