#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int bin_to_dec(const char* bin)
{
    int value = 0;
    for(int i = 0 ; bin[i] != '\0' ; ++i)
    {
        value = value * 2 + (bin[i] - '0');
    }
    return value;
}


int main()
{
    char input[100];
    scanf("%s", input);

    char* answer = (char*)malloc(36);

    char* token = strtok(input, ".");
    int first = 1; // 토큰 출력중인지 1: 토큰 출력 중 0: 토큰 출력 아님, .

    while(token != NULL)
    {
        int num = bin_to_dec(token); // 10진수로 변환된 수

        char buf[20]; // 10진수를 변환할 문자열
        sprintf(buf, "%d", num); // 10진수 -> 문자열로 변환

        if(first == 0)
        {
            strcat(answer, ".");
        }
        strcat(answer, buf);

        first = 0 ; 
        token = strtok(NULL, "."); // 다음 토큰을 가져와서 token에 넣는다
    }
    printf("%s\n", answer); // 토큰 처리가 끝났다
    free(answer);

    return 0;
}
