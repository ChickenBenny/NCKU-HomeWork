#include <iostream>
 
using namespace std;
 
void maxheapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printAll(int arr[], int n);

 
int main(){
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    
 
    heapSort(arr, n);    
    printAll(arr, n);
}

void maxheapify(int arr[], int n, int i){
    int mx = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;    
    if (l < n && arr[l] > arr[mx])
        mx = l; 
    if (r < n && arr[r] > arr[mx])
        mx = r;
    if (mx != i) {
        swap(arr[i], arr[mx]);
        maxheapify(arr, n, mx);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);

    for (int i=0; i<n; ++i){
        cout << arr[i] << " ";

    }
    cout << "\n";
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}

void printAll(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}