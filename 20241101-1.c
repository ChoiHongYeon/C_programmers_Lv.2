// 연속 부분 수열 합의 개수 (https://school.programmers.co.kr/learn/courses/30/lessons/131701?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int elements[], size_t elements_len) {

    int* numbers = (int*)calloc(1000001, sizeof(int));
    int sum = 0;
    for (int i = 0; i < elements_len; i++) {
        sum += elements[i];
    }
    numbers[sum]++;

    int* nums = (int*)malloc(sizeof(int) * elements_len);
    for (int i = 0; i < elements_len; i++) {
        nums[i] = sum;
    }

    for (int i = 0; i < elements_len - 1; i++) {
        int n = i;
        for (int j = 0; j < elements_len; j++) {
            nums[j] -= elements[n];
            n++;
            if (n == elements_len)
                n = 0;
        }
        for (int j = 0; j < elements_len; j++) {
            numbers[nums[j]]++;
        }
    }
    free(nums);
    
    int answer = 0;
    for (int i = 0; i < 1000001; i++) {
        if (numbers[i] > 0)
            answer++;
    }
    free(numbers);

    return answer;

}

void main()
{

    int elements[] = { 7, 9, 1, 1, 4 };
    size_t elements_len = 5;
    printf("%d", solution(elements, elements_len));

}