#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N;
vector<int> arr[100001];
int answer[100001];
int idx = 0;
bool check[100001];


void dfs(int num) {
    if (idx == N) {
        cout << "1";
        exit(0);
    }
    else {
        for (int a = 0; a < arr[num].size(); ++a) {
            if (!check[arr[num][a]] && (answer[idx] == arr[num][a])) {
                check[arr[num][a]] = 1;
                idx += 1;
                dfs(arr[num][a]);
                a = -1;
            }
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);

    cin >> N;
    int x, y;
    for (int a = 1; a < N; ++a) {
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    arr[0].push_back(1);
    for (int a = 0; a < N; ++a) {
        cin >> answer[a];
    }

    check[0] = 1;
    dfs(0);
    cout << "0";
    return 0;
}
