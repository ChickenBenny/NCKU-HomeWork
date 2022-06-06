#include <stdio.h>


int main () {
    char ch, process, str[1025] = {0}, act[9];
    int turn = -1, count = 0, active;
    while (turn == -1){
        scanf("%c", &ch);
        if (ch != '\n') {
            str[count] = ch;
            count += 1;
        }
        else
            turn = 0;
    }
    scanf("%d\n", &active);
    for (int i = 0;i < active;i ++){
        turn = -1;
        int act_count = 0;
        while (turn == -1){
            scanf("%c", &ch);
            if (ch != '\n') {
                act[act_count] = ch;
                act_count += 1;
            }
            else
                turn = 0;
        }
        if (act[0] == 'P'){
            for (int j = 0;j < count;j ++)
                printf("%c", str[j]);
            printf("\n");
        }
        else if (act[0] == 'R'){
            if (act[2] == 'V'){
                char tmp[1025] = {0};
                for (int i = 0;i < count; i ++){
                    tmp[i] = str[count - 1 - i];
                }
                for (int i = 0; i < count; i ++){
                    str[i] = tmp[i];
                    printf("%c", str[i]);
                }
                printf("\n");
            }
            else if (act[2] == 'M'){
                int index = 0, remove_index = 0;
                process = act[7];
                while (index < count){
                    if (str[index] != process){
                        str[remove_index] = str[index];
                        printf("%c", str[remove_index]);
                        index += 1, remove_index += 1;
                    }
                    else if (str[index] == process){
                        index += 1;
                    }
                }
                count = remove_index;
                printf("\n");
            }
        }
        else if (act[0] == 'C'){
            int index = 0 , tmp_index = 0, repeat = 0;
            char  tmp[1025] = {0};
            while (index < count) {
                if (str[index] != 0) {
                    tmp[tmp_index] = '-', tmp_index += 1;
                    process = str[index], str[index] = 0;
                    repeat += 1;
                    for (int j = index + 1;j <count;j ++) {
                        if (str[j] != 0 && str[j] == process)
                            repeat += 1, str[j] = 0;
                        else {
                            index = j - 1;
                            break;
                        }
                    }
                    tmp[tmp_index] = process, tmp_index += 1;
                    tmp[tmp_index] = (char) repeat + '0', tmp_index += 1, repeat = 0;
                }
                index += 1;
            }
            for (int j = 0;j < tmp_index;j ++){
                str[j] = tmp[j];
                printf("%c", str[j]);
            }
            count = tmp_index;
            printf("\n");
        }
        else {
            if (act[3] == 'L'){
                for (int j = 0;j < count;j ++){
                    process = str[j];
                    if (process >= 'A' && process <= 'Z')
                        str[j] = process - 'A' + 'a';
                    printf("%c", str[j]);
                }
            }
            else if (act[3] == 'U') {
                for (int j = 0;j < count;j ++){
                    process = str[j];
                    if (process >= 'a' && process <= 'z')
                        str[j] = process - 'a' + 'A';
                    printf("%c", str[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
