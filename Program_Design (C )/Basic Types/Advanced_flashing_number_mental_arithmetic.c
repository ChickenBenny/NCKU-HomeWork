#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    int s;
    long int a, tmp_sum, tmp;
    tmp_sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &s);
        if (s == 8){
            scanf("%lo", &a);
            tmp_sum += a;
        }
        else if (s == 16){
            scanf("%lx", &a);
            tmp_sum += a;
        }
        else if (s == 10){
            scanf("%ld", &a);
            tmp_sum += a;
        }
        else {
            scanf("%ld", &a);
            int j = 0;
            int b[15];
            while (a > 0){
                b[j] = a % 10;
                a /= 10;
                j += 1;
            }
            for (int k =0; k <= j-1; k ++) {
                tmp_sum += b[k] * (long int)pow((double) 6, (double) k );
            }
            //printf("%lld")

        }


    }
    tmp_sum %= 1000000007;
    printf("%lld", tmp_sum);
    return 0;

}