#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int findmax(int left, int right, vector<int > stones){
    int num = stones.size(), mx=0;
    vector<int > rangeList;
    // cout <<"\n" << "=============" << "\n";
    // cout << left << ":" << right << "\n";
    if (stones.size() == 0) {
        mx = right - left;
        rangeList.push_back(mx);
    } else {
        for (int i=0; i<stones.size(); ++i){
            // cout << i << "\n";
            if (i==0){
                rangeList.push_back(stones[i] - left);
            } else {
                rangeList.push_back(stones[i] - stones[i-1]);            
            };                
        }
        rangeList.push_back(right - stones.back());
    }

    for (int i=0; i< rangeList.size(); ++i){        
        if (i+1 == rangeList.size()) break;
        mx = max(mx, rangeList[i] + rangeList[i+1]);
    }
    
    return mx;
}


int main(){
    int round, x;
    cin >> round;

    while (round--){        
        vector<int > stones;
        vector<int > rangeList;
        int stoneNum, riverLength, mx=0, curPos=0;
        cin >> stoneNum >> riverLength;
        int left=0, right=0;
        
        
        while (stoneNum--) {
            char size;
            int pos;
            cin >> size >> pos;
            
            if (size == 'b') {
                if (right < pos){
                    right = pos;
                    mx = max(mx, findmax(left, right, stones));                                        
                    stones = {};
                    left = pos;
                }
            }
            if (size == 's'){
                stones.push_back(pos);
            }
            
        }
        right = riverLength;
        
        mx = max(mx, findmax(left, right, stones));
        cout << mx <<"\n";        
    }
}