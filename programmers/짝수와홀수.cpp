#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer;
    // 2로 나눠서 짝수면 Even
    if(num % 2 == 0)
    {
        answer = "Even";
    }    
    else    // 2로 나눠서 홀수면 Odd
    {
        answer = "Odd";
    }
    return answer; 
}
