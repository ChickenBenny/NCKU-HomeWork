#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int MAX_N = 1001; // 10^3
int N, M;

vector<int> VECTOR_SPACE[MAX_N];

void getCoordinates(int a, int& x, int& y){
    for (x = 0; x<=N; ++x){
        for (y=0; y< VECTOR_SPACE[x].size(); ++y){
            if (VECTOR_SPACE[x][y] == a){
                return ;
            }
        }
    }
}


void moveAboveBack(int x, int y){
    // printf("move above back %d\n", x );
    for (int i=y+1; i<VECTOR_SPACE[x].size(); ++i){
        int b=VECTOR_SPACE[x][i];
        VECTOR_SPACE[b].push_back(b);        
    }
    VECTOR_SPACE[x].resize(y+1);    
}

void pileOnto(int x, int y, int toX){
    for (int i = y; i < VECTOR_SPACE[x].size(); ++i){
        VECTOR_SPACE[toX].push_back(VECTOR_SPACE[x][i]);
    }
    VECTOR_SPACE[x].resize(y);
}

void printAll(){
    for (int i=1; i<=N; ++i){
        printf("%d:", i);
        for (int j = 0; j < VECTOR_SPACE[i].size(); j++){
            printf(" %d", VECTOR_SPACE[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a, b;
    string s1, s2;
    
    scanf("%d %d", &N, &M);
    
    
    for (int i=1; i<=N; ++i){
        VECTOR_SPACE[i].push_back(i);        
    }

    for (int i=0; i<M; ++i){
        // printf("%d\n", i);        
        cin>> s1 >> a >> s2 >> b;
        int aX, bX, aY, bY;
        getCoordinates(a, aX, aY);
        getCoordinates(b, bX, bY);

        if(aX == bX){
            continue;
        }

        if(s1 == "move"){
            moveAboveBack(aX, aY);
        }

        if (s2 == "onto"){
            moveAboveBack(bX, bY);
        }

        pileOnto(aX, aY, bX);
    }
    printAll();
    return 0;
    
}