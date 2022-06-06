#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class node{
    public:
    float percentage;
    string name;
};
bool cmp(node a, node b);

int main(){
    int n, k, lime, sugar, base;
    float percentage;
    node tmp;
    vector<node> vectorSpace;
    string wine;
    cin >> n >> k;
    for(int i = 0;i < n;i ++){
        cin >> lime >> sugar >> base >> wine;
        percentage = (float)base/((float)base + lime + sugar);
        tmp.percentage = percentage;
        tmp.name = wine;
        vectorSpace.push_back(tmp);
    }
    sort(vectorSpace.begin(), vectorSpace.end(), cmp);
    cout << vectorSpace[k - 1].name;
}

bool cmp(node a, node b){
    if(a.percentage > b.percentage)
        return true;
    else 
        return false;
}