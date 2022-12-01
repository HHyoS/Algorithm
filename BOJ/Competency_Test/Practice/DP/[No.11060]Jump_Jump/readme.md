문제 사이트 : https://www.acmicpc.net/problem/11060

개발 환경 : Visual Studio2019

문제 설명 :

    재환이가 1×N 크기의 미로에 갇혀있다. 
    
    미로는 1×1 크기의 칸으로 이루어져 있고, 각 칸에는 정수가 하나 쓰여 있다. 
    
    i번째 칸에 쓰여 있는 수를 Ai라고 했을 때, 
    
    재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 한 번에 점프할 수 있다.
    
    예를 들어, 3번째 칸에 쓰여 있는 수가 3이면, 재환이는 4, 5, 6번 칸 중 하나로 점프할 수 있다.

    재환이는 지금 미로의 가장 왼쪽 끝에 있고, 
    
    가장 오른쪽 끝으로 가려고 한다. 
    
    이때, 최소 몇 번 점프를 해야 갈 수 있는지 구하는 프로그램을 작성하시오. 
    
    만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.

입력

    첫째 줄에 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 Ai (0 ≤ Ai ≤ 100)가 주어진다.

출력

    재환이가 최소 몇 번 점프를 해야 가장 오른쪽 끝 칸으로 갈 수 있는지 출력한다. 만약, 가장 오른쪽 끝으로 갈 수 없는 경우에는 -1을 출력한다.

예제 입력 1 

    10
    1 2 0 1 3 2 1 5 4 2

예제 출력 1 

    5
    
풀이 알고리즘 

      위 문제는 마지막 위치 N까지 최소 횟수의 점프를 하여 도달하는 것을 목표로 하고있습니다.
      
      그래서 이 문제가 BFS와 DP 풀이 두가지를 사용하여 풀 수 있다고 생각하였고, 두가지 방법 모두를
      
      사용하여 풀이해보았습니다.
      
      두 가지 풀이의 기본 알고리즘은 같습니다.
      
      1. 특정 위치 A 에 대하여 처음 방문한 횟수보다 많은 점프를 하여 방문한 케이스는 무시하고 최단 케이스만 남기기
      
      2. 특정 위치 A에서 다른 미로로 점프할 경우 다른 미로의 점프값 = A의 점프값 + 1
      
      위의 알고리즘을 기본으로 코딩하였고
      
      BFS방식은 queue를 사용하여 X번쨰 점프했을 때 가능한 모든 미로 위치를 queue에 저장하여 N에 최단거리로 도달하는 점프값을 찾도록 하였고
      
      DP 방식은 현재 위치 X에서 점프 가능한 모든 미로의 위치에 X의 도달한 최소값 + 1 을 dp를 방식으로 구현하여 DP[N] 을 찾고 프로그램의 마지막에 DP[N]을 출력하여 문제를
      
      해결하였습니다.
      
구 현

1. BFS

        #include <iostream>
        #include <string>
        #include <queue>
        using namespace std;

        int N;
        int arr[1001];
        bool check[1001];

        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          //freopen("Input.txt", "r", stdin);
          cin >> N;
          for (int a = 1; a <= N; ++a)
            cin >> arr[a];
          queue<int> que;
          que.push(1);
          int answer = -1;
          int lop = 1;
          if (N == 1) {
            que.pop();
            answer = 0;
          }
          while (!que.empty()) {
            int size = que.size();
            for (int a = 0; a < size; ++a) {
              int idx = que.front();
              que.pop();

              for (int jump = 1; jump <= arr[idx]; ++jump) {
                if ((idx+jump <= N) && !check[idx + jump]) {
                  if (idx + jump == N) {
                    answer = lop;
                    que = queue<int>();
                    a = size;
                    break;
                  }
                  check[idx + jump] = 1;
                  que.push(idx + jump);
                }
              }
            }
            ++lop;
          }
          cout << answer;
          return 0;
        }

2. DP

        #include <iostream>
        #include <string>
        #include <queue>
        using namespace std;

        int N;
        int dp[1001][2];

        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);
          freopen("Input.txt", "r", stdin);
          cin >> N;
          for (int a = 1; a <= N; ++a)
            cin >> dp[a][0];

          for (int a = 1; a <= 1000; ++a) {
            dp[a][1] = 2000;
          }
          dp[1][1] = 0;
          for (int a = 1; a < N; ++a) {
            for (int b = 1; b <= dp[a][0]; ++b) {
              if (dp[a + b][1] > (dp[a][1] + b))
                dp[a + b][1] = dp[a][1] + 1;
            }
          }
          if (dp[N][1] != 2000)
            cout << dp[N][1];
          else
            cout << -1;
          return 0;
        }

      
      
