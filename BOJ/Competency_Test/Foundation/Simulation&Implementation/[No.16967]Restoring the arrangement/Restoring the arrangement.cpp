#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int H, W, X, Y;
int arr[600][600];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);
    cin >> H >> W >> X >> Y;

    for (int a = 0; a < H + X; ++a) {
        for (int b = 0; b < W + Y; ++b) {
            cin >> arr[a][b];
        }
    }

    for (int a = 0; a <H; ++a) {
        for (int b =0; b < W; ++b) {
            arr[X + a][Y + b] -= arr[a][b];
        }
    }
    for (int a = 0; a < H; ++a) {
        for (int b = 0; b < W; ++b) {
            cout << arr[a][b] << " ";
        }
        cout << "\n";
    }
    return 0;

}
