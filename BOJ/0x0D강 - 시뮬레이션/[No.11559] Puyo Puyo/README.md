문제 사이트 : https://www.acmicpc.net/problem/11559

문제 설명

![image](https://github.com/user-attachments/assets/c1574c5b-a7db-4e49-8a83-f770c2c855fe)
![image](https://github.com/user-attachments/assets/3445d9b9-2666-4673-a910-b0d716de6ffe)

문제 정리

    필드 크기 : 12 x 6
    색상 : R,G,B,P,Y
    빈칸 : '.'
    연쇄 조건 : 같은 색 뿌요가 상하좌우로 4개 이상 연걸시 팡!
    연쇄 처리 프로세스
      1. 터질 수 있는 모든 뿌요 그룹을 찾기
      2. 동시에 팡!
      3. 중력에 따라 뿌요를 아래로 떨어트리기
      4. 다시 터트릴 수 있는 그룹이 있는지 확인하여 1-3 반복
    출력 : 주어진 필드에서 몇 연쇄가 발생하는지 출력

풀이 알고리즘

    입력 처리: 필드를 12행 × 6열의 2차원 리스트로 저장.

    연쇄 루프:
    
      1) 연쇄 횟수를 0으로 초기화
      
      2) 반복문을 통해 다음을 수행
      
        2-1)방문 여부를 추적하는 2차원 리스트를 초기화.
      
        2-2)모든 셀을 순회하며, 아직 방문하지 않았고 빈 칸이 아닌 셀에 대해 
          BFS를 수행하여 같은 색의 뿌요 그룹 찾기.
        
        2-3)그룹의 크기가 4 이상이면 해당 위치들을 리스트에 저장.
        
        2-4)터질 수 있는 그룹이 없으면 반복을 종료.
        
        2-5)그룹에 포함된 모든 뿌요를 '.'으로 변경하여 제거.
        
        2-6)중력을 적용하여 뿌요를 아래로 떨어뜨리기.
        
        2-7)연쇄 횟수를 1 증가.
      
      출력: 연쇄 횟수를 출력.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>
    
    using namespace std;
    
    int ROWS = 12;
    int COLS = 6;
    int dx[4] = {-1, 1, 0, 0}; // 상하좌우 방향 벡터
    int dy[4] = {0, 0, -1, 1};
    
    vector<string> field(ROWS);
    
    // BFS를 이용하여 같은 색의 뿌요 그룹을 찾음
    vector<pair<int, int>> bfs(int x, int y, vector<vector<bool>>& visited) {
        vector<pair<int, int>> connected;
        queue<pair<int, int>> q;
        char color = field[x][y];
        q.push({x, y});
        visited[x][y] = true;
        connected.push_back({x, y});
    
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
                    if (!visited[nx][ny] && field[nx][ny] == color) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        connected.push_back({nx, ny});
                    }
                }
            }
        }
        return connected;
    }
    
    // 중력을 적용하여 뿌요를 아래로 떨어뜨림
    void applyGravity() {
        for (int col = 0; col < COLS; ++col) {
            int emptyRow = ROWS - 1;
            for (int row = ROWS - 1; row >= 0; --row) {
                if (field[row][col] != '.') {
                    field[emptyRow][col] = field[row][col];
                    if (emptyRow != row) field[row][col] = '.';
                    --emptyRow;
                }
            }
            for (int row = emptyRow; row >= 0; --row) {
                field[row][col] = '.';
            }
        }
    }
    
    int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
        
        // 필드 입력
        for (int i = 0; i < ROWS; ++i) {
            cin >> field[i];
        }
    
        int chainCount = 0;
    
        while (true) {
            vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
            vector<pair<int, int>> toPop;
            for (int i = 0; i < ROWS; ++i) {
                for (int j = 0; j < COLS; ++j) {
                    if (field[i][j] != '.' && !visited[i][j]) {
                        auto connected = bfs(i, j, visited);
                        if (connected.size() >= 4) {
                            toPop.insert(toPop.end(), connected.begin(), connected.end());
                        }
                    }
                }
            }
    
            if (toPop.empty()) break;
    
            for (auto [x, y] : toPop) {
                field[x][y] = '.';
            }
    
            applyGravity();
            ++chainCount;
        }
    
        cout << chainCount << "\n";
        return 0;
    }

풀이 후기

    시뮬레이션은 재밌따.

![image](https://github.com/user-attachments/assets/a33c7d5e-dae6-4bb4-981f-f6e36b914774)



