#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge{
    public:
    int start, end, weight;
};

void BellmanFord(vector<Edge> &Graph, int n, int e){
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for(int i = 0;i < n - 1;i ++){
        for(int j = 0;j < e;j ++){
            int u = Graph[j].start, v = Graph[j].end, w = Graph[j].weight;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] = w;
        }
    }
    bool flag = true;
    for(int i = 0;i < e;i ++){
        int u = Graph[i].start, v = Graph[i].end, w = Graph[i].weight;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "No solution exits!" << endl;
            flag = false;
        }
    }
    if(flag)
        for(int i = 0;i < n;i ++)
            cout << i << " " << dist[i] << endl;
}

void addEdge(vector<Edge> &Graph, int start, int end, int weight){
    Edge tmp;
    tmp.start = start, tmp.end = end, tmp.weight = weight;
    Graph.push_back(tmp);
}

int main(){
    vector<Edge> Graph;
    addEdge(Graph, 0, 2, 1);
    addEdge(Graph, 1, 2, -4);
    addEdge(Graph, 3, 4, 2);
    addEdge(Graph, 2, 3, 7);
    addEdge(Graph, 4, 0, 5);
    addEdge(Graph, 3, 1, 10);
    addEdge(Graph, 0, 1, 2);
    addEdge(Graph, 4, 2, -1);
    BellmanFord(Graph, 5, 8);
}