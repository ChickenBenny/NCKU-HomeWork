#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyd_warshall(vector<vector<int>> &Graph, int n){
    int dist[4][4];
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++)
            dist[i][j] = Graph[i][j];
    }
    for(int k = 0;k < 4;k ++){
        for(int i = 0;i < 4;i ++){
            for(int j = 0;j < 4;j ++){
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[k][j] != INT_MAX && dist[i][k] != INT_MAX)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i = 0;i < 4;i ++){
        for(int j = 0;j < 4;j ++){
            if(dist[i][j] == INT_MAX)
                cout << "INF" << "    ";
            else
                cout << dist[i][j] << "    ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> Graph;
    Graph.push_back({0, 5, INT_MAX, 6});
    Graph.push_back({7, 0, 3, INT_MAX});
    Graph.push_back({14, INT_MAX, 0, 1});
    Graph.push_back({2, INT_MAX, INT_MAX, 0});
    floyd_warshall(Graph, 4);
}