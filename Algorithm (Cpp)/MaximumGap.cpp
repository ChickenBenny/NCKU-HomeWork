#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int MaxmiumGap(vector<int> &vectorSpace, int length, int maxVal, int minVal);

int main(){
    int n, x, max_dist, maxVal = INT_MIN, minVal = INT_MAX;
    cin >> n;
    vector<int> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vectorSpace.push_back(x);
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }
    cout <<  MaxmiumGap(vectorSpace, n, maxVal, minVal);
    return 0;
}

int MaxmiumGap(vector<int> &vectorSpace, int length, int max_val, int minVal){
    if(vectorSpace.size() < 2)
        return 0;
    int size = (max_val - minVal) / length + 1, cnt = (max_val - minVal) / size + 1, pre = 0, res = 0;
    vector<int> bucket_min(cnt, INT_MAX), bucket_max(cnt, INT_MIN);
    for (int num : vectorSpace) {
        int idx = (num - minVal) / size;
        bucket_min[idx] = min(bucket_min[idx], num);
        bucket_max[idx] = max(bucket_max[idx], num);
    }
    for (int i = 1; i < cnt; ++i) {
        if (bucket_min[i] == INT_MAX || bucket_max[i] == INT_MIN) continue;
        res = max(res, bucket_min[i] - bucket_max[pre]);
        pre = i;
    }
    return res;
}