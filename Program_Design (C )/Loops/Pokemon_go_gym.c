#include<stdio.h>

int main () {
    int n, i, j, a, b, win, lose;
    float w = 0. ;
    w = 0;
    scanf("%d", &n);
    for(i = 1 ; i <= n; i ++){
        win =  0;
        lose = 0;
        for (j = 1; j < 4; j++){
            scanf("%d%d", &a, &b);
            if( a > b)
                win += 1;
            else if (a < b)
                lose += 1;
            else continue;
            }
        if (win > lose){
            printf("Win\n");
            w += 1.;
        }
        else if (win < lose)
            printf("Lose\n");
        else printf("Tie\n");
    }
    printf("%.2f%%" , w/ (float)n * 100);
    return 0;
}
