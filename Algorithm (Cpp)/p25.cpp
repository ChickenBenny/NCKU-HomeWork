#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
    int score, deadline, time;
};
bool cmp(node a, node b){
    if(a.deadline > b.deadline)
        return true;
    else if(a.deadline == b.deadline && a.time < b.time)
        return true;
    else
        return false;
}
int max_score(vector<node> &vectorSpace, int n, int limit);


int main(){
    int n;
    cin >> n;
    node tmp;
    vector<node> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> tmp.score >> tmp.deadline >> tmp.time;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    cout << max_score(vectorSpace, n, vectorSpace[0].deadline);
}

int max_score(vector<node> &vectorSpace, int n, int limit){
    vector<vector<int>> score_table(2, vector<int> (limit + 1));
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= limit;j ++){
            if(i == 0 || j == 0)
                score_table[i % 2][j] = 0;
            else if(vectorSpace[i - 1].time > j)
                score_table[i % 2][j] = score_table[(i - 1) % 2][j];
            else if(j >= limit - vectorSpace[i - 1].deadline + vectorSpace[i - 1].time)
                score_table[i % 2][j] = max(score_table[(i - 1) % 2][j], vectorSpace[i - 1].score + score_table[(i - 1) % 2][j - vectorSpace[i - 1].time]);
            else
                score_table[i % 2][j] = score_table[(i - 1) % 2][j];
        }

    }
    return score_table[n % 2][limit];
}