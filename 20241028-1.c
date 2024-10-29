// 귤 고르기 (https://school.programmers.co.kr/learn/courses/30/lessons/138476?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int k, int tangerine[], size_t tangerine_len) {

    int* numbers = (int*)calloc(10000001, sizeof(int));
    for (int i = 0; i < tangerine_len; i++) {
        numbers[tangerine[i]]++;
    }

    int* number = (int*)malloc(sizeof(int) * 100000);
    int n = 0;
    for (int i = 0; i < 10000001;i++) {
        if (numbers[i] > 0)
            number[n++] = numbers[i];
    }
    free(numbers);

    qsort(number, n, sizeof(int), compare);

    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
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