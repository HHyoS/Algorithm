#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


int N; // 지방 개수
vector<long long> province; // 각 지방 별 필요 예산
long long total_sum = 0; // 전체 비용 합
long long budget; // 보유 예산

// 특정 상한치를 설정했을 때, 모든 도시에 예산 배분이 가능한지 확인하는 함수
bool able_check(long long expect_budget) { 
    long long temp_budget = budget;
    for (int a = 0; a < N; ++a) {
        long long temp_province = province[a];
      // 특정 상한액에 걸리는 예산 요청은 상한액으로 변경
        if (temp_province > expect_budget)
            temp_province = expect_budget;

        temp_budget -= temp_province;

      // 특정 상한액으로 설정시 예산 분배가 안된다면 false
        if (temp_budget < 0) {
            return 0;
        }
    }

  //예산 배정이 된다면 true
    return 1;
}

// 이진 탐색으로, 보유 예산부터 시작해서 상한치 최대액 찾아보자
long long bs(long long start, long long end) {
    long long mid = (start + end) / 2;
    long long ans = 0;
    while (start <= end) {
        mid = (start + end)/2;

        bool checker = able_check(mid);

      // 특정 상한액으로 모든 도시 배분이 가능하다면 해당 값을 임시 정답으로 저장
        if (checker == 1) {
            start = mid + 1;
            ans = mid;
        }
          //아니라면 상한액을 줄어보자
        else {
            end = mid - 1;
        }
    }

    return ans;
}
int Solve() {

  //큰 값부터 정렬, 의미는 없는 듯?
    sort(province.begin(), province.end(), greater<long long>());

  // 전체 예산으로 모든 도시에 배분이 가능하다면 그냥 주자
    if (budget >= total_sum)
        return province[0];
    
    return bs(0, budget);

}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        long long temp;
        cin >> temp;
        province.push_back(temp);
        total_sum += temp;
    }
    cin >> budget;
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    cout << Solve();

    return 0;
}
