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
    long long sX; // start x
    long long sY; // start y
    long long eX; // end x;
    long long eY; // end y;
    long long arrow; // 머리가 어디방향인지;
};

long long L, N;


// mov[0] -> 위 mov[1] -> 우, mov[2] -> 아래 , mov[3] -> 좌
long long mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

vector<Node> snake;
long long deadLine;

void init() {
    deadLine = (L << 1) + 1;
    snake.push_back({ -1,-1,-1,deadLine,0 }); // 상단 수평 아웃라인
    snake.push_back({ deadLine,-1,deadLine,deadLine,0}); // 하단 수평 아웃라인 
    snake.push_back({ -1,-1,deadLine,-1,1 }); // 좌측 수직 아웃라인
    snake.push_back({ -1,deadLine,deadLine,deadLine,1 }); // 우측 수직 아웃라인
   
}

long long solve(long long sX, long long sY, long long eX, long long eY, long long arrow) {

    long long endTime = deadLine;
    int size = snake.size();
    if (size > 4)
        size -= 1;
    for (int a = 0; a < size; ++a) {
        // 비교하려는 직선이 수평일 경우
        if (snake[a].arrow == 0) {
            // 현재 이동 동선이 수평이고, 대상 직선과 같은 x축에 위치할 경우
            if ((arrow == 1 || arrow == 3)&&snake[a].sX == sX){
                if (arrow == 1) {
                    if (snake[a].sY >= sY && snake[a].sY <= eY) {
                        endTime = min(endTime,snake[a].sY - sY);
                    }
                }
                else if(arrow == 3){
                    if (snake[a].eY >= eY && snake[a].eY <= sY) {
                        endTime = min(endTime, sY - snake[a].eY);
                    }
                }
            }
            // 현재 이동 동선이 수직이고, 
            else if ((arrow == 0 || arrow == 2) && snake[a].sY <= sY && snake[a].eY >= sY) {
                if (arrow == 0){
                    if (snake[a].sX <= sX && snake[a].sX >= eX) {
                        endTime = min(endTime,sX - snake[a].sX);
                    }
                }
                else if (arrow == 2){
                    if (snake[a].sX >= sX && snake[a].sX <= eX) {
                        endTime = min(endTime,snake[a].sX - sX);
                    }
                }
            }
        }
        // 비교하려는 직선이 수직일 경우
        else {
            // 현재 뱀의 이동이 수평이동
            if ((arrow ==1 || arrow == 3) && snake[a].sX <= sX && snake[a].eX >= sX){
                if (arrow == 1) {
                    if (snake[a].sY >= sY && snake[a].sY <= eY) {
                        endTime = min(endTime, snake[a].sY - sY);
                    }
                }
                else if (arrow == 3) {
                    if (snake[a].sY <= sY && snake[a].sY >= eY) {
                        endTime = min(endTime, sY - snake[a].sY);
                    }
                }
            }
            //현재 뱀의 이동이 수직이고
            else if ((arrow == 0 || arrow == 2) && snake[a].sY == sY) {
                if (arrow == 0) {
                    if (snake[a].eX <= sX && snake[a].eX >= eX) {
                        endTime = min(endTime, sX - snake[a].eX);
                    }
                }
                else if (arrow == 2) {
                    if (snake[a].sX >= sX && snake[a].sX <= eX) {
                        endTime = min(endTime, snake[a].sX - sX);
                    }
                }
            }
        }
    }
    return endTime;
}
void input() {

    cin >> L >> N;

    init();

    long long sX = L;
    long long sY = L;
    long long time = 0;
    long long arrow = 1;
    for (int a = 0; a < N; ++a) {
        long long nextTime;
        char nextArrow;
        long long eX;
        long long eY;

        cin >> nextTime >> nextArrow;
        eX= sX + mov[arrow][0] * nextTime;
        eY = sY + mov[arrow][1] * nextTime;
        long long ans = solve(sX, sY, eX, eY, arrow);
        if (ans != deadLine) {
            cout << time + ans;
            return;
        }


        if (arrow == 0 || arrow == 2) {
            snake.push_back({ min(sX,eX),min(sY,eY),max(sX,eX),max(sY,eY),1 });
        }
        else {
            snake.push_back({ min(sX,eX),min(sY,eY),max(sX,eX),max(sY,eY),0});
        }

        time = time + nextTime;
        sX = eX;
        sY = eY;
        if (nextArrow == 'L') {
            arrow = (arrow + 3) % 4;
        }
        else {
            arrow = (arrow + 1) % 4;
        }

    }
    cout << time + solve(sX, sY, sX + mov[arrow][0] * deadLine*2, sY + mov[arrow][1] * deadLine*2, arrow);

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  // freopen("input.txt", "r", stdin);


    input();

    return 0;

}
