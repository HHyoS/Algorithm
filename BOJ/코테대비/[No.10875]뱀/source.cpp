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
    int sX; // start x
    int sY; // start y
    int eX; // end x;
    int ey; // end y;
    int arrow; // 머리가 어디방향인지;
};
int L, N;


// mov[0] -> 위 mov[1] -> 우, mov[2] -> 아래 , mov[3] -> 좌
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

vector<Node> snake;
int maxi = L * 2;

void solve() {

    for (int a = 0; a < snake.size()-1; ++a) {
        Node now = snake[a];
        for (int b = a - 1; b >= 0; --b) {
            Node before = snake[b];
            
            // 내가 만약 수평선이라면
            if (now.arrow == 0) {
                // 그리고 이전에 존재한 선 또한 수평선이라면
                if (before.arrow == 0) {
                    // 이전에 존재한 선과 같은 X좌표이고
                    if(now.sX == before.sX && )
                  
                }
                else {

                }
            }
            // 내가 만약 수직선이라면
            else {

            }
        }
    }
}
void input() {

    cin >> L >> N;

    int x = L;
    int y = L;
    int time = 0;
    int head = 1;
    for (int a = 0; a <= N; ++a) {
        int nextTime;
        char nextArrow;
        int nx;
        int ny;
        if (a == N) {
            nx = x + mov[head][0] * (2L + 1);
            ny = y + mov[head][1] * (2L + 1);

        }
        else {
            cin >> nextTime >> nextArrow;
            nx = x + mov[head][0] * nextTime;
            ny = y + mov[head][1] * nextTime;
        }

        if(head == 0 || head == 2)
            snake.push_back({ min(x,nx),min(y,ny),max(x,nx),max(y,ny),1 });
        else
            snake.push_back({ min(x,nx),min(y,ny),max(x,nx),max(y,ny),0 });

        x = nx;
        y = ny;
        if (nextArrow == 'L') {
            head = (head + 3) % 4;
        }
        else {
            head = (head + 1) % 4;
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
