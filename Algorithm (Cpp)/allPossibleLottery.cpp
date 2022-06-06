#include <iostream>
#include <vector>
#include <set>

using namespace std;

void combination(vector<int> &vectorSpace, bool check[], int limit, int start, int count, int max);

int main(){
    int k, x, count = 0;
    cin >> k;
    set<int> setSpace;
    set<int>:: iterator iter;
    vector<int> vectorSpace;
    for(int i = 0;i < k;i ++){
        cin >> x;
        setSpace.insert(x);
    }
    bool check[setSpace.size()];
    for(iter = setSpace.begin();iter != setSpace.end();iter ++){
        vectorSpace.push_back(*iter);
        check[count] = false;
        count += 1;
    }
    combination(vectorSpace, check, 6, 0, 1, vectorSpace.size());
    return 0;
}

void combination(vector<int> &vectorSpace, bool check[], int limit, int start, int count, int max){
    if(count > limit)
        return;
    if(start == max)
        return;
    check[start] = true;
    if(count == limit){
        for(int i = 0;i < max;i ++){
            if(check[i] == 1)
                cout << vectorSpace[i] << " ";
        }
        cout << "\n";
    }
    combination(vectorSpace, check, limit, start + 1, count + 1, max);
    check[start] = false;
    combination(vectorSpace, check, limit, start + 1, count, max);
}