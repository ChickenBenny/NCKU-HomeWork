#include<stdio.h>
#include<string.h>

char *reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]);

int main(){
    char author[100], title[150], conference[150], location[30], date[5], ppdoi[60];
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]", author, title, conference, location, date, ppdoi);
    printf("%s", reference(author, title, conference, location, date, ppdoi));
    return 0;
}

char *reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]) {
    static char result[300];
    int i = 0, index = 0, turn = 1;
    char ch;
    while (turn == 1){
        ch = author[i];
        if (ch != '\0') {
            result[index] = ch;
            index += 1, i += 1;
        }
        else
            turn = -1;
    }
    result[index] = ',', index += 1;
    result[index] = ' ', index += 1;
    result[index] = '"', index += 1;
    turn = 1, i = 0;
    while (turn == 1){
        ch = title[i];
        if (ch != '\0'){
            result[index] = ch;
            index += 1, i += 1;
        }
        else turn = -1;
    }
    result[index] = ',', index += 1;
    result[index] = '"', index += 1;
    result[index] = ' ', index += 1;
    turn = 1, i = 0;
    while(turn == 1){
        ch = conference[i];
        if (ch != '\0'){
            result[index] = ch;
            index += 1, i += 1;
        }
        else turn = -1;
    }
    result[index] = ',', index += 1;
    result[index] = ' ', index += 1;
    turn = 1, i = 0;
    while(turn == 1){
        ch = location[i];
        if (ch != '\0'){
            result[index] = ch;
            index += 1, i += 1;
        }
        else turn = -1;
    }
    result[index] = ',', index += 1;
    result[index] = ' ', index += 1;
    turn = 1, i = 0;
    while(turn == 1){
        ch = date[i];
        if (ch != '\0'){
            result[index] = ch;
            index += 1, i += 1;
        }
        else turn = -1;
    }
    result[index] = ',', index += 1;
    result[index] = ' ', index += 1;
    turn = 1, i = 0;
    while(turn == 1){
        ch = ppdoi[i];
        if (ch != '\0'){
            result[index] = ch;
            index += 1, i += 1;
        }
        else turn = -1;
    }
    result[index] = '.', index += 1;
    result[index] = '\0';
    return result;
}