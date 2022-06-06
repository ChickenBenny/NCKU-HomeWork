#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}

void find_fruit(char input[],char fruit[][15]){
// input is the fruit sequence eg: watermelon+_+watermelon+_+coconut+_+grape+_+coconut
// fruit is 20 kinds of fruit name eg: fruit[0] is "guava", fruit[1] is litchi and so on.
// you need to check the Loader code to understand above meaning
    char symbol[] = {"+_+"}, *token;
    int count[20] = {0}, index = 0, max = 0, ans[20] = {0}, loc;
    token = strtok(input, symbol);
    while(token != NULL){
        for (int i = 0;i < 20;i ++){
            if(strcmp(token, fruit[i]) == 0)
                count[i] += 1;
        }
        token = strtok(NULL, symbol);
    }
    for (int i = 0;i < 20;i ++){
        if (count[i] > max){
            max = count[i];
            index = 0;
            ans[index] = i;
            index += 1;
        }
        else if (count[i] == max){
            ans[index] = i;
            index += 1;
        }
    }
    for (int i = 0;i < index;i ++){
        loc = ans[i];
        printf("%s\n", &fruit[loc][0]);
    }
}