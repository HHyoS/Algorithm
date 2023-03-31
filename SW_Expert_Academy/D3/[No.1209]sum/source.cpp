#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int S;
int arr[101][101];

int solve() {
    int maxi = -1;
    int LeftDownCross = 0;
    int RightDownCross = 0;
    for (int a = 0; a < S; ++a) {
        int rowSum = 0;
        int colSum = 0;
        for (int b = 0; b < S; ++b) {
            if (a == b) {
                LeftDownCross += arr[a][b];
            }
            if (a + b == S-1) {
                RightDownCross += arr[a][b];
            }
            rowSum += arr[a][b];
            colSum += arr[b][a];
        }
        maxi = max(maxi, max(rowSum, colSum));
    }
    maxi = max(maxi, max(LeftDownCross, RightDownCross));

    return maxi;
}
void input() {
    int T;
    S = 100;
    T = 10;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        for (int a = 0; a < S; ++a) {
            for (int b = 0; b < S; ++b) {
                cin >> arr[a][b];
            }
        }
        cout << "#"<<N<<" "<<solve() << "\n";
    }
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  //  freopen("input.txt", "r", stdin);

    input();
    return 0;
}
