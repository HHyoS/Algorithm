문제 사이트 : https://www.acmicpc.net/problem/7562

문제 설명:

    체스판 위에 한 나이트가 놓여져 있다.
    나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
    나이트가 이동하려고 하는 칸이 주어진다.
    나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?
    
<img width="400" height ="250" alt="knight" src="https://user-images.githubusercontent.com/57944215/143767299-15640a50-6ce8-4c81-b3aa-d030c596f244.png">


입력

    입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
    각 테스트 케이스는 세 줄로 이루어져 있다. 
    첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
    체스판의 크기는 l × l이다.
    체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
    둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력

    각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.

예제 입력 1 

    3
    8
    0 0
    7 0
    100
    0 0
    30 50
    10
    1 1
    1 1
    
예제 출력 1 

    5
    28
    0
    

풀이 알고리즘

    1. 나이트의 이동 위치가 (x,y) 일 떄, 3번 움직여 도착한 (x,y)와 4번 움직여 도착한 (x,y) 중 3번 움직인 (x,y)만 필요
    2. 최소 이동으로 특정위치에 도착하면, 그 이후 그 위치에 다시 방문할 필요가없음.
    3. 그러므로 queue를 이용한 BFS탐색 방식 실시.
    
[ 구 현 ]

1. 사용 전역 변수 

        int n,m;
        bool map[301][301] = { 0, };
        int mmove[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
        
    1) n = 테스트 케이스 갯수, m = 특정 케이스의 체스판 크기
    2) map = 체스판의 방문을 체크하는 배열
    3) mmove = 나이트의 움직임을 나타낸 배열로, 특정위치 (x,y)에 있을 때 배열의 각 요소를 더한 값이 나이트의 위치

2. BFS 구현


    	  cin >> n; // 테스트 케이스 갯수 입력
        
        int x, y; // 현재 좌표 
        
        int tar, gett; // 목표 위치
        
        queue<pair<int, int>> que; // 특정 이동횟수에서 가질 수 있는 위치의 갯수
        
        for (int a = 0; a < n; ++a) {
          cin >> m >> x >> y >> tar >> gett; 
          
          que.push({ x,y }); // 초기 위치를 queue에 push
          
          memset(map, 0, sizeof(map)); // 방문배열 초기화
          
          int count = 0; // 이동횟수 초기화
          while (!que.empty()) { // que가 비는게 while문의 탈출조건
            int size = que.size(); // que의 사이즈만큼 for문 반복
            for (int a = 0; a < size; ++a) {
              x = que.front().first;  // que의 가장 앞 값을 현재 좌표로 설정
              y = que.front().second;
              que.pop(); // que pop!
              if ((x == tar) && (y == gett)) { // 주어진 좌표가 목표 위치와 같다면
                cout << count << "\n"; // 이동 횟수를 출력하고
                que = queue<pair<int, int>>(); // que를 비운 뒤(while문 탈출조건)
                break; // for문종료
              }
              for (int a = 0; a < 8; ++a) { // 나이트의 이동 구현
                if ((x + mmove[a][0] >= 0) && (x + mmove[a][0] < m) && (y + mmove[a][1] >= 0) && (y + mmove[a][1] < m)) { // 이동 위치가 체스판 안이라면
                  if (!map[x + mmove[a][0]][y + mmove[a][1]]) { // 이동 한 위치가 방문 하지않은 위치라면!
                    que.push({ x + mmove[a][0], y + mmove[a][1] }); // que에 해당 위치를 넣은 뒤
                    map[x + mmove[a][0]][y + mmove[a][1]] = 1; // 방문표시
                  }
                }
              }
            }
            ++count; //for문의 한 사이클이 지난 뒤에도 목표 위치를 못찾았다면 count 증가
          }
        }
