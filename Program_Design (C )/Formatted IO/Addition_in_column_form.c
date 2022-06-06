#include <stdio.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("  %.4d\n", a);
    printf("+)%.4d\n", b);
    printf("------\n");
    printf("%.6d", a + b);
}