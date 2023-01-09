#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int idx;
    int point;
};
int N;
vector<Node> one;
vector<Node> two;
vector<Node> three;

int ans[100001][3];
bool cmp(Node a, Node b) {
    if (a.point == b.point) {
        return a.idx < b.idx;
    }
    return a.point > b.point;
}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int first, second, third;
        cin >> first >> second >> third;
        one.push_back({ a,first });
        two.push_back({ a,second });
        three.push_back({ a,third });
    }
    sort(one.begin(), one.end(), cmp);
    sort(two.begin(), two.end(), cmp);
    sort(three.begin(), three.end(), cmp);

    for (int a = 0; a < N; ++a) {
        int gijoon = one[a].point;
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
