#include <iostream>
#include <vector>

using namespace std;
int count = 0;

void mergeSort(vector<int> &vector_space, int start, int end);
void mergeANDcount(vector<int> &vector_space, int start, int end, int mid);

int main(){
    int n, x;
    vector<int> vector_space;

    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vector_space.push_back(x);
    }

    mergeSort(vector_space, 0, n -1);
    
    count = count % 524287 ;

    cout << count;
}

void mergeSort(vector<int> &vector_space, int start, int end){
    if(start != end){
        int mid = (start + end)/ 2;
        mergeSort(vector_space, start, mid);
        mergeSort(vector_space, mid + 1, end);
        mergeANDcount(vector_space, start, end, mid);
    }
}

void mergeANDcount(vector<int> &vector_space, int start, int end, int mid){
    vector<int> left(vector_space.begin() + start, vector_space.begin() + mid + 1), right(vector_space.begin() + mid + 1, vector_space.begin() + end + 1);
    int left_index = 0, right_index = 0, array_index = start, len_left = left.size(), len_right = right.size();

    while(left_index < len_left && right_index < len_right){
        if(left[left_index] <= right[right_index]){
            vector_space[array_index] = left[left_index];
            left_index += 1;
        }
        else{
            vector_space[array_index] = right[right_index];
            right_index += 1;
            count += (len_left - left_index); 
            count %= 524287;

        }
        array_index += 1;
    }


    while(left_index < len_left){
        vector_space[array_index] = left[left_index];
        left_index += 1;
        array_index += 1;
    }


    while(right_index < right_index){
        vector_space[array_index] = right[right_index];
        right_index += 1;
        array_index += 1;
    }
}