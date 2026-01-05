#include <string>
#include <vector>

using namespace std;

// 약수 개수 구하는 함수
int count(int n)
{
    int cnt = 0;
    for(int i = 1 ; i*i <= n ; ++i)
    {
        if((n % i) == 0)
        {
            if(i*i == n) cnt += 1;
            else cnt += 2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> knight;
    vector<int> divisor;
    for(int i = 1 ; i <= number ; ++i)
    {
        knight.push_back(i);
    }
    int n = knight.size();
    for(int i = 0 ; i < n ; ++i)
    {
        int cnt = 0;
        cnt = count(knight[i]);
        divisor.push_back(cnt);
    }
    
    for(int i = 0 ; i < n ; ++i)
    {
        if(divisor[i] > limit) answer += power;
        else answer += divisor[i];
    }

    return answer;
}
