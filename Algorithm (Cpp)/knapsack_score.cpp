#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class node{
    public:
    int time, score;
};
bool cmp(node a, node b);
int knapsack(vector<node> &vectorSpace, int n, int limit);

int main(){
    int n, limit;
    node tmp;
    cin >> n >> limit;
    vector<node> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> tmp.score >> tmp.time;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    cout << knapsack(vectorSpace, n, limit);
}

bool cmp(node a, node b){
    if(a.time < b.time)
        return true;
    else
        return false;
}

int knapsack(vector<node> &vectorSpace, int n, int limit){
    vector<vector<int>> time(2, vector<int> (limit + 1));
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= limit;j ++){
            if(i == 0 || j == 0)
                time[i % 2][j] = 0;
            else if(vectorSpace[i - 1].time <= j){
                time[i % 2][j] = max(time[(i - 1) % 2 ][j], vectorSpace[i - 1].score + time[(i - 1) % 2][j - vectorSpace[i - 1].time]);
            }
            else
                time[i % 2 ][j] = time[(i - 1) % 2][j];
        }
    }
    return time[n % 2][limit];
}