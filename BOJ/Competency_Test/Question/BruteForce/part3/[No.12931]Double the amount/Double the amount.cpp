#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, M;
int B[50];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt","r", stdin);

    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> B[a];
    }
    int answer = 0;
    while (1) {
        bool zero = 1;
        bool judge = 1;

        for (int a = 0; a < N; ++a) {
            if (B[a])
                zero = 0;

            if (B[a] % 2) {
                ++answer;
                judge = 0;
                B[a] -= 1;
            }
        }

        if (zero)
            break;

        if (judge) {
            for (int a = 0; a < N; ++a) {
                B[a] /= 2;
            }
            ++answer;
        }

    }
    cout << answer;

    return 0;

}
