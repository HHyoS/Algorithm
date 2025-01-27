문제 사이트 : https://www.acmicpc.net/problem/20922

문제 설명 :

![image](https://github.com/user-attachments/assets/7d077343-b9f8-4336-b5f4-28812f827076)
![image](https://github.com/user-attachments/assets/766375a5-1396-495a-abc7-1f6ea7b376af)

풀이 알고리즘

    겹치는 것을 매우 싫어하는 도현이를 위해 같은 원소가 K개 이하로 들어있는 최장거리 수열을
    
    구하는 문제 '겹치는 건 싫어' 입니다.

    문제의 조건은 매우 간단한데, 주어진 수열에서 특정 숫자가 K번 이하로 이루어진 부분

    수열을 만들었을 때, 가장 긴 부분 수열의 길이를 출력하는 것 입니다.

    단순이 특정 좌표를 찍고 오른쪽으로 이동하며 수열의 길이를 측정할 경우 수열의 길이가 

    20만이라는 조건에 의해 시간초과가 발생할 수 있습니다. 

    따라서 적절한 방법을 통해 수열 내부의 값을 관리하고 불필요한 반복 연산을 제거해야 하는데

    그 방법은 아래와 같습니다.

    1) 입력 받은 수열의 시작지점(0번 인덱스)부터 시작하여 오른쪽으로 한칸씩 이동하여

    부분 수열을 만든다

    2) 오른쪽으로 이동할 때, 방문한 숫자의 개수를 기록하여 K번 이하로 사용되도록 관리

    3) 2)를 진행할 떄 K번 초과하여 사용될 경우 시작지점의 위치를 오른쪽으로 한 칸씩 이동하며

    방문 기록을 하나씩 지워나감

    4) 3)을 진행하며 K번 초과하는 케이스에 해당하는 숫자를 만났을 경우 시작지점 이동을 종료

    5) 3-4 를 거치게 되면 K번 초과하여 이동하는 케이스가 종료되므로 수열 확장 가능

    6) 1-4 단계를 완료할 떄 마다 수열의 길이를 확인하고, 현재까지 최장 수열의 길이와 비교하여

    더 큰 값만 출력

풀이 코드

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/20922
    문제 설명 :
        겹치는 것을 매우 싫어하는 도현이를 위해 같은 원소가 K개 이하로 들어있는 최장거리 수열을 구해보자

        1) 슬라이딩 윈도우를 사용하여 시작 지점을 관리하고, 오른쪽으로 이동하면서

        같은 숫자가 K번 이하로 사용되도록 관리하자.

        2) 만약 오른쪽 지점 T로 이동했을 때, K번을 넘었다면 T에 존재하는 숫자와 동일한

        수를 만날 때 까지 시작지점을 오른쪽으로 옮기면서 수열을 줄여나가자.

        위의 단계를 반복하여 현재 수열의 길이를 확인하고, 최장 길이를 기록하여 정답을

        출력해보자.
        */

int N, K;

int sequence[200001]; // 입력받을 수열의 길이
int used[100001]; // 사용 횟수 기록을 위한 배열
void Solve() {
    int s = 0;
    used[sequence[0]] = 1;
    int max_leng = 1;
    int now_leng = 1;
    for (int a = 1; a < N; ++a) {
        if (used[sequence[a]] + 1 > K) { // 만약 이번 방문에 K번 초과하여 사용할 경우
            while (s < a) { // 현재 방문 위치의 숫자와 동일한 수를 만날 때 까지 수열을 줄여보자
                int start_integer = sequence[s++];
                --now_leng;
                --used[start_integer];
                if (start_integer == sequence[a]) { // 현재 위치의 숫자와 동일한 숫자를 만났다면 while문 종료
                    break;
                }
            }
        }

        // 어쨋든 오른쪽으로 한칸 이동했으므로 수열의 길이 1증가 및 사용 횟수 1증가
        now_leng++;
        ++used[sequence[a]];
        max_leng = max(max_leng, now_leng);
    }
    cout << max_leng;
}
void Input() {
    cin >> N >> K;
    for (int a = 0; a < N; ++a) {
        cin >> sequence[a];
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

오늘의 일기

    실버1 쉽다

    연휴는 짧다.. 벌써 월요일 끝!

![image](https://github.com/user-attachments/assets/972af6cc-361d-4482-905c-a61131e7a27b)

    
