#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void shortestpath(vector<pair<int, int>> Graph[], int n, int loc){
    priority_queue<pair<int, int>> pq;
    vector<int> dist(7, INT_MAX);
    pq.push(make_pair(0, loc));
    dist[0] = 0;
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for(it = Graph[u].begin();it != Graph[u].end();it ++){
            int v = (*it).first, weight = (*it).second;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
    for(int i = 0;i < n;i ++)
        cout << i << " " << dist[i] << endl;
}

void addEdge(vector<pair<int, int>> Graph[], int u, int v, int length){
    Graph[u].push_back(make_pair(v, length));
}

int main(){
    vector<pair<int, int>> Graph[7];
    addEdge(Graph, 0, 1, 1);
    addEdge(Graph, 0, 6, 7);
    addEdge(Graph, 0, 4, 4);
    addEdge(Graph, 1, 2, 8);
    addEdge(Graph, 1, 4, 2);
    addEdge(Graph, 1, 5, 9);
    addEdge(Graph, 2, 3, 5);
    addEdge(Graph, 4, 5, 6);
    addEdge(Graph, 5, 3, 2);
    addEdge(Graph, 5, 6, 3);
    addEdge(Graph, 6, 2, 1);
    addEdge(Graph, 6, 3, 5);
    shortestpath(Graph, 7, 0);
}