#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    int cnt = 0;
    while (num > 1 && cnt <= 500)
    {
        if(num % 2 == 0)
        {
            num = num / 2;
            cnt ++;
        }
        else
        {
            num = (num * 3) + 1;    
            cnt ++;
        }
    }
    
    if(num == 1) answer = cnt;
    else answer = -1;
    
    return answer;
}
