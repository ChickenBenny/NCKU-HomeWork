#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    if (a < 10)
        printf("0 0 %d", a);
    else if (a >= 10 && a < 100){
        printf("0 ");
        printf("%d ", a/10);
        printf("%d", a%10);
    }
    else {
        printf("%d ", a/100);
        printf("%d ", a%100/10);
        printf("%d", a%10);
    }
    return 0 ;
}
