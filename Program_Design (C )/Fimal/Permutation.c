#include <stdio.h>
#include <stdlib.h>

void perm (char string[], int start, int end);
void swap_front (char string[], int a, int b);
void swap_back (char string[], int a, int b);

int main(void){
    char string[7] = {0}, ch;
    int index = 0, turn = 1;
    while(turn == 1){
        scanf("%c", &ch);
        if (ch == '\n'){
            turn = -1;
            continue;
        }
        else{
            string[index] = ch;
            index += 1;
        }
    }
    int loc, min = 100;
    for (int i = 0;i < index;i ++){
        loc = i;
        min = (int) string[i];
        for (int j = i + 1;j < index;j ++){
            if (min > (int) string[j]){
                loc = j;
                min = (int) string[j];
            }
        }
        if(loc != i) {
            string[loc] = string[i];
            string[i] = (char) min;
        }
    }
    string[index] = '\0';
    perm(string, 0, index - 1);
    return 0;
}

void perm(char string[], int start, int end){
    if (start == end){
        printf("%s\n", string);
    }
    else{
        for (int i = start;i <= end;i ++){
            swap_front(string, start, i);
            perm(string, start + 1, end);
            swap_back(string, i, start);
        }
    }
}

void swap_front(char string[], int a, int b) {
    char tmp;
    if (a == b)
        return;
    tmp = string[b];
    for(int i = b;i > a ;i --)
        string[i] = string[i - 1];
    string[a] = tmp;
}

void swap_back(char string[], int a, int b) {
    char tmp;
    if (a == b) return;
    tmp = string[b];
    for (int i = b ;i <= a ;i++)
        string[i] = string[i + 1];
    string[a] = tmp;
}