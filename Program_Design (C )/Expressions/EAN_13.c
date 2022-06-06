#include <stdio.h>
#include <stdlib.h>

int main(){
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, sum_weight;
    scanf("%1d %1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
    sum_weight = (d1 + d3 + d5 + d7 + d9 + d11) + 3 * (d2 + d4 + d6 + d8 + d10 +d12);
    while(sum_weight >10){
        sum_weight %= 10;
    }
    if ( sum_weight > 5)
        printf("%d", (10 - sum_weight));
    else if (sum_weight == 5)
        printf("5");
    else printf("%d", sum_weight);
    return 0 ;
}
