#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    int n = absolutes.size();
    vector<int> real(n);
    for(int i = 0 ; i < n ; ++i)
    {
        if(signs[i] == true)
        {
            real[i] = absolutes[i];
        }
        else
        {
            real[i] = absolutes[i] * (-1);
        }
    }
    
    answer = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        answer += real[i];
    }
    return answer;
}
