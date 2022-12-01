문제 사이트 : https://www.acmicpc.net/submit/16948/36374978

문제 설명 :

    게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다.
    
    데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.

    크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다.
    
    데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 
    
    체스판의 행과 열은 0번부터 시작한다.

    데스 나이트는 체스판 밖으로 벗어날 수 없다.

입력

    첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다.
    
    둘째 줄에 r1, c1, r2, c2가 주어진다.

출력

    첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다.
    
    이동할 수 없는 경우에는 -1을 출력한다.

예제 입력 1 

    7
    6 6 0 1

예제 출력 1 

    4

예제 입력 2 

    6
    5 1 0 5

예제 출력 2 

    -1

예제 입력 3 

    7
    0 3 4 3

예제 출력 3 

    2
    
풀이 알고리즘 

    1. 전형적인 체스말의 이동으로 설명되는 BFS문제였습니다.
    
    2. 체스말의 이동이 현재 말의 위치가 (r,c)일떄  
    
    (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 주어지고, 
    
    최단횟수를 찾는 문제이기때문에 bfs방식이 떠올랐습니다.
    
    3. 풀이방법은 다음과 같습니다. 현재 말의 (r,c)를 저장하는 Queue를 선언한 뒤 초기위치를 push하고 
    
    while(!queue.emtpy())의 동작을 시작합니다.
    
    4. 말이 이동하거나 존재했던 위치는 방문을 저장하는 배열을 사용하여 계속해서 채워나가고
    
    이동시킬 때 해당 위치를 방문했었는지 체크를 하고 방문하지 않은경우에만 이동을 시킵니다.
    
    5. 말의 6가지 이동이 다 끝나면 이동을 저장하는 배열을 1추가시키며 현재까지 말의 이동횟수를 증가시킵니다.
    
    6. 만약 이동한 말의 위치가 목적지와 같다면 while문을 종료시키고 이동횟수를 출력, 만약 queue를 더이상 
    
    채울수 없는 상태, 즉 모든 가능한 모든뒤치를 방문했는데도 목적지 도착을 못했다면 -1을 출력합니다.
    
[ 구 현 ] 

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <vector>
    #include <queue>
    #include <utility>
    using namespace std;
    int n;
    bool check[200][200]; // 체스말이 방문한 위치를 저장하는 배열
    int mv[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} }; // 체스말의 6가지 이동
    
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    //	freopen("Input.txt", "r", stdin);
      cin >> n;

      queue<pair<int,int>> que; // 말이 이동한 위치를 저장하는 배열
      
      int answer = 0; // 말의 이동횟수를 저장하는 변수
      
      int x, y, t_x, t_y; // 현재위치 (x,y) 목적지 (t_x,t_y)
      
      cin >> x >> y >> t_x >> t_y;
      
      check[x][y] = 1; // 체스말의 시작지점을 방문표시
      
      que.push({ x,y }); // 현재 위치를 queue에 넣으며 while문 시작
      
      while (!que.empty()) { // que가 비어있지않다면 while문 무한반복
      
        int size = que.size();
        
        for (int a = 0; a < size; ++a) { // que에 저장된 체스말의 이동만큼 for문을 반복하며
        
          int xx = que.front().first;
          int yy = que.front().second; // 말이 answer번 이동했을 때 가능한 위치 (xx,yy)
          
          que.pop();
          
          for (int b = 0; b < 6; ++b) { // 6가지 이동 실시
            int xxx = xx + mv[b][0];
            int yyy = yy + mv[b][1];
            if ((xxx >= 0) && (xxx < n) && (yyy >= 0) && (yyy < n)) { // 체스판의 범위 내의 이동이라면
              if (!check[xxx][yyy]) { // 이동한 위치가 방문 하지않은 위치라면 동작
                if ((xxx == t_x) && (yyy == t_y)) {  // 이동한 위치가 목적지와 같다면
                  ++answer; // answer는 while문 끝에서 해주므로 출력 전 하나 증가
                  cout << answer; // 이동횟수 출력
                  return 0; // 프로그램 종료
                }
                check[xxx][yyy] = 1; // 방문한 위치가 목적지가 아니라면 방문표시 후
                que.push({ xxx,yyy }); // que에 push하여 다음이동 준비
              }
            }
          }
        }
        ++answer; // 6가지 동작 후 목적지에 도착하지 못했다면 이동횟수 1 증가
      }
      cout << "-1"; // 방문가능한 모든위치 방문 후 목적지에 도착하지 못했다면 -1 출력
      return 0;
    }


    
    
