#include <stdio.h>
#include <stdint.h>

int bingo (unsigned char[]);

int main () {
    unsigned char num[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%hhu", &num[i]);
    }

    printf("%d\n", bingo(num));
}

int bingo (unsigned char num[]) {
    int line = 0, index = 0, mode_num, tmp, sum = 0;
    while (index < 8){
        tmp = (int) num[index];
        if (tmp == 255)
            line += 1;
        index += 1;
    }
    index = 0;
    while (index < 8){
        sum = 0;
        for (int i = 0;i < 8; i++){
            tmp = (int) num[i];
            int tmp_p = 0;
            while (tmp_p < index){
                tmp /= 2;
                tmp_p += 1;
            }
            tmp %= 2;
            if (tmp)
                sum += 1;
            else break;
        }
        if (sum == 8)
            line += 1;
        index += 1;
    }
    sum = 0;
    for (int i = 0;i < 8;i ++){
        tmp = (int) num[i];
        tmp = tmp << i;
        tmp = (tmp / 128) % 2;
        if (tmp == 1)
            sum += 1;
    }
    if (sum == 8)
        line += 1;
    sum = 0;
    for (int i = 0;i <8 ;i ++){
        tmp = (int) num[i];
        tmp = tmp >> i;
        tmp %= 2;
        if (tmp == 1)
            sum += 1;
    }
    if (sum == 8)
        line += 1;
    return line;
}