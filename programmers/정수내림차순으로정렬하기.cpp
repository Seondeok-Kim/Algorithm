#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> v;
    // 정수 n을 문자열 m으로
    string m = to_string(n);
    
    // 정수 벡터 v에다 한 개씩 정수로 변환한 값 저장
    for(int i = 0 ; i < m.size() ; ++i)
    {
        v.push_back(m[i] - '0');   
    }
    // 정수 벡터 v 내림차순 정렬
    sort(v.begin(), v.end(), greater());
    
    string s;
    // 정수 벡터 v 내 정수 원소를 문자로 변환 후 문자열에 추가
    for(int i = 0 ; i < m.size() ; ++i)
    {
        s.push_back(v[i] + '0');
    }
    // 전체 문자열 정수로 변환
    answer = stoll(s);
    
    return answer;
}
