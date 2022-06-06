#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
class wineNode{
    public:
    string name;
    int count;
};
bool cmp(wineNode a, wineNode b);

int main(){
    int n, k, tmp;
    cin >> n >> k;
    string wineName;
    map<string, int> mapSpace;
    map<string, int>:: iterator iter;
    vector<wineNode> vectorSpace;
    for(int i = 0;i < n;i ++){
        cin >> wineName;
        if(i > 0){
            iter = mapSpace.find(wineName);
            if(iter != mapSpace.end()){
                iter->second += 1;
            }
            else{
                tmp = 1;
                mapSpace.insert(pair<string, int>(wineName, tmp));
            }
        }
        else{
            tmp = 1;
            mapSpace.insert(pair<string, int>(wineName, tmp));
        }
    }
    wineNode tmpNode;
    for(iter = mapSpace.begin();iter != mapSpace.end();iter ++){
        tmpNode.name = iter->first;
        tmpNode.count = iter->second;
        vectorSpace.push_back(tmpNode);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    cout << vectorSpace[k - 1].name;
}

bool cmp(wineNode a, wineNode b){
    if(a.count > b.count)
        return true;
    else if(a.count == b.count){
        if(strncasecmp(a.name.c_str(), b.name.c_str(), a.name.length()) < 0){
            return true;
        }
        else if(strncasecmp(a.name.c_str(), b.name.c_str(), a.name.length()) == 0){
            if(a.name.length() < b.name.length())
                return true;
            else
                return false;
        }
    }
    else
        return false;
}