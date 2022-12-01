문제 사이트 : https://www.acmicpc.net/problem/13913

문제 설명 :

    수빈이는 동생과 숨바꼭질을 하고 있다. 
    
    수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
    
    수빈이는 걷거나 순간이동을 할 수 있다. 
    
    만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
    
    순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

    수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력

    첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력

    첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

    둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

예제 입력 1 

    5 17

예제 출력 1 

    4
    5 10 9 18 17

예제 입력 2 

    5 17

예제 출력 2 

    4
    5 4 8 16 17
    
풀이 알고리즘

    1. 수빈이와 동생이 존재 할 수 있는 값의 범위는 0 ~ 100,000 까지.
    2. 수빈이의 이동은 X-1 , X+1, X + X 의 범위 내에서 이동가능하지만 범위는 0 ~ 100,000까지.
    3. 수빈이가 동생을 찾았을 떄 방문한 위치를 역추적해야하므로 역추적을 위한 배열필요!
    
[ 구 현 ]

1. 사용 지역변수와 함수.

        #define MAX 100000 
        int n, m; 
        int check[100001];
        bool map[100001];
        queue<int> que;

        void recur(int num) {
          if (check[num] != -1) {
            recur(check[num]);
            cout << check[num] << " ";
            return;
          }
          return;
        }
        
    1) MAX = 이동 가능한 최대위치 설정
    2) n = 수빈이의 위치, m = 동생의 위치
    3) check = 수빈이가 방문한 위치의 추적을 위한 배열
    4) map = 방문했는지 체크하기 위한 배열
    5) que = BFS탐색을 위해 사용한 queue.
    6) void recur(int num) = 역추적을 위한 함수로, check[n]의 위치에 도달하면 재귀를 종료.

2. main 함수와 BFS 구현

        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);

        //	freopen("Input.txt", "r", stdin);
          cin >> n >> m;
          
          que.push(n); // que에 수빈이의 초기위치 push
          
          map[n] = 1;  // 초기 위치이므로 방문표시
          
          check[n] = -1; // recur의 종료를 위해 -1 입력
          
          int count = 0; // 이동 횟수를 의미하는 변수
          
          while (!que.empty()) { // while문의 탈출 조건으로 que가 비어있을 경우 탈출
            int size = que.size(); // BFS탐색을 위한 que 사이즈 확인
            for (int a = 0; a < size; ++a) { // que 사이즈만큼 반복 실시
              int index = que.front(); 
              que.pop();
              if (index == m) { // 뽑은 que.front의 값이 동생의 위치라면
                cout << count << "\n"; // 횟수를 출력하고
                recur(index); // 수빈이가 index까지 가는데 이동한 동선 출력 후
                cout << m; // 동생의 위치까지 출력
                que = queue<int>(); // que를 비워 while문 탈출조건을 채우고
                break; // 탈출
              }
              if ((index > 0) && (map[index - 1] == 0)) { 
              // 수빈이의 X-1 이동조건으로 현재 위치가 0보다 커야하고, X-1 의 위치가 방문한 기록 X  
                
                que.push(index - 1); 
                // 다음 BFS탐색을 위한 que.push
               
                map[index - 1] = 1; 
                // 추적을 위한 위치표시 
                
                check[index - 1] = index;
                // 방문표시
              }
              if ((index < MAX) && (map[index + 1] == 0)) {
              // 수빈이의 X+1 이동조건으로 현재 위치가 MAX보다 작아야하고, X+1 의 위치를 방문한 기록 X
                
                que.push(index + 1);
                
                map[index + 1] = 1;
                
                check[index + 1] = index;
              }
              int gop = index + index;
              if ((gop <= MAX) && (map[gop] == 0)) {
              // 수빈이의 X * 2 이동조건으로 X * 2가 MAX보다 작아야하고, X * 2 의 위치를 방문한 기록 X
                
                que.push(gop);
                
                map[gop] = 1;
                
                check[gop] = index;
              }
            }
            ++count; // BFS탐색을 한번 한 이후에 찾지 못했면 횟수증가 후 BFS탐색 재실시

          }
          return 0;
        }
