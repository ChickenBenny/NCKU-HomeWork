#include<stdio.h>

void addition();

void print_binary(void *n){
    for(int i = 31; i >= 0; --i){
        printf("%d", (*(int *)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main(){
    addition();
    return 0;
}

void addition(){
    long int a, b, index = 8, a_float[32] = {0}, b_float[32] = {0}, c_float[32] = {0}, tmp[23] = {0}, sum = 0;
    scanf("%ld %ld", &a, &b);
    if (a >= 0) a_float[0] = 0;
    else {
        a_float[0] = 1;
        a = - a;
    }
    if (b >= 0) b_float[0] = 0;
    else {
        b_float[0] = 1;
        b = -b;
    }
    int count = 0, count_a = a, count_b = b;
    while (count_a > 0){
        count_a /= 2, count += 1;
    }
    count_a = 127 + count - 1;
    while (index > 0) {
        a_float[index] = count_a % 2;
        count_a /= 2;
        index -= 1;
    }
    index = 0, count_a = a;
    while (count_a > 0){
        tmp[index] = count_a % 2;
        count_a /= 2;
        index += 1;
    }
    index -= 2, count = 9;
    while (index >= 0){
        a_float[count] = tmp[index];
        index -= 1, count += 1;
    }
    count = 0;
    while (count_b > 0){
        count_b /= 2, count += 1;
    }
    count_b = 127 + count - 1, index = 8;
    while (index > 0) {
        b_float[index] = count_b % 2;
        count_b /= 2;
        index -= 1;
    }
    index = 0, count_b = b;
    while (count_b > 0){
        tmp[index] = count_b % 2;
        count_b /= 2;
        index += 1;
    }
    index -= 2, count = 9;
    while (index >= 0){
        b_float[count] = tmp[index];
        index  -= 1, count += 1;
    }
    index = 31, count = 0;
    while (index >= 0){
        if (a_float[index] + b_float[index] + count == 3){
            c_float[index] = 1;
            count = 1;
            index -= 1;
        }
        else if (a_float[index] + b_float[index] + count == 2){
            c_float[index] = 0;
            count = 1;
            index -= 1;
        }
        else if (a_float[index] + b_float[index] + count == 1){
            c_float[index] = 1;
            count = 0;
            index -= 1;
        }
        else {
            index -= 1;
            continue;
        }
    }
    int i;
    count = 0;
    while (count < 32){
        i = c_float[count];
        if (i == 1) {
            for (int j = 0; j < 31 - count; j++)
                i *= 2;
            sum += i;
        }
        count += 1;
    }
    i = 0;
    printf("  ");
    while(i < 32){
        if (i % 8 == 0)
            printf(" %ld", a_float[i]);
        else
            printf("%ld", a_float[i]);
        i += 1;
    }
    printf("\n+)");
    i = 0;
    while(i < 32){
        if (i % 8 == 0)
            printf(" %ld", b_float[i]);
        else
            printf("%ld", b_float[i]);
        i += 1;
    }
    printf("\n---------------------------------------\n  ");
    i = 0;
    while(i < 32){
        if (i % 8 == 0)
            printf(" %ld", c_float[i]);
        else
            printf("%ld", c_float[i]);
        i += 1;
    }
    if (a_float[0] == 1) a = -a;
    if (b_float[0] == 1) b = -b;
    printf("\n%ld + %ld = %ld", a, b, sum);
}