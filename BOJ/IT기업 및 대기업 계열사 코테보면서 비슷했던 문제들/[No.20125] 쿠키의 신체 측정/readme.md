문제 사이트 : https://www.acmicpc.net/problem/20125

문제 설명 :
    
    쿠키런은 데브시스터즈에서 제작한 모바일 러닝 액션 게임이다. 
    
    마녀의 오븐에서 탈출한 쿠키들과 함께 모험을 떠나는 게임으로, 
    
    점프와 슬라이드 2가지 버튼만으로 손쉽게 플레이할 수 있는 것이 특징이다.
    
    연세대학교를 졸업한 김강산 선배님이 데브시스터즈에 취직하면서 주변 사람들에게 쿠키런을 전파시켰다. 
    
    하지만 게임을 전파하던 중에 쿠키들에게 신체적으로 이상이 생기는 것을 발견하였다. 
    
    팔, 다리 길이가 임의적으로 변한 것이다. 때문에 긴급하게 각 쿠키들의 신체들을 측정하려고 한다.
    
    쿠키들은 신체를 측정하기 위해서 한 변의 길이가 N인 정사각형 판 위에 누워있으며, 
    
    어느 신체 부위도 판 밖으로 벗어나지 않는다. 판의 x번째 행, y번째 열에 위치한 곳을 (x, y)로 지칭한다. 
    
    판의 맨 왼쪽 위 칸을 (1, 1), 오른쪽 아래 칸을 (N, N)으로 나타낼 수 있다.

![image](https://github.com/user-attachments/assets/301c342e-0a0d-4aca-9850-c4ec1a6e8fa3)

    그림과 같이 쿠키의 신체는 머리, 심장, 허리, 그리고 좌우 팔, 다리로 구성되어 있다. 
    
    그림에서 빨간 곳으로 칠해진 부분이 심장이다.
    
    머리는 심장 바로 윗 칸에 1칸 크기로 있다. 
    
    왼쪽 팔은 심장 바로 왼쪽에 붙어있고 왼쪽으로 뻗어 있으며, 
    
    오른쪽 팔은 심장 바로 오른쪽에 붙어있고 오른쪽으로 뻗어있다.
    
    허리는 심장의 바로 아래 쪽에 붙어있고 아래 쪽으로 뻗어 있다. 
    
    왼쪽 다리는 허리의 왼쪽 아래에, 오른쪽 다리는 허리의 오른쪽 아래에 바로 붙어있고,
    
    각 다리들은 전부 아래쪽으로 뻗어 있다. 
    
    각 신체 부위들은 절대로 끊겨있지 않으며 굽혀진 곳도 없다.
    
    또한, 허리, 팔, 다리의 길이는 1 이상이며, 너비는 무조건 1이다.
    
    쿠키의 신체가 주어졌을 때 심장의 위치와 팔, 다리, 허리의 길이를 구하여라.

입력

다음과 같이 입력이 주어진다.

    N
    a1,1 . . . a1,N
    . . . . . .
    aN,1 . . . aN,N

출력

    첫 번째 줄에는 심장이 위치한 행의 번호 x와 열의 번호 y를 공백으로 구분해서 출력한다.
    
    두 번째 줄에는 각각 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 
    
    오른쪽 다리의 길이를 공백으로 구분해서 출력하여라.

제한

    5 ≤ N ≤ 1,000. N은 판의 한 변의 길이를 의미하는 양의 정수다.
    ai,j는 * 또는 _이다.
    *는 쿠키의 신체 부분이고, _는 쿠키의 신체가 올라가 있지 않은 칸을 의미한다.
    (1 ≤ i, j ≤ N)
    쿠키의 신체 조건에 위배되는 입력은 주어지지 않는다.

예제 입력 1 

    5
    _____
    __*__
    _***_
    __*__
    _*_*_
    
예제 출력 1 

    3 3
    1 1 1 1 1

예제 입력 2 

    10
    __________
    _____*____
    __******__
    _____*____
    _____*____
    _____*____
    ____*_*___
    ____*_____
    ____*_____
    ____*_____

예제 출력 2 

    3 6
    3 2 3 4 1

예제 입력 3 

    9
    ____*____
    *********
    ____*____
    ____*____
    ____*____
    ___*_*___
    ___*_*___
    ___*_*___
    ___*_*___

예제 출력 3 

    2 5
    4 4 3 4 4

풀이 알고리즘

    주어진 설명을 읽고 1) 심장의 위치 2) 왼팔,오른팔,몸통,왼다리,오른다리 길이를

    출력하는 문제 '쿠키의 신체 측정' 입니다.

    문제에서 주어지는 조건 그대로 구현을 진행하면 되는 문제이며, 아래 조건대로 구현을

    진행하면 문제 없이 풀이가 가능한 문제 였습니다.

    1) 심장 찾기

    2) 심장 기준 왼쪽 쭉 = 왼팔 길이 / 오른쪽 쭉 = 오른팔 길이 / 밑으로 쭉 = 몸통 길이

    3) 몸통 맨 밑 기준 왼쪽 대각선 = 왼다리 시작 -> 밑으로 쭉 = 왼다리 길이

    4) 몸통 맨 밑 기준 오른쪽 대각선 = 오른다리 시작 -> 밑으로 쭉 = 오른다리 길이

    위 순서대로 구현을 진행하면 풀이가 완료됩니다.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <unordered_map>
    using namespace std;


    struct Node {
        int x;
        int y;
    };
    int N;
    char cookie[1002][1002];
    
    // 0=왼팔,1=오른팔,2=몸통,3=왼다리,4=오른다리
    int mov[5][2] = { {0,-1},{0,1},{1,0},{1,-1},{1,1} }; // 0=머리, 그 외 팔다리 이동 방향
    Node heart;
    int answer[5]; // 0=머리, 1=왼팔, 2=오른팔, 3=왼다리, 4=오른다리
    void Solve() {
        
        Node body;
        for (int a = 0; a < 3; ++a) { // 왼팔,오른팔, 몸통은 규칙이 있어서 바로 풀이 가능
            Node location = heart;
            int leng = 0;
            for (int b = 0; b < N; ++b) {
                location = { location.x + mov[a][0], location.y + mov[a][1] };
                if (location.x >= N || location.x < 0 || location.y >= N || location.y < 0 || cookie[location.x][location.y] == '_') {
                    answer[a] = leng;
                    if (a == 2) {
                        body = { location.x - mov[a][0],location.y - mov[a][1] };
                    }
                    break;
                }
                else if (cookie[location.x][location.y] == '*') {
                    ++leng;
                }
            }
        }

        // 다리들은 몸통 기준 대각선에 위치하므로 별개로 처리 필요
        Node left_leg = { body.x + 1,body.y - 1 };
        Node right_leg = { body.x + 1, body.y + 1 };
       
        int leng = 1;
        for (int a = 0; a < N; ++a) {
            left_leg = { left_leg.x + 1,left_leg.y };
            if (left_leg.x >= N || left_leg.x < 0 || left_leg.y >= N || left_leg.y < 0 || cookie[left_leg.x][left_leg.y] == '_') {
                answer[3] = leng;
                break;
            }
            else if (cookie[left_leg.x][left_leg.y] == '*') {
                ++leng;
            }
        }
    
        leng = 1;
        for (int a = 0; a < N; ++a) {
            right_leg = { right_leg.x + 1,right_leg.y };
            if (right_leg.x >= N || right_leg.x < 0 || right_leg.y >= N || right_leg.y < 0 || cookie[right_leg.x][right_leg.y] == '_') {
                answer[4] = leng;
                break;
            }
            else if (cookie[right_leg.x][right_leg.y] == '*') {
                ++leng;
            }
        }
        cout << heart.x+1 << " " << heart.y+1 << "\n";
        for (int a = 0; a < 5; ++a) {
            cout << answer[a] << " ";
        }
    }
    void Input() {
        cin >> N;
        bool first_visit = false;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
                cin >> cookie[a][b];
                if (cookie[a][b] == '*' && first_visit == false) {
                    heart = { a+1,b };
                    first_visit = true;
                }
            }
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Solve();
    
    
        return 0;
    }

풀이 후기

    괜히 규칙 찾으려다가 시간이 오래 걸렸지만 몸풀기로 좋은 문제였구먼

    다른 C++ 풀이 보면 나보다 8ms가 짧은데, 나중에 시간되면 코드 읽어 봐야겠다.

    내일의 출근... 해야지

![image](https://github.com/user-attachments/assets/0c288ab4-65d6-40ff-a990-76df4293c4a5)


