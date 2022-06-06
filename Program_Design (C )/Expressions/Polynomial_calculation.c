#include <stdio.h>

int main(){
    double a, sum ;
    scanf("%lf", &a);
    sum = 7 * (pow(a, 4)) - 8 * (pow(a, 3)) - pow(a, 2) + (6 * a) - 22;
    printf("%.1lf", sum);
}
