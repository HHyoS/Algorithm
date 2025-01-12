문제 사이트 : https://www.acmicpc.net/problem/2512

문제 설명 :

    국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다. 
    
    국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다. 
    
    그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정한다.
    
        모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
        모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 
        예산요청에는 모두 상한액을 배정한다. 
        상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다. 
        예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 
        각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 
        위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다. 
        
    여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 
    
    위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

입력

    첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. 
    N은 3 이상 10,000 이하이다. 
    다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다.
    이 값들은 모두 1 이상 100,000 이하이다. 
    그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. 
    M은 N 이상 1,000,000,000 이하이다. 

출력

    첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다. 

예제 입력 1 

    4
    120 110 140 150
    485
    
예제 출력 1 

    127
    
예제 입력 2 

    5
    70 80 30 40 100
    450
    
예제 출력 2 

    100

풀이 알고리즘

    예산을 배분해야 하는 지방의 수 N과 각 지방에서 필요로 하는 예산, 나라의 예산이 주어졌을 때

    각 도시에 배분할 수 있는 금액의 최대치를 찾는 문제 '예산' 입니다.

    문제에서 요구하는 금액의 최대치 - '상한액'은 모두 균등하게 배분하는 것이 아니라 
    
    특정 도시의 경우 상한액보다 적은 금액을 가져가기 때문에 단순하게 계산해서는 구할 수 없습니다.

    이를 위해서, 제가 사용한 방법은 아래와 같습니다.

    1) 각 도시에 전달할 수 있는 예산의 최소치는 0, 최대치는 전체 예산 임.

    2) 두 값을 사용하여 이분 탐색을 진행, 특정 상한액을 설정했을 때, 모든 도시애 배분 가능한지
    시뮬레이션 진행

    3) 가능하다면 임시 상한액으로 설정 후, 상한액을 증액하여 다시 시뮬레이션.

    4) 불가능 하다면 예산을 줄여서 시뮬레이션

    5) 모든 이분 탐색이 끝난 후, 저장된 상한액이 정답

풀이 코드

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
            mid = (start + end) / 2;
    
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

풀이 후기

    뭔가 문제를 분석해야 하는데, 느낌적인 느낌으로 갑자기 이분탐색인데? 하면서 풀어버렸다..

    나에게는 양치기가 답인가벼

![image](https://github.com/user-attachments/assets/a64bfe60-b0e0-4487-95d2-3b8122a88a3a)

    

    
