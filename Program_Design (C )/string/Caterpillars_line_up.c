#include<stdio.h>
#include<stdbool.h>

void lineup_again(char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}

void swap(char *a, char *b) {
    int i = 0, turn = 1;
    char ch;
    while (turn == 1){
        ch = *(b + i);
        if (ch == '\0'){
            turn = -1;
            continue;
        }
        else {
            *(a + i) = ch;
        }
        i += 1;
    }
}

void reverse_caterpillar(char *l, char *r) {
    int length = r - l + 1;
    char ch_swap[length + 1];
    for (int i = 0;i < length;i ++)
        *(ch_swap + i) = *(r - i);
    ch_swap[length] = '\0';
    swap(l, ch_swap);
}

void lineup_again(char line[]) {
    int index = 0, turn = 1, a_control = -1, z_control = -1;
    char ch;
    while (turn == 1){
        ch = line[index];
        if (ch == '\0'){
            turn = -1;
            continue;
        }
        if (ch == 'A' && a_control == -1 && z_control == -1){
            a_control = index;
        }
        else if (ch == 'A' && a_control == -1 && z_control != -1){
            a_control = index;
            reverse_caterpillar(&line[z_control], &line[a_control]);
            a_control = -1, z_control = -1;
        }
        else if (ch == 'Z' && a_control == -1 && z_control == -1){
            z_control = index;
        }
        else if (ch == 'Z' && a_control != -1 && z_control == -1){
            a_control = -1, z_control = -1;
        }
        index += 1;
    }
}