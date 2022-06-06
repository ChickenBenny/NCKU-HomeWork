#include<stdio.h>

int main () {
    unsigned long int a, b, total;
    scanf("%lx%lx", &a, &b);
    total = a + b;
    if (total < 65536 && total >=0 )
        printf("%lu", total);
    else
        printf("OVERFLOW!");
    return 0;
}
