#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M;
vector<int> frnd[4001];
bool check[4001][4001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> N >> M;
    int x, y;

    for (int a = 0; a < M; ++a) {
        cin >> x >> y;
        frnd[x].push_back(y);
        frnd[y].push_back(x);
        check[x][y] = 1;
        check[y][x] = 1;
    }
    int answer = -1;
    for (int a = 1; a <= N; ++a) {
        for (int b = 0; b < frnd[a].size(); ++b) {
            if (frnd[a][b] <= a)
                continue;
            else {
                int bb = frnd[a][b];
                for (int c = 0; c < frnd[bb].size(); ++c) {
                    if (frnd[bb][c] <= bb)
                        continue;
                    else{
                        int cc = frnd[bb][c];
                        if (check[a][cc]) {
                            if ((answer == -1) || (frnd[a].size() + frnd[bb].size() + frnd[cc].size() - 6 < answer)) {
                                answer = frnd[a].size() + frnd[bb].size() + frnd[cc].size() - 6;
                            }
                        }
                    }
                }
            }
                
        }
    }
    cout << answer;
    return 0;
}
