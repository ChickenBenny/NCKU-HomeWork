#include <stdio.h>

__uint128_t down(long long int x);
__uint128_t up(long long int x, long long int y);

int main() {
    long long int a, b, dif, output;
    scanf("%lld%lld", &a, &b);
    dif = a - b;
    if (a == 0 || a== b)
        printf("1");
    else{
    if (dif > b){
        output = up(a, dif)/down(b);
        printf("%lld", output);
    }
    else {
        output = up(a, b)/down(dif);
        printf("%lld", output);
    }
    }
    return 0;
}

__uint128_t up(long long int x, long long int y){
    long long int  i;
    __uint128_t sum = 1;

    for (i = y + 1;i <= x; i++){
        sum *= i;
    }
    return sum;
}
__uint128_t down(long long int x){
    long long int i;
    __uint128_t sum = 1;
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