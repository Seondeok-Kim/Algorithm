#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    // 0번째 원소 넣기
    if(arr.size() > 0)
    {
        answer.push_back(arr[0]);
    }

    int i = 1;
    while (i < arr.size())
    {
        if(answer.back() != arr[i])
        {
            answer.push_back(arr[i]);
            i++;
        }
        else
        {
            i++;
        }       
    }
    

    return answer;
}
