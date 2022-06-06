#include <stdio.h>

long int down(long int x);
long int up(long int x, long int y);

int main() {
    long int a, b, dif, output;
    scanf("%ld%ld", &a, &b);
    dif = a - b;
    if (dif > b){
        output = up(a, dif)/down(b);
        printf("%ld", output);
    }
    else {
        output = up(a, b)/down(dif);
        printf("%ld", output);
    }

    return 0;
}

long int up(long int x, long int y){
    long int sum, i;
    sum = 1;

    for (i = y + 1;i <= x; i++){
        sum *= i;
    }
    return sum;
}
long int down(long int x){
    long int i, sum;
    if (x == 1)
        return 1;
    else {
        sum = 1;
        for (i = 1; i <= x;i ++){
            sum *= i;
        }
        return sum;
    }
}