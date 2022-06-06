#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &unsort_array, int start, int end);
void merge(vector<int> &unsort_array, int start, int end, int mid);

int main(){
    std::vector<int> unsort_array;
    int length, x;
    cin >> length;
    for(int i = 0;i < length;i ++){
        cin >> x;
        unsort_array.push_back(x);
    }
    mergeSort(unsort_array, 0, unsort_array.size() - 1);
    for(int i = 0;i < length;i ++)
        cout << unsort_array[i];
    return 0;
}

void mergeSort(vector<int> &unsort_array, int start, int end){
    if(start < end){
        int mid = (start + end)/ 2;
        mergeSort(unsort_array, start, mid);
        mergeSort(unsort_array, mid + 1, end);
        merge(unsort_array, start, end, mid);
    }
}

void merge(vector<int> &unsort_array, int start, int end, int mid){
    vector<int> left(unsort_array.begin() + start, unsort_array.begin() + mid + 1), right(unsort_array.begin() + mid + 1, unsort_array.begin() + end + 1);
    int left_index = 0, right_index = 0, array_index = start, len_left = left.size(), len_right = right.size();
    while(left_index < len_left && right_index < len_right){
        if(left[left_index] < right[right_index]){
            unsort_array[array_index] = left[left_index];
            left_index += 1;
        }
        else{
            unsort_array[array_index] = right[right_index];
            right_index += 1;
        }
        array_index += 1;
    }
    while(left_index < len_left){
        unsort_array[array_index] = left[left_index];
        left_index += 1;
        array_index += 1;
    }
    while(right_index < right_index){
        unsort_array[array_index] = right[right_index];
        right_index += 1;
        array_index += 1;
    }

}