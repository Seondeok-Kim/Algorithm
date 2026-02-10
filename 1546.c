#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int grade[1001];
    cin >> N;
    
    for(int i = 0 ; i < N ; ++i)
    {
        cin >> grade[i];
    }
	
    int max = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        if(grade[i] >= max)
        {
            max = grade[i];
        }
    }

    float new_grade[1001];
    for(int i = 0 ; i < N ; ++i)
    {
        new_grade[i] = (float) grade[i] * 100.0f / max ;
    }
    float sum = 0;
    float average = 0;
    for(int i = 0 ; i < N ; ++i)
    {
        sum += new_grade[i];
    }
    average = float(sum / N);
    cout << average << '\n';
	return 0;
}
