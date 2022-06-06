#include <stdio.h>
#include <math.h>


int main() {
    float h, f;
    scanf("%f", &h);
    int t;
    t = (int) sqrt((h * 2/ 9.8)) + 1;
    int i;
    printf("%.1f\n", h);
    for (i = 1; i <= t; i++){
        f = ((1./2.) * 9.8 * i * i) -((1./2.) * 9.8 * (i-1) * (i-1));
        h -= f;
        if (h > 0)
            printf("%.1f\n", h);
        }
    return 0;
}