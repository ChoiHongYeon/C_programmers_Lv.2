// 이진 변환 반복하기 (https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s) {

    int* answer = (int*)malloc(sizeof(int) * 2);

    if (strlen(s) == 1) {
        answer[0] = 0;
        answer[1] = 0;
        return answer;
    }

    int A = 0;
    int B = 0;

    int count_1 = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1')
            count_1++;
    }
    A++;
    B += (strlen(s) - count_1);

    while (count_1 != 1) {

        int n = 1;
        int o = 1;
        while (true) {
            if (count_1 >= n) {
                n *= 2;
                o++;
            }
            else {
                n /= 2;
                o--;
                break;
            }
        }

        int m = 0;
        while (count_1 > 0) {
            if (count_1 - n >= 0) {
                count_1 -= n;
                m++;
            }
            n /= 2;
        }

        A++;
        B += (o - m);
        count_1 = m;
        
    }

    answer[0] = A;
    answer[1] = B;

    return answer;
}

void main()
{

    const char* s1 = "110010101001";
    const char* s2 = "01110";
    const char* s3 = "1111111";

    int* answer1 = solution(s1);
    int* answer2 = solution(s2);
    int* answer3 = solution(s3);

    printf("%d %d\n", answer1[0], answer1[1]);
    printf("%d %d\n", answer2[0], answer2[1]);
    printf("%d %d\n", answer3[0], answer3[1]);

}