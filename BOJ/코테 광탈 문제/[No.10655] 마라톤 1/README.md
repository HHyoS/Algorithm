문제 사이트 : https://www.acmicpc.net/problem/10655

문제 설명  

![image](https://github.com/user-attachments/assets/e0188c29-3028-4349-9d04-8aaf2409a043)
![image](https://github.com/user-attachments/assets/b200e611-a346-4389-af1a-6c01e5a46073)

풀이 알고리즘

    최대 10만개의 체크 포인트 좌표(x,y)가 주어지고, 체크포인트를 모두 통과해야한다.
    하지만 그 중 단 하나의 체크포인트는 무시할 수 있는데, 최소 비용으로 체크포인트를 통과할 수 있는
    하나의 체크포인트를 찾아보자.
    그리고 그 때 최소 비용을 출력하자 << 이게 문제의 정리

    N이 최대 10만개 이므로 특정 케이스를 지날 때 마다 거리를 측정하면 10민 * 10만 번 연산으로
    시간 초과가 발생하게 됨.

    따라서 기존 연산 이력을 재사용하여 풀이를 진행해야하고 풀이 방법은 아래와 같음.

    1) 모든 체크포인트를 지날 때, 각 체크포인트 별 필요한 코스트를 기록 (cost 배열)
    2) 기록된 코스트를 사용하여 특정 위치를 넘어갈 떄 코스트 계산
    ex- a번째 체크포인트를 넘어선다면 = cost[N] - cost[a+1] + cost[a-1] + (a-1번쨰 위치 -> a+1번쨰 위치 비용)

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    struct Node {
        int x;
        int y;
    };
    
    int N;
    vector<Node> v;
    int total_sum[100001];
    
    
    void init() {
        int before = 0;
        int dist = 0;
        for (int a = 1; a < N; ++a) {
            dist += (abs(v[before].x - v[a].x) + abs(v[before].y - v[a].y));
            total_sum[a] = dist;
            before = a;
        }
    }
    
    void Solve() {
        init();
        int ans = 21e8;
        for (int a = 1; a < N - 1; ++a) {
            int cal_dist = total_sum[N - 1] - total_sum[a + 1] + total_sum[a-1] + abs(v[a+1].x - v[a-1].x) + abs(v[a+1].y - v[a-1].y);
            ans = min(ans, cal_dist);
        }
        cout << ans;
    }
    
    
    void Input() { 
        cin >> N;
        for (int a = 0; a < N; ++a) {
            int x,y;
            cin >> x >> y;
            v.push_back({ x,y });
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

풀이 후기

    브롱즈도 무시하지 말 것.
    오늘을 초큼 피곤하니까.... 담에 두 문제 풀게요
![image](https://github.com/user-attachments/assets/102a2093-a18b-4d12-b2e8-8d43b27f44c6)
