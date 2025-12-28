#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    deque<int> dq;

    for(int i = 1 ; i <= n ; ++i)
    {
        dq.push_back(i);
    }
    
    int flag = 1;

    while (dq.size() > 1)
    {
        if(flag == 1) // trash
        {
            dq.pop_front();
            flag = 0;
        }
        else // lift
        {
            dq.push_back(dq.front());
            dq.pop_front();
            flag = 1;
        }
    }
    cout << dq.front() <<'\n';
	return 0;
}
