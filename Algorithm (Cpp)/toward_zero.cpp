#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int minimum_sum(vector<int> &vectorSpace, int n, int sum);

int main(){
    int n, x, sum = 0;
    cin >> n;
    vector<int> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vectorSpace.push_back(x);
        sum += x;
    }
    cout << minimum_sum(vectorSpace, n, sum);
}

int minimum_sum(vector<int> &vectorSpace, int n, int sum){
    int arr[n + 1][2 * sum + 1];
    memset(arr, 0, sizeof(arr));
    arr[0][0] = 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < (2 * sum + 1);j ++){
            if(arr[i - 1][j] == 1) {
                arr[i][j] = 1;
                arr[i][j + 2 * vectorSpace[i - 1]] = 1;
            }
        }
    }
    for(int i = 0;i <= sum;i ++){
        if(arr[n][i + sum] == 1)
            return i;
    }
}