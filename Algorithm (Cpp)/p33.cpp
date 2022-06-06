#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class point{
public:
    int x, y;
};
bool escape(vector<vector<int>> &arr, vector<vector<bool>> &visit, int n, int m, point start, point end);
bool canmove(point current, int d);

int main(){
    int n, m, x;
    cin >> n >> m;
    point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    start.x -= 1, start.y -= 1, end.x -= 1, end.y -= 1;
    vector<vector<int>> arr;
    vector<vector<bool>> visit;
    for(int i = 0;i < n;i ++){
        vector<int> tmp;
        vector<bool> tmp_;
        for(int j = 0;j < m;j ++){
            cin >> x;
            tmp.push_back(x);
            tmp_.push_back(false);
        }
        arr.push_back(tmp);
        visit.push_back(tmp_);
    }
    if(escape(arr, visit, n, m, start, end) == true)
        cout << "Success!";
    else
        cout << "Fail!";
}

bool escape(vector<vector<int>> &arr, vector<vector<bool>> &visit, int n, int m, point start, point end){
    queue<point> path;
    point current, next;
    path.push(start);
    visit[current.x][current.y] = true;
    while(!path.empty()){
        current = path.front();
        path.pop();
        if(current.x == end.x && current.y == end.y)
            return true;
        if(current.x + 1 < n && arr[current.x + 1][current.y] == 1){
            next.x = current.x + 1, next.y = current.y;
            if(visit[next.x][next.y] == false){
                path.push(next);
                visit[next.x][next.y] = true;
            }
        }
        if(current.x - 1 >= 0 && arr[current.x - 1][current.y] == 1){
            next.x = current.x - 1, next.y = current.y;
            if(visit[next.x][next.y] == false){
                path.push(next);
                visit[next.x][next.y] = true;
            }
        }
        if(current.y + 1 < m && arr[current.x][current.y + 1] == 1){
            next.x = current.x, next.y = current.y + 1;
            if(visit[next.x][next.y] == false){
                path.push(next);
                visit[next.x][next.y] = true;
            }
        }
        if(current.y - 1 >= 0 && arr[current.x][current.y - 1] == 1){
            next.x = current.x, next.y = current.y - 1;
            if(visit[next.x][next.y] == false){
                path.push(next);
                visit[next.x][next.y] = true;
            }
        }
    }
    return false;
}