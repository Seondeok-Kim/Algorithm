#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int N;
	cin >> N;
	
	queue<int> q;

	for(int i = 0 ; i < N ; ++i)
	{
		string cmd;
		cin >> cmd;
		if(cmd == "push")
		{
			int x ;
			cin >> x;
			q.push(x);
		}
		else if(cmd == "pop")
		{
			if(q.size() != 0)
			{
				int x = q.front(); 
				q.pop();
				cout << x << '\n';
			}
			else
			{
				cout << "-1"<<'\n';
			}
		}
		else if(cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if(q.empty() == true)
			{
				cout << "1" << '\n';
			}
			else
			{
				cout << "0" << '\n' ;
			}
		}
		else if (cmd == "front")
		{
			if(q.size() != 0)
			{
				cout << q.front() << '\n';
			}
			else
			{
				cout << "-1"<<'\n';
			}
		}
		else if (cmd == "back")
		{
			if(q.size() != 0)
			{
				cout << q.back() << '\n';
			}
			else
			{
				cout << "-1"<<'\n';
			}
		}
	}

	return 0;
}
