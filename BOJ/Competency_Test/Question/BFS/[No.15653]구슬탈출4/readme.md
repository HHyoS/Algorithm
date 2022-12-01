문제 사이트 :

문제 설명 :

    스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 
    
    구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

    보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 
    
    가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
    
    빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다.
    
    게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

    이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
    
    왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

    각각의 동작에서 공은 동시에 움직인다. 
    
    빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
    
    빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 
    
    빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
    
    또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 
    
    기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

    보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력

    첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 
    
    다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 
    
    이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. 
    
    '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 
    
    'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

    입력되는 모든 보드의 가장자리에는 모두 '#'이 있다.
    
    구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력

    최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다.
    
    만약, 어떻게 움직여도 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

예제 입력 1 

    5 5
    #####
    #..B#
    #.#.#
    #RO.#
    #####

예제 출력 1 

    1

예제 입력 2 

    7 7
    #######
    #...RB#
    #.#####
    #.....#
    #####.#
    #O....#
    #######

예제 출력 2 

    5

예제 입력 3 

    7 7
    #######
    #..R#B#
    #.#####
    #.....#
    #####.#
    #O....#
    #######

예제 출력 3 

    5

예제 입력 4 

    10 10
    ##########
    #R#...##B#
    #...#.##.#
    #####.##.#
    #......#.#
    #.######.#
    #.#...##.#
    #.#.#.#..#
    #...#.O#.#
    ##########

예제 출력 4 

    12

예제 입력 5 

    3 7
    #######
    #R.O.B#
    #######

예제 출력 5 

    1

예제 입력 6 

    10 10
    ##########
    #R#...##B#
    #...#.##.#
    #####.##.#
    #......#.#
    #.######.#
    #.#....#.#
    #.#.##...#
    #O..#....#
    ##########

예제 출력 6 

    7

예제 입력 7 

    3 10
    ##########
    #.O....RB#
    ##########

예제 출력 7 

    -1
  
풀이 알고리즘

    주어진 게임판의 정보와 파란색,빨간색 구슬의 위치가 주어질 때, 빨간색 구슬만을 구멍에 넣을 수 있는 최소 횟수를 찾는
    
    문제였습니다.
    
    이 문제를 풀 때 생각해야하는 부분은 다음과 같습니다.
    
    1. 상,하,좌,우 움직임을 취했을 때, 같은 위치에 구슬이 자리잡을 경우 반복하지 않도록하기
    
    2. 빨간구슬이 구멍에 들어가더라도 파란구슬이 구멍에 들어가면 안되므로, 빨간구슬 이동 후에 파란구슬 이동도 확인
    
    위의 두 가지를 생각하고 상 하 좌 우 를 구현하면, 현재 구슬의 위치부터 벽을만날때까지 이동을 시키고
    
    파랑과 빨강 둘 다 이동을 시키고 난 뒤에 해당 위치에 도착한 적이 있는지 확인하고, 도착한적이 있다면
    
    동작하지 탐색하지 않도록 하여 문제를 해결하였습니다.
    
구 현

    #include<iostream>
    #include<vector>
    #include<queue>
    #include<algorithm>
    using namespace std;

    struct Node {
      int x;
      int y;
    };
    int N, M;
    char map[11][11];
    bool check[11][11][11][11]; // blue /red순
    queue<Node> blue;
    queue<Node> red;

    bool checker;
    int cnt;
    void left(int rx, int ry, int bx, int by) {

      int nry = ry;
      int nby = by;

      while (1) {
        nry -= 1;
        if (map[rx][nry] != '#') {
          if (map[rx][nry] == 'O')
            break;
          else
            continue;
        }
        else {
          nry += 1;
          break;
        }
      }
      while (1) {
        nby -= 1;
        if (map[bx][nby] != '#') {
          if (map[bx][nby] == 'O')
            return;
          else
            continue;
        }
        else {
          nby += 1;
          break;
        }
      }
      if (rx == bx && nry == nby) {
        if (ry < by) {
          nby = nby + 1;
        }
        else {
          nry = nry + 1;
        }
      }
      if (map[rx][nry] == 'O') {
        checker = 1;
        return;
      }
      if (check[rx][nry][bx][nby])
        return;
      else {
        check[rx][nry][bx][nby] = 1;
        red.push({ rx,nry });
        blue.push({ bx,nby });
      }
    }
    void right(int rx, int ry, int bx, int by) {

      int nry = ry;
      int nby = by;

      while (1) {
        nry += 1;
        if (map[rx][nry] != '#') {
          if (map[rx][nry] == 'O')
            break;
          else
            continue;
        }
        else {
          nry -= 1;
          break;
        }
      }
      while (1) {
        nby += 1;
        if (map[bx][nby] != '#') {
          if (map[bx][nby] == 'O')
            return;
          else
            continue;
        }
        else {
          nby -= 1;
          break;
        }
      }
      if (rx == bx && nry == nby) {
        if (ry > by) {
          nby = nby - 1;
        }
        else {
          nry = nry - 1;
        }
      }
      if (map[rx][nry] == 'O') {
        checker = 1;
        return;
      }
      if (check[rx][nry][bx][nby])
        return;
      else {
        check[rx][nry][bx][nby] = 1;
        red.push({ rx,nry });
        blue.push({ bx,nby });
      }
    }
    void up(int rx, int ry, int bx, int by) {

      int nrx = rx;
      int nbx = bx;

      while (1) {
        nrx -= 1;
        if (map[nrx][ry] != '#') {
          if (map[nrx][ry] == 'O')
            break;
          else
            continue;
        }
        else {
          nrx += 1;
          break;
        }
      }
      while (1) {
        nbx -= 1;
        if (map[nbx][by] != '#') {
          if (map[nbx][by] == 'O')
            return;
          else
            continue;
        }
        else {
          nbx += 1;
          break;
        }
      }
      if (nrx == nbx && ry == by) {
        if (rx < bx) {
          nbx = nbx + 1;
        }
        else {
          nrx = nrx + 1;
        }
      }
      if (map[nrx][ry] == 'O') {
        checker = 1;
        return;
      }
      if (check[nrx][ry][nbx][by])
        return;
      else {
        check[nrx][ry][nbx][by] = 1;
        red.push({ nrx,ry });
        blue.push({ nbx,by });
      }
    }

    void down(int rx, int ry, int bx, int by) {

      int nrx = rx;
      int nbx = bx;

      while (1) {
        nrx += 1;
        if (map[nrx][ry] != '#') {
          if (map[nrx][ry] == 'O')
            break;
          else
            continue;
        }
        else {
          nrx -= 1;
          break;
        }
      }
      while (1) {
        nbx += 1;
        if (map[nbx][by] != '#') {
          if (map[nbx][by] == 'O')
            return;
          else
            continue;
        }
        else {
          nbx -= 1;
          break;
        }
      }
      if (nrx == nbx && ry == by) {
        if (rx >bx) {
          nbx = nbx - 1;
        }
        else {
          nrx = nrx - 1;
        }
      }
      if (map[nrx][ry] == 'O') {
        checker = 1;
        return;
      }
      if (check[nrx][ry][nbx][by])
        return;
      else {
        check[nrx][ry][nbx][by] = 1;
        red.push({ nrx,ry });
        blue.push({ nbx,by });
      }
    }
    int bfs() {
      check[blue.front().x][blue.front().y][red.front().x][red.front().y] = 1;

      cnt = 1;
      while (!red.empty()) {


        int size = red.size();
        for (int i = 0; i < size; ++i) {
          int rX = red.front().x;
          int rY = red.front().y;
          int bX = blue.front().x;
          int bY = blue.front().y;
          red.pop();
          blue.pop();

          for (int a = 0; a < 4; ++a) {
            if (a == 0) {
              left(rX, rY, bX, bY);
            }
            else if (a == 1) {
              right(rX, rY, bX, bY);
            }
            else if (a == 2) {
              up(rX, rY, bX, bY);
            }
            else {
              down(rX, rY, bX, bY);
            }

            if (checker) {
              return cnt;
            }
          }
        }
        ++cnt;
      }

      return -1;
    }
    void input() {
      cin >> N >> M;
      for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
          cin >> map[a][b];
          if (map[a][b] == 'B') {
            blue.push({ a,b });
            map[a][b] = '.';
          }
          else if (map[a][b] == 'R') {
            red.push({ a,b });
            map[a][b] = '.';
          }
          else
            continue;
        }
      }
    }
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      //freopen_s(new FILE*, "input.txt", "r", stdin);
      input();
      cout << bfs();
      return 0;
    }

풀이 인증샷

![image](https://user-images.githubusercontent.com/57944215/188309128-b8b05d91-43a5-4413-96df-681c96f7e522.png)
