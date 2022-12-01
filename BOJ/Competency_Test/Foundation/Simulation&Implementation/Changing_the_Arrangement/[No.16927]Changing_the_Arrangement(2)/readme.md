문제 사이트 : https://www.acmicpc.net/problem/16927

문제 설명 :

    크기가 N×M인 배열이 있을 때, 배열을 돌려보려고 한다. 배열은 다음과 같이 반시계 방향으로 돌려야 한다.

    A[1][1] ← A[1][2] ← A[1][3] ← A[1][4] ← A[1][5]
       ↓                                       ↑
    A[2][1]   A[2][2] ← A[2][3] ← A[2][4]   A[2][5]
       ↓         ↓                   ↑         ↑
    A[3][1]   A[3][2] → A[3][3] → A[3][4]   A[3][5]
       ↓                                       ↑
    A[4][1] → A[4][2] → A[4][3] → A[4][4] → A[4][5]
    
    예를 들어, 아래와 같은 배열을 2번 회전시키면 다음과 같이 변하게 된다.

    1 2 3 4       2 3 4 8       3 4 8 6
    5 6 7 8       1 7 7 6       2 7 8 2
    9 8 7 6   →   5 6 8 2   →   1 7 6 3
    5 4 3 2       9 5 4 3       5 9 5 4
     <시작>         <회전1>        <회전2>
     
    배열과 정수 R이 주어졌을 때, 배열을 R번 회전시킨 결과를 구해보자.

입력

    첫째 줄에 배열의 크기 N, M과 수행해야 하는 회전의 수 R이 주어진다.

    둘째 줄부터 N개의 줄에 배열 A의 원소 Aij가 주어진다.

출력

    입력으로 주어진 배열을 R번 회전시킨 결과를 출력한다.

제한

    2 ≤ N, M ≤ 300
    1 ≤ R ≤ 109
    min(N, M) mod 2 = 0
    1 ≤ Aij ≤ 108
    
예제 입력 1
    
    4 4 2
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    
예제 출력 1 
    
    3 4 8 12
    2 11 10 16
    1 7 6 15
    5 9 13 14
    
예제 입력 2 
    
    5 4 7
    1 2 3 4
    7 8 9 10
    13 14 15 16
    19 20 21 22
    25 26 27 28
    
예제 출력 2 
    
    28 27 26 25
    22 9 15 19
    16 8 21 13
    10 14 20 7
    4 3 2 1
    
예제 입력 3 
    
    2 2 3
    1 1
    1 1
    
예제 출력 3 
    
    1 1
    1 1

풀이 알고리즘

    1. 이전에 풀어보았던 배열돌리기(1) -> https://github.com/HHyoS/BOJ/tree/master/Competency_Test/Foundation/Simulation%26Implementation/Changing_the_Arrangement/%5BNo.16926%5DChanging_the_Arrangement(1)
       과 유사한 문제였습니다. 
       배열돌리기(1)의 소스코드가 이 문제를 풀고난 뒤 다시 코딩하여 작성해서 코드가 매우 비슷합니다..
       
    2. 배열돌리기(2)가 배열돌리기(1)과 달라진점은 테스트케이스의 갯수가 10^8개까지 늘어났다는 점입니다.
   
[ 구 현 ]

1.  전체 코드 설명( 배열돌리기(1)과 매우 비슷하기 떄문에 달라진 점만 추가설명 하겠습니다.)

        #include <iostream>
        #include <vector>
        using namespace std;
        int n,m,k;
        int arr[300][300];
        vector<int> temp;

        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);

        //	freopen("Input.txt", "r", stdin);
        
          cin >> n >> m >> k;

          for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
              cin >> arr[a][b]; // 배열 입력받기
            }
          }
          int min = 0;
          
          if (n > m) 
            min = m;
          else
            min = n;

          int start_n;
          int start_m;
          int end_n;
          int end_m;
          int size;
          int t;
          int index;
          for (int a = 0; a < (min / 2); ++a) {
          // 배열돌리기(1)에서 함수로 구현하였던 시뮬레이션 코드를 main 내부로 구현(이 방법이 시간단축에 유의미함!)
              start_n = 0 + a;
              start_m = 0 + a;
              end_n = (n - 1) - a;
              end_m = (m - 1) - a;

              for (int a = start_n; a < end_n; ++a) {
                temp.push_back(arr[a][start_m]);
              }
              for (int a = start_m; a < end_m; ++a) {
                temp.push_back(arr[end_n][a]);
              }
              for (int a = end_n; a > start_n; --a) {
                temp.push_back(arr[a][end_m]);
              }
              for (int a = end_m; a > start_m; --a) {
                temp.push_back(arr[start_n][a]);
              }
              size = temp.size();
              t = k % size;
              int index = size - 1 - k % size;

              for (int a = start_n; a < end_n; ++a) {
                index = (index + 1) % size;
                arr[a][start_m] = temp[index];
              }
              for (int a = start_m; a < end_m; ++a) {
                index = (index + 1) % size;
                arr[end_n][a] = temp[index];
              }
              for (int a = end_n; a > start_n; --a) {
                index = (index + 1) % size;
                arr[a][end_m] = temp[index];
              }
              for (int a = end_m; a > start_m; --a) {
                index = (index + 1) % size;
                arr[start_n][a] = temp[index];
              }
              temp.clear();
          }

          for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
              cout << arr[a][b] << " ";
            }
            cout << "\n";
          }
          return 0;
        }
       
