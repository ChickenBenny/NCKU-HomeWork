#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
void add_edge(vector<int> graph[], int v, int u);
void repair_village(vector<int> graph[], vector<int> &destroy_node, int n, int m);
int BFS(vector<int> graph[], int start, int end, int n);
void repair_cost(vector<vector<int>> &cost, int m);

int main(){
    int n, m, v, u;
    cin >> n >> m;
    vector<int> graph[n];
    vector<int> destroy_node;
    for(int i = 0;i < n - 1;i ++){
        cin >> v >> u;
        add_edge(graph, v, u);
    }
    for(int i = 0;i < m;i ++){
        cin >> v;
        destroy_node.push_back(v);
    }
    repair_village(graph, destroy_node, n);
}

void add_edge(vector<int> graph[], int v, int u){
    graph[v].push_back(u);
    graph[u].push_back(v);
}

void repair_village(vector<int> graph[], vector<int> &destroy_node, int n, int m){
    vector<vector<int>> cost;
    cost.assign(m, vector<int>(m, 0));
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < m;j ++){
            if(i == j)
                cost[i][j] = 0;
            else if(j < i)
                cost[i][j] = cost[j][i];
            else
                cost[i][j] = BFS(graph, destroy_node[i], destroy_node[j], n);
        }
    }
    repair_cost(cost, m);
}

int BFS(vector<int> graph[], int start, int end, int n){
    queue<int> path;
    vector<int> visit(n, 0), dist(n, 0);
    int u;
    visit[start] = 0, dist[start] = 0;
    path.push(start);
    while(!path.empty()){
        u = path.front();
        for(int i = 0;i < graph[u].size();i ++){
            if(visit[graph[u][i]] == 0){
                visit[graph[u][i]] = 1;
                dist[graph[u][i]] = dist[u] + 1;
                path.push(graph[u][i]);
            }
            if(graph[u][i] == end)
                return dist[end];
        }
    }
}

void repair_cost(vector<vector<int>> &cost, int m){
    int min_path, tmp, location;
    for(int i = 0;i < m;i ++){
        vector<int> visit(m, 0);
        visit[i] = 0;
        min_path = INT_MAX;
        for(int j = 0;j < m;j ++){
            tmp = cost[i][j];
            min_path = min(tmp, min_path);
        }
    }
}