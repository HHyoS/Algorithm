#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int x;
    int y;
};
int mini = 21e8;
char map[27][27];
vector<Node> location;
int total;
int N, M;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 순서대로 상,우,하,좌 
bool visited[27][27];
char command[5] = { "^>v<" };
char startArrow;
Node start;
string ans;
bool check(int x, int y) { // 직진이 가능한지 맵의 정보를 탐색하는 함수
    if (x <= 0 || x > N || y <= 0 || y > M) return 0;
    if (map[x][y] == '.') return 0;
    if (visited[x][y] == 1) return 0;

    return 1;
}
bool go(int x, int y,int arrow) { // 직진하는 함수
    for (int a = 1; a <= 2; ++a) {
        int nx = x + mov[arrow][0] * a;
        int ny = y + mov[arrow][1] * a;
        if (!check(nx, ny))
            return 0;
    }
    return 1;
}

void paint(int x, int y, int arrow, int color) { // 명령어로 지나간 위치를 모두 방문 / 방문취소하는 함수
    for (int a = 1; a <= 2; ++a) {
        int nx = x + mov[arrow][0] * a;
        int ny = y + mov[arrow][1] * a;
        visited[nx][ny] = color;
    }
}
void dfs(int x, int y, int arrow, string path, int cnt) {
    if (path.length() >= mini) // 이미 구한것보다 길어질것같다면 스킵
        return;
    if (total == cnt) { // 모든 경로에 대해 탐색했다면 현재 경로가 최단 명령어
        mini = path.length(); 
        ans = path;
        return;
    }

    if (go(x, y, arrow)) {
        paint(x, y, arrow,1);
        dfs(x + mov[arrow][0] * 2, y + mov[arrow][1] * 2, arrow, path + "A", cnt + 2);
        paint(x, y, arrow, 0);
    }
    for (int a = 1; a <= 3; a += 2) {
        int nArrow = (arrow + a) % 4;
        if (go(x, y, nArrow)) {
            paint(x, y, nArrow, 1);
            string addWord;
            if (a == 1)
                addWord = "RA";
            else
                addWord = "LA";

            dfs(x + mov[nArrow][0] * 2, y + mov[nArrow][1] * 2, nArrow, path + addWord, cnt + 2);
            paint(x, y, nArrow, 0);
        }
    }
}
void solve() {
  
    for (int a = 0; a < location.size(); ++a) { // 로봇이 이동한 경로를 시작위치로 하는 탐색 실시
        Node now = location[a];
        visited[now.x][now.y] = 1; // 
        for (int b = 0; b < 4; ++b) { // 상,하, 좌,우 방향을 설정하고 출발
            int before = mini;
            dfs(now.x, now.y,b,"",1);
            int after = mini;
            if (before != after) { // 탐색을 진행한 이전 / 이후의 mini값이 다르다면 최단 명령어가 갱신된것이으로 
              // 현재 위치 + 시작 방향을 저장
                startArrow = command[b];
                start = now;
            }
        }
        visited[now.x][now.y] = 0;
    }
    cout << start.x << " " << start.y << "\n" << startArrow << "\n" << ans;
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= M; ++b) {
            cin >> map[a][b];
            if (map[a][b] == '#') {
                ++total;
                location.push_back({ a,b });
            }
        }
    }
}
int main(int argc, char** argv)
{

    input();
    solve();
	return 0;
}
