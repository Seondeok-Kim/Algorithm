#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int m = t.size(); // 문자 길이 7
    int n = p.size(); // 슬라이딩 길이 3
    vector<string> v;
    for(int i = 0 ; (i + n) <= m ; ++i)
    {
        string part = "";
        for (int j = 0 ; j < n ; ++j)
        {
            part.push_back(t[i+j]);
        }
        v.push_back(part);
    }
    int k = v.size();
    for(int i = 0 ; i < k ; ++i)
    {
        long a = stoll(v[i]);
        long b = stoll(p);
        if(a <= b) answer++;
    }
    
    return answer;
}
