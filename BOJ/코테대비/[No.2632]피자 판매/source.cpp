#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


int T;
int N, M;
int aPizza[1001];
int bPizza[1001];

int aMemo[1001][1002];
int bMemo[1001][1002];


vector<int> aSize;
vector<int> bSize;
int ans = 0;
void init() {

    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a > 1 && b == N) continue;
            int idx = a + b - 1;
            if (idx > N) {
                idx -= N;
            }
            aMemo[a][b] = aMemo[a][b - 1] + aPizza[idx];
            if (aMemo[a][b] == T)
                ++ans;
            else if(aMemo[a][b] < T)
                aSize.push_back(aMemo[a][b]);
        }
    }
    for (int a = 1; a <= M; ++a) {
        for (int b = 1; b <= M; ++b) {
            if (a > 1 && b == M) continue;
            int idx = a + b - 1;
            if (idx > M) {
                idx -= M;
            }
            bMemo[a][b] = bMemo[a][b-1] + bPizza[idx];
            if (bMemo[a][b] == T)
                ++ans;
            else if(bMemo[a][b] < T)
                bSize.push_back(bMemo[a][b]);
        }
    }
    sort(aSize.begin(), aSize.end());
    sort(bSize.begin(), bSize.end());
}

void getAnswer() {

    for (int a = 0; a < aSize.size(); ++a) {
        int low = lower_bound(bSize.begin(), bSize.end(), T - aSize[a]) - bSize.begin();
        int high = upper_bound(bSize.begin(), bSize.end(), T - aSize[a]) - bSize.begin();
        ans += (high - low);
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    cin >> T;

    cin >> N >> M;

    for (int a = 1; a <= N; ++a) {
        cin >> aPizza[a];
    }
    for (int b = 1; b <= M; ++b) {
        cin >> bPizza[b];
    }

    init();

    getAnswer();

    cout << ans;

    return 0;

}
