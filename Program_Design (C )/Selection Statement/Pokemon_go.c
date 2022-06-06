#include<stdio.h>

int main () {
    int x, cp, hp, s;
    scanf("%d", &x);
    scanf("%d%d", &cp, &hp);
    scanf("%d", &s);
    if (s > 4){
        printf("NO");
        x = 0;
    }
    else if (s <= 4 && cp < 100) {
        x -= 1;
        if (x > 0) {
            printf("YES\n");
            printf("%d", x);
        }
        else
            printf("NO");
    }
    else if (s <= 4 && cp >= 100 && cp <= 600){
        x -= 5;
        if (hp > 100) {
            x -= 3;
        }
        if (x > 0) {
            printf("YES\n");
            printf("%d", x);
        }
        else
            printf("NO");
    }
    else{
        x -= 15;
        if (hp >200){
            x -= 10;
        }
        if (x > 0) {
            printf("YES\n");
            printf("%d", x);
        }
        else
            printf("NO");

    }
    return 0;
}
