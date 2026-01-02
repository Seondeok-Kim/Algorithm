#include <string>
#include <vector>

using namespace std;
// 1 2 3 4 6 12
int solution(int n) {
    int answer = 0;
    
    vector<int> v(0);
    for(int i = 1 ; i <= n ; ++i)
    {
        if(n % i == 0)
        {
            v.push_back(i);
        }
    }
    
    for(int i = 0; i < v.size() ; ++i)
    {
        answer += v[i];    
    }
        
    return answer;
}
