문제 사이트 : https://www.acmicpc.net/problem/16967

문제 설명 :

    크기가 H × W인 배열 A와 두 정수 X와 Y가 있을 때, 
    
    크기가 (H + X) × (W + Y)인 배열 B는 배열 A와 배열 A를 아래로 X칸, 
    
    오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만들 수 있다. 수가 겹쳐지면 수가 합쳐진다.

    즉, 배열 B의 (i, j)에 들어있는 값은 아래 3개 중 하나이다.

    a. (i, j)가 두 배열 모두에 포함되지 않으면, Bi,j = 0이다.
    b. (i, j)가 두 배열 모두에 포함되면, Bi,j = Ai,j + Ai-X,j-Y이다.
    c. (i, j)가 두 배열 중 하나에 포함되면, Bi,j = Ai,j 또는 Ai-X,j-Y이다.
    
    배열 B와 정수 X, Y가 주어졌을 때, 배열 A를 구해보자.

입력

    첫째 줄에 네 정수 H, W, X, Y가 주어진다. 둘째 줄부터 H + X개의 줄에 배열 B의 원소가 주어진다.

    항상 배열 A가 존재하는 경우만 입력으로 주어진다.

출력

    총 H개의 줄에 배열 A의 원소를 출력한다.

제한

    2 ≤ H, W ≤ 300
    1 ≤ X < H
    1 ≤ Y < W
    0 ≤ Bi,j ≤ 1,000

예제 입력 1 

    2 4 1 1
    1 2 3 4 0
    5 7 9 11 4
    0 5 6 7 8

예제 출력 1 

    1 2 3 4
    5 6 7 8

예제 입력 2 

    3 3 2 1
    1 2 3 0
    4 5 6 0
    7 9 11 3
    0 4 5 6
    0 7 8 9

예제 출력 2 

    1 2 3
    4 5 6
    7 8 9
    
[ 풀이 알고리즘 ]

    주어진 조건에 따라 만들어진 배열 B를 만드는데 사용된 배열 A를 복원하는 문제입니다.
    
    배열 B에서 배열 A를 복원하기 위해서는 남아있는 배열 A의 요소를 찾아내고, 
    
    그 요소들을 사용하여 배열 B를 배열 A로 변환시키는것이 필요합니다.
    
    ex ) H = 3. W = 3 인 배열 A 와 X=1, Y = 1 인 배열 B가 있습니다.
    
    [ 배열 A ]                   [ 배열 B ]
    
      1 2 3                       1 2  3
      4 5 6                       4 6  8  3
      7 8 9                       7 12 14 6
                                  0 7  8  9
    
    배열 B를 조건 
    
    b. (i, j)가 두 배열 모두에 포함되면, B(i,j) = A(i,j) + A(i-X,j-Y) 이다.
    
    에 맞추어 다시 정리해보면 다음과 같습니다.
    
    [ 배열 B ]
    
    1   2     3     0
    
    4   5+1   6+2   3
    
    7   8+4   9+5   6
    
    0   7     8     9
    
    B(i,j) = A(i,j) + A(i-X,j-Y) 이므로 B(i,j) - A(i-X,j-Y) = A(i,j) 입니다.
    
    배열 B의 원소들에 대하여 위의 식을 바탕으로 배열 B의 모든 원소를 다시 계산하면 
    
    A(0,0) ~ A(H,W) 부분을 복구할 수 있습니다.
    
    위의 알고리즘을 코드로 구현하였고, 그를통해 문제를 해결하였습니다 .
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    #include <vector>

    using namespace std;
    int H, W, X, Y;
    int arr[600][600];

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        //freopen("Input.txt","r", stdin);
        cin >> H >> W >> X >> Y;

        for (int a = 0; a < H + X; ++a) {
            for (int b = 0; b < W + Y; ++b) {
                cin >> arr[a][b]; // 배열 B 입력받기
            }
        }

        for (int a = 0; a <H; ++a) {
            for (int b =0; b < W; ++b) {
                    arr[X + a][Y + b] -= arr[a][b]; // 배열 B의 모든 원소를 계산하여
                    // 배열 A를 복구하기
            }
        }
        for (int a = 0; a < H; ++a) {
            for (int b = 0; b < W; ++b) {
                cout << arr[a][b] << " "; // 복구된 모든 원소들을 
            }
            cout << "\n";
        }
        return 0;

    }
    
