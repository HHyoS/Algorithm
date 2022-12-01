문제 사이트 : https://www.acmicpc.net/problem/17472

문제 설명 :

    섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 한다. 

    이 나라의 지도는 N×M 크기의 이차원 격자로 나타낼 수 있고, 격자의 각 칸은 땅이거나 바다이다.

    섬은 연결된 땅이 상하좌우로 붙어있는 덩어리를 말하고, 아래 그림은 네 개의 섬으로 이루어진 나라이다. 색칠되어있는 칸은 땅이다.

<img src="https://user-images.githubusercontent.com/57944215/187015330-491332f5-5128-4dd7-b87b-2c3029c0608d.jpg" width="40%" height="300px">


    다리는 바다에만 건설할 수 있고, 다리의 길이는 다리가 격자에서 차지하는 칸의 수이다. 

    다리를 연결해서 모든 섬을 연결하려고 한다. 

    섬 A에서 다리를 통해 섬 B로 갈 수 있을 때, 섬 A와 B를 연결되었다고 한다.

    다리의 양 끝은 섬과 인접한 바다 위에 있어야 하고, 한 다리의 방향이 중간에 바뀌면 안된다.

    또, 다리의 길이는 2 이상이어야 한다.

    다리의 방향이 중간에 바뀌면 안되기 때문에, 다리의 방향은 가로 또는 세로가 될 수 밖에 없다.

    방향이 가로인 다리는 다리의 양 끝이 가로 방향으로 섬과 인접해야 하고, 

    방향이 세로인 다리는 다리의 양 끝이 세로 방향으로 섬과 인접해야 한다.

    섬 A와 B를 연결하는 다리가 중간에 섬 C와 인접한 바다를 지나가는 경우에 섬 C는 A, B와 연결되어있는 것이 아니다. 

    아래 그림은 섬을 모두 연결하는 올바른 2가지 방법이고, 다리는 회색으로 색칠되어 있다. 

    섬은 정수, 다리는 알파벳 대문자로 구분했다.

<img src="https://user-images.githubusercontent.com/57944215/187015331-2e33c055-9b27-4adb-87bd-caf322be3827.jpg" width="40%" height="300px">

	
다리의 총 길이: 13

D는 2와 4를 연결하는 다리이고, 3과는 연결되어 있지 않다.


<img src="https://user-images.githubusercontent.com/57944215/187015332-df920f95-e3fe-4f91-9c58-815e98efe2f4.jpg" width="40%" height="300px">

다리의 총 길이: 9 (최소)

다음은 올바르지 않은 3가지 방법이다

<img src="https://user-images.githubusercontent.com/57944215/187015350-3c6df2e5-31dd-4b83-824f-bb4615004cf7.jpg" width="40%" height="300px">

C의 방향이 중간에 바뀌었다	

<img src="https://user-images.githubusercontent.com/57944215/187015354-cfbe6445-384c-465d-a839-04bce6cbeebf.jpg" width="40%" height="300px">
D의 길이가 1이다.	

<img src="https://user-images.githubusercontent.com/57944215/187015358-e9550040-7bb8-486d-824b-f986a98ab1a6.jpg" width="40%" height="300px">
가로 다리인 A가 1과 가로로 연결되어 있지 않다.

다리가 교차하는 경우가 있을 수도 있다. 교차하는 다리의 길이를 계산할 때는 각 칸이 각 다리의 길이에 모두 포함되어야 한다. 아래는 다리가 교차하는 경우와 기타 다른 경우에 대한 2가지 예시이다.

<img src="https://user-images.githubusercontent.com/57944215/187015373-8492e9ac-d344-4cda-8075-3fbbabf7a4ee.jpg" width="40%" height="300px">
A의 길이는 4이고, B의 길이도 4이다.

총 다리의 총 길이: 4 + 4 + 2 = 10


<img src="https://user-images.githubusercontent.com/57944215/187015375-cf443e51-e90a-4dc4-9122-0b124545e119.jpg" width="40%" height="300px">
다리 A: 2와 3을 연결 (길이 2)

다리 B: 3과 4를 연결 (길이 3)

다리 C: 2와 5를 연결 (길이 5)

다리 D: 1과 2를 연결 (길이 2)

총 길이: 12

    나라의 정보가 주어졌을 때, 모든 섬을 연결하는 다리 길이의 최솟값을 구해보자.

입력

    첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. 
    
    둘째 줄부터 N개의 줄에 지도의 정보가 주어진다. 
    
    각 줄은 M개의 수로 이루어져 있으며, 수는 0 또는 1이다. 0은 바다, 1은 땅을 의미한다.

출력

    모든 섬을 연결하는 다리 길이의 최솟값을 출력한다. 모든 섬을 연결하는 것이 불가능하면 -1을 출력한다.

제한

    1 ≤ N, M ≤ 10
    3 ≤ N×M ≤ 100
    2 ≤ 섬의 개수 ≤ 6

예제 입력 1 

    7 8
    0 0 0 0 0 0 1 1
    1 1 0 0 0 0 1 1
    1 1 0 0 0 0 0 0
    1 1 0 0 0 1 1 0
    0 0 0 0 0 1 1 0
    0 0 0 0 0 0 0 0
    1 1 1 1 1 1 1 1

예제 출력 1 

    9

예제 입력 2 

    7 8
    0 0 0 1 1 0 0 0
    0 0 0 1 1 0 0 0
    1 1 0 0 0 0 1 1
    1 1 0 0 0 0 1 1
    1 1 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    1 1 1 1 1 1 1 1

예제 출력 2 

    10

예제 입력 3 

    7 8
    1 0 0 1 1 1 0 0
    0 0 1 0 0 0 1 1
    0 0 1 0 0 0 1 1
    0 0 1 1 1 0 0 0
    0 0 0 0 0 0 0 0
    0 1 1 1 0 0 0 0
    1 1 1 1 1 1 0 0

예제 출력 3 

    9

예제 입력 4 

    7 7
    1 1 1 0 1 1 1
    1 1 1 0 1 1 1
    1 1 1 0 1 1 1
    0 0 0 0 0 0 0
    1 1 1 0 1 1 1
    1 1 1 0 1 1 1
    1 1 1 0 1 1 1

예제 출력 4 

    -1  
 
풀이 알고리즘

    0과 1로 주어지는 지도의 정보를 바탕으로 섬과 섬사이를 연결하는 다리를 만들 때, 최소 길이로
    
    만드는 법을 찾아내는 문제였습니다.
    
    제가 푼 문제의 순서는 다음과 같습니다.
    
    1. 각 섬마다 bfs돌려 같은 섬끼리는 고유의 값을 갖도록 함(1,2,3,4,...)
    
    2. 2중for문으로 섬을 찾은 뒤, idx번의 값을 갖는 섬이 아닌 다른 4방향의 직선 탐색으로 찾아낸 섬의
        다리길이를 저장
        
    3. 2중for문을 반복하여 모든 섬끼리의 정보를 최단길이로 갱신
    
    4. 크루스칼 알고리즘을 사용하여 최단길이의 섬부터 연결시키고, Union Find를 통해
    
    이미 연결된 섬이라면 생각, 아니면 연결 을 반복
    
    5. 만약 N개의 섬이 확인되었다면, N-1개의 연결선이 될때까지 연결을 반복하고
    
    만약 N-1개의 연결을 할 수 없다면 모든 섬을 연결할 수 없으므로 -1을 출력
    
구 현

      #include<iostream>
      #include<string>
      #include<algorithm>
      #include<queue>

      using namespace std;

      struct Node {
        int x;
        int y;
      };
      struct T {
        int from;
        int to;
        int cost;
      };
      int N, M;
      int map[11][11];
      bool check[11][11];
      int mov[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
      int tot;
      int leng[11][11];
      int parent[10];



      bool operator<(T a, T b) {
        if (a.cost < b.cost) return 0;
        if (a.cost > b.cost) return 1;

        return 0;
      }
      int Find(int now) {
        if (parent[now] == 0) {
          return now;
        }

        return parent[now] = Find(parent[now]);
      }

      void Union(int A, int B) {

        int pA = Find(A);
        int pB = Find(B);

        if (pA == pB) return;

        parent[pB] = pA;
      }
      void finder(int x, int y) {

        int now = map[x][y];
        for (int a = 0; a < 4; ++a) {
          int t = 1;
          while (1) {
            int xx = x + mov[a][0] * t;
            int yy = y + mov[a][1] * t;

            if (xx < 0 || xx >= N || yy < 0 || yy >= M) break;
            if (map[x][y] == map[xx][yy]) break;
            if (map[xx][yy] == 0) {
              ++t;
            }
            else {
              if (t <= 2) break;
              int target = map[xx][yy];
              if (leng[now][target] ==0 || leng[now][target] > t-1) {
                leng[now][target] = t-1;
              }
              break;
            }
          }
        }
      }


      void bfs(int x, int y, int idx) {
        queue<Node> que;
        que.push({ x,y });
        check[x][y] = 1;
        map[x][y] = idx;

        while (!que.empty()) {
          int xx = que.front().x;
          int yy = que.front().y;
          que.pop();

          for (int a = 0; a < 4; ++a) {
            int nx = xx + mov[a][0];
            int ny = yy + mov[a][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == 0 || check[nx][ny]) continue;

            que.push({ nx,ny });
            check[nx][ny] = 1;
            map[nx][ny] = idx;
          }
        }
      }

      void solve() {
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < M; ++b) {
            finder(a, b);
          }
        }

        priority_queue<T> que;
        for (int a = 1; a <= tot; ++a) {
          for (int b = a + 1; b <= tot; ++b) {
            if (leng[a][b] >= 2) {
              que.push({ a,b,leng[a][b] });
            }
          }
        }

        int ans = 0;
        int edge = 0;
        while (!que.empty()) {
          int from = que.top().from;
          int to = que.top().to;
          int cost = que.top().cost;

          que.pop();

          if (Find(from) != Find(to)) {
            ans += cost;
            Union(from, to);
            ++edge;
          }
        }
        if (edge+1 != tot)
          cout << -1;
        else
          cout << ans;
      }
      void input() {
        cin >> N >> M;
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
          }
        }

        int cnt = 1;
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < M; ++b) {
            if (map[a][b] == 1 && !check[a][b]) {
              bfs(a, b,cnt);
              ++cnt;
            }
          }
        }
        tot = cnt - 1;

      }
      int main()
      {
        ios::sync_with_stdio(false);

        cin.tie(NULL);
        cout.tie(NULL);

        input();
        solve();
        return 0;

      }
      
      
풀이 인증

![image](https://user-images.githubusercontent.com/57944215/187015831-50ae3759-25b7-4f7d-be5b-6afd9b196793.png)


