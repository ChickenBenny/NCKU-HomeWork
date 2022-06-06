#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

stack<set<string>> stack_space;
set<string>::iterator iter;

void PUSH();
void DUP();
void UNION();
void INTERSECT();
void ADD();

int main(){
    int n;
    string action;
    cin >> n;
    for(int i = 0;i < n;i ++){
        cin >> action;
        if(action == "PUSH")
            PUSH();
        else if(action == "DUP")
            DUP();
        else if(action == "UNION")
            UNION();
        else if(action == "INTERSECT")
            INTERSECT();
        else if(action == "ADD")
            ADD();
        cout << stack_space.top().size() - 1 << endl;
    }
    return 0;
}

void PUSH(){
    set<string> tmp;
    tmp.insert("{}");
    stack_space.push(tmp);
}

void DUP(){
    set<string> tmp_dup;
    tmp_dup = stack_space.top();
    stack_space.push(tmp_dup);
}

void UNION(){
    set<string> tmp_first, tmp_second, tmp_combine;
    tmp_first = stack_space.top();
    stack_space.pop();
    tmp_second = stack_space.top();
    stack_space.pop();
    set_union(tmp_first.begin(), tmp_first.end(), tmp_second.begin(), tmp_second.end(), inserter(tmp_combine, tmp_combine.begin()));
    stack_space.push(tmp_combine);
}

void INTERSECT(){
    set<string> tmp_first, tmp_second, tmp_combine;
    tmp_first = stack_space.top();
    stack_space.pop();
    tmp_second = stack_space.top();
    stack_space.pop();
    set_intersection(tmp_first.begin(), tmp_first.end(), tmp_second.begin(), tmp_second.end(), inserter(tmp_combine, tmp_combine.begin()));
    stack_space.push(tmp_combine);
}

void ADD(){
    set<string> tmp_first, tmp_second;
    string first = "{";
    tmp_first = stack_space.top();
    stack_space.pop();
    tmp_second = stack_space.top();
    stack_space.pop();
    for(iter = tmp_first.begin();iter != tmp_first.end();iter ++)
        first += *iter;
    first += "}";
    tmp_second.insert(first);
    stack_space.push(tmp_second);
}