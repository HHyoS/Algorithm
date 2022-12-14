문제 사이트 : https://www.acmicpc.net/problem/14499

문제 설명 :

    크기가 N×M인 지도가 존재한다. 
    
    지도의 오른쪽은 동쪽, 위쪽은 북쪽이다.
    
    이 지도의 위에 주사위가 하나 놓여져 있으며, 주사위의 전개도는 아래와 같다. 
    
    지도의 좌표는 (r, c)로 나타내며, 
    
    r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다. 

      2
    4 1 3
      5
      6
      
    주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며, 
    
    놓여져 있는 곳의 좌표는 (x, y) 이다. 가장 처음에 주사위에는 모든 면에 0이 적혀져 있다.

    지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 
    
    주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
    
    0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.

    주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 
    
    주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.

    주사위는 지도의 바깥으로 이동시킬 수 없다. 
    
    만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

입력

    첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20), 
    
    주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 
    
    그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

    둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로, 
    
    각 줄은 서쪽부터 동쪽 순서대로 주어진다. 
    
    주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 
    
    지도의 각 칸에 쓰여 있는 수는 10 미만의 자연수 또는 0이다.

    마지막 줄에는 이동하는 명령이 순서대로 주어진다. 
    
    동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.

출력

    이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 
    
    만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

예제 입력 1 

    4 2 0 0 8
    0 2
    3 4
    5 6
    7 8
    4 4 4 1 3 3 3 2

예제 출력 1 

    0
    0
    3
    0
    0
    8
    6
    3
    
예제 입력 2 

    3 3 1 1 9
    1 2 3
    4 0 5
    6 7 8
    1 3 2 2 4 4 1 1 3

예제 출력 2

    0
    0
    0
    3
    0
    1
    0
    6
    0

예제 입력 3 

    2 2 0 0 16
    0 2
    3 4
    4 4 4 4 1 1 1 1 3 3 3 3 2 2 2 2

예제 출력 3 

    0
    0
    0
    0

예제 입력 4 

    3 3 0 0 16
    0 1 2
    3 4 5
    6 7 8
    4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2
    
예제 출력 4 

    0
    0
    0
    6
    0
    8
    0
    2
    0
    8
    0
    2
    0
    8
    0
    2
    
풀이 알고리즘

    1. 주어진 조건 하에 주사위의 동작을 구현하여 해결하는 문제였습니다.
    
    2. 문제 해결을 위해서는 주사위의 4가지 동작, [ 동 , 서 , 남 , 북 ] 이동을 했을 때
    
    주사위의 상태변화를 알아야했습니다.
    
    3. 주사위의 초기 상태를 배열 변수 dice 를 생성하였을 때 각 배열의 index가 의미하는 바는 다음과 같습니다.
    
    dice[0] : 주사위의 윗면   dice[1] : 주사위의 아랫면 dice[2] : 주사위의 동쪽
    dice[3] : 주사위의 서쪽   dice[3] : 주사위의 북쪽   dice[3] : 주사위의 남쪽
    
    4. 이 주사위의 초기값을 0 ~ 5 까지로 세팅후 4가지 동작을 구현하면 다음과 같이 변화합니다.
    동작▶
    상태▼       초기         동        서       남         북
    
    윗면         0           3         2         5         4
    
    아랫면       1           2         3         4         5
    
    동           2           0         1         2         2
    
    서           3           1         0         3         3
    
    남           4           4         4         0         1
    
    북           5           5         5         1         0
    
    5. 위의 상태변화를 코드로 구현한 뒤, 조건에 맞추어 동작에 따른 주사위의 상태를 변화시켜 문제를 해결하였습니다.
    

[ 구 현 ]

    #include <iostream>
    #include <cstring>
    using namespace std;
    int n, m, k;
    int dice[6] = { 0, };// 순서대로 상,하,동,서,남,북
    int map[20][20]; // 지도 배열
    int x, y; // 주사위 위치
    void dong() { // 동쪽 이동 구현
      if (y + 1 >= m) // 동쪽으로 이동할 수 없다면
        return; // 명령어 탈출
      else {
        ++y; // 주사위의 위치를 이동시킨 후

        int temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1]; // 주사위의 상태변화

        cout << dice[0] << "\n"; // 윗면 출력

        if (map[x][y] == 0) { // 현재 위치의 지도 값이 0이라면

          dice[1] = dice[2]; 
    //  else 부분에 dice[1]의 값을 변화시키는 문장이 있기때문에 dice[1]에 두변 연산이 발생하지 않도록 if문에 넣었습니다.

          map[x][y] = dice[1]; // 주사위의 밑면을 지도에 복사

        }

        else {// 현재 위치의 지도 값이 0이 아니라면
          dice[1] = map[x][y]; // dice[1]에 지도의 값 복사 후
          map[x][y] = 0; // 지도의 값을 0으로 변화
        }
        dice[2] = temp; // 주사위 상태변화 마무리
      }
      return;

    }
    void su() { // dong()함수와 대부분 동일한 동작
      if (y <= 0)
        return;
      else {
        --y;
        int temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        cout << dice[0] << "\n";
        if (map[x][y] == 0) {
          dice[1] = dice[3];
          map[x][y] = dice[1];
        }
        else {
          dice[1] = map[x][y];
          map[x][y] = 0;
        }
        dice[3] = temp;
      }
      return;

    }
    void nam() {// dong()함수와 대부분 동일한 동작
      if (x + 1 >= n)
        return;
      else {
        ++x;
        int temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        cout << dice[0] << "\n";
        if (map[x][y] == 0) {
          dice[1] = dice[4];
          map[x][y] = dice[1];
        }
        else {
          dice[1] = map[x][y];
          map[x][y] = 0;
        }
        dice[4] = temp;
      }
      return;

    }
    void book() {// dong()함수와 대부분 동일한 동작
      if (x - 1 < 0)
        return;
      else {
        --x;
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        cout << dice[0] << "\n";
        if (map[x][y] == 0) {
          dice[1] = dice[5];
          map[x][y] = dice[1];
        }
        else {
          dice[1] = map[x][y];
          map[x][y] = 0;
        }
        dice[5] = temp;
      }
      return;
    }
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      //	freopen("Input.txt", "r", stdin);
      cin >> n >> m >> x >> y >> k;
      for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) { // 지도 정보 입력받은 뒤
          cin >> map[a][b];
        }
      }
      int command;
      while (k--) { // 명령어 만큼 while문 반복.
        cin >> command;
        switch (command) {
        case 1:
          dong();
          break;
        case 2:
          su();
          break;
        case 3:
          book();
          break;
        case 4:
          nam();
          break;
        default:
          break;
        }
      }
      return 0;
    }
