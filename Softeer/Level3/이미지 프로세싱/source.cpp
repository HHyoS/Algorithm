#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct Node {
    int x;
    int y;
};
int H, W;
int map[129][129];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<Node> que;


void bfs(int x,int y,int originColor, int color) {
    que.push({ x,y });
    map[x][y] = color;
    while (!que.empty()) {
        Node now = que.front();
		que.pop();
        for (int a = 0; a < 4; ++a) {
            int nx = now.x + mov[a][0];
            int ny = now.y + mov[a][1];

            if (nx <= 0 || nx > H || ny <= 0 || ny > W) continue;
            if (map[nx][ny] != originColor) continue;

            map[nx][ny] = color;
            que.push({ nx,ny });
        }
    }
}
void input() {
    cin >> H >> W;
    for (int a = 1; a <= H; ++a) {
        for (int b = 1; b <= W; ++b) {
            cin >> map[a][b];
        }
    }
    int Q;
    cin >> Q;
    for (int a = 0; a < Q; ++a) {
        int x, y;
        int color;
        cin >> x >> y >> color;
        int originColor = map[x][y];
        if(originColor != color)
            bfs(x, y, originColor, color);
    }
}

void print() {
    for (int a = 1; a <= H; ++a) {
        for (int b = 1; b <= W; ++b) {
            cout << map[a][b] << " ";
        }
        cout << "\n";
    }
}
int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	input();
	print();
	return 0;
}
