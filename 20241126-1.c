// 방문 길이 (https://school.programmers.co.kr/learn/courses/30/lessons/49994?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* dirs) {

    char UDRL[] = { 'U', 'D', 'R', 'L' };
    int X[] = { 0, 0, 1, -1 };
    int Y[] = { 1, -1, 0, 0 };

    int visited_x[501];
    int visited_y[501];
    visited_x[0] = 0;
    visited_y[0] = 0;

    int answer = 0;
    int n = 1;

    for (int i = 0; i < strlen(dirs); i++) {

        bool moved = false;
        for (int j = 0; j < 4; j++) {
            if (dirs[i] == UDRL[j]) {
                if (visited_x[n - 1] + X[j] >= -5 && visited_x[n - 1] + X[j] <= 5 && visited_y[n - 1] + Y[j] >= -5 && visited_y[n - 1] + Y[j] <= 5) {
                    moved = true;
                    visited_x[n] = visited_x[n - 1] + X[j];
                    visited_y[n] = visited_y[n - 1] + Y[j];
                }
            }
        }

        if (moved) {
            answer++;
            for (int j = 0; j < n; j++) {
                if (visited_x[n] == visited_x[j] && visited_y[n] == visited_y[j]) {
                    if (j - 1 >= 0 && visited_x[n - 1] == visited_x[j - 1] && visited_y[n - 1] == visited_y[j - 1]) {
                        answer--;
                        break;
                    }
                    else if (j + 1 < n && visited_x[n - 1] == visited_x[j + 1] && visited_y[n - 1] == visited_y[j + 1]) {
                        answer--;
                        break;
                    }
                }
            }
            n++;
        }

    }
    
    return answer;

}

void main()
{

    const char* dirs1 = "ULURRDLLU";
    const char* dirs2 = "LULLLLLLU";
    printf("%d %d", solution(dirs1), solution(dirs2));

}