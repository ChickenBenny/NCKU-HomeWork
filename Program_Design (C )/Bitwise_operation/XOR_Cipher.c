#include <stdio.h>

int main () {
    char key[1000] = {0}, key_ch, ch;
    int turn = 1, index = 0, key_len, key_index;
    while (turn == 1){
        scanf("%c", &ch);
        if (ch == '\n'){
            turn = -1;
            continue;
        }
        else {
            key[index] = ch;
            index += 1;
        }
    }
    key_len = index;
    turn = 1, index = 0, key_index = 0;
    while (turn == 1){
        scanf("%c", &ch);
        if (ch == '\n'){
            turn = -1;
            continue;
        }
        else {
            key_ch = key[key_index];
            ch = ch ^ key_ch;
            printf("%c", ch);
            index += 1, key_index += 1;
            if (key_index >= key_len)
                key_index -= key_len;
        }
    }
    return 0;
}