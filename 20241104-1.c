// 피로도 (https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=c)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max_count = 0;

void dfs(int k, int** dungeons, size_t dungeons_rows, int count, int* visited) {

    if (count > max_count)
        max_count = count;

    for (int i = 0; i < dungeons_rows; i++) {
        if (visited[i] == 0 && k >= dungeons[i][0]) {
            visited[i] = 1;
            dfs(k - dungeons[i][1], dungeons, dungeons_rows, count + 1, visited);
            visited[i] = 0;
        }
    }

}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {

    int* visited = (int*)calloc(dungeons_rows, sizeof(int));
    max_count = 0;
    dfs(k, dungeons, dungeons_rows, 0, visited);
    free(visited);

    return max_count;

}

void main()
{

    int k = 80;
    size_t dungeons_rows = 3;
    size_t dungeons_cols = 2;

    int** dungeons = (int**)malloc(dungeons_rows * sizeof(int*));
    for (size_t i = 0; i < dungeons_rows; i++) {
        dungeons[i] = (int*)malloc(dungeons_cols * sizeof(int));
    }

    dungeons[0][0] = 80;
    dungeons[0][1] = 20;
    dungeons[1][0] = 50;
    dungeons[1][1] = 40;
    dungeons[2][0] = 30;
    dungeons[2][1] = 10;

    printf("%d\n", solution(k, dungeons, dungeons_rows, dungeons_cols));

    for (size_t i = 0; i < dungeons_rows; i++) {
        free(dungeons[i]);
    }
    free(dungeons);

}