#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
vector<int> findsmallestrange(vector<vector<int>> &vectorSpace, int n);

int main(){
    int n, x, tmpNum;
    cin >> n;
    vector<vector<int>> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vector<int> tmp;
        for(int j = 0;j < x;j ++){
            cin >> tmpNum;
            tmp.push_back(tmpNum);
        }
        vectorSpace.push_back(tmp);
    }
    vector<int> ans = findsmallestrange(vectorSpace, n);
    cout << ans[0] << " " << ans[1];
}

vector<int> findsmallestrange(vector<vector<int>> &vectorSpace, int n){
        int curMax = INT_MIN;
        vector<int> idx(n, 0);
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);
        for (int i = 0; i < n; ++i) {
            q.push({vectorSpace[i][0], i});
            idx[i] = 1;
            curMax = max(curMax, vectorSpace[i][0]);
        }
        vector<int> res{q.top().first, curMax};
        while (idx[q.top().second] < vectorSpace[q.top().second].size()) {
            int t = q.top().second; q.pop();
            q.push({vectorSpace[t][idx[t]], t});
            curMax = max(curMax, vectorSpace[t][idx[t]]);
            ++idx[t];
            if (res[1] - res[0] > curMax - q.top().first) {
                res = {q.top().first, curMax};
            }
        }
        return res;

}
