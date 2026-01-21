#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n ;
    scanf("%d", n);
    
    int count = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        char s[101];
        scanf("%s", s);

        int visited[26] = {0}; // 해당 문자를 과거에 한 번이라도 봤는지
        char prev = 0; // 직전문자
        int ok = 1; // 그룹 단어 플래그

        for(int j = 0 ; s[j] != '\0' ; j++)
        {
            char c = s[j]; // h
            int idx = c - 'a';
            if(c != prev) 
            {
                if (visited[idx] == 1) // 예전에 봤던 단어인데 다시 나왔다면
                {
                    ok = 0; // 그룹 단어 아님
                    break;
                }
                visited[idx] = 1;
                prev = c;
            }
        }
        if(ok == 1) count++;
    }
    printf("%d\n", count);
    return 0;
}
