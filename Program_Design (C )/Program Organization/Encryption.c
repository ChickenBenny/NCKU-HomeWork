#include<stdio.h>

int main () {
    int a, count = 0, front = 0, back = 32;
    char ch, code[64] = {0}, output[64] = {0}, process, tmp;
    scanf("%d\n", &a);
    while (count <64){
        scanf("%c", &code[count]);
        count += 1;
    }
    if (a == 1){
        char code_num[4] = {'m' - 'a', 'e' - 'a', 'o' - 'a', 'w' - 'a'};
        int count = 0;
        while (front < 32){
            process = code[front];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + code_num[count];
                if (process > 25)
                    process %= 26;
                output[front + 32] = process + 'a';
                count += 1;
                count %= 4;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + code_num[count];
                if (process > 25)
                    process %= 26;
                output[front + 32] = process + 'A';
                count += 1;
                count %= 4;
            }
            else
                output[front + 32] = process;
            front += 1;

            process = code[back];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + 13;
                if (process > 25)
                    process %= 26;
                output[back - 32] = process + 'a';
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + 13;
                if (process > 25)
                    process %= 26;
                output[back - 32] = process + 'A';
            }
            else
                output[back - 32] = process;
            back += 1;
        }
        int index = 3;
        count = 0;
        while(count < 64){
            printf("%c", output[index]);
            index += 1;
            index %= 64;
            count += 1;
        }
    }
    else if (a == 2){
        int index = 11;
        count = 0;
        while (count < 64){
            output[index] = code[count];
            count += 1;
            index += 1;
            index %= 64;
        }
        index = 74;
        index %= 26;
        count = 0;
        while (count < 64){
            process = output[count];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                output[count] = process +'a';
                index += 1;
                index %= 26;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                output[count] = process +'A';
                index += 1;
                index %= 26;
            }
            else {
                output[count] = process;
            }
            count += 1;
        }
        front = 31;
        back = 63;
        tmp = output[31];
        while (front > 0){
            output[front] = output[front - 1];
            front -= 1;
        }
        output[0] = tmp;
        code[0] = output[61];
        code[1] = output[62];
        code[2] = output[63];
        while (back > 34){
            output[back] = output[back - 3];
            back -= 1;
        }
        output[32] = code[0];
        output[33] = code[1];
        output[34] = code[2];
        int rail[8] = {4, 3, 1, 2, 7, 6, 5, 8};
        index = 0;
        count = 0;
        while (index < 64){
            for (int i = 0;i < 8;i ++)
                code[index +rail[i] - 1] = output[index + i];
            index += 8;
        }
        for (int i = 0;i < 64;i ++)
            printf("%c", code[i]);
    }
    else if (a == 3){
        int rail[4] = {3, 2, 4, 1};
        count = 0;
        while (count <64){
            for (int i = 0;i < 4;i ++)
                output[count + rail[i] - 1] = code[count + i];
            count += 4;
        }
        front = 0;
        back = 32;
        int index = 8;
        while (front < 32){
            process = output[front];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'a';
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'A';
            }
            else
                output[front] = process;
            front += 1;
        }
        int rail_2[8] = {1, 8, 4, 3, 6, 5, 7, 2};
        while (back < 64){
            for (int i = 0;i < 8;i ++)
                code[back + rail_2[i] - 1] = output[back + i];
            for (int i = 0;i < 8;i ++)
                output[back + i] = code[back + i];
            back += 8;
        }
        count = 0;
        while (count < 32){
            code[count] = output[count + 32];
            code[count + 32] = output[count];
            count += 1;
        }
        count = 0;
        index = 602;
        index %= 26;
        while (count < 64){
            process = code[count];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                code[count] = process + 'a';
                index -= 1;
                if (index < 0)
                    index += 26;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                code[count] = process + 'A';
                index -= 1;
                if (index < 0)
                    index += 26;
            }
            else
                code[count] = process;
            count += 1;
        }
        index = 57;
        count = 0;
        while (count < 64){
            printf("%c", code[index]);
            index += 1;
            index %= 64;
            count += 1;
        }
    }
    else if (a == 4){
        int front = 0, back = 32, vig[8] = {21, 8, 6, 4, 13, 4, 17, 4}, index = 0, count = 0;
        while(front < 32){
            process = code[front];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + vig[index];
                if (process > 25)
                    process %= 26;
                code[front] = process + 'a';
                index += 1;
                if (index > 7)
                    index %= 8;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + vig[index];
                if (process > 25)
                    process %= 26;
                code[front] = process + 'A';
                index += 1;
                if (index > 7)
                    index %= 8;
            }
            else
                code[front] = process;
            front += 1;
        }
        //右半部
        index = 40;
        while(count < 32){
            output[index] = code[back + count];
            index += 1, count += 1;
            if(index >63)
                index -= 32;
        }

        front = 16, index = 3,count = 0;
        while (count < 32){
            output[count] = code[front];
            front += 1, count += 1;
            if(front > 31)
                front %= 32;
        }
        front = 0;
        while (front < 32){
            process = output[front];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'a';
                index += 1;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'A';
                index += 1;
            }
            else
                output[front] = process;
            front += 1;
        }
        count = 0, index = 45;
        while (count < 64){
            printf("%c", output[index]);
            index += 1, count += 1;
            if (index >63)
                index -= 64;
        }
    }
    else {
        int front = 0, back = 32, count = 0, index = 10, rail[8] = {3, 1, 7, 6, 4, 5, 2, 8}, rail_2[4] = {2, 4, 1, 3};
        while (count < 64){
            for (int i = 0;i < 8;i ++)
                output[count + rail[i] - 1] = code[count + i];
            count += 8;
        }
        while (front < 32){
            process = output[front];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'a';
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                output[front] = process + 'A';
            }
            else
                output[front] = process;
            front += 1;
        }
        while (back < 64){
            for (int i = 0;i < 4;i ++)
                code[back + rail_2[i] - 1] = output[back + i];
            for (int i = 0;i < 4;i ++)
                output[back + i] = code[back + i];
            back += 4;
        }
        count = 0, index = 32;
        while(count < 64){
            code[count] = output[index];
            index += 1, count += 1;
            if (index > 63)
                index %= 64;
        }
        index = 52, count = 0;
        while (count < 64){
            process = code[count];
            if (process >= 'a' && process <= 'z'){
                process = process - 'a' + index;
                if (process > 25)
                    process %= 26;
                code[count] = process + 'a';
                index += 1;
            }
            else if (process >= 'A' && process <= 'Z'){
                process = process - 'A' + index;
                if (process > 25)
                    process %= 26;
                code[count] = process + 'A';
                index += 1;
            }
            else
                code[count] = process;
            count += 1;
        }
        count = 0, index = 57;
        while (count < 64){
            printf("%c", code[index]);
            index += 1, count += 1;
            if (index >63)
                index -= 64;
        }
    }


    return 0;
}