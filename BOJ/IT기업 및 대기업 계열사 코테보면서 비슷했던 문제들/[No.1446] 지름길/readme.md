문제 사이트 : https://www.acmicpc.net/problem/1446

문제 설명 

![image](https://github.com/user-attachments/assets/278335bf-5023-491d-a788-2e3ba88d293f)
![image](https://github.com/user-attachments/assets/a9de9462-da8f-459b-b532-9af4c75dfe48)
![image](https://github.com/user-attachments/assets/1d8943b5-1568-4c7f-ab39-ae60d1b7991b)

풀이 알고리즘

    고속도로의 길이 D와 0-D 사이에 지름질 정보가 주어질 때, 지름길을 이용하여 최단거리를

    출력하는 문제 '지름길' 입니다.

    주어진 정보를 바탕으로 최단거리만 구하면 되는 문제로, 주의 해야할 점은 두 가지 입니다.

    1) 동일한 시작-목적 지점의 정보가 주어질 때 거리가 다를 수 있다.
    2) 지름길을 사용하지 않는 케이스가 더 가까울 수 있다.

    위의 두가지 정보를 사용하여 특정지점 x까지 이동하고, 그 때 지름길이 있다면

    (1) 지름길 사용하기 (2) 이번 지름길을 스킵하고 다음 지름길 사용하기

    두 가지를 고려하여 모든 케이스에 대해 DP 방식으로 구현을 진행하면 풀이가 가능합니다.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    struct Node {
        int d;
        int cost;
    };
    int N, D;
    
    vector<Node> arr[10001];// 이동 코스트 정보 저장
    int mini[10001]; // 이동 최소 코스트 저장
    
    
    
    void Solve() {
    
        for (int a = 0; a <= D; ++a) {
            mini[a] = a;
        }
        for (int a = 0; a <= D; ++a) {
            if (a != 0) {
                 mini[a] = min(mini[a], mini[a - 1] + 1);
            }
            for (int b = 0; b < arr[a].size(); ++b) {
                int nextD = arr[a][b].d;
                int nextCost = arr[a][b].cost;
    
                mini[nextD] = min(mini[nextD], min(mini[a] + nextCost, mini[a] + nextD - a));
            }
        }
    
        cout << mini[D];
    }
    void Input() {
        cin >> N >> D;
        for (int a = 0; a < N; ++a) {
            int s, e, d;
            cin >> s >> e >> d;
            arr[s].push_back({ e,d });
        }
    
    
        /* for debugging
        for (int a = 0; a <= D; ++a) {
            cout << "start at " << a << "\n";
            for (int b = 0; b < info[a].size(); ++a) {
                cout << info[a][b] << " ";
            }
            cout << "===========================\n";
        }
        */
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

    생각없이 풀었는데 DP문제였다.

    생각보다(?) 쉽군

![image](https://github.com/user-attachments/assets/58606e82-57b9-4db9-98f4-f13b02919f06)
