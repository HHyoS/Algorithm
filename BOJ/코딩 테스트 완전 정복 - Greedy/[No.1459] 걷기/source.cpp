#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;
  
long long tx, ty,W,S;
long long solve() {

    long long ans_A = (tx + ty) * W; // 단순 직선이동
    long long ans_B = min(tx, ty) * S + abs(tx - ty) * W; // 일단 대각선으로 이동해보기
    ans_B = min(ans_B, abs(tx+ty)%2==1 ? (max(tx,ty)-1)*S+W : max(tx,ty)*S);
    // 남은 위치만큼 이동할 때 (1) 단순 직선이동 (2)- 두 좌표의 합이 홀수라면 큰수 -1 만큼 대각선 이동 후 한칸 직진 (3)두 좌표의 합이 짝수라면 대각선 티키타가 이동 
    return min(ans_A,ans_B);
}
void input() {
    cin >> tx >> ty >> W >> S; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    clock_t start, finish;
    double duration;
    freopen("input.txt", "r", stdin);
    start = clock();
    input();
    cout << solve()<<"\n";
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
    return 0;
}
