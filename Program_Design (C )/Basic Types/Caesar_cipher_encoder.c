#include <stdio.h>

int main(void){
    int k;
    char ch, tmp;
    scanf("%d\n", &k);
    if (k > 0)
        k =  k % 26;
    else k = k % 26 +26;
    do {
        scanf("%c", &ch);
        if (ch >= 97 && ch <= 122){
            tmp = (ch - 97) + k;
            if (tmp > 25 ){
                tmp = tmp - 26 ;
                printf("%c", tmp + 97);
            }
            else {
                printf("%c", tmp + 97);
            }
        }
        else if (ch >= 65 && ch <= 90){
            tmp = (ch - 65) + k;
            if (tmp > 25){
                tmp = tmp -26;
                printf("%c", tmp + 65);
            }
            else {
                printf("%c", tmp + 65);
            }
        }
        else {
            printf("%c", ch);
        }

    } while (ch != '\n');
    return 0;
}
