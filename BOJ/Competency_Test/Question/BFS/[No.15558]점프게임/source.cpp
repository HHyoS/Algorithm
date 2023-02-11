#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    int position;
    int idx;
};
string line[2];
bool visited[2][100001];
int N, K;
queue<Node> que;

int solve() {
    visited[0][0] = 1;
    que.push({ 0,0 });
    int time = 0;
    while (!que.empty()) {
        
        int size = que.size();

        for (int s = 0; s < size; ++s) {
            Node now = que.front();
            que.pop();

            if (now.idx < time) continue;
            
            if (now.idx + K >= N) {
                return 1;
            }
            
            int nextPosition = (now.position + 1) % 2;
            if (line[nextPosition][now.idx + K] == '1' && visited[nextPosition][now.idx+K] == 0){
                visited[nextPosition][now.idx+K] = 1;
                que.push({ nextPosition,now.idx + K });
            }
            if (line[now.position][now.idx + 1] == '1' && visited[now.position][now.idx+1] == 0) {
                visited[now.position][now.idx + 1] =1;
                que.push({ now.position,now.idx+1 });
            }
            if (now.idx - 1 > time && line[now.position][now.idx - 1] == '1' && visited[now.position][now.idx-1] == 0) {
                visited[now.position][now.idx - 1] = 1;
                que.push({ now.position,now.idx - 1 });
            }
        }
        ++time;
    }
    return 0;
}
void input() {
    cin >> N >> K >> line[0] >> line[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    cout << solve();
    return 0;
}
