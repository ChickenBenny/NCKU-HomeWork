#include <iostream>
#include <vector>

using namespace std;

void APutil(vector<int> village[], int i, vector<bool> &visit, vector<int> &disc, vector<int> &low, int& step, int parent, vector<bool> isAP){
    int children = 0;
    step += 1;
    visit[i] = true;
    disc[i] = low[i] = step;
    for(auto j : village[i]){
        if(!visit[j]){
            children += 1;
            APutil(village, j, visit, disc, low, step, i, isAP);
            low[i] = min(low[i], low[j]);
            if(parent != -1 && low[j] >= disc[i])
                isAP[i] = true;
        }
        else if(j != parent)
            low[i] = min(low[j], disc[i]);
    }
    if(parent == -1 && children > 1)
        isAP[i] = true;
}

void AP(vector<int> village[], int n, int m){
    vector<int> disc(n, 0), low(n, 0);
    vector<bool> visit(n, false), isAP(n, false);
    int step = 0, parent = -1;
    for(int i = 0;i < n;i ++){
        if(!visit[i])
            APutil(village, i, visit, disc, low, step, parent, isAP);
    }
    for(int i = 0; i < n; i++){
        if(isAP[i] == true)
            cout << i << " ";
    }
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<int> village[n];
    bool flag = true;
    while(flag){
        cin >> u >> v;
        if(u == -1 && v == -1){
            flag = false;
            continue;
        }
        village[u].push_back(v);
        village[v].push_back(u);
    }
    AP(village, n, m);
}