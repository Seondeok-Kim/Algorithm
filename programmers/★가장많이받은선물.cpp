#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    // friend 벡터 내용 확인하고 친구들 이름에 따라 번호 부여할 거임
    vector<int> frineds_index;
    // 친구들 전체 수
    int n = friends.size();
    // 이름 -> 번호로 매핑
    unordered_map<string, int> id;
    id.reserve(n * 2);
    for(int i = 0 ; i < n ; ++i)
    {
        id[friends[i]] = i;
    }
    // out: 준 선물 수, in: 받은 선물 수
    vector<int> out(n,0);
    vector<int> in(n,0);
    
    // give 테이블 만들기
    vector<vector<int>> give(n, vector<int>(n, 0));
    
    // gifts 파싱해서 데이터 채우기
    for(const string &s : gifts)
    {
        string a, b; // a, b 로 분리
        {
            istringstream iss(s);
            iss >> a >> b;
        }
        
        int giver = id[a];
        int recv = id[b];
        
        give[giver][recv] += 1;
        out[giver] += 1;
        in[recv] += 1;
    }
    
    // gift_index에 선물 지수 채우기
    vector<int> gift_index (n,0);
                              
    for(int i = 0 ; i < n ; ++i)
    {
        gift_index[i] = out[i] - in[i];
    }
    
    // 다음 달에 받을 선물 수 
    vector<int> next_recv(n,0);
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = i+1 ; j < n ; ++j)
        {
            if (give[i][j] > give[j][i]) next_recv[i]++;
            else if (give[i][j] < give[j][i]) next_recv[j]++;
            else 
            {
                if(gift_index[i] > gift_index[j]) next_recv[i]++;
                else if(gift_index[i] < gift_index[j]) next_recv[j]++;     
            }
        } 
    }
    
    for (int i = 0; i < n; ++i) {
        if (answer < next_recv[i]) answer = next_recv[i];
    }
   
    return answer;
}
