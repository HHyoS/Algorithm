문제 사이트 : https://www.acmicpc.net/problem/17086

문제 설명 : 

    N×M 크기의 공간에 아기 상어 여러 마리가 있다. 
    
    공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 
    
    한 칸에는 아기 상어가 최대 1마리 존재한다.

    어떤 칸의 안전 거리는 그 칸과 가장 거리가 가까운 아기 상어와의 거리이다.
    
    두 칸의 거리는 하나의 칸에서 다른 칸으로 가기 위해서 지나야 하는 칸의 수이고, 
    
    이동은 인접한 8방향(대각선 포함)이 가능하다.

    안전 거리가 가장 큰 칸을 구해보자. 

입력

    첫째 줄에 공간의 크기 N과 M(2 ≤ N, M ≤ 50)이 주어진다. 
    
    둘째 줄부터 N개의 줄에 공간의 상태가 주어지며, 0은 빈 칸, 1은 아기 상어가 있는 칸이다. 
    
    빈 칸의 개수가 한 개 이상인 입력만 주어진다.

출력

    첫째 줄에 안전 거리의 최댓값을 출력한다.

예제 입력 1

    5 4
    0 0 1 0
    0 0 0 0
    1 0 0 0
    0 0 0 0
    0 0 0 1

예제 출력 1 

    2

예제 입력 2 

    7 4
    0 0 0 1
    0 1 0 0
    0 0 0 0
    0 0 0 1
    0 0 0 0
    0 1 0 0
    0 0 0 1

예제 출력 2 

    2
    
[ 풀이 알고리즘 ]

    주어진 N * M 크기의 바둑판이 (1) 상어가 있는 칸  (2) 상어가 없는 칸 으로 구분되어 있을 때
    
    상어가 없는 칸 중 상어가 있는 칸 과 가장 멀리 떨어져 있는 칸이 가지는 안전거리를 구하는 문제였습니다.
    
    안전거리는 상어가 없는 칸에서 가장 가까운 상어가 있는 칸까지 거리를 나타내는 거리입니다.
    
    이 문제를 풀기위해 모든 빈칸에 대하여 BFS탐색을 실행하였고, 상어가 만나면 해당칸이 가지는
    
    안전거리와, 현재까지 구해진 안전거리 중 가장 큰 안전거리를 저장하도록 구현하였고,
    
    상어가 없는 모든칸의 탐색이 끝나면 가장 긴 안전거리를 출력하도록 하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    #include <vector>

    using namespace std;
    
    int N, M;
    
    bool sea[50][50]; // 상어가 존재하는 바둑판 정보
    
    vector<pair<int, int>> shark; // 비어있는 칸의 위치
    
    int mov[8][2] = { {-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1} }; // 8가지 이동
    
    bool check[50][50];
    
    int big = -1;
    
    void bfs(int X, int Y) { // 안전거리를 구하는 BFS 탐색
        queue<pair<int, int>> que; // 현재 위치를 queue에 저장하고
        que.push({ X,Y }); // 
        int count = 1; // 최소 이동거리는 1칸이므로 1
        check[X][Y] = 1; // 현재 위치 재방문하지 않도록 check에 저장 후
        
        while (!que.empty()) { // BFS탐색 실시
        
            int size = que.size();
            
            for (int a = 0; a < size; ++a) { // 현재 count횟수에 도달한 모든 위치에 대해 탐색 실시
            
                int x = que.front().first;
                int y = que.front().second;
                
                que.pop();
                
                for (int b = 0; b < 8; ++b) { // 여덟 방향에 대해 탐색하고
                
                    int xx = x + mov[b][0];
                    int yy = y + mov[b][1];
                    if ((xx >= 0) && (xx < N) && (yy >= 0) && (yy < M) && !check[xx][yy]) {
                    // 바둑판 내의 범위이며, 방문하지 않은 위치라면 
                        check[xx][yy] = 1; // 방문표시 후
                        if (sea[xx][yy]) { // 방문한 곳이 상어가 존재한다면
                            if (big < count)
                                big = count; // 현재까지 안전거리와 최대 안전거리 비교 후 
                                // 큰값 저장
                            return; // 상어를 만났으므로 BFS탐색 종료
                        }
                        que.push({ xx,yy }); // 상어를 만나지 않았다면 다음 BFS탐색 실시
                    }
                }
            }
            ++count;
        }
    }
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

       freopen("Input.txt","r", stdin);
        cin >> N >> M;
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                cin >> sea[a][b];
                if (!sea[a][b])
                    shark.push_back({ a,b });
            }
        }

        for (int a = 0; a < shark.size(); ++a) { // 상어가 없는 모든칸에 대하여 탐색 실시
                bfs(shark[a].first, shark[a].second);
                memset(check, 0, sizeof(check));
        }
        cout << big;
        return 0;

    }
    
    
