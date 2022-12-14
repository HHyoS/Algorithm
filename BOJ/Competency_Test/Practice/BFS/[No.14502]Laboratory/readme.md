문제 사이트 : https://www.acmicpc.net/problem/14502

문제 설명 

    인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 
    
    다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

    연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.
    
    연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

    일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
    
    새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

    예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

    2 0 0 0 1 1 0
    0 0 1 0 1 2 0
    0 1 1 0 1 0 0
    0 1 0 0 0 0 0
    0 0 0 0 0 1 1
    0 1 0 0 0 0 0
    0 1 0 0 0 0 0
    
    이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 
    
    아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

    2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

    2 1 0 0 1 1 0
    1 0 1 0 1 2 0
    0 1 1 0 1 0 0
    0 1 0 0 0 1 0
    0 0 0 0 0 1 1
    0 1 0 0 0 0 0
    0 1 0 0 0 0 0
    
    바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

    2 1 0 0 1 1 2
    1 0 1 0 1 2 2
    0 1 1 0 1 2 2
    0 1 0 0 0 1 2
    0 0 0 0 0 1 1
    0 1 0 0 0 0 0
    0 1 0 0 0 0 0
    
    벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.
    
    위의 지도에서 안전 영역의 크기는 27이다.

    연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

    둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 
    
    0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 
    
    2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

    빈 칸의 개수는 3개 이상이다.

출력

    첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

예제 입력 1 

    7 7
    2 0 0 0 1 1 0
    0 0 1 0 1 2 0
    0 1 1 0 1 0 0
    0 1 0 0 0 0 0
    0 0 0 0 0 1 1
    0 1 0 0 0 0 0
    0 1 0 0 0 0 0
    
예제 출력 1 

    27
    
예제 입력 2 

    4 6
    0 0 0 0 0 0
    1 0 0 0 0 2
    1 1 1 0 0 2  
    0 0 0 0 0 2
    
예제 출력 2 

    9
    
예제 입력 3 

    8 8
    2 0 0 0 0 0 0 2
    2 0 0 0 0 0 0 2
    2 0 0 0 0 0 0 2
    2 0 0 0 0 0 0 2
    2 0 0 0 0 0 0 2
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    
예제 출력 3 

    3
    
    
풀이 알고리즘 

    1. 문제의 풀이순서와 구현방법은 다음과 같습니다.
      1) 바이러스 없는 기둥을 세울 수 있는 위치에 기둥 세개를 세운다.
          -> dfs방식으로 현재 a,b에 기둥을 세웠다면, 다음 탐색에는 
          [1] (a,b+1)에 기둥을 세우거나.
          [2] 기둥을 세우지 않고 넘어가기
          두가지 동작을 하여 기둥을 세울 수 있는 모든 경우에 대해서 탐색 탐색 실시
      2) 기둥을 다 세운 후 바이러스가 확산할 수 없을떄까지 확산시킨다.
          -> 초기에 연구소의 정보를 입력받을 때, 바이러스의 위치는 배열에 저장시킨 후
            기둥 세개를 세운 이후 탐색에서 queue에 해당 위치들을 옮겨 bfs탐색하며 바이러스 확산
      3) 안전구역의 크기를 구한다.
          -> 바이러스가 확산 된 연구소 배열에서 0의 갯수 찾아 더하고
      4) 이전에 구한 안전구역과 비교하여 더 큰값을 저장
          -> 이전에 구한 안전구역과 비교, 큰값 저장
      5) 기둥 세개를 새울 수 있는 모든 경우의 수를 진행 한 후 안전구역의 최대값을 출력
          -> 저장된 최대의 안전구역 크기 출력
          

[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    using namespace std;
    int n,m;
    int arr[8][8]; // 연구소 정보를 저장하는 배열
    int big = -1; // 안전구역의 최대값
    int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    int vir[64][2];
    int idx = 0; // 저장된 바이러스 위치 갯수
    
    void dfs(int x, int y, int count) {
      if (count == 3) { // 기둥을 세개 세웠다면
        queue<pair<int, int>> que; // queue 선언 후
        for (int a = 0; a < idx; ++a) { // queue에 바이러스의 위치 복사
          que.push({ vir[a][0],vir[a][1] });
        }
        int cpy[8][8]; // 연구소 정보를 복사하여 기존의 정보 유지
        memcpy(cpy, arr, sizeof(arr));
        
        while (!que.empty()) { // 바이러스가 확산할 수 없을떄까지 확산
          int size = que.size();
          for (int a = 0; a < size; ++a) {
            int xx = que.front().first;
            int yy = que.front().second;
            que.pop();
            for (int b = 0; b < 4; ++b) {
              int xxx = xx + mov[b][0];
              int yyy = yy + mov[b][1];
              if ((xxx >= 0) && (xxx < n) && (yyy >= 0) && (yyy < m)) {
                if (cpy[xxx][yyy] == 0) {
                  cpy[xxx][yyy] = 2;
                  que.push({ xxx,yyy });
                }
              }
            }
          }
        }
        int answer = 0;
        for (int a = 0; a < n; ++a) {
          for (int b = 0; b < m; ++b) {
            if (cpy[a][b] == 0) // 안전구역 이라면 answer +1
              ++answer;
          }
        }
        if (answer > big) { // answer 가 현재까지 구한 안전구역 최대값보다 크다면
          big = answer; // big = answer
        }
      }
      else { // 기둥을 다 세우지 못했다면
        ++y; // y를 하나 증가시키고
        if(y >= m){ // y값이 범위를 넘어섰다면
          y = 0; 
          ++x; // x값을 증가시키고, y값을 0으로
          if (x >= n) // x가 범위를 벗어나면
            return; // dfs탐색 종료
        }
        if (arr[x][y] == 0) { // 현재 위치가 벽을 세울 수 있는 위치라면
          arr[x][y] = 1; // 벽을 세우고
          dfs(x, y, count + 1); // dfs탐색 돌리고
          arr[x][y] = 0; // dfs탐색 종료 후 벽 철거
        }
        dfs(x, y, count); // 현재 위치가 뭐든 생략

      }
    }
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    //	freopen("Input.txt", "r", stdin);

      cin >> n >> m;
      for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
          cin >> arr[a][b];
          if (arr[a][b] == 2) { // 입력받은 값이 바이러스일경우
            vir[idx][0] = a;
            vir[idx][1] = b; // 바이러스의 위치 저장
            ++idx; // 바이러스 갯수 추가
          }
        }
      }


      for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) { // 기둥 세개 세우기 시작
          if (arr[a][b] == 0) { // 현재 위치가 아무것도 없는 위치라면
            arr[a][b] = 1; // 기둥을 세우고 
            dfs(a, b, 1); // dfs탐색을 시킨 후
            arr[a][b] = 0; // dfs탐색 종료 후 
          }
        }
      }
      cout << big;
      return 0;
    }


   
