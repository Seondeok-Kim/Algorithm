#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    int n = players.size();
    int m = callings.size(); // 추월 선수 목록 크기
    
    unordered_map<string, int> pos; // 선수 이름, 현재 등수
    pos.reserve(n*2); // unordered_map이 내부적으로 사용할 버킷(bucket) 수를 미리 확보
    
    // 초기 상태
    for(int i = 0 ; i < n ; ++i)
    {
        pos[players[i]] = i;
    }
    
    for(int i = 0 ; i < m ; ++i)
    {
        string name = callings[i]; // 현재 호출한 이름
        int index = pos[name]; // 현재 이름의 위치
        int front_index = index - 1; // 바로 직전 인덱스
        
        string front_name = players[front_index];
        
        // swap
        players[front_index] = name;
        players[index] = front_name;
        
        // pos index 업데이트
        pos[name] = front_index;
        pos[front_name] = index;
    }
    
    answer = players;
    return answer;
}
