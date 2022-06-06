#include<stdio.h>
#include<string.h>

int main () {
    int n, person = 0, index;
    scanf("%d\n", &n);
    char name[n][100], name_copy[n][100], ch;
    while (person < n){
        scanf("%c", &ch);
        if (ch == '\n'){
            name[person][index] = '\0';
            name_copy[person][index] = '\0';
            person += 1, index = 0;
        }
        else {
            name[person][index] = ch;
            if (ch >= 'A' && ch <= 'Z')
                name_copy[person][index] = ch - 'A' +'a';
            else
                name_copy[person][index] = ch;
            index += 1;
        }
    }
    int check[n], tmp;
    for (int i = 0;i < n;i ++){
        *(check + i) = -1;
    }
    person = 0;
    while (person < n){
        for (int i = 0;i < n;i ++){
            if (*(check + i) == -1){
                tmp = i;
                break;
            }
        }
        for (int i = 0;i < n;i ++){
            if (check[i] == -1 && name_copy[tmp][0] > name_copy[i][0])
                tmp = i;
            else if (check[i] == -1 && name_copy[tmp][0] == name_copy[i][0] && strcmp(&name_copy[tmp][0], &name_copy[i][0]) > 0)
                tmp = i;
        }
        check[tmp] = person;
        person += 1;
    }
    person = 0;
    while (person < n){
        for (int i = 0;i < n;i ++){
            if (check[i] == person){
                printf("%s\n", &name[i][0]);
                break;
            }
        }
        person += 1;
    }

    return 0;
}