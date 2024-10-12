// 피보나치 수 (https://school.programmers.co.kr/learn/courses/30/lessons/12945?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {

    int a = 1;
    int b = 1;
    int bb = 0;

    for (int i = 0; i < n - 1; i++) {
        a = (b + bb) % 1234567;
        bb = b;
        b = a;
    }

    return a;

}

void main()
{

    printf("%d %d", solution(3), solution(5));

}