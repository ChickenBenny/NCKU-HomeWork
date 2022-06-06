#include <iostream>
#include <vector>

using namespace std;
vector<int> minHeap;

void heapSort(int length);
void minHeapify(int index, int length);

int main(){
    int n, x;
    cin >> n;
    minHeap.push_back(0);
    for(int i = 1;i <= n;i ++){
        cin >> x;
        minHeap.push_back(x);
    }
    heapSort(n);
    for(int i = 1;i <= n;i ++)
        cout << minHeap[i] << " ";
    return 0;
}

void heapSort(int length){
    for(int i = length/ 2;i >= 1;i --){
        minHeapify(i, length);
    }
}

void minHeapify(int i, int length){
    int left = 2 * i, right = 2 * i + 1, smallest = i;
    if(left <= length && minHeap[left] < minHeap[i])
        smallest = left;
    
    if(right <= length && minHeap[right] < minHeap[smallest])
        smallest = right;

    if(smallest != i){
        swap(minHeap[i], minHeap[smallest]);
        minHeapify(smallest, length);
    }
}