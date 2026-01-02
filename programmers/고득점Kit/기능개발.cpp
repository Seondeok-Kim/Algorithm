#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = progresses.size();
    vector<int> answer;
    vector<int> gap(n); 
    vector<int> g;
    
    for(int i = 0 ; i < n ; ++i)
    {
        if((100-progresses[i]) % speeds[i] == 0)
        {
            gap[i] = (100-progresses[i]) / speeds[i];    
        }
        else
        {
            gap[i] = ((100-progresses[i]) / speeds[i]) + 1;
        }
    }
    
    int i = 1;
    g.push_back(gap[0]);
    int cnt = 0;
    
    while (i < n)
    {
        if (g.back() < gap[i])
        {
            cnt++;
            answer.push_back(cnt);
            g.push_back(gap[i]);
            i++;
            cnt = 0;
        }
        else
        {
            cnt++;
            i++;
        }
    }
    answer.push_back(cnt+1);
    return answer;
}
