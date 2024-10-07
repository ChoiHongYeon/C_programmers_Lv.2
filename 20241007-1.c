// 올바른 괄호 (https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {

    bool answer = true;
    int n = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            if (n < 0) {
                answer = false;
                break;
            }
            n++;
        }
        else {
            n--;
        }
    }

    if (n != 0)
        answer = false;

    return answer;

}

void main()
{

    const char* s1 = "()()";
    const char* s2 = "(())()";
    const char* s3 = ")()(";
    const char* s4 = "(()(";

    printf("%d %d %d %d", solution(s1), solution(s2), solution(s3), solution(s4));

}