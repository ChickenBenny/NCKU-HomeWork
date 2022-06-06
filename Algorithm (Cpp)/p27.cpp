#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_two_subarray(vector<int> &arr);

int main(){
    int n, x;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i ++){
        cin >> x;
        arr.push_back(x);
    }
    cout << find_two_subarray(arr);
}

int find_two_subarray(vector<int> &arr){
    vector<int> left(arr.size(), 0), right(arr.size(), 0);
    int n = arr.size(), prev_max = arr[0], now_max = arr[0];
    left[0] = arr[0];
    for(int i = 1;i < n;i ++){
        prev_max = max(prev_max + arr[i], arr[i]);
        now_max = max(now_max, prev_max);
        left[i] = now_max;
    }
    right[n - 1] = arr[n - 1];
    prev_max = arr[n - 1], now_max = arr[n  - 1];
    for(int i = n - 2;i >= 0;i --){
        prev_max = max(prev_max + arr[i], arr[i]);
        now_max = max(now_max, prev_max);
        right[i] = now_max;
    }
    int answer = INT_MIN;
    for(int i = 0;i < n - 1;i ++){
        answer = max(answer, left[i] + right[i + 1]);
    }
    return answer;
}