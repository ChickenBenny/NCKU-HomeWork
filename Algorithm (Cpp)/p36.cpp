#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void travel(int i, vector<int> Graph[], vector<bool> &visit);

int main(){
    int n, m, u, v, d;
    bool flag = true;
    while(flag){
        cin >> n >> m;
        if(n == 0 && m == 0){
            flag = false;
            continue;
        }
        else{
            vector<int> Graph[n], GraphT[n];
            vector<bool> visit(n, false), visitT(n, false);
            for(int i = 0;i < m;i ++){
                cin >> u >> v >> d;
                if(d == 1){
                    Graph[u - 1].push_back(v - 1);
                    GraphT[v - 1].push_back(u - 1);
                }
                else{
                    Graph[u - 1].push_back(v - 1);
                    Graph[v - 1].push_back(u - 1);

                    GraphT[v - 1].push_back(u - 1);
                    GraphT[u - 1].push_back(v - 1);
                }
            }
            travel(0, Graph, visit);
            travel(0, GraphT, visitT);
            bool x = true, y = true;
            for(int i = 0;i < n;i ++){
                if(visit[i] == false)
                    x = false;
                if(visitT[i] == false)
                    y = false;
            }
            if(x == true && y == true)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}

void travel(int i, vector<int> Graph[], vector<bool> &visit){
    visit[i] = true;
    vector<int>::iterator j;
    for(j = Graph[i].begin();j < Graph[i].end();j ++){
        if(!visit[*j])
            travel(*j, Graph, visit);
    }
}