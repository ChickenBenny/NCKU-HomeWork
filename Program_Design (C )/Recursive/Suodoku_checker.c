#include <stdio.h>
#define NUM 9

void check_sudoku(int grid_p[][NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int grid_p[][NUM]){
    int check[NUM][NUM] = {0};
    for(int i = 0;i < NUM;i ++){
        int check_dif_col[NUM] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, check_dif_row[NUM] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        int tmp_col, tmp_row;
        for (int j = 0;j < NUM;j ++){
            tmp_col = grid_p[i][j];
            if (check_dif_col[tmp_col - 1] == -1)
                check_dif_col[tmp_col - 1] = j;
            else {
                if (check[i][j] == 0)
                    check[i][j] = 1;
                if (check[i][check_dif_col[tmp_col - 1]] == 0)
                    check[i][check_dif_col[tmp_col - 1]] = 1;
            }
            tmp_row = grid_p[j][i];
            if (check_dif_row[tmp_row - 1] == -1)
                check_dif_row[tmp_row - 1] = j;
            else {
                if (check[j][i] == 0)
                    check[j][i] = 1;
                if (check[check_dif_row[tmp_row - 1]][i] == 0)
                    check[check_dif_row[tmp_row - 1]][i]  = 1;
            }
        }
    }
    for (int i = 0;i < 9;i = i + 3){
        for (int j = 0;j < 9;j = j + 3){
            int check_square[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, tmp_square, x, y, count = 0;
            while (count < 9){
                x = count % 3;
                y = count / 3;
                tmp_square = grid_p[i + y][j + x];
                if (check_square[tmp_square - 1] == -1)
                    check_square[tmp_square - 1] = count;
                else {
                    if (check[i + y][j + x] ==0)
                        check[i + y][j + x] = 1;
                    if (check[i + check_square[tmp_square - 1] / 3][j + check_square[tmp_square - 1] % 3] ==0)
                        check[i + check_square[tmp_square - 1] / 3][j + check_square[tmp_square - 1] % 3] = 1;
                }
                count += 1;
            }
        }
    }
    for (int i = 0;i < NUM;i ++){
        for (int j = 0;j < NUM;j ++){
            if (check[i][j] == 1)
                printf("(%d,%d)\n", i, j);
        }
    }
}