#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int number[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,1,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
int light[10] = { 6,2,5,5,4,5,6,4,7,6 };
int T;
int solve(string A, string B) {
    int ans = 0;
    for (int a = 0; a < 5; ++a) {
        if (A[a] == B[a]) continue;
        int numA = A[a] - '0';
        int numB = B[a] - '0';
        if (A[a] == 'q') ans += light[B[a] - '0'];
        else if (B[a] == 'q') ans += light[A[a] - '0'];
        else {
            int numA = A[a] - '0';
            int numB = B[a] - '0';
            for (int b = 0; b < 7; ++b) {
                if (number[numA][b] != number[numB][b]) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

void input() {
    cin >> T;
    for (int a = 0; a < T; ++a) {
        string A, B;
        cin >> A >> B;
        int need = 5 - A.length();
        for (int b = 0; b < need; ++b) {
            A = "q" + A;
        }
        need = 5 - B.length();
        for (int b = 0; b < need; ++b) {
            B = "q" + B;
        }
        cout << solve(A, B) << "\n";;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    input();
    return 0;
}
