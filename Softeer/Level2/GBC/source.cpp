#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Node {
    int end;
    int speed;
};
int N, M;
Node target[101];
Node elv[101];
void solve() {
    int index = 1;
    int maxi = 0;
    for (int a = 1; a <= N; ++a) {
        if (index > M)
            break;
        for (int b = index; b <= M; ++b) {
            int nowSpeed = elv[b].speed - target[a].speed;
            if (nowSpeed > 0)
                maxi = max(maxi, nowSpeed);
            index = b;
            if (elv[b].end == target[a].end) {
                index = b + 1;
                break;
            }
            else if (elv[b].end > target[a].end) {
                break;
            }
        }
    }
    cout << maxi;
}
void input() {
    cin >> N >> M;
    target[0] = { 0,0 };
    elv[0] = { 0,0 };
    for (int a = 1; a <= N; ++a) {
        int leng, speed;
        cin >> leng >> speed;
        target[a] = { target[a-1].end + leng,speed };
    }
    for (int a = 1; a <= M; ++a) {
        int leng, speed;
        cin >> leng >> speed;
        elv[a] = { elv[a-1].end + leng,speed };
    }
}
int main(int argc, char** argv)
{

    input();
    solve();
	return 0;
}
