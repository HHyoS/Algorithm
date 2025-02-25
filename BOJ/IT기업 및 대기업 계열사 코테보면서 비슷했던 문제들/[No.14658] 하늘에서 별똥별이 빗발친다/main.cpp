#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/14658
    문제 설명 : 
      */



struct star {
    int x;
    int y;
};
vector<star> stars;
vector<int> xs; // x 좌표에 있는 별들
vector<int> ys; // y 좌표에 있는 별들
int N, M, L, K;

void Solve() {
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int ans = 0;
    for (int a = 0; a < xs.size(); ++a) {
        for (int b = 0; b < ys.size(); ++b) {
            int cnt = 0;
            for (int c = 0; c < stars.size(); ++c) {
                int sx = xs[a];
                int sy = ys[b];
                int ex = sx + L;
                int ey = sy + L;

                if (stars[c].x < sx || stars[c].x > ex)
                    continue;

                if (stars[c].y < sy || stars[c].y > ey)
                    continue;

                ++cnt;
            }
            ans = max(ans, cnt);
        }
    }
    cout << K - ans;
}


void Input() {
    cin >> N >> M >> L >> K;
    for (int a = 0; a < K; ++a) {
        int x, y;
        cin >> x >> y;
        stars.push_back({ x, y });
        xs.push_back(x);
        ys.push_back(y);
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
