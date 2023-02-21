#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int x;
    int y;
};
int H,W,N;
int map[101][101];
vector<Node> v;


bool check(int x, int y, int h, int w) {
    int nx = x + h;
    int ny = y + w;
    for (int a = x; a < nx; ++a) {
        for (int b = y; b < ny; ++b) {
            if (map[a][b] == 1)
                return 0;
        }
    }
    return 1;
}

int findMax(int width, int height) {

    for (int b = 0; b < H; ++b) {
        for (int c = 0; c < W; ++c) {
            if (map[b][c] == 0 && b + height <= H && c + width <= W) {
                if (check(b, c, height, width)) {
                    return height * width;
                }
            }
        }
    }
    return 0;
}
int isPossible(int idx) {
    int maxi = 0;
    for (int a = idx; a < v.size(); ++a) {
        int width = v[a].y;
        int height = v[a].x;
        maxi = max(maxi, findMax(width,height));
    }
    return maxi;
}
void paint(int height, int width, int color) {
    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            map[h][w] = color;
        }
    }
}
int solve() {
    int maxi = 0;
    for (int a = 0; a < v.size(); ++a) {
        int width = v[a].y;
        int height = v[a].x;
        int ans = width * height;
        if (width > H && width > W) continue;
        if (height > H && height > W) continue;
        paint(height, width, 1);

        int result = isPossible((a/2)*2+2);
        paint(height, width, 0);
        if (result != 0) {
            maxi = max(maxi, ans + result);
        }
    }
    return maxi;
}
void input() {
    cin >> H >> W >> N;
    for (int n = 0; n < N; ++n) {
        int R, C;
        cin >> R >> C;
        v.push_back({ R,C });
        v.push_back({ C,R });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    freopen("input.txt", "r", stdin);
    start = clock();
    input();
    cout << solve()<<"\n";
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
