#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/13144
    문제 설명 : 
        N개의 수로 이루어진 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 
        같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 구현하는 문제 'List of Unique Numbers' 입니다.

        문제의 입력이 10만개이고, 경우의 수는 50억 5만개 입니다.

        이 경우의 수를 하나씩 찾는 경우 반드시 시간 초과가 발생하기 때문에 문제에서 원하는
        경우의 수를 구하는 것은 옳은 풀이가 아닙니다.

        저는 전체 경우의 수에서 오히려 구하기 쉬운 연속해서 수열의 경우의 수를 빼는 방식으로
        풀이 진행했습니다.

        풀이 알고리즘은 다음과 같습니다.
        1) 전체 경우의 수를 구한다
        2) 입력 받은 수열에서 two point를 사용한 슬라이딩 윈도우 방식으로 구현 시작
        2-1) 왼쪽 좌표 l, 오른쪽 좌표 r을 설정하고 슬라이딩 윈도우 시작
        2-2) r을 오른쪽으로 한칸 옮기려고 했을 때, 해당 좌표의 숫자가 이미 사용된 숫자인지 확인
        2-3) 사용된 숫자라면 l의 위치 숫자를 사용하지 않은 숫자로 처리하고, N-R+1의 경우의 수를 전체 경우의 수에서 빼줌
        -> 특정 좌표 r에서 중복된 수가 사용되었으면 이후 N-R+1개를 추가로 연속 선택해도 모두 중복 사용되기 떄문
        2-4) r좌표의 숫자가 사용되지 않은 수 처리가 될 때 까지 l을 한칸씩 오른쪽으로 옮기기
        2-5) 2-4가 완료되었다면 r위치의 수를 사용 표시
        3) 2의 과정을 모두 완료한 후 남은 경우의 수 출력

      */

long long N;
int nums[100001]; // 입력 수열 
long long cnt = 0; // 경우의 수가 50억개가 넘으므로 long long
bool used[100001]; // 숫자 사용 체크용
void Solve() {
    long long l = 0, r = 1; // two point 슬라이딩 윈도우
    used[nums[0]] = true; // 가장 왼쪽 좌표는 사용하고 시작

    while (r <= N) {
        int nowNum = nums[r]; // r 좌표의 값 확인
        if (used[nowNum] == true) { // 만약 이미 사용된 값이라면
            cnt = cnt - (N - r); // 경우의 수 제거(본 코드에서는 좌표를 0부터 쓰므로 +1을 안해줘도 됨
            used[nums[l]] = false; // l 좌표의 수 미사용 체크
            ++l; // l좌표 오른쪽으로 한칸 이동
        }
        else { // 만약 사용된 적 없는 수라면
            used[nowNum] = true; // 사용 체크하고
            ++r; // r 한칸 옮겨서 다음 수 체크 진행
        }
    }
    cout << cnt; // 남은 경우의 출력
}


void init() { // 최대 경우의 수
    for (int a = N; a >= 1; --a) {
        cnt = cnt + a;
    }
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> nums[a];
    }
    init();
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
