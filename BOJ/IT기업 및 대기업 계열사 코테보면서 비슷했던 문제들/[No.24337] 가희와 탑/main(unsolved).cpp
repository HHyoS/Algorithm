#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/14658
    문제 설명 : 
      */
int N;
int aa, bb;
stack<int> l;
queue<int> r;
void Solve() {

    if (aa + bb > N + 1) {
        cout << -1;
        return;
    }
    int maxH = max(aa,bb);
    int center = 0;
    int left_cnt = N - bb;
    
    // 제일 높은 곳의 위치는 maxH로 정해졌고, 볼 수 있는 건물 중 하나는 이미 maxH임
    // 따라서 가희가 볼 수 있는 건물의 수는 이제 a -1개, 단비는 b-1개
    int taa = aa - 1 ;
    int tbb = bb - 1; 

    // 제일 높은 곳 기준 왼쪽부터 해보자

    for (int a = maxH-1; a > 0; --a) {
        if (left_cnt > 0 && taa > 0){
            l.push(a);
            --taa;
            --left_cnt;
        }
        else {
            break;
        }
    }
    if (taa == 0) {
        left_cnt = left_cnt + tbb;
    }
    else {
        while (left_cnt > 0) {
            l.push(1);
            --left_cnt;
        }
        left_cnt = tbb;
    }

    while (left_cnt != tbb) {
        r.push(1);
        --left_cnt;
    }
    for (int a = tbb; a > 0; --a) {
        r.push(a);
    }


    while (!l.empty()) {
        cout << l.top() << " ";
        l.pop();
    }
    cout << maxH << " ";
    while (!r.empty()) {
        cout << r.front() << " ";
        r.pop();
    }
    

}


void Input() {
    cin >> N >> aa >> bb;
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
