#include<stdio.h>

int row_start;
int row_end;
int column_start;
int column_end;

void rightrotate(int image[][100]);
void leftrotate(int image[][100]);
int main() {
	int image[100][100];
	int row, column;
	scanf("%d %d", &row, &column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			scanf("%d", &image[i][j]);
		}
	}
	row_start = 0;
    row_end = row - 1;
    column_start = 0;
    column_end = column - 1;
    
	int n;
	scanf("%d", &n);
    
	for ( ; n > 0; n--) {
		char option;
		getchar();
		scanf("%c", &option);
		if (option == 'r') {
			getchar();
			char direction;
			int times;
			scanf("%c", &direction);
			getchar();
			scanf("%d", &times);
			if(direction=='r'){
				for ( ; times>0; times--) {
					rightrotate(image);
				}
			} else if(direction=='l'){
				for (;times>0;times--) {
					leftrotate(image);
				}
			}
		} else if (option == 'v') {
			int temp[100][100], i, j;
			for (i = row_start; i <= row_end; i++) {
				for (j = column_start; j <= column_end; j++) {
					temp[row_end - i][j] = image[i][j];
				}
			}
			for (i = row_start; i <= row_end; i++) {
				for (j = column_start; j <= column_end; j++) {
					image[i][j] = temp[i][j];
				}
			}
		} else if (option == 'h') {
			int temp[100][100], i, j;
			for (i = row_start; i <= row_end; i++) {
				for (j = column_start; j <= column_end; j++) {
					temp[i][column_end-j] = image[i][j];
				}
			}
			for (i = row_start; i <= row_end; i++) {
				for (j = column_start; j <= column_end; j++) {
					image[i][j] = temp[i][j];
				}
			}
		} else if (option== 'p') {
			int i, j;
			for (i = 0; i <= row_end; i++) {
				for (j = 0; j <= column_end; j++) {
					printf("%d ", image[i][j]);
				}
				printf("\n");
			}
            printf("\n");
		} else if (option == 'c') {
			int right, left, upper, lower, i, j, m = 0, p = 0;
			int temp[100][100];
			getchar();
			scanf("%d %d %d %d", &left, &right, &upper, &lower);
			for (i = upper - 1, m = 0; i <= lower - 1; i++, m++) {
				for (j = left - 1, p = 0; j <= right - 1; j++, p++) {
					temp[m][p] = image[i][j];
					
				}
			}
			row_end = m - 1;
			column_end = p - 1;
			for (i = 0; i <= row_end; i++) {
				for (j = 0; j <= column_end; j++) {
					image[i][j] = temp[i][j];
				}
			}
		}
	}
	return 0;
}
void rightrotate(int image[][100]) {
	int i, j, temp[100][100];
	for (j = column_start; j <= column_end; j++){
		for (i = row_start; i <= row_end; i++) {
			temp[j][row_end-i] = image[i][j];
		}
	}
    
	int dot;
	dot = row_start;
    row_start = column_start;
    column_start = dot;
    
	dot = row_end;
    row_end = column_end;
    column_end = dot;
    
	for (i = row_start; i <= row_end; i++) {
		for (j = column_start; j <= column_end; j++) {
			image[i][j] = temp[i][j];
		}
	}
}
void leftrotate(int image[][100]) {
	int i, j, temp[100][100];
	for (j = column_end; j >= column_start; j--) {
		for (i = row_start; i <= row_end; i++) {
			temp[column_end-j][i] = image[i][j];
		}
	}
    
	int dot;
	dot = row_start;
    row_start = column_start;
    column_start = dot;
    
	dot = row_end;
    row_end = column_end;
    column_end = dot;
    
	for (i = row_start; i <= row_end; i++) {
		for (j = column_start; j <= column_end; j++) {
			image[i][j] = temp[i][j];
		}
	}
}