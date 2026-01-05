#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int n = photo.size();
    int m = name.size();
    
    for(int i = 0 ; i < n ; ++i)
    {
        int sum = 0;
        for(int j = 0 ; j < photo[i].size() ; ++j)
        {
            for(int k = 0 ; k < m ; ++k)
            {
                if(photo[i][j] == name[k])
                {
                    sum += yearning[k];
                }
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}
