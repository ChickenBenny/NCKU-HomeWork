#include <iostream>

void insertionSort(int unsort[], int length);

int main(){
    int unsort[10];
    for(int i = 0;i < 10;i ++)
        std::cin >> unsort[i];
    insertionSort(unsort, 10);
    for(int i = 0;i < 10;i ++)
        std::cout << unsort[i] << " ";
    std::cout<< std::endl;
}

void insertionSort(int unsort[], int length){
    int key, tmp, i, j;
    for(i = 1;i < length;i ++){
        key = unsort[i];
        for(j = i -1;j >= 0 && unsort[j] > key;j --){
            unsort[j + 1] = unsort[j];
        }
        unsort[j + 1] = key;
    }
}