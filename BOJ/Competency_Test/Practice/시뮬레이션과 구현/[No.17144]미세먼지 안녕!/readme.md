문제 사이트 : https://www.acmicpc.net/problem/17144

문제 설명 :


    미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다.
    
    공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고,
    
    1×1 크기의 칸으로 나눴다. 
    
    구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로
    
    모니터링하는 시스템을 개발했다. (r, c)는 r행 c열을 의미한다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185641250-efbf3fd6-d174-404f-9ed5-d964c4f3a2e1.png)


    공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 
    
    공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, 
    
    (r, c)에 있는 미세먼지의 양은 Ar,c이다.

    1초 동안 아래 적힌 일이 순서대로 일어난다.

    1. 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
      - (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
      - 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
      - 확산되는 양은 Ar,c/5이고 소수점은 버린다.
      - (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
    
    2. 공기청정기가 작동한다.
      -공기청정기에서는 바람이 나온다.
      -위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
      -바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
      -공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 
      공기청정기로 들어간 미세먼지는 모두 정화된다.
      
    다음은 확산의 예시이다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185641467-68f7129c-4706-4131-ab7b-3317bc188870.png)


    왼쪽과 오른쪽에 칸이 없기 때문에, 두 방향으로만 확산이 일어났다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185641476-a975f453-345d-4b2b-b96d-002bb07feb56.png)


    인접한 네 방향으로 모두 확산이 일어난다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185641483-2266e6a8-1be9-40a8-a8c6-a4662ab89e25.jpg)


    공기청정기가 있는 칸으로는 확산이 일어나지 않는다.

    공기청정기의 바람은 다음과 같은 방향으로 순환한다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185641502-18f8d501-d02a-4ddb-8759-656e0d474728.jpg)


    방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.

입력

    첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.

    둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다.
    
    공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다
    
    . -1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.

출력

    첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력한다.

예제 입력 1 

    7 8 1
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 1 

    188

미세먼지의 확산이 일어나면 다음과 같은 상태가 된다. 

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185640922-f746c8c9-2a36-4fee-986f-ef70b00f9e31.png)


공기청정기가 작동한 이후 상태는 아래와 같다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/185640848-d3d59c5a-37f2-4b11-9bd2-4eca8d093d86.png)


예제 입력 2 

    7 8 2
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 2 

    188

예제 입력 3 

    7 8 3
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 3 

    186

예제 입력 4 

    7 8 4
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 4 

    178 

예제 입력 5 

    7 8 5
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 5 

    172

예제 입력 6

    7 8 20
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 6 

    71

예제 입력 7 

    7 8 30
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 7 

    52

예제 입력 8 

    7 8 50
    0 0 0 0 0 0 0 9
    0 0 0 0 3 0 0 8
    -1 0 5 0 0 0 22 0
    -1 8 0 0 0 0 0 0
    0 0 0 0 0 10 43 0
    0 0 5 0 15 0 0 0
    0 0 40 0 0 0 20 0

예제 출력 8 

    46

풀이 알고리즘

    주어진 조건에 맞추어 1초동안 두가지 동작 (1) 미세먼지의 확산 (2) 공기청정기의 작동이 실행되고
    
    입력받은 T초동안 두가지 동작이 반복된 이후 남아있는 미세먼지의 양을 출력하는 문제입니다.
    
    문제에서 자세히 설명되있는 동작처럼 (1)미세먼지의 확산 (2) 공기청정기의 작동
    
    을 그대로 구현하면 해결할 수 있는 문제였습니다
    
    (1) 미세먼지의 확산 구현
    
    미세먼지의 확산은 남아있는 미세먼지를 확산시키는 동작으로 배열의 값을 그대로 사용하면
    
    확산되어 증가된 값으로 확산시키는 오류가 발생하기 때문에, queue나 배열에 저장하여 맵에 확산시키고
    
    그 값을 더해가며 미세먼지의 확산 총량을 더하도록 구현하였습니다.
    
    (2) 공기청정기의 작동
    
    공기청정기는 주어진 조건대로 움직이기 때문에 주어진 조건에 맞추어 미세먼지들을 시계,반시계 방향으로
    
    이동시켰고, 공기청정기로 들어가는 미세먼지는 이동시킨 후 공기 청정기의 값을 재할당하여
    
    없어진것으로 처리하여 문제를 해결하였습니다.
    


구 현

    #include<iostream>
    #include<string>
    #include<algorithm>
    #include<queue>

    using namespace std;

    struct Node {
      int x;
      int y;
      int dust;
    };
    int R, C,T;
    int map[51][51];
    bool flag;
    queue<Node> que;
    int tx, ty;
    int mov[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };


    void print() {
      int ans = 0;
      while (!que.empty()) {
        ans += que.front().dust;
        que.pop();
      }
      cout << ans;
    }
    void cleaner(int x, int y) {

      for (int a = x; a > 0; --a) {
        map[a][y] = map[a - 1][y];
      }

      for (int a = 0; a < C-1; ++a) {
        map[0][a] = map[0][a + 1];
      }
      for (int a = 0; a < x; ++a) {
        map[a][C - 1] = map[a + 1][C - 1];
      }

      for (int a = C - 1; a > 1; --a) {
        map[x][a] = map[x][a - 1];
      }
      map[x][1] = 0;
      map[x][y] = -1;

      int xx = x + 1;
      int yy = y;

      for (int a = xx; a < R-1; ++a) {
        map[a][yy] = map[a + 1][yy];
      }

      for (int a = 0; a < C - 1; ++a) {
        map[R - 1][a] = map[R - 1][a + 1];
      }

      for (int a = R - 1; a > xx ; --a) {
        map[a][C - 1] = map[a - 1][C - 1];
      }

      for (int a = C - 1; a > 1; --a) {
        map[xx][a] = map[xx][a - 1];
      }

      map[xx][yy + 1] = 0;
      map[xx][yy] = -1;

      for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
          if (map[a][b] > 0) {
            que.push({ a,b,map[a][b] });
            map[a][b] = 0;
          }
        }
      }
    }
    void bfs() {

      while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int dust = que.front().dust;
        que.pop();
        int wind = dust / 5;
        if (wind != 0) {
          for (int a = 0; a < 4; ++a) {
            int xx = x + mov[a][0];
            int yy = y + mov[a][1];

            if (xx >= 0 && xx < R && yy >= 0 && yy < C && map[xx][yy] >= 0) {
              map[xx][yy] += wind;
              dust -= wind;
            }
          }
        }
        map[x][y] += dust;
      }

      cleaner(tx,ty);

    }

    void input() {
      cin >> R >> C >> T;

      int tmp;
      for (int a = 0; a < R; ++a) {
        for (int b = 0; b < C; ++b) {
          cin >> tmp;
          if (tmp > 0) {
            que.push({ a,b,tmp });
            map[a][b] = 0;
          }
          else {
            map[a][b] = tmp;
            if (tmp == -1 && flag == 0) {
              tx = a;
              ty = b;
              flag = 1;
            }
          }
        }
      }

    }

    void solve() {
      while (T--) {
        bfs();
      }
      print();
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

 

풀이 인증샷

![image](https://user-images.githubusercontent.com/57944215/185643049-2aa4f23d-db8c-4281-8fe4-c24dcafc43dc.png)

