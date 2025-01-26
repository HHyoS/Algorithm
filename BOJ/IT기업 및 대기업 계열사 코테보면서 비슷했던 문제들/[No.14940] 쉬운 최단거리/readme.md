문제 사이트 : https://www.acmicpc.net/problem/14940

문제 설명 :

![image](https://github.com/user-attachments/assets/335a71a2-55f3-4b2b-a435-ca25908a60b1)
![image](https://github.com/user-attachments/assets/96ecd83d-f93e-4b1e-8815-f0e420489446)

풀이 알고리즘

      맵 정보가 주어질 때, 각 위치별 최단거리를 출력하는 문제 '쉬운 최단거리' 입니다.
      
      문제의 설명처럼 최단거리만 구하면 되기 때문에 priority_queue를 사용하여 
      
      이동 횟수가 작은 값의 우선순위를 높혀 최단거리만을 이용하도록 하여 구현하면 됩니다.

      문제를 풀이하며 fail이 발생한 케이스 세가지로 아래와 같습니다.

      1) 배열 크기 미스

      2) 코드 상 N,M 처리 미스

      3) 방문할 수 있지만, 방문하지 못한 위치에 대한 출력 값

      1)과 3)은 문제 이해 미스, 2)는 구현상 실수 였는데 해당 부분만 신경 쓴다면

      풀이에 문제 없을 것으로 보입니다.

  풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    /*
        문제 사이트 : https://www.acmicpc.net/problem/14940
        문제 설명 :
            맵 정보가 주어질 때, 각 위치별 최단거리를 출력하는 문제 '쉬운 최단거리' 입니다.
            문제의 설명처럼 최단거리만 구하면 되기 때문에
            priority_queue를 사용하여 이동 횟수가 작은 값의 우선순위를 높혀
            최단거리만을 이용하도록 하여 구현하면 됩니다.
    */
    
    struct Node {
        int x;
        int y;
        int cnt;
    };
    
    bool operator<(Node a, Node b) {
        if (a.cnt == b.cnt) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.cnt > b.cnt;
    }
    
    int N, M;
    int info[1001][1001];
    int mini[1001][1001];
    int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
    int tx, ty;
    priority_queue<Node> que;
    
    // 갈 수 있는 위치들에 대해 모두 최대치 입력 -> 아직 방문하지 않음을 표시
    void init() {
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                if (info[a][b] != 0)
                    mini[a][b] = 21e8;
            }
        }
    }
    void Solve() {
    
        // 초기 위치 tx,ty
        que.push({ tx,ty,0 });
        mini[tx][ty] = 0;
        while (!que.empty()) {
            Node nNode = que.top();
            que.pop();
            // 이미 최단 거리로 방문한 기록이 있다면 스킵
            if (mini[nNode.x][nNode.y] < nNode.cnt) continue;
    
            for (int a = 0; a < 4; ++a) {
                int nx = nNode.x + mov[a][0];
                int ny = nNode.y + mov[a][1];
                int nCnt = nNode.cnt + 1;
    
                // 1) 새로 방문할 위치가 지도를 벗어났거나 2) 갈 수 없는 장소거나 3) 이미 최단거리로 방문한 위치라면 스킵
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (info[nx][ny] == 0) continue;
                if (mini[nx][ny] <= nCnt) continue;
    
                mini[nx][ny] = nCnt;
                que.push({ nx,ny,nCnt });
            }
        }
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                if (mini[a][b] == 21e8 && info[a][b] != 0)
                    cout << -1 << " ";
                else {
                    cout << mini[a][b] << " ";
                }
            }
            cout << "\n";
        }
    }
    void Input() {
        cin >> N >> M;;
    
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                cin >> info[a][b];
                if (info[a][b] == 2) {
                    tx = a;
                    ty = b;
                }
            }
        }
    
        init();
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

    설 연휴에도 알고리즘 푸는 나는 멋져

    아 근데 문제 좀 잘 읽자.. 이거 코테였으면 틀렸다잉

![image](https://github.com/user-attachments/assets/73fa1867-3e04-4e95-822d-118c726d09b9)
