#include<stdio.h>

void solve_problem(long int a);

int main () {
    int i = 0 , turn = 0;
    long int even_part, odd_part;
    char ch;
    even_part = 0;
    odd_part = 0;
    while (turn == 0) {
        scanf("%c", &ch);
        if(ch == '\n'){
            turn = -1;
            break;
        }
        if (i % 2 == 0) {
            if (ch == 'a' || ch == 'A')
                even_part += 10;
            else if (ch == 'b' || ch == 'B')
                even_part += 11;
            else if (ch == 'c' || ch == 'C')
                even_part += 12;
            else if (ch == 'd' || ch == 'D')
                even_part += 13;
            else if (ch == 'e' || ch == 'E')
                even_part += 14;
            else if (ch == 'f' || ch == 'F')
                even_part += 15;
            else {
                ch = ch - '0';
                even_part += ch;
            }
        } else {
            if (ch == 'a' || ch == 'A')
                odd_part += 10;
            else if (ch == 'b' || ch == 'B')
                odd_part += 11;
            else if (ch == 'c' || ch == 'C')
                odd_part += 12;
            else if (ch == 'd' || ch == 'D')
                odd_part += 13;
            else if (ch == 'e' || ch == 'E')
                odd_part += 14;
            else if (ch == 'f' || ch == 'F')
                odd_part += 15;
            else {
                ch = ch - '0';
                odd_part += ch;
            }
        }
        i += 1;
    }

    solve_problem(odd_part);
    solve_problem(even_part);
    return 0;
}

void solve_problem(long int a){
    if (a >=0 && a <=15) {
        printf("%lx", a);
        return;
    }
    else{
        long int odd_part_process = 0, even_part_process = 0, count = 0, tmp, x[5000] = {0};
        while (a > 0){
            tmp = a % 16;
            a /= 16;
            x[count] = tmp;
            count += 1;
        }
        for (int i = 0;i < count;i ++){
            if (i % 2 ==1)
                odd_part_process += x[count - 1 - i];
            else
                even_part_process += x[count - 1 - i];
        }
        solve_problem(odd_part_process);
        solve_problem(even_part_process);
        return;
    }
}

