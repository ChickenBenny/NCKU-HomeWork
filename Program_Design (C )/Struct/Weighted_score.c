#include <stdio.h>

struct weight {
    char chapter[10];
    int percent;
};

struct score {
    char chapter[10];
    int score;
};

struct report_card {
    char name[32];
    struct score record[10];
    int final;
    int max_score;
    int min_score;
};

void calculate (struct report_card[], struct weight[], int student_num, int chapter_num);

int main () {
    int student_num, chapter_num;
    struct weight chapter[10];
    struct report_card card[100];

    scanf("%d %d\n", &chapter_num, &student_num);
    for (int i = 0; i < chapter_num; ++i) {
        scanf("%d %s", &chapter[i].percent, chapter[i].chapter);
    }

    for (int i = 0; i < student_num; ++i) {
        scanf("%s", card[i].name);
        for (int j = 0; j < chapter_num; ++j) {
            scanf("%d %s", &card[i].record[j].score, card[i].record[j].chapter);
        }
    }

    calculate(card, chapter, student_num, chapter_num);

    for (int i = 0; i < student_num; ++i) {
        printf("%s %d %d %d\n", card[i].name, card[i].final, card[i].max_score, card[i].min_score);
    }
}

void calculate (struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    int count = 0, max_score = 0, min_score = 100, percent_ch;
    float sum_score = 0;
    char tmp_chapter[10] = {0};
    while (count < student_num){
        for (int i = 0;i < chapter_num;i ++){
            for (int j = 0;j < chapter_num;j ++){
                if (strcmp(card[count].record[i].chapter, chapter[j].chapter) == 0){
                    percent_ch = chapter[j].percent ;
                    break;
                }
            }
            sum_score += card[count].record[i].score * percent_ch;
            if (card[count].record[i].score > max_score)
                max_score = card[count].record[i].score;
            if (card[count].record[i].score < min_score)
                min_score = card[count].record[i].score;
        }
        card[count].final = sum_score/ 100.;
        card[count].max_score = max_score;
        card[count].min_score = min_score;
        max_score = 0, min_score = 100, sum_score = 0;
        count += 1;
    }
}
