#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
    문제 사이트 :https://www.acmicpc.net/problem/2467
    문제 설명 : 
       양수와 음수로 이루어진 오름차순 수열이 주어진다.
       오름차순 수열 중 두 수를 더해서 절대값이 0에 가깝게 해라 <- 이것이 용액 문제의 설명 입니다.

       단순하게 특정 수를 찍은 후 다른 수와 비교하여 합의 절대값이 0에 가깝게 할 경우
       N의 크기가 10만 이므로 시간 초과가 발생합니다.

       그렇기 때문에 다른 아이디어가 필요한데, 제가 생각한 풀이 아이디어는 아래와 같습니다.

       1) 두 포인터를 정해서 수열의 맨 왼쪽 끝과 오른쪽 끝을 가리킨다.
       2) 두 포인터의 합의 절대값을 구한 뒤, 0에 가까운 값 일경우에만 정답의 위치로 저장한다.
       3) 왼쪽 포인터를 한칸 오른쪽으로 옮기는 것과, 오른쪽 포인터를 한칸 왼쪽으로 옮기는 것 중
       절대값이 0에 더 가까워 지는 케이스를 찾는다.
       4) 3에서 찾은 케이스에 해당하는 포인터의 움직임을 설정한다.(절대값이 더 작은 포인터를 움직임)
       5) 2-4의 과정을 두 포인터가 인접할 때 까지 반복.

       위의 풀이를 생각한 이유는 반드시 두 숫자를 정해야하고, 포인터가 움직임에 따라
       왼쪽 포인터는 음의 값이 감소, 오른쪽 포인터는 양의 값이 감소하기 때문입니다.

       절대값이 0에 가까운 위치를 찾기위해 움직일 때, 양 포인터는 위의 과정에 의해 현재 위치에서
       절대값을 작게 만드는 방향으로 움직이기 떄문에 결과적으로 정답에 해당하는 위치를 찾아가게 됩니다.


      */

int N;
int liquid[100001];
int mini = 21e8;
int al, ar;
void Solve() {

    // 초기 위치 세팅
    int l = 0, r = N-1;

    while (l < r) {
        int ssum = liquid[l] + liquid[r]; // 절대값 확인
        if (abs(ssum) < mini) { // 현재까지 찾은 절대값보다 더 작으면 갱신
            mini = abs(ssum);
            al = l;
            ar = r;
        }

        if (l + 1 == r) { // left와 right가 인접하다면 더 이상 연산 불필요
            break;
        }
        else { // 아니라면 왼쪽 포인터와 오른쪽 포인터 중 어떤 포인터가 움직였을 때
            // 절대값이 더 작아지는지 확인
            int temp_left_sum = abs(liquid[l + 1] + liquid[r]);
            int temp_right_sum = abs(liquid[l] + liquid[r - 1]);

            // 결과에 따라 포인터 이동
            if (temp_left_sum < temp_right_sum) {
                ++l;
            }
            else {
                --r;
            }
        }
    }
    // 정답 출력
    cout << liquid[al] << " " << liquid[ar];
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> liquid[a];
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
