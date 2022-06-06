#include <stdio.h>

int f(int x);
int main() {
    int  x;
    scanf("%d", &x);
    printf("%d", f(x));
    return 0;
}

int f(int x){
    if (x == 1)
        return 1;
    else if (( x % 2 )== 0){
        return f(x / 2);
    }
    else
        return f(x - 1) + f((x + 1)/ 2);
}