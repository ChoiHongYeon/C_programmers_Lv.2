// N개의 최소공배수 (https://school.programmers.co.kr/learn/courses/30/lessons/12953?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len) {

    long long answer = (long long)arr[0];
    for (int i = 1; i < arr_len; i++) {
        long long LCM = 0;
        long long max = answer > (long long)arr[i] ? answer : arr[i];
        long long min = answer > (long long)arr[i] ? arr[i] : answer;
        for (long long j = min;j > 0;j--) {
            if (max % j == 0 && min % j == 0) {
                LCM = j;
                break;
            }
        }
        answer = answer * arr[i] / LCM;
    }

    return (int)answer;
}

void main()
{

    int arr1[] = { 2, 6, 8, 14 };
    int arr2[] = { 1, 2, 3 };
    size_t arr1_len = 4;
    size_t arr2_len = 3;
    printf("%d %d", solution(arr1, arr1_len), solution(arr2, arr2_len));

}