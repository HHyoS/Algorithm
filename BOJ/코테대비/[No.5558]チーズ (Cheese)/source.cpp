#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
char map[1005][1005];
bool visit[1005][1005];
int target[12][2];
int start[2];
int r, c, n, cnt;
int ly[] = { 1,-1,0,0 };
int lx[] = { 0,0,1,-1 };
struct Node{
    int y, x, mov_n;
};
bool isin(int y, int x) {
    if (y >= 1 && y <= r && x >= 1 && x <= c && map[y][x] != 'X')
        return true;
    else
        return false;
}
void find(int y, int x, int n) {
    queue <Node> q;
    q.push({ y,x,0 });
    visit[y][x] = true;
    while (!q.empty()) {
        Node t = q.front(); q.pop();
        // 도착했는지 확인
        if (t.y == target[n][0] && t.x == target[n][1]) {
            cnt += t.mov_n;
            start[0] = t.y;
            start[1] = t.x;
            break;
        }
        // 아니면 계속 돎
        for (int a = 0; a < 4; ++a) {
            int ny = t.y + ly[a];
            int nx = t.x + lx[a];
            if (isin(ny, nx) && !visit[ny][nx]) {
                q.push({ ny, nx, t.mov_n + 1 });
                visit[ny][nx] = true;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    
    cin >> r >> c >> n;
    
    for (int a = 1; a <= r; ++a) {
        for (int b = 1; b <= c; ++b) {
            cin >> map[a][b];
            if (map[a][b] >= '0' && map[a][b] <= '9') {
                target[map[a][b] - '0'][0] = a;
                target[map[a][b] - '0'][1] = b;
            }
            if (map[a][b] == 'S') { 
                start[0] = a;
                start[1] = b;
            }
        }
    }
    
    for (int a = 1; a <= n; ++a) {
        memset(visit, false, sizeof(visit));
        find(start[0], start[1], a);
    }
    cout << cnt;
}
