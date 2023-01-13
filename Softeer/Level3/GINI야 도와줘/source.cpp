#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Location {
    int x;
    int y;
};
int R, C;
char map[51][51];
Location home;
Location taebum;
queue<Location> human;
queue<Location> rain;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int visited[51][51];


int rainOut(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return 0;
    if (map[x][y] == '*' || map[x][y] == 'X' || map[x][y] == 'H')
        return 0;

    return 1;
}

int humanOut(int x, int y) {

    if (x < 0 || x >= R || y < 0 || y >= C) return 0;
    if (map[x][y] == '*' || map[x][y] == 'X') return 0;
    if (visited[x][y] == 1) return 0;
    if (map[x][y] == 'H') return 2;
    return 1;
}
void rainGo() {

    int size = rain.size();
    for (int a = 0; a < size; ++a) {
        Location now = rain.front();
        rain.pop();
        for (int b = 0; b < 4; ++b) {
            int x = now.x + mov[b][0];
            int y = now.y + mov[b][1];
            if (rainOut(x,y)==1) {
                map[x][y] = '*';
                rain.push({ x,y });
            }
        }
    }
}
int humanGo() {

    int size = human.size();
    for (int a = 0; a < size; ++a) {
        Location now = human.front();
        human.pop();
        for (int b = 0; b < 4; ++b) {
            int x = now.x + mov[b][0];
            int y = now.y + mov[b][1];

            int result = humanOut(x, y);
            if(result == 1){
                visited[x][y] = 1;
                human.push({ x,y });
            }
            else if (result == 2) {
                return 1;
            }
        }
    }
    return 0;
}

int solve() {
    int ans = -1;
    int time = 1;
    while (!human.empty()) {
        rainGo();
        if (humanGo() == 1) {
            return time;
        }
        ++time;

    }
    return ans;

}
void input() {
    cin >> R >> C;
    for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 'H') {
                home = { a,b };
            }
            else if (map[a][b] == 'W') {
                map[a][b] = '.';
                taebum = { a,b };
            }
            else if (map[a][b] == '*') {
                rain.push({ a,b });
            }
        }
    }
    visited[taebum.x][taebum.y] = 1;
    human.push(taebum);
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
    int result = solve();
    if (result == -1) {
        cout << "FAIL";
    }
    else
        cout << result;
	return 0;
}
