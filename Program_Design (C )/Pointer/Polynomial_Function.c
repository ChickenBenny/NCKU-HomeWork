#include<stdio.h>

int *poly(int*, int*, int*);

int main() {
    int a, b, c;
    int *A, *B, *C;
    scanf("%d %d %d", &a, &b, &c);
    A = &a;
    B = &b;
    C = &c;
    if (a < 0) A = NULL;
    if (b < 0) B = NULL;
    if (c < 0) C = NULL;

    int *result = poly(A, B, C);
    printf("%d", *result);
    return 0;
}

int function_answer = 0, *output = &function_answer;

int* poly(int* A, int* B, int* C) {
    if (A != NULL)
        *output += *A * *A * *A;
    if (B != NULL)
        *output += *B * *B ;
    if (C != NULL)
        *output += *C;
    return output;
}