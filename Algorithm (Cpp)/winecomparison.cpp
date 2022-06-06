#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<int> vectorSpace;
    multiset<int> setSpace;
    multiset<int>:: iterator iter;
    for(int i = 0;i < n;i ++){
        cin >> x;
        vectorSpace.push_back(x);
        if(i < m)
            setSpace.insert(x);
    }
    iter = next(setSpace.begin(), k - 1);
    cout << *iter << " ";
    for(int i = m;i < n;i ++){
        setSpace.insert(vectorSpace[i]);
        if(vectorSpace[i] < *iter)
            -- iter;
        if(vectorSpace[i - m] <= *iter)
            ++ iter;
        setSpace.erase(setSpace.find(vectorSpace[i - m]));
        cout << *iter << " ";
    }
}