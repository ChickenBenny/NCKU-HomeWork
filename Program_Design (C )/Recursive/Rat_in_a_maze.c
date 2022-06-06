#include <stdio.h>
#include <stdbool.h>
#define n 5

bool visit(char [][n], int [][n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    // initialize maze and route matrices
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
	        route[i][j]=0;
	        scanf("%c", &maze[i][j]);
	        getchar();
	    }
    }
    if (visit(maze, route, 0, 0)) { // (0,0) is a starting point
        for (int i=0; i<n; i++) {
	        for (int j=0; j<n; j++)
	            printf("%d ", route[i][j]);
	        printf("\n");
        }
    } else {
	    printf("Can't find the exit!");
    }
    return 0;
}
bool visit(char maze[][n], int route[][n], int originY, int originX) {
    if (originY >= 0 && originX >= 0) {
        if (maze[originY][originX] == 'r')
            route[originY][originX] = 1;
        if (originY == 4 && originX == 4)
            return true;

        if (route[originY + 1][originX] == 0 && maze[originY + 1][originX] == 'r') {
            if (!visit(maze, route, originY + 1, originX))
                route[originY + 1][originX] = 0;
            else
                return true;
        }
        if (route[originY][originX + 1] == 0 && maze[originY][originX + 1] == 'r') {
            if (!visit(maze, route, originY, originX + 1))
                route[originY][originX + 1] = 0;
            else
                return true;
        }
        if (route[originY - 1][originX] == 0 && maze[originY - 1][originX] == 'r') {
            if (!visit(maze, route, originY - 1, originX))
                route[originY - 1][originX] = 0;
            else
                return true;
        }
        if (route[originY][originX - 1] == 0 && maze[originY][originX - 1] == 'r') {
            if (!visit(maze, route, originY, originX - 1))
                route[originY][originX - 1] = 0;
            else
                return true;
        }
    }
    return false;
}
