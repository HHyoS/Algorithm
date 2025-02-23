#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/2110
    문제 설명 : 
       문제에서 주어진 조건을 바탕으로 C개의 공유기를 설치하여 각 공유기 간
       거리가 최대가 되도록 하는 문제 '공유기 설치' 입니다.

       공유기 간 거리가 최대가 되야하기 때문에, 모든 공유기가 동일한 거리를 가지는 것이
       정답에 해당하는 거리가 될 수 있습니다.

       하지만 좌표가 정확하게 정해져 있는것이 아닌 N개의 집 좌표가 랜덤한 위치에 존재하므로
       임의의 거리를 정해서 공유기기 배치를 시도하고, 그 시도에서 실제 공유기 간 거리의 최대값을
       찾는 시뮬레이션이 필요합니다.

       이를 위해 이분탐색을 사용하여 공유기 간거리를 1부터 최대 위치(마지막 위치 - 시작 위치)에 대한
       탐색을 진행했고 임의의 거리로 시뮬레이션을 동작시켜서 실제 공유기 간 거리를 측정했습니다.
       측정하며 1) C개 이상의 공유기를 설치할 수 있다면 -> 실제로 가능한 유효한 테스트
       2) C개 이하의 공유기 -> C개 설치가 불가능 하므로 무의미한 데이터 로 구분했고,
       이후 이전까지 측정한 거리의 최대값과, 현재 거리를 비교하여 이후 시뮬레이션할 거리를
       늘릴지,줄일지 판단하여 다음 탐색을 진행 했습니다.
      */

int N, C;

vector<int> home;


int simul(int jump) {
    
    int idx = 0;
    int nx = home[0];
    int leng = jump;
    int ap_cnt = 1;
    while (idx < N) {
        int nnx = home[idx] + jump;
        bool flag = false;
        for (int a = idx; a < N; ++a) {
            if (home[a] >= nnx) {
                ap_cnt++;
                leng = min(leng, home[a] - home[idx]);
                idx = a;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            break;
        }
    }
    if (ap_cnt >= C) {
        return leng;
    }
    else {
        return 0;
    }
}
int bs() {
    int s = 1;
    int e = home[N - 1] - home[0];
    int ans = 0;

    while (s <= e) {
        int mid = (s + e) / 2;

        int tmp = simul(mid);

        if (ans < tmp) {
            ans = tmp;
            s = mid + 1;
        }
        else if (tmp == 0) {
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
void Solve() {
    sort(home.begin(), home.end());
    cout << bs();
}
void Input() {
    cin >> N >> C;
    for (int a = 0; a < N; ++a) {
        int tmp;
        cin >> tmp;
        home.push_back(tmp);
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
