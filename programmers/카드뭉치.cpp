#include <string>
#include <vector>


using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    // 제거할 횟수
    
    while(goal.empty() != true)
    {
        string first = goal.front();
        if(first == cards1.front())
        {
            goal.erase(goal.begin());
            cards1.erase(cards1.begin());

        }
        else if(first == cards2.front())
        {            
            goal.erase(goal.begin());
            cards2.erase(cards2.begin());          
        }
        else
        {
            break;
        }
        first = "";
        continue;
    }
    
    if (goal.size() == 0) answer = "Yes";
    else answer = "No";

    return answer;
}
