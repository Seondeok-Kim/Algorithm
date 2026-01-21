#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s", s);
    char *croatia[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    int len = strlen(s);

    int cnt = 0;
    int i = 0;
    while(i < len)
    {
        if(s[i] == 'c' && (i+1) < len && (s[i+1] == '=' || s[i+1] == '-'))
        {
            cnt++;
            i += 2;
        }
        else if(s[i] == 'd'&& (i+2) < len && s[i+1] == 'z' && s[i+2] == '=')
        {
            cnt++;
            i += 3;
        }
        else if(s[i] == 'd' && (i+1) < len && s[i+1] == '-')
        {
                cnt++;
                i += 2;
        }
        else if(s[i] == 'l' && (i+1) < len && s[i+1] == 'j')
        {
            cnt++;
            i += 2;
        }
        else if(s[i] == 'n' && (i+1) < len && s[i+1] == 'j')
        {
            cnt++;
            i += 2;
        }
        else if(s[i] == 's' && (i+1) < len && s[i+1] == '=')
        {
            cnt++;
            i += 2;
        }
        else if(s[i] == 'z' && (i+1) < len && s[i+1] == '=')
        {
            cnt++;
            i += 2;
        }
        else
        {
            cnt++;
            i += 1;
        }
    }

    printf("%d", cnt);

    return 0;
}
