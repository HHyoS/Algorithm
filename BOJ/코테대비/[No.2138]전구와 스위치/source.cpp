#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;
// 1번 스위치를 누르고 시작하는 경우
char ramp1[100003];

// 1번 스위치를 누르지 않고 시작하는 경우
char ramp2[100003];

char target[100001];

void change(int number,int idx) {
    if (number == 1) {
        for (int a = 0; a < 3; ++a) {
            int next = idx + a;
            if (ramp1[next] == '0') {
                ramp1[next] = '1';
            }
            else if (ramp1[next] == '1') {
                ramp1[next] = '0';
            }
        }
    }
    else {
        for (int a = 0; a < 3; ++a) {
            int next = idx + a;
            if (ramp2[next] == '0') {
                ramp2[next] = '1';
            }
            else if (ramp2[next] == '1') {
                ramp2[next] = '0';
            }
        }
    }
}
int solve() {

    int ramp1Cnt = 1;
    int ramp2Cnt = 0;
    for (int a = 2; a <= N; ++a) {
        if (ramp1[a - 1] != target[a - 1]) {
            ++ramp1Cnt;
            change(1, a - 1);
        }
    }

    for (int a = 2; a <= N; ++a) {
        if (ramp2[a - 1] != target[a - 1]) {
            ++ramp2Cnt;
            change(2, a - 1);
        }
    }

    
    if ((ramp1[N] == target[N]) && (ramp2[N] == target[N])) {
        return min(ramp1Cnt, ramp2Cnt);
    }
    else if (ramp1[N] == target[N]) {
        return ramp1Cnt;
    }
    else if (ramp2[N] == target[N]) {
        return ramp2Cnt;
    }
    else
        return -1;
}
void input() {
    cin >> N;
    ramp1[0] = '0';
    ramp2[0] = '0';
    for (int a = 1; a <= N; ++a) {
        cin >> ramp1[a];
        ramp2[a] = ramp1[a];
    }
    ramp1[N + 1] = '0';
    ramp2[N + 1] = '0';
    for (int a = 1; a <= N; ++a) {
        cin >> target[a];
    }
    change(1,0);
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   // freopen("input.txt", "r", stdin);

    input();
    cout << solve();
    return 0;

}
