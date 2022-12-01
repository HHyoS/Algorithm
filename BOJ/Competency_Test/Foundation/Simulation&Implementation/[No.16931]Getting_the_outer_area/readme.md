문제 사이트 : https://www.acmicpc.net/problem/16931

문제 설명 :

    크기가 N×M인 종이가 있고, 종이는 1×1크기의 칸으로 나누어져 있다. 이 종이의 각 칸 위에 1×1×1 크기의 정육면체를 놓아 3차원 도형을 만들었다.

    종이의 각 칸에 놓인 정육면체의 개수가 주어졌을 때, 이 도형의 겉넓이를 구하는 프로그램을 작성하시오.

![탑탑](https://user-images.githubusercontent.com/57944215/144740878-44a76278-19b9-479a-9391-84479980b0e8.png)


    위의 그림은 3×3 크기의 종이 위에 정육면체를 놓은 것이고, 겉넓이는 60이다.

입력

    첫째 줄에 종이의 크기 N, M이 주어진다. 둘째 줄부터 N개의 줄에는 종이의 각 칸에 놓인 정육면체의 수가 주어진다.

출력

    첫째 줄에 도형의 겉넓이를 출력한다.

제한

    1 ≤ N, M ≤ 100
    1 ≤ 종이의 한 칸에 놓인 정육면체의 수 ≤ 100
    
예제 입력 1 

    1 1
    1

예제 출력 1 

    6

예제 입력 2 

    3 3
    1 3 4
    2 2 3
    1 2 4

예제 출력 2 

    60
   
풀이 알고리즘

    1) 정육면체 동형 하나는 기본적으로 6개의 면을 가지고 있습니다.
    2) 한줄로 세워진 도형의 겉넓이 최대값은 다음과 같이 증가합니다.
      1 -> 4 + 2 , 2 -> 4*2 + 2, 3 -> 4*3 + 2.... n -> 4*n + 2
    3) 겉넓이는 한 층마다 상,하,좌,우 에 블록이 존재할경우 면이 하나씩 줄어들게됩니다.
    4) 그러므로 n * m 크기에 놓여있는 도형들에 대하여 각 칸마다 존재할 수 있는 최대값을 구한 후,
       각 층마다 상,하,좌,우 에 존재하는 블록의 갯수를 뺴면 한 칸의 도형이 가지는 겉넓이를 구할 수 있습니다.
       
[ 구 현 ]

1. main함수 및 시뮬레이션 코드

        #include <iostream>
        #include <vector>
        using namespace std;
        int n , m ;
        int arr[102][102];


        int main() {

          ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);

        //	freopen("Input.txt", "r", stdin);
          cin >> n >> m;
          for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
              cin >> arr[a][b]; // 종이의 도형정보 입력
            }
          }
          int answer = 0;
          for (int a = 1; a <= n; ++a) { // 범위는 (1,1) ~ (n,m) 까지 n*m 개의 칸에 대한 탐색
          // a와 b 값을 1 ~ n , 1 ~m 까지의 범위로 만들고, 배열의 크기는 n+2, m+2 만큼 사용할 수 있도록 만들어 예외조건 없이 모두 동일한 연산으로 계산할 수 있도록 구현.
            for (int b = 1; b <= m; ++b) {
              answer += (arr[a][b] * 4 + 2); // (a,b)칸이 가질 수 있는 최대값 도형수를 미리 구한 후 answer에 더하고
              if (arr[a][b + 1] >= arr[a][b]) // (a,b) 의 오른쪽 칸에 있는 도형이 (a,b)칸의 높이보다 높다면 
                answer -= arr[a][b]; // (a,b)의 높이만큼만 겉넓이 제거
              else
                answer -= arr[a][b + 1]; // 아니라면 오른쪽 칸의 높이만큼만 겉넓이 제거

              if (arr[a][b - 1] >= arr[a][b]) // 왼쪽 연산
                answer -= arr[a][b];
              else
                answer -= arr[a][b-1];

              if (arr[a + 1][b] >= arr[a][b]) // 위쪽 연산
                answer -= arr[a][b];
              else
                answer -= arr[a + 1][b];

              if (arr[a - 1][b] >= arr[a][b]) // 아래쪽 연산
                answer -= arr[a][b];
              else
                answer -= arr[a - 1][b];
            }
          }
          cout << answer;
          return 0;
        }
