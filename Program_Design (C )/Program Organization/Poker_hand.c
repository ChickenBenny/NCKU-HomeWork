#include <stdio.h>

void read_card(int num[], char ch[]);
void parse_card(int num[], char ch[], int compare[]);
void compare_card(int a[], int b[], int c[], int d[]);

int main(void){
    int a_num[5] = {0}, b_num[5] = {0}, c_num[5] = {0}, d_num[5] = {0};
    char a_char[5] = {0}, b_char[5] = {0}, c_char[5] = {0}, d_char[5] = {0};
    int a_compare[3] = {0}, b_compare[3] = {0}, c_compare[3] = {0}, d_compare[3] = {0};
    read_card(a_num, a_char);
    read_card(b_num, b_char);
    read_card(c_num, c_char);
    read_card(d_num, d_char);
    parse_card(a_num, a_char, a_compare);
    parse_card(b_num, b_char, b_compare);
    parse_card(c_num, c_char, c_compare);
    parse_card(d_num, d_char, d_compare);
    compare_card(a_compare, b_compare, c_compare, d_compare);
    return 0;
}

void read_card(int num[], char ch[]){
    char tmp_num, tmp_char, blank;
    for (int i = 0;i < 5;i ++){
        scanf("%c%c%c", &tmp_num, &tmp_char, &blank);
        if (tmp_num == 't')
            num[i] = 10;
        else if (tmp_num == 'j')
            num[i] = 11;
        else if (tmp_num == 'q')
            num[i] = 12;
        else if (tmp_num == 'k')
            num[i] = 13;
        else if (tmp_num == 'a')
            num[i] = 14;
        else
            num[i] = (tmp_num - '0');
        ch[i] = tmp_char;
        if (blank == '\n')
            break;
    }
}

void parse_card(int num[], char ch[], int compare[]){
    int number[15] = {0}, suit[4] = {0}, tmp, index;
    char tmp_c;
    for (int i = 0;i < 5;i ++){
        tmp = num[i];
        tmp_c = ch[i];
        number[tmp] += 1;
        if (tmp_c == 'c')
            suit[0] += 1;
        else if (tmp_c == 'd')
            suit[1] += 1;
        else if (tmp_c == 'h')
            suit[2] += 1;
        else
            suit[3] += 1;
    }

    for (int i = 0;i < 5;i ++){
        if (suit[i] == 5){
            index = 2;
            while (index < 11){
                if (number[index] != 0){
                    int count = 0;
                    for (int j = 1;j < 5;j ++){
                        if (number[index + j] != 0)
                            count += 1;
                    }
                    if (count == 4){
                        compare[0] = 9;
                        compare[1] = index + 4;
                        compare[2] = i;
                        break;
                    }
                }
                index += 1;
            }
            if (compare[0]== 0) {
                compare[0] = 6;
                int max = 0;
                for (int j = 0; j < 15; j++) {
                    if (number[j] != 0 && j > max)
                        max = j;
                }
                compare[1] = max;
                compare[2] = i;
                break;
            }
        }
    }

    if (compare[0] != 0)
        return;

    index = 2;
    while (index < 11){
        if (number[index] != 0){
            int count = 0;
            for (int j = 1;j < 5;j ++){
                if (number[index + j] != 0)
                    count += 1;
            }
            if (count == 4){
                compare[0] = 5;
                compare[1] = index + 4;
                for (int i = 0;i < 5;i ++){
                    if(num[i] == index + 4)
                        if (ch[i] == 'c')
                            compare[2] = 1;
                        else if (ch[i] == 'd')
                            compare[2] = 2;
                        else if (ch[i] == 'h')
                            compare[2] = 3;
                        else
                            compare[2] = 4;
                }
                break;
            }
            else
                break;
        }
        index += 1;
    }

    if (compare[0] != 0)
        return;

    for (int i = 2;i < 15;i ++){
        if (number[i] == 4){
            compare[0] = 8;
            compare[1] = i;
            break;
        }
        else if (number[i] == 3){
            for (int j  = 2;j < 15;j ++){
                if (number[j] == 2){
                    compare[0] = 7;
                    compare[1] = i;
                    compare[2] = 0;
                    break;
                }
            }
            if (compare[0] == 0){
                compare[0] = 4;
                compare[1] = i;
                compare[2] = 0;
                break;
            }
        }
        else if (number[i] == 2){
            for (int j = i +1;j < 15;j ++){
                if (number[j] == 3){
                    compare[0] = 7;
                    compare[1] = j;
                    compare[2] = 0;
                    break;
                }
                else if (num[j] == 2){

                    compare[0] = 3;
                    compare[1] = j;
                    for (int k = 0;k < 5;k ++){
                        if (num[k] == j)
                            compare[2] = ch[j];
                    }
                    break;
                }
            }
            if (compare[0] == 0) {
                compare[0] = 2;
                compare[1] = i;
                for (int j = 0;j < 5;j ++){
                    if (num[j] == i)
                        compare[2] = ch[j];
                }
            }
        }
    }
    if(compare[0] != 0)
        return;
    else {
        compare[0] = 1;
        int max = 0;
        for (int i = 2;i < 15;i ++){
            if (number[i] != 0 && i >max)
                max = i;
        }
        compare[1] = max;
        max = 0;
        for (int i = 0;i < 4;i ++){
            if (ch[i] != 0 && i > max)
                max = i;
        }
        compare[2] = max;
        return;
    }
}

void compare_card(int a[], int b[], int c[], int d[]){
    int compare[4][4];
    compare[0][0] = 1;
    compare[1][0] = 2;
    compare[2][0] = 3;
    compare[3][0] = 4;
    for (int i = 1;i < 4;i ++){
        compare[0][i] = a[i - 1];
        compare[1][i] = b[i - 1];
        compare[2][i] = c[i - 1];
        compare[3][i] = d[i - 1];
    }
    int tmp, swap_target[4] = {0}, count = 0;
    for (int i = 0;i < 3;i ++){
        tmp = compare[i][1];
        for (int j = i + 1;j < 4;j ++){
            if (compare[j][1] > tmp){
                tmp = compare[j][1];
                for (int k = 0;k < 4;k ++){
                    swap_target[k] = compare[i][k];
                    compare[i][k] = compare[j][k];
                    compare[j][k] = swap_target[k];
                }
            }
        }
    }
    for (int i = 0;i < 3;i ++){
        if (compare[i][1] == compare[i + 1][1]){
            if (compare[i][2] < compare[i + 1][2]) {
                for (int j = 0;j < 4;j ++) {
                    swap_target[j] = compare[i][j];
                    compare[i][j] = compare[i + 1][j];
                    compare[i + 1][j] = swap_target[j];
                }
                break;
            }
            else if (compare[i][2] == compare[i + 1][2]){
                if(compare[i][3] < compare[i + 1][3]){
                    for (int j = 0;j < 4;j ++) {
                        swap_target[j] = compare[i][j];
                        compare[i][j] = compare[i + 1][j];
                        compare[i + 1][j] = swap_target[j];
                    }
                    break;
                }
            }
        }
    }
    while (count < 4){
        if(compare[count][0] == 1)
            printf("A ");
        else if (compare[count][0] == 2)
            printf("B ");
        else if (compare[count][0] == 3)
            printf("C ");
        else
            printf("D ");
        count += 1;
    }
}