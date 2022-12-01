#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef pair<int, int>P;
int n, k;
queue<P>q;
int visited[200001];
int dx[] = { 1,-1,2 };

void print(int cnt) {
    cout << cnt << "\n";
    stack<int>res;
    for (int i = k; ; i = visited[i]) {
        res.push(i);
        if (visited[i] == -1) {
            res.push(0);
            break;
        }
        if (visited[i] == -11)
            break;
    }
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
}

void bfs() {
    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (now == k)
            print(cnt);
        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 2)
                next = now * 2;
            else
                next = now + dx[i];
            if (next < 0 || next > 200000)
                continue;
            if (visited[next])
                continue;
            if (now == 0)
                visited[next] = -1;
            else
                visited[next] = now;
            q.push({ next, cnt + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    q.push({ n,0 });
    visited[n] = -11;
    bfs();
    return 0;
}
