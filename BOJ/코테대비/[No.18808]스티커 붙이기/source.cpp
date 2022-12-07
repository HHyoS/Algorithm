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
Node memo[101];

void makeBlock(int index,int nBlock[][41],int turn) {
    int row = memo[index].row;
    int col = memo[index].col;
    int tmp[41][41] = { 0 };
    if (turn % 2) {
        if (turn == 0)
            return;
        else {
            for (int a = 0; a < row; ++a) {
                for (int b = 0; b < col; ++b) {
                    tmp[b][row - 1 - a] = nBlock[a][b];
                }
            }
            memset(nBlock, 0, sizeof(nBlock));
            for (int a = 0; a < col; ++a) {
                for (int b = 0; b < row; ++b) {
                    nBlock[a][b] = tmp[a][b];
                }
            }
        }
    }
    else {
        for (int a = 0; a < col; ++a) {
            for (int b = 0; b < row; ++b) {
                tmp[b][col - 1 - a] = nBlock[a][b];
            }
        }

        memset(nBlock, 0, sizeof(nBlock));
        for (int a = 0; a < row; ++a) {
            for (int b = 0; b < col; ++b) {
                nBlock[a][b] = tmp[a][b];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
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
        int temp[41][41];
        memcpy(temp, block[a], sizeof(block[a]));
        for (int b = 0; b < 4; ++b) {
            makeBlock(a, temp,b);
            int row, col;
            if (b % 2) {
                row = memo[a].col;
                col = memo[a].row;
            }
            else {
                row = memo[a].row;
                col = memo[a].col;
            }
            for (int c = 0; c < row; ++c) {
                for (int d = 0; d < col; ++d) {
                    cout << temp[c][d] << " ";
                }
                cout << "\n";
            }
            cout << "\n";

        }
    }
    return 0;

}
