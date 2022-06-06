#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class wine{
    public:
    int index, density;
};

bool cmp(wine a, wine b);
void binarySearch(vector<wine> &vectorSpace, int index, int target, int size);
int leftSearch(vector<wine> &vectorSpace, int location, int index, int target, int size);
int rightSearch(vector<wine> &vectorSpace, int location, int index, int target, int size);
int twosideSearch(vector<wine> &vectorSpace, int location, int index, int target, int size, int status);

int main(){
    int n, q, index, target;
    wine tmp;
    vector<wine> vectorSpace;
    cin >> n >> q;
    for(int i = 0;i < n;i ++){
        cin >> tmp.index >> tmp.density;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    for(int i = 0;i < q;i ++){
        cin >> index >> target;
        binarySearch(vectorSpace, index, target, n - 1);
    }
}

bool cmp(wine a, wine b){
    if(a.index < b.index)
        return true;
    else
        return false;
}

void binarySearch(vector<wine> &vectorSpace, int index, int target, int size){
    int left = 0, right = size, answer;
    if(index >= vectorSpace[right].index){
        answer = leftSearch(vectorSpace, right, index, target, size);
        cout << answer << endl;
    }
    else if(index <= vectorSpace[left].index){
        answer = rightSearch(vectorSpace, left, index, target, size);
        cout << answer << endl;
    }
    else{
        int mid, status;
        while(left <= right){
            mid = (left + right)/ 2;
            if(index > vectorSpace[mid].index)
                left = mid + 1;
            else if(index < vectorSpace[mid].index)
                right = mid - 1;
            else
                break;
        }
        if(index > vectorSpace[mid].index)
            status = 1;
        else if(index < vectorSpace[mid].index)
            status = -1;
        else
            status = 0;
        answer = twosideSearch(vectorSpace, mid, index, target, size, status);
        cout << answer << endl;
    }
}

int leftSearch(vector<wine> &vectorSpace, int location, int index, int target, int size){
    while(location >= 0){
        if(vectorSpace[location].density >= target)
            return vectorSpace[location].index;
        location -= 1;
    }
    return -1;
}

int rightSearch(vector<wine> &vectorSpace, int location, int index, int target, int size){
    while(location <= size){
        if(vectorSpace[location].density >= target)
            return vectorSpace[location].index;
        location += 1;
    }
    return -1;    
}

int twosideSearch(vector<wine> &vectorSpace, int location, int index, int target, int size, int status){
    int left = 0, right = 0;
    if(status == 0){
        if(vectorSpace[location].density >= target)
            return vectorSpace[location].index;
    }
    else if(status == 1){
        if((index - vectorSpace[location].index) <= (vectorSpace[location + 1].index - index)){
            if(vectorSpace[location].density >= target)
                return vectorSpace[location].index;
            left += 1;
        }
        else{
            if(vectorSpace[location + 1].density >= target)
                return vectorSpace[location + 1].index;
            right += 2;
        }
    }
    else{
        if((index - vectorSpace[location - 1].index) <= (vectorSpace[location].index - index)){
            if(vectorSpace[location - 1].density >= target)
                return vectorSpace[location - 1].index;
            left += 2;
        }
        else{
            if(vectorSpace[location].density >= target)
                return vectorSpace[location].index;
            right += 1;
        }
    }
    while((location + right) <= size && (location - left) >= 0){
        if((index - vectorSpace[location - left].index) <= (vectorSpace[location + right].index - index)){
            if(vectorSpace[location - left].density >= target)
                return vectorSpace[location - left].index;
            left += 1;
        }
        else{
            if(vectorSpace[location + right].density >= target)
                return vectorSpace[location + right].index;
            right += 1;            
        }
    }
    while((location + right) <= size){
        if(vectorSpace[location + right].density >= target)
            return vectorSpace[location + right].index;
        right += 1;
    }
    while((location - left) >= 0){
        if(vectorSpace[location - left].density >= target)
            return vectorSpace[location - left].index;
        left += 1;
    }
    return -1;
}