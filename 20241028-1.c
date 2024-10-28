// 귤 고르기 (https://school.programmers.co.kr/learn/courses/30/lessons/138476?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int k, int tangerine[], size_t tangerine_len) {

    int answer = 0;

    for (size_t i = tangerine_len - 1; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            if (tangerine[j] > tangerine[j + 1]) {
                int temp = tangerine[j];
                tangerine[j] = tangerine[j + 1];
                tangerine[j + 1] = temp;
            }
        }
    }

    int* number = (int*)malloc(sizeof(int) * tangerine_len);
    int n = 1;
    int t = 0;
    for (size_t i = 1; i < tangerine_len; i++) {
        if (tangerine[i] == tangerine[i - 1])
            n++;
        else {
            number[t++] = n;
            n = 1;
        }
    }
    number[t++] = n;

    number = (int*)realloc(number, sizeof(int) * t);
    for (int i = t - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (number[j] > number[j + 1]) {
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }

    for (int i = t - 1; i >= 0; i--) {
        k -= number[i];
        answer++;
        if (k <= 0)
            break;
    }

    free(number);

    return answer;

}

void main()
{

    int tangerine1[] = { 1, 3, 2, 5, 4, 5, 2, 3 };
    int tangerine2[] = { 1, 3, 2, 5, 4, 5, 2, 3 };
    int tangerine3[] = { 1, 1, 1, 1, 2, 2, 2, 3 };
    size_t tangerine_len1 = 8;
    size_t tangerine_len2 = 8;
    size_t tangerine_len3 = 8;
    printf("%d\n", solution(6, tangerine1, tangerine_len1));
    printf("%d\n", solution(4, tangerine2, tangerine_len2));
    printf("%d\n", solution(2, tangerine3, tangerine_len3));

}