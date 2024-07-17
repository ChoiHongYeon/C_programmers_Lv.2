// 마법의 엘리베이터 (https://school.programmers.co.kr/learn/courses/30/lessons/148653?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int storey) {

    int answer = 0;
    int n = 1;

    while (storey > 0) {
        int i = (storey % (n * 10)) / n;
        switch (i) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            storey -= i * n;
            answer += i;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            storey += 10 - i * n;
            answer += 10 - i;
            break;
        }
        n *= 10;
    }

    return answer;

}

void main()
{
    
    int result1 = solution(16);
    int result2 = solution(2554);
    printf("%d %d", result1, result2);

}