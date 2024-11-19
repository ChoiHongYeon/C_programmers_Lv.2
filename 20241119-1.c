// 롤케이크 자르기 (https://school.programmers.co.kr/learn/courses/30/lessons/132265?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int topping[], size_t topping_len) {

    int brother[10001];
    int cheolsu[10001];
    int kinds_brother = 0;
    int kinds_cheolsu = 0;
    for (int i = 0; i < 10001; i++) {
        brother[i] = 0;
        cheolsu[i] = 0;
    }
    for (int i = 0; i < topping_len; i++) {
        cheolsu[topping[i]]++;
        if (cheolsu[topping[i]] == 1)
            kinds_cheolsu++;
    }

    int answer = 0;
    for (int i = 0; i < topping_len; i++) {
        brother[topping[i]]++;
        if (brother[topping[i]] == 1)
            kinds_brother++;
        cheolsu[topping[i]]--;
        if (cheolsu[topping[i]] == 0)
            kinds_cheolsu--;
        if (kinds_brother == kinds_cheolsu)
            answer++;
    }

    return answer;

}

void main()
{

    int topping1[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    int topping2[] = { 1, 2, 3, 1, 4 };
    size_t topping_len1 = 8;
    size_t topping_len2 = 5;
    printf("%d %d", solution(topping1, topping_len1), solution(topping2, topping_len2));

}