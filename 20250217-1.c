// k진수에서 소수 개수 구하기 (https://school.programmers.co.kr/learn/courses/30/lessons/92335?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool is_prime(long long n) {

    if (n <= 1)
        return false;
    else if (n == 2 || n == 3)
        return true;

    long long s = (long long)sqrt(n);
    for (long long i = 2; i <= s; i++) {
        if (n % i == 0)
            return false;
    }

    return true;

}

int solution(int n, int k) {

    int q = 1;
    int p = 0;
    while (n >= q) {
        q *= k;
        p++;
    }
    q /= k;
    p--;

    char changed_n[20];
    for (int i = 0; i <= p; i++) {
        changed_n[i] = (n / q) + '0';
        n -= (n / q) * q;
        q /= k;
    }
    changed_n[p + 1] = '\0';

    char numbers[20][20];
    int count = 0;
    int in_count = 0;
    for (int i = 0; i < 20; i++) {
        if (changed_n[i] != '0')
            numbers[count][in_count++] = changed_n[i];
        else if (changed_n[i] == '0' && in_count != 0) {
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
        if (is_prime(atoll((long long)numbers[i])))
            answer++;
    }

    return answer;

}

void main()
{

    printf("%d %d", solution(437674, 3), solution(110011, 10));
    
}