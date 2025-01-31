#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/1522
    문제 설명 : 

        a와 b로 이루어진 문자열이 주어질 때, a와 b의 위치를 교환하는 '교환' 이라는 과정을

        거쳐 a를 한 곳으로 모아야 하는데, 이 때, 교환의 횟수를 최소로 사용하여 a를 모으고
        
        그 횟수를 출력하는 문제를 출력하는 문제 '문자열 교환' 입니다.

        단순하게 생각하면 모든 케이스에 대해 a와 b를 교환하여 연결되는지 확인하고, 

        최소 횟수를 출력하면 되는데, 문자열의 길이가 1000이므로 모든 케이스에 대해 시뮬레이션

        해 보아도 1000*1000 = 100만회의 연산으로 해결이 가능합니다.

        해당 방법으로 구현이 가능하므로 단순 Brute Force로 구현 진행 하였습니다.
    */

string ab;
int sz = ab.size();
int a_cnt = 0;
int SSolve(int idx) {
    int mov_cnt = 0;
    int aa_cnt = 0;
    int used_b = 0;

  // 정해진 a 개수만큼 만족해야하고, 그를 위해서 b를 만나면 모두 a와 위치 교환한다 가정
    for (int a = 0; a < sz; ++a) {
        int next_idx = (idx + a) % sz;

      // b를 만났다면 어딘가에 존재하는 a를 끌고와서 위치를 교환했다 가정한다
        if (ab[next_idx] == 'b') {
            ++used_b;
            ++mov_cnt;
        }
        ++aa_cnt;

      // 모든 교환이 끝낫을 때 for문 종료
        if (aa_cnt == a_cnt)
            break;
    }
    return mov_cnt;
}

int Solve() {
    int ans = 21e8;

  // 특정 좌표 a부터 시작하는 연속하는 a문자열 만들어보기
    for (int a = 0; a < sz; ++a) {
        ans = min(ans,SSolve(a));
    }

    if (a_cnt == 0)
        ans = 0;

    return ans;
}
void Input() {
    cin >> ab;
    sz = ab.size();
    for (int a = 0; a < sz; ++a) {
        if (ab[a] == 'a')
            ++a_cnt;
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
