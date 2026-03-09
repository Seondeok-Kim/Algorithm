#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> ingredient(N,0);
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> ingredient[i];
    }
    sort(ingredient.begin(), ingredient.end());
    
    int start_index = 0;
    int end_index = N-1;
    int cnt = 0;

    while(start_index < end_index)
    {
        int sum = ingredient[start_index] + ingredient[end_index];
        if(sum > M)
        {
            end_index--;
        }
        else if(sum < M)
        {
            start_index++;
        }
        else
        {
            cnt++;
            start_index++;
            end_index--;
        }
    }

    cout << cnt << "\n";
    
    return 0;
}
