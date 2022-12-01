문제 사이트 : https://www.acmicpc.net/problem/1913

풀이 환경 : Visual Studio 2019

문제 설명 :

    홀수인 자연수 N이 주어지면, 
    
    다음과 같이 1부터 N2까지의 자연수를 달팽이 모양으로 N×N의 표에 채울 수 있다.

    9	2	3
    8	1	4
    7	6	5
    25	10	11	12	13
    24	9	2	3	14
    23	8	1	4	15
    22	7	6	5	16
    21	20	19	18	17
    
    N이 주어졌을 때, 이러한 표를 출력하는 프로그램을 작성하시오. 

    또한 N2 이하의 자연수가 하나 주어졌을 때, 그 좌표도 함께 출력하시오.

    예를 들어 N=5인 경우 6의 좌표는 (4,3)이다.

입력

    첫째 줄에 홀수인 자연수 N(3 ≤ N ≤ 999)이 주어진다. 둘째 줄에는 위치를 찾고자 하는 N2 이하의 자연수가 하나 주어진다.

출력

    N개의 줄에 걸쳐 표를 출력한다. 각 줄에 N개의 자연수를 한 칸씩 띄어서 출력하면 되며, 자릿수를 맞출 필요가 없다. N+1번째 줄에는 입력받은 자연수의 좌표를 나타내는 두 정수를 한 칸 띄어서 출력한다.

예제 입력 1 

7
35

예제 출력 1 

    49 26 27 28 29 30 31
    48 25 10 11 12 13 32
    47 24 9 2 3 14 33
    46 23 8 1 4 15 34
    45 22 7 6 5 16 35
    44 21 20 19 18 17 36
    43 42 41 40 39 38 37
    5 7
    
풀이 알고리즘

    주어진 조건에 맞추어 달팽이 배열을 생성한 뒤, 배열과 찾는수 K 의 위치를 출력하는 문제입니다.
    
    이 문제를 풀 떄 제가 생각한 풀이 알고리즘은 다음과 같습니다.
    
    1. 배열에 처음으로 쓰여지는 값을 N^2 = num 변수사용
    
    2. 배열에서 처음으로 쓰여지는 위치는 (1,1)
    
    3. 진행 방향 순서는 (1) 아래 -> (2) 오른쪽 -> (3) 위쪽 -> (4) 왼쪽 순
    
    4. 각 방향으로 진행이 되었을 떄, 진행을 막는 벽의 의미하는 변수 4가지를 선언하여
    
    벽에 부딛혔을 때 진행되지 않도록함
    
    5. 배열에 한칸씩 숫자가 쓰일때마다 num 값을 하나씩 줄임
    
    6. num값잉 0이되면 배열 작성을 종료하고, 배열을 출력하며 찾는 값 K의 위치를 찾아 저장한 뒤
    
    출력.
    
 구 현
 
    #include <iostream>
    #include <string>
    #include <queue>
    #include <algorithm>
    using namespace std;

    int N, K;
    int arr[1000][1000];
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> N >> K;
      int num = N * N; // 처음 쓰여지는 수 num
      
      int down = N, right = N, up = 1, left = 2; // 초기 벽의 위치 설정
      int x = 1, y = 1;
      while (num != 0) {

          for (int a = 0; x + a <= down; ++a) { // 아래로 이동하며 배열 작성
            arr[x + a][y] = num--;
          }
          // 벽에 부딛힌 이후 x,y 위치 재설정
          x = down;
          --down;
          ++y;
          for (int a = 0; y+a <= right; ++a) {// 오른쪽으로 이동하며 배열 작성
            arr[x][y + a] = num--;
          }
          y = right;
          --right;
          --x;
          for (int a = 0; x-a >= up; ++a) {// 위로 이동하며 배열 작성
            arr[x - a][y] = num--;
          }
          x = up;
          ++up;
          --y;
          for (int a = 0; y-a >= left; ++a) {// 왼쪽으로 이동하며 배열 작성
            arr[x][y - a] = num--;
          }
          y = left;
          x = x + 1;
          ++left;
      }

      int answer_x, answer_y;
      for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
          cout << arr[a][b] << " ";
          if (K == arr[a][b]) {
            answer_x = a;
            answer_y = b;
          }
        }
        cout << "\n";
      }
      cout << answer_x << " " << answer_y;
      return 0;
    }
