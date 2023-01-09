#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Participant {
    int idx;
    int point;
};
int N;
Participant Competition[4][100001];
vector<Participant> totalRecord;
int answer[4][100001];

bool cmp(Participant a, Participant b) {
    if (a.point == b.point) {
        return a.idx > b.idx;
    }
    return a.point > b.point;
}
void solve() {

    sort(Competition[0], Competition[0] + N, cmp);
    sort(Competition[1], Competition[1] + N, cmp);
    sort(Competition[2], Competition[2] + N, cmp);
    sort(Competition[3], Competition[3] + N, cmp);
    for (int a = 0; a < 4; ++a) {
        int rank = -1;
        int beforePoint = -1;
        for (int b = 0; b < N; ++b) {
            int point = Competition[a][b].point;
            int index = Competition[a][b].idx;
            if (beforePoint == point) {
                answer[a][index] = rank;
            }
            else {
                rank = b + 1;
                answer[a][index] = rank;
                beforePoint = point;
            }
        }
    }
    
    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < N; ++b) {
            cout << answer[a][b] << " ";
        }
        cout << "\n";
    }

}
void input() {
    cin >> N;
    for (int a = 0; a < 3; ++a) {
        int point;
        for (int b = 0; b < N; ++b) {
            cin >> point;
            Competition[a][b] = { b,point };
        }
    }
    for (int a = 0; a < N; ++a) {
        Competition[3][a] = { a,Competition[0][a].point + Competition[1][a].point + Competition[2][a].point };
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
