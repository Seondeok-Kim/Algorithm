#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    // 정수 x를 문자열로 만들기
    string S = to_string(x);
    
    int sum = 0;
    // 문자열 내 문자들 정수로 변환하고 합 구하기
    for(char c : S)
    {
        sum += (c-'0');
    }
    // 하샤드 수 인지 확인
    if(x % sum == 0) answer = true;
    else answer = false;
    
    return answer;
}
