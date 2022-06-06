#include <stdio.h>
int *report_card (int *s) ;

int main () {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}

int *report_card (int *s) {
    int *start, *end, *answer, length = 0, *index = s, tmp = 0, sum = 0;
    while (* index != -1){
        if (* index >= 60){
            start = index;
            while (* index >= 60){
                tmp += *index;
                index += 1;
            }
            if ((index - start) > length){
                length = index - start;
                end = index;
                answer = start;
                tmp = 0;
            }
            else if ((index - start) == length && tmp > sum){
                end = index;
                answer = start;
                sum = tmp, tmp = 0;
            }
        }
        else index += 1;
    }
    *end = -1;
    return answer;
}