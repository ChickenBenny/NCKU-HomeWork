#include<stdio.h>
#include<math.h>

typedef struct {
    int sign;
    int exp[8];
    int frac[23];
} float_num;

int convert_float(float x);

int main () {
    int n;
    float num;
    scanf("%d\n", &n);
    for (int i = 0; i < n;i ++){
        scanf("%f", &num);
        if (convert_float(num) == 1)
            printf("Back\n");
        else
            printf("Front\n");
    }
    return 0;
}

int convert_float(float x){
    int count = 0, int_part = (int) x, index, exp, tmp_dec[24] = {0};
    float float_part = x - (float) int_part;
    float_num tmp;
    while (int_part > 0){
        tmp_dec[count] = int_part % 2;
        int_part /= 2;
        count += 1;
    }
    exp = count - 1 + 127;
    count -= 2;
    if (x >= 0)
        tmp.sign = 0;
    else
        tmp.sign = 1;
    index = 7;
    while (index >= 0) {
        tmp.exp[index] = exp % 2;
        exp /= 2;
        index -= 1;
    }
    index = 0;
    while (index < 23){
        if (count >= 0) {
            tmp.frac[index] = tmp_dec[count];
            count -= 1;
        }
        else {
            float_part *= 2;
            if (float_part >= 1) {
                tmp.frac[index] = 1;
                float_part -= 1.;
            }
            else
                tmp.frac[index] = 0;
        }
        index += 1;
    }
    int sum = 0;
    for (int i = 0;i < 8;i ++){
        sum += (int)((double) tmp.frac[22 - i] * (pow(2., i))) ;
    }
    for (int i = 0;i < 8;i ++){
        sum += (int)((double) tmp.frac[14 - i] * (pow(2, i))) ;
    }
    for (int i = 0;i < 7;i ++){
        sum += (int)((double) tmp.frac[6 - i] * (pow(2, i))) ;
    }
    sum += (int)((double)tmp.exp[7] * (pow(2, 7)));
    sum += (int)((double)tmp.sign * (pow(2, 7)));
    for (int i = 0;i < 7;i ++){
        sum += (int)((double) tmp.exp[6 - i] * (pow(2, i))) ;
    }
    sum %= 2;
    return sum;
}
