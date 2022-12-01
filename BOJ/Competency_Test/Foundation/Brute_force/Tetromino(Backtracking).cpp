#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
vector<vector<int>> ar;
int best[4] = { 0 };
int mx = 0;
void dfs(int count, vector<vector<bool>> mp, int x, int y, int sum,vector<pair<int,int>> que) {
    ++count;
    mp[x][y] = false;
    sum += ar[x][y];
    que.push_back({ x,y });

    if (count == 4) {
        if (mx < sum) {
            mx = sum;
        }

        return;
    }
    vector<pair<int, int>> test;
    if (best[count - 1] <= sum) {
        best[count - 1] == sum;
        for (int i = 0; i < que.size(); ++i) {
            int a = que[i].first;
            int b = que[i].second;
            int big = 0;
            if (0 < a && a < ar.size()) {
                if (mp[a - 1][b] == true) {
                    if (count == 3) {
                        if (sum + ar[a - 1][b] > mx && ar[a - 1][b] > big) {
                            big = ar[a - 1][b];
                            test.clear();
                            test.push_back({ a - 1,b });
                        }
                    }
                    else {
                        if (ar[a - 1][b] > big) {
                            big = ar[a - 1][b];
                            test.clear();
                            test.push_back({ a - 1,b });
                        }
                        else if (ar[a - 1][b] == big)
                            test.push_back({ a - 1,b });
                    }
                }
            }
            if (0 <= a && a < ar.size() - 1) {
                if (mp[a + 1][b] == true) {
                    if (count == 3) {
                        if (sum + ar[a + 1][b] > mx && ar[a + 1][b] > big) {
                            big = ar[a + 1][b];
                            test.clear();
                            test.push_back({ a + 1,b });
                        }
                    }
                    else {
                        if (ar[a + 1][b] > big) {
                            big = ar[a + 1][b];
                            test.clear();
                            test.push_back({ a + 1,b });
                        }
                        else if (ar[a + 1][b] == big)
                            test.push_back({ a + 1,b });
                    }
                }
            }
            if (0 < b && b < ar[0].size()) {
                if (mp[a][b - 1] == true) {
                    if (count == 3) {
                        if (sum + ar[a][b - 1] > mx && ar[a][b - 1] > big) {
                            big = ar[a][b - 1];
                            test.clear();
                            test.push_back({ a ,b - 1 });
                        }
                    }
                    else {
                        if (ar[a][b - 1] > big) {
                            big = ar[a][b - 1];
                            test.clear();
                            test.push_back({ a,b - 1 });
                        }
                        else if (ar[a][b - 1] == big)
                            test.push_back({ a,b - 1 });
                    }
                }
            }
            if (0 <= b && b < ar[0].size() - 1) {
                if (mp[a][b + 1] == true) {
                    if (count == 3) {
                        if ((sum + ar[a][b + 1] > mx) && (ar[a][b + 1] > big)) {
                            big = ar[a][b + 1];
                            test.clear();
                            test.push_back({ a,b + 1 });
                        }
                    }
                    else {
                        if (ar[a][b + 1] > big) {
                            big = ar[a][b + 1];
                            test.clear();
                            test.push_back({ a, b + 1 });
                        }
                        else if (ar[a][b + 1] == big)
                            test.push_back({ a, b + 1 });
                    }
                }
            }
            for (int t = 0; t < test.size(); ++t) {
                dfs(count, mp, test[t].first, test[t].second, sum, que);
            }
        }
        test.clear();
    }
}
int main() {
    int x, y;
 //   freopen("input.txt", "r",stdin);
    cin >> x >> y;
    int v;
    vector<pair<int,int>> que;
    
    vector<vector<bool>> mp(x, vector<bool>(y, true));
    ar.assign(x, vector<int>(y, 0));
    int max = 0;
    for (int a = 0; a < x; ++a) {
        for (int b = 0; b < y; ++b) {
            cin >> v;
            ar[a][b] = v;
        }
    }
    sort(ar.begin(), ar.end());
    for (int a = 0; a < x; ++a) {
        for (int b = 0; b < y; ++b) {
                dfs(0, mp, a,b,0,que);
        }
    }
    printf("%d", mx);
    return 0;
}
