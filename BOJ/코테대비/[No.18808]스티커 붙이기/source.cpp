#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
struct Node {
    int row;
    int col;
};
int block[101][41][41];
int map[41][41];
int temp[41][41];
Node memo[101];

void makeBlock(int index, int turn) {
    int row = memo[index].row;
    int col = memo[index].col;
    int tmp[41][41] = { 0 };
    if (turn % 2) {
        for (int a = 0; a < row; ++a) {
            for (int b = 0; b < col; ++b) {
                tmp[b][row - 1 - a] = temp[a][b];
            }
        }
        memset(temp, 0, sizeof(temp));
        for (int a = 0; a < col; ++a) {
            for (int b = 0; b < row; ++b) {
                temp[a][b] = tmp[a][b];
            }
        }
    }
    else {
        if (turn == 0)
            return;
        else {
            for (int a = 0; a < col; ++a) {
                for (int b = 0; b < row; ++b) {
                    tmp[b][col - 1 - a] = temp[a][b];
                }
            }

            memset(temp, 0, sizeof(temp));
            for (int a = 0; a < row; ++a) {
                for (int b = 0; b < col; ++b) {
                    temp[a][b] = tmp[a][b];
                }
            }
        }
    }
}

bool isOk(int x, int y,int row, int col) {
    if (x + row > N || y + col > M) return 0;
    for (int a = 0; a < row; ++a) {
        for (int b = 0; b < col; ++b) {
            if (temp[a][b] == 1 && map[x + a][y+b] == 1)
                return 0;
        }
    }
    for (int a = 0; a < row; ++a) {
        for (int b = 0; b < col; ++b) {
            if (temp[a][b] == 1)
                map[x + a][y+b] = 1;
        }
    }
    return 1;
}
bool go(int row, int col) {
    
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            if (isOk(a, b,row,col)) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   // freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;

    for (int a = 0; a < K; ++a) {
        int row, col;
        cin >> row >> col;
        memo[a] = { row,col };
        for (int b = 0; b < row; ++b) {
            for (int c = 0; c < col; ++c) {
                cin >> block[a][b][c];
            }
        }
    }
    for (int a = 0; a < K; ++a) {
        memcpy(temp, block[a], sizeof(block[a]));
        for (int b = 0; b < 4; ++b) {
            makeBlock(a, b);
            int row, col;
            if (b % 2) {
                row = memo[a].col;
                col = memo[a].row;
            }
            else {
                row = memo[a].row;
                col = memo[a].col;
            }
            if (go(row, col))
                break;
        }

    }
    int ans = 0;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            if (map[a][b] == 1) {
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;

}
