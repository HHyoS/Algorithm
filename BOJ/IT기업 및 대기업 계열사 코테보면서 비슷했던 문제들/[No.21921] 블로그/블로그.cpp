#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


/*
    블로그를 운영하는 주인장 A가 있다.
    A는 N일동안 블로그를 운영했는데, 이중 연속된 X일 간 가장 많은 누적 방문자가 몇명인지
    찾아보자

    -> 그냥 읽자마자 슬라이딩 윈도우
    오늘은 운수 좋은 날

    N * 방문자수 = 최대 20억 이므로 int만 써도 가능
*/
struct Node {
    int maxi;
    int maxi_cnt;
};
int blog[250001]; // 블로그 방문 인원 배열
int N, X;

Node Solve() {
    int maxi = 0;
    int total = 0;
    int left = 0;

    for (int a = 0; a < X; ++a) {
        total += blog[a]; // X일까지 누적 방문자 수 
    }

    maxi = total; // 일단 최대값

    int cnt = 1;
    for (int a = X;  a < N; ++a) {

      // 한칸씩 오른쪽으로 옮기면서 누적합 구하기
        total -= (blog[left++]);
        total += (blog[a]); 

      // 현 누적합이 이미 있던 최대 값 이라면 구간 개수 +1
        if (maxi == total) {
            cnt++;
        }

          // 현 누적합이 더 큰 값이라면 최대 값으로 등록 해주기
        else if (maxi < total) {
            maxi = total;
            cnt = 1;
        }
    }
// 정답 return
    return { maxi,cnt };
}
void Input() {
    cin >> N >> X;
    for (int a = 0; a < N; ++a) {
        cin >> blog[a];
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Node answer = Solve();

  // 예외처리
    if (answer.maxi == 0) {
        cout << "SAD";
    }
    else {
        cout << answer.maxi << "\n" << answer.maxi_cnt;
    }

    return 0;
}
