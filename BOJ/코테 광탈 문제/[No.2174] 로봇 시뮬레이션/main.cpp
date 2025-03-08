#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/2174
    문제 설명 : 


   
      */


struct Robot{
    int x;
    int y;
    int head;
};
int A, B, N, M;
Robot rb[110];
int exist[110][110];
int mov[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void Solve() {
    for (int a = 0; a < M; ++a) {
        int target, repeat;
        char command;
        cin >> target >> command >> repeat;

        if (command == 'L') {
            rb[target].head = (rb[target].head + (3*repeat)) % 4;
        }
        else if (command == 'R') {
            rb[target].head = (rb[target].head + repeat) % 4;
        }
        else {
            int head = rb[target].head;
            for (int b = 0; b < repeat; ++b) {
                exist[rb[target].x][rb[target].y] = 0;
                int nx = rb[target].x + mov[head][0];
                int ny = rb[target].y + mov[head][1];

                if (nx <= 0 || nx > B || ny <= 0 || ny > A) {
                    cout << "Robot " << target << " crashes into the wall";
                    return;
                }
                else if (exist[nx][ny] != 0) {
                    cout << "Robot " << target << " crashes into robot " << exist[nx][ny];
                    return;
                }
                else {
                    rb[target] = { nx,ny,head };
                    exist[nx][ny] = target;
                }
     /*           for (int c = B; c > 0; --c) { for debugging
                    for (int d = 1; d <= A; ++d) {
                        cout << exist[c][d] << " ";
                    }
                    cout << "\n";
                }
                cout << "\n";*/
            }
        }
    }

    cout << "OK";
}


void Input() {
    cin >> A >> B >> N >> M;
    for (int a = 1; a <= N; ++a) {
        int x, y;
        char head;
        cin >> y >> x >> head;
        if (head == 'N') {
            rb[a] = {x,y,0};
        }
        else if (head == 'E') {
            rb[a] = {x,y,1};
        }
        else if (head == 'S') {
            rb[a] = {x,y,2};
        }
        else {
            rb[a] = {x,y,3};
        }
        exist[x][y] = a;
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
