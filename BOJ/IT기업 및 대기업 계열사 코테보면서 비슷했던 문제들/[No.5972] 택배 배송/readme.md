문제 사이트 : https://www.acmicpc.net/problem/5972

문제 설명

![image](https://github.com/user-attachments/assets/1f0ab3e4-f6b5-433e-8049-df6994e032a8)
![image](https://github.com/user-attachments/assets/1f24c44e-c9d7-425c-85fa-13b352b227ee)

풀이 알고리즘

    최소 비용으로 1의 위치에 있는 현서를 N의 위치에 있는 찬홍이에게 도달시키는 문제 '택배 배송' 입니다.

    단순 DFS를 사용할 경우 5만 * 5만의 배열이 필요하여 메모리 초과가 발생하고, 그 외의 단순한
    방법을 사용할 경우에도 불필요한 연산으로 인해 시간 초과가 발생할 수 있습니다.

    위 문제 풀이를 위해서는 1) 입력 배열 최소 사용 2) 최소 비용 관리 3) 불필요 연산 방지 / 세 가지 동작이 필요합니다.

    저는 1) 입력 배열 최소 사용을 위해 vector를 선언하여 실제로 사용하는 정보만 저장하였고
    2) 최소 비용 관리 를 위해서 별도의 배열을 선언하여 현재 위치에 도달할 떄 최소비용일 경우에만 동작하도록
    구현했습니다.
    3) 불필요 연산 방지는 우선순위 큐를 사용하여 최소 비용만 관리하여 현서를 이동시키고,
    현서가 이동 전 현재 내 비용과, 최소 비용에 저장된 값을 비교하여 현재 내 비용이 더 크다면
    이동하지 않도록 구현했습니다.

    코드 전체 동작 요약은 아래와 같습니다.

    1) 양방향 이동 정보를 vector에 저장

    2) 1에서 시작하는 우선순위 큐를 동작하여 1부터 N까지 모든 위치 방문

    3) 우선순위 큐에서 값을 빼낼 때, 내가 가지고 있는 코스트와 최소 비용 코스트를 비교하여
    최소 비용과 같을 때만 동작

    3) 특정 위치를 방문할 때, 최소 비용에 저장된 값과 현재 값+이동 비용을 비교하여 최소 일 경우에만
    이동 진행

    4) 1-3까지 완료된 이후 N번째 위치 이동 비용 출력

    위 동작을 통해 문제 풀이 완료 했습니다.

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    using namespace std;
    
    struct Node {
        int d;
        int cost;
    };
    
    bool operator<(Node a, Node b) {
        if (a.cost == b.cost) {
            return a.d < b.d;
        }
        return a.cost > b.cost;
    }
    int N, M;
    vector<Node> cow[50001]; // 이동 정보 저장
    int mCost[50001]; // 최소 비용 저장
    priority_queue<Node> que; // 코스트가 작은 값을 우선순위로 사용 예정
    
    void Solve() {
    
        que.push({ 1,0 }); // 초기 위치 1
    
        while (!que.empty()) {
            Node nNode = que.top();
            que.pop();
    
    
            // 현재 위치에 올 때 사용한 코스트보다 더 작은 코스트로 현재 위치에 올 수 있었다면
            // 스킵
            if (mCost[nNode.d] < nNode.cost) continue;
            for (int a = 0; a < cow[nNode.d].size(); ++a) {
                int s = cow[nNode.d][a].d;
                int cost = nNode.cost + cow[nNode.d][a].cost;
    
                // 가려고 하는 위치의 최소 비용보다 더 비싸다면 스킵
                if (mCost[s] <= cost) continue;
    
                // 가려고 하는 위치가 1번 위치라면 스킵
                if (s == 1) continue;
                
                mCost[s] = cost;
                if (s != N) { // 가려고 하는 위치가 N 이라면 더 이상 추가 연산 필요하지 않음
                    que.push({ s,cost });
                }
            }
        }
    
        cout << mCost[N];
    }
    void Input() {
        cin >> N >> M;
    
        for (int a = 0; a <= N; ++a) {
            mCost[a] = 21e8;
        }
    
        for (int a = 0; a < M; ++a) {
            int s, e, cost;
            cin >> s >> e >> cost;
            cow[s].push_back({ e,cost });
            cow[e].push_back({ s,cost });
        }
        mCost[1] = 0;
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

    바쁘다 바빠 현대인의 삶
![image](https://github.com/user-attachments/assets/76a3051a-7382-483e-907b-010299612a1a)
