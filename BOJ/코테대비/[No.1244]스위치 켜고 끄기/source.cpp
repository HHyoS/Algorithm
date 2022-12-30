#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    int sex;
    int idx;
};
int switches[101];
int N, M;


void print() {

    int maxi = N / 20;
    for (int a = 0; a < maxi; ++a) {
        int start = a * 20;
        for (int b = 1; b <= 20; ++b) {
            cout << switches[start + b] << " ";
        }
        cout << "\n";
    }
    maxi = N - N % 20 + 1;
    for (int a = maxi; a <= N; ++a) {
        cout << switches[a] << " ";
    }
}
void boy(int idx) {

    for (int a = idx; a <= N; a +=idx) {
        switches[a] = !switches[a];
    }
}

void girl(int idx) {

    switches[idx] = !switches[idx];
    int maxi = min(idx - 1, N - idx);
    for (int a = 1; a <= maxi; ++a) {
        if (switches[idx - a] == switches[idx + a]) {
            switches[idx - a] = !switches[idx - a];
            switches[idx + a] = !switches[idx + a];
        }
        else
            break;

    }
}
void solve() {
    cin >> M;
    for (int a = 0; a < M; ++a) {
        int sex, idx;
        cin >> sex >> idx;
        if (sex == 1) {
            boy(idx);
        }
        else if (sex == 2) {
            girl(idx);
        }
    }
    print();
    
}
void input() {
    cin >> N;
    for (int a = 1; a <= N; ++a) {
        cin >> switches[a];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen("input.txt", "r", stdin);

    input();
    solve();
    return 0;

}
