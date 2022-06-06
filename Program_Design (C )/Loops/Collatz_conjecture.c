#include <stdio.h>

int main() {
    int s, count, max_num;
    scanf("%d", &s);
    count = 1;
    max_num = s;
    while (s != 1){
        count += 1;
        if ( s % 2 ==0){
            s = s /2;
            if ( s > max_num)
                max_num = s;
        }
        else {
            s = 3 * s + 1;
            if( s > max_num)
                max_num = s;
        }
    }
    printf("%d %d", count, max_num);
	return 0;
}