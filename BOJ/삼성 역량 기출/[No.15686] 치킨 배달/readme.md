문제 사이트 : https://www.acmicpc.net/problem/15686

문제 설명 :

![image](https://github.com/user-attachments/assets/6c9764cf-bcf4-4915-ac85-f02b32dc856e)
![image](https://github.com/user-attachments/assets/3bac3e5d-d208-4b85-bb4b-8989a74c00be)
![image](https://github.com/user-attachments/assets/edcd08c3-ece9-4e35-b6f9-98071d2220a2)

풀이 알고리즘

    주어진 정보와 '치킨 거리' 계산법을 이용하여 M개 이하의 치킨집이 남아있을 때

    '치킨 거리' 값이 최대가 되도록 하는 문제 '치킨 거리'입니다.

    문제 풀이 진행시 기본적으로 생각 해야하는 부분은 두 가지 입니다.

      1) 치킨집이 많을수록 '치킨 거리'값은 증가함 -> 따라서 M개 미만을 남기면 안됨.

      2) 탐색의 개수가 적으므로 조합 + 완탐으로 정리 가능

    위 두가지를 바탕으로 풀이를 진행하면 다음과 같이 진행할 수 있습니다.

      1. 치킨집 / 집의 위치를 저장.
      2. M개의 치킨집을 선택하며 저장해둠.
      3. M개가 선택이 완료 되었다면, '치킨 거리'를 계산 함.
      4. 모든 조합에 대해 2-3 과정을 반복하며 '치킨 거리'의 최대 값 구하기


풀이 코드

    #include <iostream>
    #include <vector>
    #include <cstdlib>
    #include <algorithm>
    #include <limits>
    using namespace std;
    
    int n, m;
    vector<pair<int, int>> houses;
    vector<pair<int, int>> chickens;
    int ans = numeric_limits<int>::max();
    
    // 재귀적으로 치킨집 조합을 생성하여 도시의 치킨 거리를 계산하는 함수
    void combination(vector<int>& indices, int start, int k) {
        if (k == 0) {
            int sum = 0;
            // 각 집에 대해 가장 가까운 치킨집까지의 거리를 계산
            for (auto& house : houses) {
                int d = numeric_limits<int>::max();
                for (int idx : indices) {
                    int cx = chickens[idx].first;
                    int cy = chickens[idx].second;
                    int dist = abs(house.first - cx) + abs(house.second - cy);
                    d = min(d, dist);
                }
                sum += d;
            }
            ans = min(ans, sum);
            return;
        }
        for (int i = start; i < chickens.size(); i++) {
            indices.push_back(i);
            combination(indices, i + 1, k - 1);
            indices.pop_back();
        }
    }
    
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int x;
                cin >> x;
                if (x == 1)
                    houses.push_back({i, j});
                else if (x == 2)
                    chickens.push_back({i, j});
            }
        }
        
        vector<int> indices;
        combination(indices, 0, m);
        
        cout << ans << "\n";
        return 0;
    }


풀이 후기

    ㅇㅅㅇ
![image](https://github.com/user-attachments/assets/72ee03f3-6c7d-41c9-9590-6b8620928c9f)
