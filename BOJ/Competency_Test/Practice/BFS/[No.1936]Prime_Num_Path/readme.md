문제 사이트 : https://www.acmicpc.net/problem/1963

문제 설명 :

    소수를 유난히도 좋아하는 창영이는 게임 아이디 비밀번호를 4자리 ‘소수’로 정해놓았다.
    
    어느 날 창영이는 친한 친구와 대화를 나누었는데:

    “이제 슬슬 비번 바꿀 때도 됐잖아”
    “응 지금은 1033으로 해놨는데... 다음 소수를 무엇으로 할지 고민중이야"
    “그럼 8179로 해”
    “흠... 생각 좀 해볼게. 이 게임은 좀 이상해서 비밀번호를 한 번에 한 자리 밖에 못 바꾼단 말이야.
    예를 들어 내가 첫 자리만 바꾸면 8033이 되니까 소수가 아니잖아. 
    여러 단계를 거쳐야 만들 수 있을 것 같은데... 예를 들면... 1033 1733 3733 3739 3779 8779 8179처럼 말이야.”
    “흠...역시 소수에 미쳤군. 그럼 아예 프로그램을 짜지 그래.
    네 자리 소수 두 개를 입력받아서 바꾸는데 몇 단계나 필요한지 계산하게 말야.”
    “귀찮아”
    그렇다. 그래서 여러분이 이 문제를 풀게 되었다. 
    입력은 항상 네 자리 소수만(1000 이상) 주어진다고 가정하자. 
    주어진 두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고,
    ‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.

입력

    첫 줄에 test case의 수 T가 주어진다. 다음 T줄에 걸쳐 각 줄에 1쌍씩 네 자리 소수가 주어진다.

출력

    각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

예제 입력 1 

    3
    1033 8179
    1373 8017
    1033 1033

예제 출력 1 

    6
    7
    0
    
풀이 알고리즘

    1. 하나의 경우에 대해서 횟수를 구하는 문제가 아닌 많은 케이스에 대해서 연산을 진행할 수 있기때문에, 
    
    에라토스테네스의 체를 이용하여 10000미만의 수에 대해서 소수를 미리 판별한 뒤 연산을 진행하였습니다.
    
    2. 연산을 진행하면서 특정 자리수의 값을 변화시키는것을 1번의 횟수를 사용하므로.
    
    1234 라는 수가 있을 떄, 1번의 이동으로 나올 수 있는 값은 (1~9) 2 3 4 , 1 (0~9) 3 4 , 1 2 (0 ~ 9) 4, 1 2 3 (0 ~ 9) 의 범위를 갖게됩니다.
    
    3. [1] 해당 범위의 값들에 대해 소수인지 판별하고 [2] 한번 사용했었던 값인지 확인 / 하는 두가지 동작을 하며 목표값으로 이동하는 횟수를 구해나가는 bfs탐색을 진행합니다.
    
    4. 만약 가능한 모든 소수케이스를 방문했는데도 목표값을 도달하지못하면 Impossible을 출력하도록 하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    using namespace std;
    int n;
    bool primeN[10000];
    bool check[10000];
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    //	freopen("Input.txt", "r", stdin);
    
      for (int a = 2; a <= 9999; ++a) {
        if (primeN[a] == 1)
          continue;
        else
          for (int b = 2; a*b <= 9999; ++b)
            primeN[a*b] = 1;
      } // 에라토스테네스의 체 구현
      
      cin >> n;
      int num_1, num_2;
      for (int a = 0; a < n; ++a) {
        cin >> num_1 >> num_2; // num_1 = 시작값 num_2 = 목표값
        int answer = 0; // 연산 횟수
        int aans = -1; // 목표값을 달성했는지 확인
        queue<int> que; // bfs탐색을 위한 queue
        
        if (num_1 == num_2) { // 이미 시작값이 목표값과 같다면
          aans = 0; // 
          answer = 1;
        }
        else {
          que.push(num_1);
        }
        while (!que.empty()) {
          int size = que.size();
          for (int b = 0; b < size; ++b) {
            int num = que.front();
            que.pop();
            if (num == num_2) { // 목표값에 도달했다면
              aans = 0; // 목표값 도달표시 후
              que = queue<int>(); // que를 비우고
              memset(check, 0, sizeof(check)); // check배열도 초기화
              break; // for문 종료, queue를 초기화시켯기 때문에 while문도 종료될 예정
            }
            int namuzi[4];
            namuzi[0] = num % 10;
            namuzi[1] = num % 100 - num % 10;
            namuzi[2] = num % 1000 - num % 100;
            namuzi[3] = num - num % 1000;
            int temp = num - namuzi[0];

            for (int c = 0; c <= 9; ++c) { // 1의자리 변화
              if (!check[temp + c] && !primeN[temp + c]) {
                que.push(temp + c);
                check[temp + c] = 1;
              }
            }
            temp = num - namuzi[1];
            for (int c = 0; c <= 90; c += 10) { // 10의 자리 변화
              if (!check[temp + c] && !primeN[temp + c]) {
                check[temp + c] = 1;
                que.push(temp + c);
              }
            }

            temp = num - namuzi[2];
            for (int c = 0; c <= 900; c += 100) { // 100의자리 변화
                if (!check[temp + c] && !primeN[temp + c]) {
                  check[temp + c] = 1;
                  que.push(temp + c);
                }
              }
            temp = num - namuzi[3];

            for (int c = 1000; c <= 9000; c += 1000) { // 1000의자리 변화
              if (!check[temp+c] && !primeN[temp + c]) {
                check[temp + c] = 1;
                que.push(temp + c);
              }
            }

          }
          ++answer; // bfs탐색 1회 진행 후 
        }
        if (aans == -1) {
          cout << "Imppossible\n";
        }
        else
          cout << answer-1<<"\n";
      }
      return 0;
    }

