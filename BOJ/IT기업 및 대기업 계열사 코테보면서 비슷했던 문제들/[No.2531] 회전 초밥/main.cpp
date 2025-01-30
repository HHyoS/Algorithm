#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/2531
    문제 설명 :
    */

int N, d, k, c;
int sushi[30001];
int ate[3001];

int Solve() {
    int cnt = 0;
    int ans = 0;
    // 쿠폰있는 c 음식은 1 추가하고 시작
    ate[c] = 1;
    ++cnt;
    // 0번 위치부터 시작해서 k개 골라서 선택하기
    for(int a = 0; a < k; ++a) {
        if (ate[sushi[a]] == 0) {
            ++cnt;
        }

        ate[sushi[a]]++;
    }

    ans = max(ans, cnt);
    
    int tail = 0;
    int head = k;

    // 처음 시작 위치로 돌아오기 전까지 한 칸씩 오른쪽 초밥을 고르면서 이동하기
    // 회전 초밥이므로 계속 오른쪽으로 가다보면 처음 위치로 돌아오게 됨.
    while(head != k-1){
        --ate[sushi[tail]];
        if (ate[sushi[tail]] == 0) {
            --cnt;
        }

        if (ate[sushi[head]] == 0) {
            ++cnt;
        }
        ++ate[sushi[head]];
        ans = max(ans, cnt);
        tail = (tail+1)%N;
        head = (head + 1)%N;
    }

    return ans;
}
void Input() {
    cin >> N >> d >> k >> c;
    for (int a = 0; a < N; ++a) {
        cin >> sushi[a];
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    cout << Solve();
    return 0;
}
