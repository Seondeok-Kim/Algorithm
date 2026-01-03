#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    // 기존 인덱스(가장 처음 상태) 담는 벡터
    vector<int> index(n);
    // 기존 인덱스 담음 ---> 가장 초기 상태
    for(int i = 0 ; i < n ; ++i) index[i] = i;
    // 실행된 프로세스의 인덱스를 담는 벡터
    vector<int> exe;
    
    while (priorities.empty() != true)
    {
        int first = priorities.front();
        int first_index = index.front();
        bool move = false; // 프로세스 맨 뒤로 보냈는지 (뒤로 보냄: 1, 안 보냄: 0)
        //뒤 프로세스 탐색
        for (int i = 1 ; i < priorities.size() ; ++i)
        {
            if (first < priorities[i]) // 뒤에 더 큰 프로세스가 있다면
            {
                priorities.erase(priorities.begin()); // 맨 앞 프로세스 제거
                priorities.push_back(first); // 맨 뒤에 프로세스 추가
                index.erase(index.begin()); // 맨 앞 인덱스 제거
                index.push_back(first_index); // 맨 뒤 인덱스 추가
                move = true;
                break;
            }
        }
        
        if (move == true) continue;
        
        // 뒤에 더 큰 프로세스가 없다면 --> 맨 앞 프로세스 실행
        priorities.erase(priorities.begin()); // 맨 앞 프로세스 제거
        index.erase(index.begin()); // 맨 앞 인덱스 제거
        exe.push_back(first_index); // 실행된 인덱스 저장           
    }
    
    
    for(int i = 0 ; i < exe.size() ; ++i)
    {
        if (exe[i] == location) answer = (i+1);
    }

    return answer;
}
