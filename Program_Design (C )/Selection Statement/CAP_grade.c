#include<stdio.h>

int main () {
    int ch, so, sc, score, point, a, b, c;
    float en, ma;
    a = b = c = score = point = 0;
    scanf("%d%f%f%d%d", &ch, &en, &ma, &so, &sc);
    if (ch > 40){
        score += 6;
        a += 1;
        if (ch > 44){
            point += 7;
        }
        else if (ch > 42 && ch < 45){
            point += 6;
        }
        else point += 5;
    }
    else if (ch > 18){
        score += 4;
        b += 1;
        if (ch > 35){
            point += 4;
        }
        else if (ch > 30 && ch < 36){
            point += 3;
        }
        else point += 2;
    }
    else {score += 2; point += 1, c += 1;}


    if (en > 89.52){
        score += 6;
        a += 1;
        if (en > 97.14){
            point += 7;
        }
        else if (en > 94.29 && en < 98.05){
            point += 6;
        }
        else point += 5;
    }
    else if (en > 38.7){
        score += 4;
        b += 1;
        if (en > 81.53){
            point += 4;
        }
        else if (en > 69.78 && ch < 81.58){
            point += 3;
        }
        else point += 2;
    }
    else {score += 2; point += 1, c += 1;}

    if (ma > 81.15){
        score += 6;
        a += 1;
        if (ma > 93.46){
            point += 7;
        }
        else if (ma > 90.00 && ma < 94.23){
            point += 6;
        }
        else point += 5;
    }
    else if (ma > 40.19){
        score += 4;
        b += 1;
        if (ma > 71.92){
            point += 4;
        }
        else if (ma > 62.31 && ma < 72.12){
            point += 3;
        }
        else point += 2;
    }
    else {score += 2; point += 1, c += 1;}

    if (so > 55){
        score += 6;
        a += 1;
        if (so > 60){
            point += 7;
        }
        else if (so > 58 && so < 63){
            point += 6;
        }
        else point += 5;
    }
    else if (so > 22){
        score += 4;
        b += 1;
        if (so > 47){
            point += 4;
        }
        else if (so > 38 && so < 48){
            point += 3;
        }
        else point += 2;
    }
    else {score += 2; point += 1, c += 1;}

    if (sc > 45){
        score += 6;
        a += 1;
        if (sc > 51){
            point += 7;
        }
        else if (sc > 49 && sc < 52){
            point += 6;
        }
        else point += 5;
    }
    else if (sc > 19){
        score += 4;
        b += 1;
        if (sc > 37){
            point += 4;
        }
        else if (sc > 30 && sc < 38){
            point += 3;
        }
        else point += 2;
    }
    else {score += 2; point += 1, c += 1;}

    printf("%d/%d", score, point);
    if (a == 5)
        printf("(%dA)", a);
    else if(b == 5)
        printf("(%dB)", b);
    else if(c == 5)
        printf("(%dC)", c);
    else if(a + b == 5 && c == 0)
        printf("(%dA%dB)", a, b);
    else if(a + c == 5 && b == 0)
        printf("(%dA%dC)", a, c);
    else if (b + c == 5 && a == 0)
        printf("(%dB%dC)", b, c);
    else printf("(%dA%dB%dC)", a, b, c);
    return 0;
}
