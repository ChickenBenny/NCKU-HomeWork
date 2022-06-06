#include <stdio.h>

int main () {
    int black_tea, white_ground, tie_tea, green_tea, milk, sugar, ice;
    scanf("%d %d %d %d %d %d %d", &black_tea, &white_ground, &tie_tea, &green_tea, &milk, &sugar, &ice);
    int b_g = black_tea * 1000, w_g = white_ground * 1000, t_g = tie_tea * 1000 , green_g = green_tea * 1000 , m_g = milk * 1000 , s_g = sugar * 1000, i_g = ice * 1000, money = 0;
    int num, drink_sugar, drink_ice, count = 0;
    char ch[2] ;
    scanf("%d", &num);
    for (int i = 0;i < num; i ++){
        count = 0 ;
        scanf("\n");
        while (count < 2) {
            scanf("%c", &ch[count]);
            count += 1;
        }
        scanf("%d/%d", &drink_sugar, &drink_ice);
        if (drink_sugar == 1)
            s_g -= 0;
        else if (drink_sugar == 2)
            s_g -= 3;
        else if (drink_sugar == 3)
            s_g -= 5;
        else if (drink_sugar == 4)
            s_g -= 7;
        else if (drink_sugar == 5)
            s_g -= 10;

        if (drink_ice == 1)
            i_g -= 0;
        else if (drink_ice == 2)
            i_g -= 30;
        else if (drink_ice == 3)
            i_g -= 50;
        else if (drink_ice == 4)
            i_g -= 70;
        else if (drink_ice == 5)
            i_g -= 100;

        if (ch[0] == 'G' && ch[1] == ' '){
            green_g -= 500;
            money += 20;
        }
        else if (ch[0] == 'B'&& ch[1] == ' '){
            b_g -= 500;
            money += 20;
        }
        else if (ch[0] == 'T'&& ch[1] == ' '){
            t_g -= 500;
            money += 30;
        }
        else if (ch[0] == 'W'&& ch[1] == ' '){
            w_g -= 500;
            money += 15;
        }
        else if (ch[0] == 'G' && ch[1] == 'T'){
            t_g -= 250;
            green_g -= 250;
            money += 45;
        }
        else if (ch[0] == 'W' && ch[1] == 'T'){
            t_g -= 350;
            w_g -= 150;
            money += 40;
        }
        else if (ch[0] == 'B' && ch[1] == 'M'){
            b_g -= 200;
            m_g -= 300;
            money += 35;
        }
        else if (ch[0] == 'T' && ch[1] == 'M'){
            t_g -= 200;
            m_g -= 300;
            money += 45;
        }
        else if (ch[0] == 'W' && ch[1] == 'M'){
            w_g -= 200;
            m_g -= 300;
            money +=30;
        }
    }

    printf("%d %d %d %d %d %d %d\n", b_g, w_g, t_g, green_g, m_g, s_g, i_g);
    printf("%d", money);

    return 0;
}
