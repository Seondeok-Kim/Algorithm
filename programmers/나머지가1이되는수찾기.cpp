#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int result=1;
    for(int i = result ; i < n ; ++i)
    {
        if((n % i) == 1)
        {
            answer = i;
            break;
        }
        else
        {
            continue;
        }
    }
    return answer;
}
