#include<iostream>


using namespace std;
int rail[11];
int path[11];
bool visited[11];
int N, M, K;
int mini = 21e8;

int getCost() {
    
    int cnt = 0;
    int idx = -1;
    int sum = 0;
    int totalSum = 0;
    while (cnt != K) {
        idx = (idx + 1) % N;
        sum += rail[path[idx]];
        if (sum > M) {
            ++cnt;
            totalSum += (sum-rail[path[idx]]);
            sum = rail[path[idx]];
        }
    }
    return totalSum;
}
void dfs(int deep) {
    if (deep == N) {
        mini = min(mini, getCost());
        return;
    }
    for (int a = 0; a < N; ++a) {
        if (visited[a] == 0) {
            path[deep] = a;
            visited[a] = 1;
            dfs(deep + 1);
            visited[a] = 0;
        }
    }
}
void solve() {
    for (int a = 0; a < N; ++a) {
        path[0] = a;
        visited[a] = 1;
        dfs(1);
        visited[a] = 0;
    }
    cout << mini<<"\n";
}

void input() {
    cin >> N >> M >> K;
    for (int a = 0; a < N; ++a) {
        cin >> rail[a];
    }
}
int main(int argc, char** argv)
{

  input();
  solve();
	return 0;
}
