#include <bits/stdc++.h>
using namespace std;


int solution(int n)
{
    // n을 string 형으로 만들기
    string m = to_string(n);
    // 문자열 길이 구하기 
    int len = m.size();

    int sum = 0;
    for(char c : m)
    {
        sum += c - '0';
    }
    return sum;
}




int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    cout << solution(n) << '\n';
    
	
	return 0;
}