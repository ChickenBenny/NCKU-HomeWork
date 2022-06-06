#include <iostream>
#include <cstring>
using namespace std;
 
const int maxn = 1005;
int n, bit[maxn][maxn], qx, qy, a[10005][2];
 
void update(int x, int y){
    while (x < maxn){
        int ty = y;
        while (ty < maxn){
            bit[x][ty]++;
            ty += ty & (-ty);
        }
        x += x & (-x);
    }
}
 
int query(int x, int y){
    int ret = 0;
    while (x){
        int ty = y;
        while (ty){
            ret += bit[x][ty];
            ty -= ty & (-ty);
        }
        x -= x & (-x);
    }
    return ret;
}
 
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        memset(bit, 0, sizeof(bit));
        cin >> a[i][0] >> a[i][1];
        update(a[i][0], a[i][1]);
    }
    for(int i = 0;i < n;i ++)
        cout << query(a[i][0] - 1, a[i][1] - 1) << " ";
    return 0;
}