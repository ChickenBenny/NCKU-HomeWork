#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class node{
    public:
    int score, deadline, time;
};
bool cmp(node a, node b);
int max_score(vector<node> &vectorSpace, int n, int time);
int find_num(vector<node> &vectorSpace, int n, int time);

int main(){
    int n;
    node tmp;
    cin >> n;
    vector<node> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> tmp.score >> tmp.deadline >> tmp.time;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    cout << max_score(vectorSpace, n, vectorSpace[0].deadline);
}

bool cmp(node a, node b){
    if(a.deadline < b.deadline)
        return true;
    else if(a.deadline == b.deadline && a.time < b.time)
        return true;
    else 
        return false;
}

int max_score(vector<node> &vectorSpace, int n, int time){
    if(n == 0)
        return vectorSpace[n].score;
    else{
        int i = find_num(vectorSpace, n, time), total_score_in = vectorSpace[i].score, total_score_over = 0;
        if(i != -1){
            total_score_in = max_score(vectorSpace, i, time - vectorSpace[i].time); // in
            total_score_over = max_score(vectorSpace, i - 1, time); // over
        }
        return max(total_score_in, total_score_over);
    }
}

int find_num(vector<node> &vectorSpace, int n, int time){
    for(int i = n;i >= 0;i --){
        if(vectorSpace[i].deadline <= time && time - vectorSpace[i].time >= 0)
            return i;
    }
    return -1;
}