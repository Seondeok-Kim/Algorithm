#include <bits/stdc++.h>

using namespace std;

long long wood(int H, vector<int>& tree)
{
    long long sum = 0;

    for(int x : tree)
    {
        if(x > H)
        sum += (long long)(x - H);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> tree(N);
    vector<int> h_tree(N);

    
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> tree[i];
    }
    
    int lo = 0;
    int hi = *max_element(tree.begin(), tree.end());
    int mid = (lo + hi) / 2;    
    int ans = 0;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(wood(mid, tree) >= M)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
