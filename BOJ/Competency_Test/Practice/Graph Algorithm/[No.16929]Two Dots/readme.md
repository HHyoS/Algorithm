문제 사이트 : https://www.acmicpc.net/problem/16929

문제 설명 :

    Two Dots는 Playdots, Inc.에서 만든 게임이다. 
    
    게임의 기초 단계는 크기가 N×M인 게임판 위에서 진행된다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/149656665-56046859-7ea8-4e41-8bbe-e44e50baaae0.png)

    각각의 칸은 색이 칠해진 공이 하나씩 있다.
    
    이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다.

    다음은 위의 게임판에서 만들 수 있는 사이클의 예시이다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/149656676-a1e15bef-06db-4be4-99ba-9d31118f557c.png)
![upload acmicpc](https://user-images.githubusercontent.com/57944215/149656677-147ad830-98a3-44be-8029-5a8d4e4e50a3.png)

	
    점 k개 d1, d2, ..., dk로 이루어진 사이클의 정의는 아래와 같다.

    모든 k개의 점은 서로 다르다. 
    
    k는 4보다 크거나 같다.
    
    모든 점의 색은 같다.
    
    모든 1 ≤ i ≤ k-1에 대해서, di와 di+1은 인접하다. 
    
    또, dk와 d1도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.
    
    게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.

입력

    첫째 줄에 게임판의 크기 N, M이 주어진다.
    
    둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다. 
    
    게임판은 모두 점으로 가득차 있고, 게임판의 상태는 점의 색을 의미한다. 
    
    점의 색은 알파벳 대문자 한 글자이다.

출력

    사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.

제한

    2 ≤ N, M ≤ 50

예제 입력 1 

    3 4
    AAAA
    ABCA
    AAAA

예제 출력 1 

    Yes

예제 입력 2 

    3 4
    AAAA
    ABCA
    AADA

예제 출력 2 

    No

예제 입력 3 

    4 4
    YYYR
    BYBY
    BBBY
    BBBY

예제 출력 3 

    Yes

예제 입력 4 

    7 6
    AAAAAB
    ABBBAB
    ABAAAB
    ABABBB
    ABAAAB
    ABBBAB
    AAAAAB

예제 출력 4

    Yes
    
예제 입력 5 

    2 13
    ABCDEFGHIJKLM
    NOPQRSTUVWXYZ
    
예제 출력 5 

    No
    
[ 풀이 알고리즘 ]

    주어진 게임판에서 사이클을 찾는 문제였습니다.
    
    위 문제를 풀 때 주의해야할 점이 한 가지 있습니다.
    
    1. 입력받을 때. char 타입으로 입력을 받고, cin 을 사용한다면
    
    입력을 받은 char 배열을 N + 1. 즉 51로 선언( 개행문자 '\n' 포함 )
    
    이 점 외에는 주어진 문자열을 입력받고, { 상 , 하 , 좌 , 우 } 이동을 코드로 구현한 뒤
    
    같은 문자이고, 방문하지 않은 점 일 경우, 그리고 사이클에 포함된 점의 갯수가 4개 이상일경우
    
    사이클이라고 판단하고 결과를 출력하도록 하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    #include <vector>

    using namespace std;
    int N, M;
    char map[50][50]; // 게임판
    bool check[50][50]; // 방문했는지 체크하는 배열
    int mov[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }; // 이동방향
    int ck = 0; // 사이클을 찾았는지 확인하기 위한 변수
    
    void dfs(int x, int y, int t_x, int t_y, int leng) { //  ( x , y ) = 현재 위치 ( t_x , t _y ) = 목표 위치, leng = 현재까지 포함된 점의 갯수
    
        if ((x == t_x) && (y == t_y)) { // 현재 위치가 목표 위치와 같을 때
            if (leng < 4) // 사이클에 포함된 점의 갯수가 4개 이하라면
                return; // 탐색 종료
            ck = 1; // 사이클이라면 ck값을 1로 바꾼 후
            return; // 모든 dfs가 종료되도록 return
        }
        else {
        
            for (int a = 0; a < 4; ++a) { // 이동할 수 있는 네 방향 탐색
                int xx = x + mov[a][0];
                int yy = y + mov[a][1];

                if ((xx >= 0) && (xx < N) && (yy >= 0) && (yy < M) && (map[xx][yy] == map[x][y]) && (!check[xx][yy])) {
                // 이동하려는 방향이 게임판에서 벗어나지않고, 현재 위치의 점과 같은 값이며, 방문하지 않은 위치라면
                
                    check[xx][yy] = 1; // 방문표시 후
                    dfs(xx, yy, t_x, t_y, leng + 1); // 탐색 실시
                    
                    if (ck) // 탐색 후 사이클을 찾았다면 
                        return; // 불필요한 탐색을 하지 않도록 dfs 종료
                        
                    check[xx][yy] = 0; // 사이클을 못 찾은 dfs라면 방문표시 해제
                }
            }
        }
    }
    int main() {
    
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        //freopen("Input.txt","r", stdin);

        cin >> N >> M;
        char temp[51]; // char배열은 개행문자까지 입력받으므로 크기를 51로
        
        for (int a = 0; a < N; ++a) {
            cin >> temp;
            for (int b = 0; temp[b]; ++b) {//연결된 문자열로 입력받기 때문에 하나씩 끊어서 배열에 저장
                map[a][b] = temp[b];
            }
        }
        
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                for (int c = 0; c < 4; ++c) {
                    int x = a + mov[c][0];
                    int y = b + mov[c][1];
                    
                    if ((x >= 0) && (x < N) && (y >= 0) && (y < M) && (map[x][y] == map[a][b])) { // 네 방향 이동 후
                        check[x][y] = 1; // 이동 위치 방문표시
                        dfs(x, y, a, b, 1); // dfs탐색 실시
                        if (ck) { // 탐색 후 사이클을 찾았다면 for문 탈출을 위해
                            a = N; // a와 b값을 최대로 설정하고
                            b = M;
                            break; // for문 탈출
                        }
                        check[x][y] = 0;
                    }
                }
            }
        }
        if (ck) // 사이클을 찾았다면
            cout << "Yes";
        else // 못찾았다면
            cout << "No";
        return 0;

    }
