#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int M;
    cin >> N >> M;

    vector<int> prefix(N+1, 0);

    for(int i = 1 ; i <= N ; ++i)
    {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }

    while(M--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n'; 
    }
	
	return 0;
}
