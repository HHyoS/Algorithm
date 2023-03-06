#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;
  

struct Node {
    int x;
    int y;
};
int N, K;

vector<Node> info[21];
int ans = 21e8;

int getArea(Node minXY, Node maxXY) {
    return (maxXY.x - minXY.x) * (maxXY.y - minXY.y);
}
void dfs(int color, Node minXY, Node maxXY) {
    int nowArea = getArea(minXY, maxXY);
    if (nowArea >= ans)
        return;
    
    if (color > K) {
        ans = nowArea;
        return;
    }
    for (int a = 0; a < info[color].size(); ++a) {
        dfs(color + 1, { min(minXY.x,info[color][a].x),min(minXY.y,info[color][a].y) }, { max(maxXY.x,info[color][a].x),max(maxXY.y,info[color][a].y) });
    }

}
void solve() {

    dfs(1, { 1001,1001 }, { -1001, -1001 });
    cout << ans << "\n";
}
void input() {
    cin >> N >> K;
    for (int a = 0; a < N; ++a) {
        int x, y, color;
        cin >> x >> y >> color;
        info[color].push_back({ x,y });
    }
}
int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
	return 0;
}
