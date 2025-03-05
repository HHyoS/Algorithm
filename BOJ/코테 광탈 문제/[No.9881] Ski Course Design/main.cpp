#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/9881
    문제 설명 : 
        
        N개의 높이 값이 주어지고, 특정 높이를 x 줄이는데 x^2의 cost가 소비된다.
        위의 조건을 바탕으로 가장 높은 곳과 낮은 곳의 차이가 17이하가 되게 하고,
        그 때 최소 비용을 출력하라 << 이게 문제의 정리 입니다.

        위의 내용을 구현해야하는 'Ski Course Design'은 생각보다 간단한 문제로
        입력값인 N이 1000개이고, 높이의 범위가 100이므로 임의의 가장 낮은 높이와
        높은 높이를 찍어서 시뮬레이션을 돌리면 풀이가 가능합니다.

        제가 진행한 풀이는 아래와 같습니다.

        1) 가장 높은 곳과 낮은 곳의 차이를 구한다
        1-1) 17 이하라면 cost는 0
        1-2) 17 이상이라면 높이의 조절이 필요한 정도는 abs(가장 높은 - 가장 낮은) - 17 입니다.
        -> 두 높이의 차이 중 17정도는 괜찮으므로 abs - 17 이 조절이 필요한 값 = X

        2) for(int a = 0; a <= X; ++a) 를 하며 아래 값을 목표로 배열 내의 모든 높이를 조절한다고 가정.
        낮은 높이 = (가장 낮은 높이 + a)
        높은 높이 = (가장 높은 높이 - X +a) 
        
        3) 낮은 높이보다 낮은 높이는 높이고, 가장 높은 높이보다 높다면 줄이는 연산 진행
        4) 연산의 결과값을 합하여 2)의 for문 내에서 가장 작은 값을 정답으로 출력
      */
int N;
vector<int> farm;

int simul(int left, int right) {

    int left_sum = 0;
    int right_sum = 0;

    // 왼쪽 위치 중 목표로 한 낮은 곳 위치보다 더 낮은 위치가 있다면 높여주고
    // 코스트 증가
    for (int a = 0; a < N; ++a) {
        if (farm[a] <= left) {
            int tmp_gop = left - farm[a];
            left_sum = left_sum + tmp_gop*tmp_gop;
        }
        // 목표보다 큰 높이라면 더이상 연산 진행 x
        else {
            break;
        }
    }


    // 오른쪽 위치 중 목표로 한 높은 곳 위치보다 높은 위치가 있다면 낮혀주고
    // 코스트 증가
    for (int a = N - 1; a >= 0; --a) {
        if (farm[a] >= right) {
            int tmp_gop = farm[a] - right;
            right_sum = right_sum + tmp_gop * tmp_gop;
        }
        else {
            break;
        }

    }
    /* for debugging
    cout << left << " " << right << " ";
    cout << left_sum + right_sum << "\n";
    cout << "\n";
    */
    // 총 코스트 return
    return left_sum + right_sum;
}
void Solve() {
    
    int ans = 21e8; // 정답 dafault 값은 매우 큰 값으로
    int chai = abs(farm[0] - farm[N - 1]); // 가장 높은 곳과 낮은 곳의 차이
    if (chai <= 17) { // 차이가 17 이라하면 조절이 필요 없음
        ans = 0;
    }
    else { // 17 이상이라면
        chai = chai - 17; // 높은 곳과 낮은 곳의 차이 중 17까지는 이해해주므로 17은 빼주자
        for (int a = 0; a <= chai; ++a) { // 특정 높이(낮은 곳, 높은 곳)를 타겟으로 시뮬레이션 시작
            ans = min(ans, simul(farm[0]+a, farm[N-1]-chai + a));
        }
    }
    cout << ans;
}


void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int tmp;
        cin >> tmp;
        farm.push_back(tmp);
    }

    // 편리한 연산을 위한 정렬
    sort(farm.begin(), farm.end());
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
