#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    string sentence;
    cin >> sentence;

    vector<string> answer;

    unordered_map<string, char> label; // 문자열 → A, B, C ...
    unordered_map<string, int> cnt;    // 문자열 → 등장 횟수
    char next_label = 'A';

    int n = sentence.size();
    for (int i = 0; i + k <= n; i += k)
    {
        string s = sentence.substr(i, k);

        if (!label.count(s))
        {
            label[s] = next_label++;
            cnt[s] = 1;
        }
        else
        {
            cnt[s]++;
        }

        string tag;
        tag.push_back(label[s]);
        tag += to_string(cnt[s]);
        answer.push_back(tag);
    }

    // 결과 출력
    for (const auto& x : answer)
    {
        cout << x << '\n';
    }

    return 0;
}
