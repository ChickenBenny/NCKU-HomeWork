#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long int num, operate, a, b;
    scanf("%ld %ld", &num, &operate);
    getchar();
    long int answer[num][num], memory[2][num];
    for(long int i = 0;i < num;i ++){
        answer[i][0] = i + 1;
        memory[0][i] = i + 1;
        memory[1][i] = 0;
        for(long int j = 1;j < num;j ++)
            answer[i][j] = 0;
    }
    char action[4], op[4];
    long int* locationA,* locationB, processNUM, locationNUM, count, *backLOC;
    for(long int i = 0;i < operate;i ++){
        scanf("%c%c%c%c %ld %c%c%c%c %ld", &action[0], &action[1], &action[2], &action[3], &a, &op[0], &op[1], &op[2], &op[3], &b);
        if((memory[0][a - 1] != memory[0][b - 1]) && (a != b)){
            if(action[0] == 'm'){
                if(op[1] == 'n'){
                    locationA = &answer[memory[0][a - 1] - 1][memory[1][a - 1]];
                    locationB = &answer[memory[0][b - 1] - 1][memory[1][b - 1]];
                    count = 1;
                    while(*(locationA + count) != 0){
                        processNUM = *(locationA + count);
                        backLOC = &answer[processNUM - 1][0];
                        while(*backLOC != 0)
                            backLOC += 1;
                        *backLOC = processNUM;
                        memory[0][processNUM - 1] = processNUM;
                        memory[1][processNUM - 1] = backLOC - &answer[processNUM - 1][0];
                        *(locationA + count) = 0;
                        count += 1;
                    }
                    count = 1;
                    while(*(locationB + count) != 0){
                        processNUM = *(locationB + count);
                        backLOC = &answer[processNUM - 1][0];
                        while(*backLOC != 0)
                            backLOC += 1;
                        *backLOC = processNUM;
                        memory[0][processNUM - 1] = processNUM;
                        memory[1][processNUM - 1] = backLOC - &answer[processNUM - 1][0];
                        *(locationB + count) = 0;
                        count += 1;
                    }
                    locationB += 1;
                    processNUM = *locationA;
                    *locationB = processNUM;
                    memory[0][processNUM - 1] = memory[0][b - 1];
                    locationNUM = locationB - &answer[memory[0][b - 1] - 1][0];
                    memory[1][processNUM - 1] = locationB - &answer[memory[0][b - 1] - 1][0];
                    *locationA = 0;
                }
                else{
                    locationA = &answer[memory[0][a - 1] - 1][memory[1][a - 1]];
                    locationB = &answer[memory[0][b - 1] - 1][memory[1][b - 1]];
                    count = 1;
                    while(*(locationA + count) != 0){
                        processNUM = *(locationA + count);
                        backLOC = &answer[processNUM - 1][0];
                        while(*backLOC != 0)
                            backLOC += 1;
                        *backLOC = processNUM;
                        memory[0][processNUM - 1] = processNUM;
                        memory[1][processNUM - 1] = backLOC - &answer[processNUM - 1][0];
                        *(locationA + count) = 0;
                        count += 1;
                    }
                    while(*locationB != 0)
                        locationB += 1;
                    processNUM = *locationA;
                    *locationB = processNUM;
                    memory[0][processNUM - 1] = memory[0][b - 1];
                    locationNUM = locationB - &answer[memory[0][b - 1] - 1][0];
                    memory[1][processNUM - 1] = locationB - &answer[memory[0][b - 1] - 1][0];
                    *locationA = 0;
                }
            }
            else{
                if(op[1] == 'n'){
                    locationA = &answer[memory[0][a - 1] - 1][memory[1][a - 1]];
                    locationB = &answer[memory[0][b - 1] - 1][memory[1][b - 1]];
                    count = 1;
                    while(*(locationB + count) != 0){
                        processNUM = *(locationB + count);
                        backLOC = &answer[processNUM - 1][0];
                        while(*backLOC != 0)
                            backLOC += 1;
                        *backLOC = processNUM;
                        memory[0][processNUM - 1] = processNUM;
                        memory[1][processNUM - 1] = backLOC - &answer[processNUM - 1][0];
                        *(locationB + count) = 0;
                        count += 1;
                    }
                    while(*locationA != 0) {
                        locationB += 1;
                        processNUM = *locationA;
                        *locationB = processNUM;
                        memory[0][processNUM - 1] = memory[0][b - 1];
                        locationNUM = locationB - &answer[memory[0][b - 1] - 1][0];
                        memory[1][processNUM - 1] = locationB - &answer[memory[0][b - 1] - 1][0];
                        *locationA = 0;
                        locationA += 1;
                    }
                }
                else{
                    locationA = &answer[memory[0][a - 1] - 1][memory[1][a - 1]];
                    locationB = &answer[memory[0][b - 1] - 1][memory[1][b - 1]];
                    while(*locationB != 0)
                        locationB += 1;
                    while(*locationA != 0) {
                        processNUM = *locationA;
                        *locationB = processNUM;
                        memory[0][processNUM - 1] = memory[0][b - 1];
                        locationNUM = locationB - &answer[memory[0][b - 1] - 1][0];
                        memory[1][processNUM - 1] = locationB - &answer[memory[0][b - 1] - 1][0];
                        *locationA = 0;
                        locationA += 1;
                        locationB += 1;
                    }
                    }
                }
            }
        getchar();
        }
    for(long int i = 0;i < num;i ++){
        printf("%ld:", i + 1);
        for(long int j = 0;j < num;j ++){
            if(answer[i][j] != 0)
                printf(" %ld", answer[i][j]);
            else
                break;
        }
        printf("\n");
    }
    return 0;
}