#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int sequence[], size_t sequence_len, int k) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    int left = 0; int right = 0;
    
    int sum = sequence[0];
    int best_len = sequence_len + 1;
    
    while(left < sequence_len && right < sequence_len)
    {
        if (sum < k)
        {
            right++;
            if(right < sequence_len)
                sum += sequence[right];
        }
        else if (sum > k)
        {
            sum -= sequence[left];
            left++;
        }
        else
        {
            if(right - left + 1 < best_len)
            {
                best_len = right - left + 1;
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left];
            left++;
        }
    }
    return answer;
}
