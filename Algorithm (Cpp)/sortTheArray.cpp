#include <iostream>
#include <vector>

using namespace std;
vector<int> vectorSpace;

void quickSort(int start, int end);
int partition(int start, int end);

int main(){
    int n, x;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vectorSpace.push_back(x);
    }
    quickSort(0, n - 1);
    for(int i = 0;i < n;i ++)
        cout << vectorSpace[i] << " ";
    return 0;
}

void quickSort(int start, int end){
    if(start < end){
        int pivot = partition(start, end);
        quickSort(start, pivot - 1);
        quickSort(pivot + 1, end);
    }
}

int partition(int start, int end){
    int pviot = vectorSpace[end], j = start - 1, tmp;
    for(int i = start;i < end;i ++){
        if(vectorSpace[i] < pviot){
            j += 1;
            swap(vectorSpace[i], vectorSpace[j]);
        }
    }
    j += 1;
    swap(vectorSpace[j], vectorSpace[end]);
    return j;
}