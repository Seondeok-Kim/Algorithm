#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char s[20];
    sprintf(s, "%lld", n); // 문자열 12345
    
    int len = (int)strlen(s); // 문자열 s 길이
    int* answer = (int*)malloc(len * sizeof(int));
    
    for(int i = 0 ; i < len ; ++i)
    {
        answer[i] = s[len-1-i] - '0';
    }
    
    return answer;
}




#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    long long a = n;
    int cnt = 0;
    
    while(a > 0)
    {
        a = a / 10;
        cnt++;
    }
    
    int* answer = (int*)malloc(sizeof(int) * cnt);
    for(int i = 0 ; i < cnt ; ++i)
    {
        answer[i] = (n % 10) ;
        n = n/10;
    }
    
    return answer;
}
