#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int N;
int arr[10][10];
int maxiNum = 0;
void solve() {
    arr[0][0] = 1;
    for (int a = 1; a < N; ++a) {
        arr[a][0] = 1;
        for (int b = 1; b < a; ++b) {
            arr[a][b] = arr[a - 1][b - 1] + arr[a - 1][b];
        }
        arr[a][a] = 1;
    }

}
void print() {
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b <= a; ++b) {
            cout << arr[a][b] << " ";
        }
        cout << "\n";
    }
}
void input() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "#" << t << "\n";
        if (maxiNum >= N)
            print();
        else {
            solve();
            print();
            maxiNum = N;
        }
    }
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    return 0;
}
