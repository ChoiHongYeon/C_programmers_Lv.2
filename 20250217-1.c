// k진수에서 소수 개수 구하기 (https://school.programmers.co.kr/learn/courses/30/lessons/92335?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int n) {

    if (n < 6) {
        if (n == 2 || n == 3 || n == 5)
            return true;
        else
            return false;
    }
    else {
        if ((n - 1) % 6 == 0 || (n - 5) % 6 == 0)
            return true;
        else
            return false;
    }

}

int solution(int n, int k) {

    char changed_n[20];
    itoa(n, changed_n, k);

    char numbers[20][20];
    int count = 0;
    int in_count = 0;
    for (int i = 0; i < 20; i++) {
        if (changed_n[i] != '0')
            numbers[count][in_count++] = changed_n[i];
        else if (changed_n[i] == '0') {
            numbers[count++][in_count] = '\0';
            in_count = 0;
        }
        else if (changed_n[i] == '\0')
            break;
    }
    if (in_count != 0)
        numbers[count++][in_count] = '\0';

    int answer = 0;
    for (int i = 0; i < count; i++) {
        if (is_prime(atoi(numbers[i])))
            answer++;
    }

    return answer;

}

void main()
{

    printf("%d %d", solution(437674, 3), solution(110011, 10));

}
// 프로그래머스에서 itoa 함수 사용 불가. 직접 구현 요망.
// 6n +- 1 로 소수 판별이 제대로 이루어지지 않을 가능성. ex) 25