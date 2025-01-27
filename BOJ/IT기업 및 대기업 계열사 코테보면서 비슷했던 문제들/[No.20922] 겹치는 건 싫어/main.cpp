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
