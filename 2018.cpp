#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int cnt = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;

    while(end_index != N)
    {
        if(sum == N)
        {
            cnt++;
            end_index++;
            sum += end_index;
        }
        else if(sum > N)
        {
            sum -= start_index;
            start_index++;
        }
        else
        {
            end_index++;
            sum += end_index;
        }
    }
    cout << cnt << "\n";
    return 0;
}
