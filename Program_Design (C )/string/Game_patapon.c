#include<stdio.h>
#include<string.h>

int main () {
    int dist, hp, count = 0, defense = 0, success = 0, success_count = 0;
    scanf("%d %d\n", &dist, &hp);
    char action[1000], dot[] = ".,", *token, action_1[] = "PATA PATA PATA PON", action_2[] = "PON PON PATA PON", action_3[] = "CHAKA CHAKA PATA PON";
    gets(action);
    token = strtok(action, dot);
    count +=1;
    while(token != NULL){
        if (count > 30)
            break;
        if (strcmp(token, action_1) == 0){
            dist -= 1;
            success_count += 1;
            if (dist <= 0)
                break;
        }
        else if (strcmp(token, action_2) == 0){
            success_count += 1;
            if (dist <= 3)
                hp -= 1;
            if (hp == 0){
                success = 1;
                break;
            }
        }
        else if (strcmp(token, action_3) == 0){
            success_count += 1;
            dist += 1;
            defense = 1;
        }
        if (count % 10 ==0 && defense != 1)
            break;
        else defense = 0;
        token = strtok(NULL, dot);
        count += 1;
    }

    if (success == 1)
        printf("YES %d", success_count);
    else
        printf("NO %d", hp);
    return 0;
}