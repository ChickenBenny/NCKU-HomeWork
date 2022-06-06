#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    for (int i = 1;i < x; i++){
        for (int z = x ;z > i;z--)
            printf(" ");
        for (int j = 1;j < i;j ++)
            printf("OX");
        printf("O\n");
    }
    for (int i = 0;i < (2 * x - 1);i++)
        printf("O");
    return 0 ;
}