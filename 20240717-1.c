// 마법의 엘리베이터 (https://school.programmers.co.kr/learn/courses/30/lessons/148653?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int storey) {

    int answer = 0;
    int n = 1;

    while (storey > 0) {
        int i = (storey % (n * 10)) / n;
        if (i > 5) {
            storey += (10 - i) * n;
            answer += 10 - i;
        }
        else if (i == 5) {
            int j = ((storey - 5 * n) % (n * 100)) / (n * 10);
            if (j < 5) {
                storey -= i * n;
                answer += i;
            }
            else {
                storey += (10 - i) * n;
                answer += 10 - i;
            }
        }
        else if (i > 0) {
            storey -= i * n;
            answer += i;
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