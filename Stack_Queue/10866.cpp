#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<int> dq;

    for (int i = 0 ; i < N ; ++i)
    {
        string cmd;
        cin >> cmd;
    
        if (cmd == "push_front")
        { 
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "pop_front")
        {
            if(dq.empty() == false)
            {
                int a = dq.front();
                dq.pop_front();
                cout << a << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (cmd == "pop_back") 
        {
            if(dq.empty() == false)
            {
                int a = dq.back();
                dq.pop_back();
                cout << a << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (dq.empty() == true) cout << "1" << '\n';
            else                   cout << "0" << '\n';
        }
        else if (cmd == "front")
        {
            if (dq.empty() == false) cout << dq.front() << '\n'; 
            else                    cout << "-1" << '\n';
        }
        else if (cmd == "back")
        {
            if(dq.empty() == false) cout << dq.back() << '\n';
            else                    cout << "-1" << '\n';
    
        }
    }

    return 0;
}
