#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    // 세로 길이, 가로 길이
    int h = park.size();
    int w = park[0].size();
    // 시작점 지정
    int dy = 0;
    int dx = 0;
    
    for(int i = 0 ; i < h ; ++i)
    {
        for(int j = 0 ; j < w ; ++j)
        {
            if(park[i][j] == 'S')
            {
                dy = i;
                dx = j;
            }
        }
    }
    // routes 배열 파싱하기
    for(int i = 0 ; i < routes.size(); ++i)
    {
        char dir;
        int move;
        istringstream iss(routes[i]);
        iss >> dir >> move;
        
        // 시작 위치 저장
        int sy = dy;
        int sx = dx;
        
        // 방향 벡터
        int ddy = 0;
        int ddx = 0;
        
        if (dir == 'N') {ddy = -1;} // 북
        else if (dir == 'S') {ddy = 1;} // 남
        else if (dir == 'E') {ddx = 1;} // 동
        else if (dir == 'W') {ddx = -1;} // 서
        
        bool ok = true;
        int ny = sy, nx = sx;
        
        for(int i = 0 ; i < move ; ++i)
        {
            ny += ddy;
            nx += ddx;
            // 범위 체크
            if(ny < 0 || ny >= h || nx < 0 || nx >= w)
            {
                ok = false;
                break;
            }
            // 장애물 체크
            if(park[ny][nx] == 'X')
            {
                ok = false;
                break;
            }
        }
        //성공한 경우 -> 위치 업데이트
        if (ok == true)
        {
            dy = ny;
            dx = nx;
        }
    }
    
    answer.push_back(dy);
    answer.push_back(dx);
    
    return answer;
}
