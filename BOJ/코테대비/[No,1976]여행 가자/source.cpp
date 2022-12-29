7#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int map[201][201];
int path[1001];
int N, M;
int solve() {
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            for (int c = 1; c <= N; ++c) {
                if (map[a][b] == 1 && map[b][c] == 1) {
                    map[a][c] = 1;
                    map[c][a] = 1;
                }
            }
        }
    }

    for (int a = 0; a < M; ++a) {
        cin >> path[a];
    }
    for (int a = 0; a < M - 1; ++a) {
        if (map[path[a]][path[a + 1]] == 0)
            return 0;
    }
    return 1;
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            cin >> map[a][b];
            if (a == b)
                map[a][b] = 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen("input.txt", "r", stdin);


    input();
    if (solve()) {
        cout << "YES";
    }
    else 
        cout << "NO";
    
    return 0; 


}
