#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> number(N, 0);

    for(int i = 0 ; i < N ; ++i)
    {
        cin >> number[i];
    }
    
    sort(number.begin(), number.end());

    int cnt = 0;
    // 1 2 3 4 5 6 7 8 9 10
    for(int k = 0 ; k < N ; ++k)
    {
        long find = number[k]; // 5
        int start = 0; // 1
        int end = N - 1; // 4
        while (start < end)
        {
            if(number[start] + number[end] == find)
            {
                if(start!= k && end != k)
                {
                    cnt++;
                    break;
                }
                else if(start == k)
                {
                    start++;
                }
                else if(end == k)
                {
                    end--;
                }
            }
            else if(number[start] + number[end] < find)
            {
                start++;
            }
            else // number[start] + number[end] > find
            {
                end--;
            }
        }

    }
    
    cout << cnt << "\n"; 
    return 0;
}
