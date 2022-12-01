문제 사이트 : https://www.acmicpc.net/problem/23815


설명 :

    이 게임은 똥냄새가 너무 나서 도저히 볼 수가 없다! 
    
    따라서 당신은 직접 똥게임을 하지 않고 프로그램한테 똥게임을 시킬 것이다
    
    처음에는 사람 1명으로 시작한다. 
    
    당신에게는 총 N번의 턴이 주어지며, 각 턴마다 다음 선택지 4개중 2개가 주어진다.
    
    같은 선택지가 주어질 수도 있다. 
    
    각 선택지는 $+x, -x, *x, /x \, (1 \leq x \leq 9)$ 중 하나로 주어진다.

     +x를 선택할 경우, 사람의 수가 x명만큼 증가한다.
     -x를 선택할 경우, 사람의 수가 x명만큼 감소한다.
     *x를 선택할 경우, 사람의 수가 x배가 된다.
     /x를 선택할 경우, 사람의 수가 x만큼 나눠진다.
     만약 현재 사람 수가 x로 나눠지지 않을 경우 나머지는 버린다.
     N개의 선택지 중 1번에 한해 광고를 보고 선택지를 건너뛸 수 있다. 
     
     광고를 보지 않고 선택지를 건너뛰지 않아도 된다. 
     
     만약 각 턴이 끝난 뒤 현재 사람이 0명 이하가 되면 게임 오버가 된다.
     
     당신은 N번의 선택지를 거친 후 사람의 수를 최대로 만들어야 한다.
     
     어떠한 선택을 하더라도 중간에 사람의 수가 32비트 정수 범위를 넘지 않음을 보장한다.

입력

    첫 번째 줄에 선택지의 개수 N \, (1 <= N  <= 100,000)가 주어진다. 

    그 이후 $N$개의 줄에 걸쳐 2개의 선택지가 공백을 사이로 두고 주어진다.

    각 선택지는 +x, -x, *x, /x 중 하나로 주어진다 (1 <= x <= 9).

출력

    N개의 선택지를 거친 후 최대 사람의 수를 출력한다. 

    만약 어떤 선택을 하더라도 게임 오버가 된다면 ddong game을 출력한다.

예제 입력 1 

    3
    +5 *2
    +4 *2
    -5 /2
    
예제 출력 1 

    12

예제 입력 2 

    3
    +3 *6
    -8 -9
    -9 -9

예제 출력 2 

    ddong game
    
풀이 알고리즘 

    1. 이 문제에서 값들이 가질 수 있는 상태는 두가지 입니다. (1) 광고 아직 안봄 (2) 광고 봄
      해당 상태를 dp라는 배열을 생성해서 표현하면
      dp[N][2]로 만들 수 있습니다.
      dp[n단계에서] [ 0 = 광고 아직 안봄 , 1 = 광고 봄]
    2. N단계 이후 최대값이 되려면, 각 단계에서도 최대값이 되는 연산을 찾아 값을 구하고
    다음 단계에서 해당값을 사용해야하고 이를 f(dp[n-1][x], 연산) = dp[n][x] 으로 표현할 수 있습니다.
    3. 두 가지 연산이 주어지면
    (1)의 케이스에서는 f(dp[n-1][0],연산이 dp[n][0]의 값이 되고
    (2)의 케이스는 dp[n][1]에 들어갈 수 있는 값은 다음과 같습니다,
      1] f(dp[n-1][1], 연산) 
      2] dp[n-1][0](이전 단계에서 광고를 안봣지만, 이번 단계에서는 광고를 봐서 연산을 스킵.
    4. 만약 특정 단계 x를 지난 후 모든 연산을 마친 dp[x][0],dp[n][1]이 둘다 0 이하의 값을 갖는다면
    다음단계로 진행이 불가능하므로 "ddong game"을 출력하고, 아닐경우 모든 단계가 지난 후 
    dp[n][0]과 dp[n][1]중 큰 값을 찾아 출력하여 문제를 해결했씁니다.
      
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <utility>
    using namespace std;
    int n;
    int dp[2][2]; // 메모리사용을 최소화하기위해 두개의 인덱스만 사용하여 이전,현재 배열 유지
      int main() {

        /*	ios::sync_with_stdio(0);
          cin.tie(0);
          cout.tie(0);*/

      //	freopen("Input.txt", "r", stdin);
        scanf("%d", &n);

      int dp[2][2];

      dp[0][0] = 1;
      dp[0][1] = 1; // 초기값 세팅. 광고를 보나 안보나 기본단계에서는 1을 세팅하여 기본값 생성

      char command[2];
      int num[2];

      for (int a = 1; a <= n; ++a) {
        int now = a % 2; // 현재 배열 위치
        int before = (a + 1) % 2; // 이전에 완성한 배열 위치
        scanf(" %c%d", &command[0], &num[0]);
        scanf(" %c%d", &command[1], &num[1]);
        dp[now][0] = 0;
        dp[now][1] = 0;
        for (int b = 0; b < 2; ++b) { // 입력되는 명령어는 두가지.
          if (command[b] == '+') {
            if (dp[before][0] > 0)// 전의 dp[a-1][0]의 값이 0이라면 그 케이스는 사용 불가능
              dp[now][0] = max(dp[before][0] + num[b], dp[now][0]);
            if (dp[before][1] > 0)//전의 dp[a-1][1]의 값이 0이라면 그 케이스는 사용 불가능
              dp[now][1] = max(dp[before][1] + num[b], max(dp[now][1],dp[before][0]));
          }
          else if (command[b] == '-') {
            if (dp[before][0] > 0)
              dp[now][0] = max(dp[before][0] - num[b], dp[now][0]);
            if (dp[before][1] > 0)
              dp[now][1] = max(dp[before][1] - num[b], max(dp[now][1], dp[before][0]));
          }
          else if (command[b] == '*') {
            if (dp[before][0] > 0)
              dp[now][0] = max(dp[before][0] * num[b], dp[now][0]);
            if (dp[before][1] > 0)
              dp[now][1] = max(dp[before][1] * num[b], max(dp[now][1], dp[before][0]));
          }
          else {
            if (dp[before][0] > 0)
              dp[now][0] = max(dp[before][0] / num[b], dp[now][0]);
            if (dp[before][1] > 0)
              dp[now][1] = max(dp[before][1] / num[b], max(dp[now][1], dp[before][0]));
          }
        }
        if ((dp[now][0] <= 0) && (dp[now][1] <= 0)){ // 모든 연산이 끝난 결과가 모두 0이하라면
        // 다음단계 진행 불가능
          printf("ddong game");
          return 0;
        }
      }
      printf("%d", max(dp[n%2][0], dp[n%2][1]));
      return 0;
    }

