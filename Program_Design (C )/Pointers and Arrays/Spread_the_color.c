#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}


void spread(char *graph, int row, int col) {
    char ch = *(graph + row * N + col), * index;
    //left
    index = graph + row * N + col;
    char * left = index, *right = index, * up = index, *down = index;
    while(right <= graph + (row+1) * N){
        if (*right == ch)
            right += 1;
        else if (*right == 'X'){
            *right = ch;
            right += 1;
        }
        else
            break;
    }
    while (left >= graph + row * N){
        if (*left == ch)
            left -= 1;
        else if (*left == 'X'){
            *left = ch;
            left -= 1;
        }
        else
            break;
    }
    while(up >= graph + col){
        if (*up == ch)
            up -= N;
        else if (*up == 'X'){
            *up = ch;
            up -= N;
        }
        else
            break;
    }
    while(down <= graph + (M -1) * N +col){
        if (*down == ch)
            down += N;
        else if (*down == 'X'){
            *down = ch;
            down += N;
        }
        else
            break;
    }
}