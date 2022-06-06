#include <stdio.h>
#define SIZE 201

void modify_array(int *);

int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE/2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void modify_array(int *p) {
    int a = *(p - (SIZE/ 2)), *location = p - (SIZE/2) + 1;
    if (a == 1){
        for (int i = 0;i < SIZE - 1;i ++){
            if (i  % 2 == 0)
                *(location + i) += 10;
        }
    }
    else if (a == 2){
        for (int i = 0;i < SIZE - 1;i ++){
            if (i % 3 == 0)
                *(location + i) *= 8;
        }
    }
    else {
        for (int i = 0;i < SIZE - 1;i ++){
            if (i % 5 == 0)
                *(location + i) -= 2;
        }
    }
    return;
}