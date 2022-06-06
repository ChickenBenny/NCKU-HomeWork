#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class node{
  public:
  int val;
  bool type;
};
bool cmp(node a, node b);
void RussianDoll(vector<node> &vectorSpace);

int main(){
  int n, x;
  node tmp;
  cin >> n;
  vector<node> vectorSpace;
  for(int i = 0;i < n;i ++){
    cin >> tmp.val;
    tmp.type = true;
    vectorSpace.push_back(tmp);
  }
  sort(vectorSpace.begin(), vectorSpace.end(), cmp);
  RussianDoll(vectorSpace);
}

bool cmp(node a, node b){
  if(a.val < b.val)
    return true;
  else
    return false;
}

void RussianDoll(vector<node> &vectorSpace){
  vector<vector<int>> answer;
  vector<int>::iterator iter;
  vector<vector<int>>::iterator iter1;
  vector<node>::iterator iter2;
  int count = 0;
  while(count < vectorSpace.size()){
    int tmpVal;
    vector<int> tmp;
    for(iter2 = vectorSpace.begin();iter2 != vectorSpace.end();iter2 ++){
      if((*iter2).type == true){
        tmpVal = (*iter2).val;
        (*iter2).type = false;
        tmp.push_back(tmpVal); 
        count += 1;
        break;
      }
    }
    for(;iter2 != vectorSpace.end();iter2 ++){
      if((*iter2).type == true && (*iter2).val > tmpVal){
        tmpVal = (*iter2).val;
        (*iter2).type = false;
        tmp.push_back(tmpVal); 
        count += 1;
        break;
      }
    }
    answer.push_back(tmp);
  }
  for(iter1 = answer.begin();iter1 != answer.end();iter1 ++){
    for(iter = (*iter1).begin();iter != (*iter1).end();iter ++){
      cout << *iter << " ";
    }
    cout << endl;
  }
}