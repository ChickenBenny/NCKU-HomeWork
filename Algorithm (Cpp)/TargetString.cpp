#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;
int findNumConc(string A,string B);

int main() {
    int n;
    string origin, target;
    for(int i = 0;i < n;i ++){
        cin >> origin;
        cin >> target;
        cout << findNumConc(origin, target);
    }
}

int findNumConc(string A,string B){
    vector<vector<int>> indexes(26,vector<int>(0,0));
    for(int i = 0;i<A.size();i++){
        indexes[int(A[i]-'a')].push_back(i);
    }
    int cur = 0;
    int count = 0;
    for(int j = 0;j<B.size();){
        vector<int> match_indexes = indexes[int(B[j]-'a')];
        vector<int>::iterator itr =lower_bound(match_indexes.begin(),match_indexes.end(),cur);
        if(itr == match_indexes.end()){
            cur = 0;
            count++;
        } else {
            cur = (*itr) + 1;
            j++;
        }
    }
    return count;
}