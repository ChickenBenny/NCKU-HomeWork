#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1024

void convert_to_polar(int *coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);
    
    
    convert_to_polar((int *) coords, N);
    
    return 0;
}

#define PI acos(-1)

void convert_to_polar(int *coords, int N){
    int x, y, count = 0;
    double tan_d, val = 180./PI, ret, length, sin_d;
    while (count < N) {
        x = *(coords + 2 * count), y = *(coords + 2 * count + 1);
        length = sqrt(x * x + y * y);
        sin_d = (double) y / length, tan_d = (double) y / (double) x;
        if (sin_d == 0 && x > 0)
            printf("0.00 %.2lf\n", length);
        else if (sin_d == 0 && x < 0)
            printf("180.00 %.2lf\n", length);
        else if (x == 0 && y == 0)
            printf("0.00 0\n");
        else if (sin_d == 1)
            printf("90.00 %.2lf\n", length);
        else if (sin_d == -1)
            printf("270.00 %.2lf\n", length);
        else if (x >= 0 && y >= 0)
            printf("%.2lf %.2lf\n", atan(tan_d) * val, length);
        else if (x <= 0 && y >= 0)
            printf("%.2lf %.2lf\n", 180. + atan(tan_d) * val, length);
        else if (x <= 0 && y <= 0)
            printf("%.2lf %.2lf\n", 180 + atan(tan_d) * val, length);
        else if (x >= 0 && y <= 0)
            printf("%.2lf %.2lf\n", 360 + atan(tan_d) * val, length);
        count += 1;
    }
}