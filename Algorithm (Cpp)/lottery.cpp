#include <iostream>
#include <vector>
#include <set>

using namespace std;

void combination(vector<int> &vector_space, bool check[], int limitLength, int count, int index, int max);

int main(){
    int k, x;
    cin >> k;

    set<int> lottery_space;
    set<int>:: iterator iter;
    for(int i = 0;i < k;i ++){
        cin >> x;
        lottery_space.insert(x);
    }
    
    vector<int> vector_space;
    for(iter = lottery_space.begin();iter != lottery_space.end();iter ++){
        vector_space.push_back(*iter);
    }
    bool check[lottery_space.size()];

    combination(vector_space, check, 6, 0, 0, lottery_space.size());
    return 0;
}

void combination(vector<int> &vector_space, bool check[], int limitLength, int count, int index, int max){
    if(count > limitLength)
        return;
    else if(count == limitLength){
        for(int i = 0;i < max;i++){
            if(check[i] == true)
                cout << vector_space[i] << " ";
        }
        cout << "\n";
    }
    if(index == max)
        return;
    check[index] = true;
    combination(vector_space, check, limitLength, count + 1, index + 1, max);
    check[index] = false;
    combination(vector_space, check, limitLength, count, index + 1, max);
}