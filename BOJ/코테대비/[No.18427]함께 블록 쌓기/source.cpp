#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M, H;

vector<int> student[51];
vector<int> check;
int dp[51][1001];
int ans = 0;
void solve() {

    for (int a = 1; a <= N; ++a) {
        dp[a - 1][0] = 1;
        for (int b = 0; b < student[a].size(); ++b) {
            for (int c = 0; c <= H; ++c) {
                int height = student[a][b] + c;
                if (height <= H) {
                    dp[a][height] = (dp[a][height] + dp[a - 1][c]) % 10007;
                }
            }
        }
        for (int b = 0; b <= H; ++b) {
                dp[a][b] = (dp[a][b]+dp[a - 1][b])%10007;
        }
    }

    cout << dp[N][H];
    
}
void input() {
    cin >> N >> M >> H;

    cin.ignore();
    for (int a = 1; a <= N; ++a) {
        string temp;
        getline(cin, temp);
        int idx = 0;
        while (1) {
            int ret = temp.find(" ", idx);
            if (ret == -1) {
                string tmp = temp.substr(idx, temp.length() - idx + 1);
                int height = stoi(tmp);
                student[a].push_back(height);
                break;
            }
            string tmp = temp.substr(idx, ret - idx + 1);
            int height = stoi(tmp);
            student[a].push_back(height);
            idx = ret + 1;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    input();
    solve();
    return 0;

}
