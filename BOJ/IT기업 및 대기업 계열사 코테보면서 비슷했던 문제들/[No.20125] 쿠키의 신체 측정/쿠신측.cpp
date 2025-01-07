#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


struct Node {
    int x;
    int y;
};
int N;
char cookie[1002][1002];

// 0=왼팔,1=오른팔,2=몸통,3=왼다리,4=오른다리
int mov[5][2] = { {0,-1},{0,1},{1,0},{1,-1},{1,1} }; // 0=머리, 그 외 팔다리 이동 방향
Node heart;
int answer[5]; // 0=머리, 1=왼팔, 2=오른팔, 3=왼다리, 4=오른다리
void Solve() {
    
    Node body;
    for (int a = 0; a < 3; ++a) {
        Node location = heart;
        int leng = 0;
        for (int b = 0; b < N; ++b) {
            location = { location.x + mov[a][0], location.y + mov[a][1] };
            if (location.x >= N || location.x < 0 || location.y >= N || location.y < 0 || cookie[location.x][location.y] == '_') {
                answer[a] = leng;
                if (a == 2) {
                    body = { location.x - mov[a][0],location.y - mov[a][1] };
                }
                break;
            }
            else if (cookie[location.x][location.y] == '*') {
                ++leng;
            }
        }
    }
    Node left_leg = { body.x + 1,body.y - 1 };
    Node right_leg = { body.x + 1, body.y + 1 };
   
    int leng = 1;
    for (int a = 0; a < N; ++a) {
        left_leg = { left_leg.x + 1,left_leg.y };
        if (left_leg.x >= N || left_leg.x < 0 || left_leg.y >= N || left_leg.y < 0 || cookie[left_leg.x][left_leg.y] == '_') {
            answer[3] = leng;
            break;
        }
        else if (cookie[left_leg.x][left_leg.y] == '*') {
            ++leng;
        }
    }

    leng = 1;
    for (int a = 0; a < N; ++a) {
        right_leg = { right_leg.x + 1,right_leg.y };
        if (right_leg.x >= N || right_leg.x < 0 || right_leg.y >= N || right_leg.y < 0 || cookie[right_leg.x][right_leg.y] == '_') {
            answer[4] = leng;
            break;
        }
        else if (cookie[right_leg.x][right_leg.y] == '*') {
            ++leng;
        }
    }
    cout << heart.x+1 << " " << heart.y+1 << "\n";
    for (int a = 0; a < 5; ++a) {
        cout << answer[a] << " ";
    }
}
void Input() {
    cin >> N;
    bool first_visit = false;
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < N; ++b) {
            cin >> cookie[a][b];
            if (cookie[a][b] == '*' && first_visit == false) {
                heart = { a+1,b };
                first_visit = true;
            }
        }
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
