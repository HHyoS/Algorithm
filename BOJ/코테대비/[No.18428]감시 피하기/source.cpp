#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Node {
    int x;
    int y;
};
int N;

char map[7][7];
vector<Node> bincan;
vector<Node> teacher;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool Find(int x, int y) {
    for (int a = 0; a < 4; ++a) {
        for (int b = 1; b <= N; ++b) {
            int nx = x + mov[a][0] * b;
            int ny = y + mov[a][1] * b;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
            if (map[nx][ny] == 'O') break;
            if (map[nx][ny] == 'S') return 1;
        }
    }
    return 0;
}
bool run() {
    for (int a = 0; a < teacher.size(); ++a) {
        Node now = teacher[a];
        if (Find(now.x, now.y)) {
            return 0;
        }
    }
    return 1;
}

bool jangEmul() {
    int size = bincan.size();
    for (int a = 0; a < size - 2; ++a) {
        Node first = bincan[a];
        map[first.x][first.y] = 'O';
        for (int b = a + 1; b < size - 1; ++b) {
            Node second = bincan[b];
            map[second.x][second.y] = 'O';
            for (int c = b + 1; c < size; ++c) {
                Node third = bincan[c];
                map[third.x][third.y] = 'O';
                if (run()) {
                    return 1;
                }
                map[third.x][third.y] = 'X';
            }
            map[second.x][second.y] = 'X';
        }
        map[first.x][first.y] = 'X';
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    cin >> N;

    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cin >> map[a][b];
            if (map[a][b] == 'X') {
                bincan.push_back({ a,b });
            }
            else if (map[a][b] == 'T') {
                teacher.push_back({ a,b });
            }
        }
    }

    if (jangEmul()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }


    return 0;

}
