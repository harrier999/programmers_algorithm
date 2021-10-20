#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int checker[10];
    int i;
    int answer = 0;
    for (i=0;i<10;i++){
        checker[i] = i;
    }
    for (i=0;i<numbers_len;i++){
        checker[numbers[i]] = 0;
    }
    for (i=0;i<10;i++){
        answer+=checker[i];
    }
    return answer;
}