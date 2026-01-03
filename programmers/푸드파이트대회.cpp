#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    int len = food.size();
    
    for(int i = 1 ; i < len ; ++i)
    {
 
        int cnt = food[i] / 2;
        while(cnt > 0)
        {
            answer.push_back('0'+(i));
            cnt--;
        }
    }
    answer.push_back('0');
    for(int i = len - 1 ; i > 0 ; --i)
    {
 
        int cnt = food[i] / 2;
        while(cnt > 0)
        {
            answer.push_back('0'+(i));
            cnt--;
        }
    }
    
    return answer;
}
