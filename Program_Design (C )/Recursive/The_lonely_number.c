#include<stdio.h>

int process(int num[],int check[], int n, int length);

int main () {
    int n ;
    scanf("%d\n", &n);
    int num[n], check[n];
    for (int i = 0;i < n;i ++){
        scanf("%d", &num[i]);
        check[i] = 1;
    }
    if (process(num, check, 0, n)){
        for (int i = 0;i < n;i ++){
            if (check[i] != 0) {
                printf("%d", num[i]);
                break;
            }
        }
    }
}

int process(int num[], int check[], int n, int length){
    if (n == length - 1)
        return 1;
    int num_1, num_2, num_sum;
    for (int i = 0 ;i < length;i ++){
        if (check[i] != 0) {
            num_1 = i;
            for (int j = i + 1; j < length; j++) {
                if (check[j] != 0) {
                    num_2 = j;
                    for (int k = j + 1; k < length; k++) {
                        if (num[k] == num[num_1] + num[num_2] && check[k] != 0) {
                            num_sum = k;
                            check[num_1] = 0, check[num_2] = 0, check[num_sum] = 0, n += 3;
                            if (! process(num, check, n, length)){
                                check[num_1] = 1, check[num_2] = 1, check[num_sum] = 1, n -= 3;
                                return 0;
                            }
                            else return 1;
                        }
                    }
                }
            }
        }
    }
}