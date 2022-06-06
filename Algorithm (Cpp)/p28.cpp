#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void decrease_search(vector<int> &arr);

int main(){
    int n, x;
    vector<int> arr;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> x;
        arr.push_back(x);
    }
    decrease_search(arr);
}

void decrease_search(vector<int> &arr){
    vector<int> left(arr.size(), 1), right(arr.size(), 1);
    for(int i = 1;i < arr.size();i ++){
        for(int j = 0;j < i;j ++){
            if(arr[i] > arr[j] && left[i] < left[j] + 1)
                left[i] = left[j] + 1;
        }
    }
    for(int i = arr.size() - 2;i >= 0;i --){
        for(int j = arr.size() - 1;j > i;j --){
            if(arr[i] > arr[j] && right[i] < right[j] + 1)
                right[i] = right[j] + 1;
        }
    }
    int tmp , min = INT_MAX;
    for(int i = 1;i < arr.size();i ++){
        tmp = (i - (left[i] - 1)) + ((arr.size() - 1 - i) - (right[i] - 1));
        if(tmp < min)
            min = tmp;
    }
    cout << min;
}