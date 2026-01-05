#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int n = seoul.size();
    int idx = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        if(seoul[i] == "Kim") idx = i;
    }
    answer += "김서방은 ";
    answer += to_string(idx);
    answer += "에 있다";
    return answer;
}
