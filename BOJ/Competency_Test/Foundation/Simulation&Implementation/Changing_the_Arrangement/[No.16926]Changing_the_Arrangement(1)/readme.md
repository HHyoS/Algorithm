문제 사이트 : https://www.acmicpc.net/problem/16926

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
    1 ≤ R ≤ 1,000
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

    1. 주어진 조건에 맞는 동작을 구현하는 배열 돌리기(3)과 다르게 배열돌리기(1)은 내부 원소를
    시계방향으로 회전시키는 문제입니다.
    
    2. 문제 해결을 위해서 첫번째로 생각한 것은, 회전하는 그룹에 몇개인지 알아내는것이였습니다.
      그래서 여러 배열을 생선시켜서 그룹을 지어보았고, [행]과 [열] 중 작은값은 같은 요소 나누기 2를 한 값이
      그룹의 갯수인것을 확인했습니다.
      
    3. 그 다음은 어떻게 회전시킬지 였습니다. 
      처음에는 회전당 한번 동작하여 k번의 회전동안 k번 함수를 호출하는 코드를 구현하여 통과하였지만,
      더 개선된 코드를 찾아보았고, 그룹된 원소들을 벡터에 넣은 뒤, 회전하는 횟수와 벡터의 사이즈를 비교하여
      불필요한 이동(한바퀴를 돌아 제자리로 돌아오는)을 제거한 상태를 찾아 원소의 이동을 최소화 하는 방법을
      찾아 구현하였씁니다.
 
[ 구 현 ]

    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    int n,m,k; // 입력받을 값 n = 행, m = 열, k = 회전 횟수
    
    int arr[300][300]; // 주어진 원소를 저장하는 배열
    
    vector<int> temp; // 그룹의 원소를 저장할 벡터
    
    void round(int count, int turn) { // 배열의 외각부터 count(0 ~ min(n,m)/2 까지 범위 중)번쨰 그룹의 k 번 회전 후 상태를 찾는 함수 
    
      int start_n = 0 + count; 
      int start_m = 0 + count;
      int end_n = (n-1) - count;
      int end_m = (m-1) - count;
      
      // count 번 그룹지어질 때 마다 그룹지어지는 범위가 상,하,좌, 우로 한칸씩 줄어들기 떄문에 그룹지을 원소들의 시작과 끝을 초기에 설정

![표11111](https://user-images.githubusercontent.com/57944215/144562115-ba38d966-4787-46f8-be13-251a0b3d734a.png)


      for (int a = start_n; a < end_n; ++a) { // 그룹의 1번 원소 집합을 벡터에 저장
        temp.push_back(arr[a][start_m]);
      }
      for (int a = start_m; a < end_m; ++a) {// 그룹의 2번 원소 집합을 벡터에 저장
        temp.push_back(arr[end_n][a]);
      }
      for (int a = end_n; a > start_n; --a) {//그룹의 3번 원소 집합을 벡터에 저장
        temp.push_back(arr[a][end_m]);
      }
      for (int a = end_m; a > start_m; --a) {//그룹의 4번 원소 집합을 벡터에 저장
        temp.push_back(arr[start_n][a]);
      }
      int size = temp.size(); // 벡터의 사이즈 확인 후
      int t = turn % size; // k번의 회전이 a번째 그룹의 완전한 한바퀴 회전을 시켰는지 확인
      int index = size - t -1; 
      /* k번의 완전 회전 후 시계방향으로 이동한 횟수를 size에서 빼주면 (start_n,start_m)의 위치에 올
      원소를 가리키게됌. 하지만 t가 0이 될경우 벡터의 size범위를 벗어나므로 -1.
      
      size - t -1 이 아닌 (size -t)%size를 사용해봤지만, 갑자기 시간이 증가하는 현상 발생.. 이유가 뭘까요?

      // 벡터가 가리키는 인덱스부터 그룹을 채우기 시작
      
      for (int a = start_n; a < end_n; ++a) { // 1번 원소집합 채우기
        index = (index + 1) % size; 
        arr[a][start_m] = temp[index];
      } 
      for (int a = start_m; a < end_m; ++a) { // 2번 원소집합 채우기
        index = (index + 1) % size;
        arr[end_n][a] = temp[index];
      }
      for (int a = end_n; a > start_n; --a) { // 3번 원소집합 채우기
        index = (index + 1) % size;
        arr[a][end_m] = temp[index];
      }
      for (int a = end_m; a > start_m; --a) { // 4번 원소집합 채우기
        index = (index + 1) % size;
        arr[start_n][a] = temp[index];
      }
      temp.clear(); // 벡터 비우기
    }
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

    //	freopen("Input.txt", "r", stdin);
      cin >> n >> m >> k;

      for (int a = 0; a < n; ++a) { // 배열을 입력받고
        for (int b = 0; b < m; ++b) {
          cin >> arr[a][b];
        }
      }
      int min = 0;
      
      if (n > m) // 둘 중 최소값을 min에 저장, n == m 의 경우는 else문으로 처리완료!
        min = m;
      else
        min = n;

      for (int a = 0; a < (min / 2); ++a) { 
      // min/2번 그룹을 만들게되고, 그룹이 만들어질떄마다, 그룹의 범위가 달라지므로 a값을 매개변수로 
      // 넘겨주어 그룹의 횟수 표시.
      
        round(a, k);
      }

      for (int a = 0; a < n; ++a) { // 회전이 끝난 배열 
        for (int b = 0; b < m; ++b) {
          cout << arr[a][b] << " ";
        }
        cout << "\n";
      }
      return 0;
    }
      
      
