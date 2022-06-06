#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
class node{
public:
    int val;
    char key;
};

bool cmp(node a, node b);

int main(){
    string input;
    char tmp, key;
    int val;
    map<char, int> mapSpace;
    map<char, int>::iterator iter;
    vector<node> vectorSpace;
    vector<node>::iterator iterVector;
    cin >> input;
    for(int i = 0;i < input.size();i ++){
        tmp = input[i];
        iter = mapSpace.find(tmp);
        if(iter != mapSpace.end()){
            iter->second += 1;
        }
        else
            mapSpace.insert(pair<char, int>(tmp, 1));
    }
    for(iter = mapSpace.begin();iter != mapSpace.end();iter ++){
        node tmp;
        tmp.val = iter->second;
        tmp.key = iter-> first;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    for(iterVector = vectorSpace.begin();iterVector != vectorSpace.end();iterVector ++){
        for(int i = 0;i < iterVector->val;i ++)
            cout << iterVector->key;
    }
}

bool cmp(node a, node b){
    if(a.val > b.val)
        return true;
    else if(a.val == b.val && a.key < b.key)
        return true;
    else
        return false;
}