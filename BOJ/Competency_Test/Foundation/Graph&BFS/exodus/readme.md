문제 사이트 : https://www.acmicpc.net/problem/3055
현재 문제 풀이 진행중입니다.

2021 / 01 / 05 완성.

설명

    주어진 조건에 따라 고슴도치의 위치 (S)가 비버소굴(D)로 도착하는 최단시간을 구하는 문제였습니다.
    
    주어지는 최대의 지도크기 50을 미리 설정하여 사용하기위해 map 변수를 할당하였고, 고슴도치가 반복된 위치에서 
    
    움직이는것을 방지하기위해 check배열을 사용하여 물이나 고슴도치가 방문했던곳을 제외하고 방문하도록 전역변수를 선언하였습니다.
    
    n과 m을 입력받아 사용할 map의 크기를 설정하고, 목적지 D, bfs방식을 통해 고슴도치와 물의 가능한위치저장   을 위한 queue S, water 를 선언하였고,
    
    while(!S.empty()) 를 조건으로 고슴도치가 더이상 이동할 수 없을때까지 while문을 반복하도록 하였습니다.
    
    count 변수를 선언하여 while문이 한번 반복할때마다 숫자가 증가하도록 하였고, 고슴도치가 비버굴에 도착하면 count를 print하고, 비버굴에 갈 수 있는 경우의 수가 존재하지 않을경우
   
    while문이 종료되어 KAKTUS를 print하도록 프로그램을 작성하였습니다.
    
소스코드 

    #include <iostream>
    #include <vector>
    #include <queue>

    using namespace std;
    char map[51][51]; - 전체적인 맵
    bool check[51][51]; - 방문 확인

    int main(void) {
      // freopen("input.txt", "r", stdin);
        int n, m; - 맵의 크기
        scanf("%d%d", &n, &m);
        int ar[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        queue<pair<int, int>> S;
        pair<int, int> D;
        queue<pair<int, int>> water;
        int count = 0;

        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
                scanf(" %c", &map[a][b]);
                if (map[a][b] == 'D') {
                    D = { a,b };
                }
                else if (map[a][b] == 'S') {
                    check[a][b] = 1;
                    S.push({ a,b });
                }
                else if (map[a][b] == '*') {
                    check[a][b] = 1;
                    water.push({ a,b });
                }
            }
        }
        if (D == S.front()) // 비버굴과 고슴도치의 위치가 동일할 경우
            printf("%d",count);

        while (!S.empty()) { // 고슴도치가 더 이상 이동이 불가능하면
            ++count; // 걸린 시간 증가
            int size = water.size(); // 물이 존재한다면, bfs방식을 통한 물의 확장
            for (int a = 0; a < size; ++a) {
                pair<int, int> w = water.front();
                water.pop();
                for (int b = 0; b < 4; ++b) {
                    int x = w.first + ar[b][0];
                    int y = w.second + ar[b][1];
                    if (x >= 1 && x <= n &&y >= 1 && y <= m) {
                        if (map[x][y] == '.') { // 이동하려는 장소가 빈 곳 일경우에만 동작
                            check[x][y] = 1;
                            map[x][y] = '*';
                            water.push({ x,y });
                        }
                    }
                }
            }
            int ssize = S.size();
            for (int a = 0; a < ssize; ++a) {
                pair<int, int> g = S.front();
                S.pop();
                for (int b = 0; b < 4; ++b) {
                    int x = g.first + ar[b][0];
                    int y = g.second + ar[b][1];
                    if (x >= 1 && x <= n && y >= 1 && y <= m && !check[x][y]) { // check 배열을  통해 물이 방문했던 곳이나 고슴도치가 방문했던 곳은 재방문 x
                        if (map[x][y] == 'D') { // 비버굴 발견 시 종료
                            printf("%d", count);
                            return 0;
                        }
                        else if (map[x][y] == '.') { // 빈 곳 발견시 check에 방문표시 후 S배열에 고슴도치가 이동 가능한 위치 추가
                            check[x][y] = 1;
                            S.push({ x,y });
                        }
                    }
                }
            }
        }
        printf("KAKTUS"); // 고슴도치가 비버굴에 도착하지 못한다면 print
        return 0;

    }


