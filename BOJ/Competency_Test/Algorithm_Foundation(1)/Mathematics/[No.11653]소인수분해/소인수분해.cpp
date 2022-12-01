#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    cin >> N;

    while (N != 1) {
        for (int a = 2; a <= N; ++a) {
            if (N % a == 0) {
                cout << a << "\n";
                N = N / a;
                break;
            }
        }
    }

    return 0;
}

