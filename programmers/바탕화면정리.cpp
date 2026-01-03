#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int len_y = wallpaper.size();
    int len_x = wallpaper[0].size();
    
    vector<int> y;
    vector<int> x;
    
    for(int i = 0 ; i < len_y ; ++i) // 세로 - y
    {
        for(int j = 0 ; j < len_x ; ++j) // 가로 - x
        {
            if(wallpaper[i][j] == '#')
            {
                y.push_back(i);
                x.push_back(j);
            }
        }
    }
    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    
    int lux = x.front();
    int luy = y.front();
    int rdx = x.back() + 1;
    int rdy = y.back() + 1;
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy);
    answer.push_back(rdx);
    
    return answer;
}
