#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}

int rising_hope(char *R) {
    int i = 0, turn = 1, ans = 0;
    char ch;
    while (turn == 1){
        ch = *(R + i);
        if (ch == 'P')
            ans += 1;
        else if (ch == 'N')
            ans -= 1;
        else if (ch == '\0')
            turn = -1;
        i += 1;
    }
    return ans;
}
