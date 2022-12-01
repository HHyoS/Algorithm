문제 사이트 : https://www.acmicpc.net/problem/2210

문제 설명 :

    5×5 크기의 숫자판이 있다. 
    
    각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다. 
    
    이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 
    
    각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다.
    
    이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 
    
    0으로 시작하는 000123과 같은 수로 만들 수 있다.

    숫자판이 주어졌을 때, 
    
    만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.

입력

    다섯 개의 줄에 다섯 개의 정수로 숫자판이 주어진다.

출력

    첫째 줄에 만들 수 있는 수들의 개수를 출력한다.

예제 입력 1 

    1 1 1 1 1
    1 1 1 1 1
    1 1 1 1 1
    1 1 1 2 1
    1 1 1 1 1

예제 출력 1 

    15
  
풀이 알고리즘.

    중복을 허용하는 완전탐색 문제였습니다.
    
    중복을 허용하기 떄문에 주어진 시간과 메모리 내에서 어떤식으로 구현해야 문제를
    
    해결할 수 있을지 고민했는데, 문제에서 주어진 메모리와, 시간이 넉넉하기 때문에 평범한
    
    dfs탐색으로 구현해보았습니다.
    
    (1,1) ~(5,5) 존재하는 25개의 위치에 대해서 상,하,좌,우 이동이 가능할 경우 모두 탐색하도록 
    
    구현하였고, 6개의 숫자를 선택하면 set container에 담아서 중복이 허용되지 않도록 하였습니다.
    
    모든 탐색이 끝난 이후에는 set container에 들어있는 원소의 갯수를 출력하여 문제를 해결하였습니다.
    
    초기에는 bool 배열의 크기는 100만으로 설정하여 모든 케이스에 대해 체크하도록 구현하였지만
    
    불필요한 메모리가 사용되어 메모리 사용량이 크게 잡혔고, 이를 보완하기 위해
    
    set container를 사용하여 메모리사용 약 20%감소하면서 문제를 해결할 수 있었습니다.
    
[ 구 현 ] 

    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <set>
    using namespace std;
    int N;
    int arr[5][5];
    set<int> answer;
    int mov[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

    void dfs(int x, int y, int count,int num) {
      if (count == 6) {
        answer.insert(num);
        return;
      }
      else {
        for (int a = 0; a < 4; ++a) {
          int xx = x + mov[a][0];
          int yy = y + mov[a][1];
          if ((xx >= 0) && (yy >= 0) && (xx < 5) && (yy < 5)) {
            dfs(xx, yy, count+1, num * 10 + arr[xx][yy]);
          }
        }
      }
    }
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    //	freopen("Input.txt", "r", stdin);
      for (int a = 0; a < 5; ++a) {
        for (int b = 0; b < 5; ++b) {
          cin >> arr[a][b];
        }
      }

      for (int a = 0; a < 5; ++a) {
        for (int b = 0; b < 5; ++b) {
          dfs(a, b, 1,arr[a][b]);
        }
      }
      cout << answer.size();
      return 0;
    }

