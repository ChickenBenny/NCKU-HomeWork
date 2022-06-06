#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}

int addition(char str[]){
    char plus[2] = "+", *token;
    int sum = 0;
    token = strtok(str, plus);
    while (token != NULL){
        sum += atoi(token);
        token = strtok(NULL, plus);
    }
    return sum;

}