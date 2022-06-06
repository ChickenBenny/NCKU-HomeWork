#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void maxium_subarray(vector<int> &arr, int n);

int main(){
    int n, x;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i ++){
        cin >> x;
        arr.push_back(x);
    }
    maxium_subarray(arr, n);
}

void maxium_subarray(vector<int> &arr, int n){
    int end, start, max = INT_MIN, tmp = 0;
    for(int i = 0;i < n;i ++){
        tmp += arr[i];
        if(tmp > max){
            max = tmp;
            end = i;
        }
        if(tmp < 0)
            tmp = 0;
    }
    tmp = max;
    for(int i = end;i >= 0;i --){
        tmp -= arr[i];
        if(tmp == 0){
            start = i;
        }
    }
    cout << max << " " << start + 1 << " " << end + 1;
}