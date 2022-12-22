#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;


struct Node {
    int x;
    int y;
};
int map[101][101];
int air[101][101];
int visited[101][101] = { 0 };
bool inserted[101][101];
bool checked[101][101];
queue<Node> cheese;
int N, M;
queue<Node> space;
queue<Node> temp;
int tot;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void print() {
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cout << map[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


// 치즈가 사라짐으로 인해 발생된 추가공간을 확인하는 함수
void spaceFinder() {

    while (!temp.empty()) {
        Node now = temp.front();
        temp.pop();


        for (int a = 0; a < 4; ++a) {
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];

            if (x >= N || x < 0 || y >= M || y < 0)continue;
            if (map[x][y] == 1)continue;
            if (inserted[x][y] == 1) continue;

          
          //추가공간을 발견했을 경우 해당공간과 연결된 추가 탐색공간을 찾아야하기때문에 temp 큐에 추가시켜주고
          // 찾은 추가공간을 space 큐에 push하여 다음 탐색에 사용할 수 있도록 
            inserted[x][y] = 1;
            space.push({ x,y });
            temp.push({ x,y });
        }
    }
}
int bfs() {
    int time = 1;
    memset(visited, 0, sizeof(visited));
    while (1) {
        
      
      // queue에 저장된 공간을 돌면서 치즈들이 있다면 공기에 닿았음을 표시
      // 만약 주변에 치즈를 하나도 발견하지 못했다면 해당 공간은 더이상 탐색할 필요가 없어짐
        int spaceSize = space.size();
        for (int s = 0; s < spaceSize; ++s) {
            Node now = space.front();
            space.pop();
            
            int flag = 0;
            for (int a = 0; a < 4; ++a) {
                int x = now.x + mov[a][0];
                int y = now.y + mov[a][1];

                if (x >= N || x < 0 || y >= M || y < 0) continue;
                
                if (map[x][y] == 1) {
                    ++visited[x][y];
                    if (flag == 0)
                        flag = 1;
                }
            }
            if (flag) {
                space.push(now);
            }
        }
      
      // 현재 치즈의 상태를 확인하는 알고리즘
      
      // 현재 치즈가 공기가 두번이상 닿았으면 해당 치즈를 없는취급하고 탐색공간에 추가하여
      // 빈공간취급
        int cheeseSize = cheese.size();

        for (int s = 0; s < cheeseSize; ++s) {
            Node now = cheese.front();
            cheese.pop();

            if (visited[now.x][now.y] >= 2) {
                inserted[now.x][now.y] = 1;
              
              // temp 큐는 치즈가 없어서 새로 추가된 공간을 임시로 저장하는 queue로
              // 해당 큐를 사용하여 내부공간이 생겼음을 확인하고, 해당 공간도 탐색공간에 추가
                temp.push({ now.x,now.y });
                map[now.x][now.y] = 0;
                space.push(now);

            }
            else {
                cheese.push(now);
                visited[now.x][now.y] = 0;
            }
        }

      
      // 치즈가 사라짐으로 인해 추가된 공간이 있는지 확인하는 함수
      // 치즈가 없어진 공간부터 시작하여 bfs탐색을 하며 탐색공간을 추가
        spaceFinder();
      
      // 만약 더이상 없어질 치즈가 없다면 현재 시간을 return
        if (cheese.size() == 0) {
            return time;
        }
        ++time;
    }
}

// 근처에 치즈가 있는 공간을 찾기 -> 근처에 치즈가 없는 공간은 굳이 확인할 필요가 없으므로
// 치즈가 있는 공간을 찾았다면 탐색에 필요하므로 queue에 저장
void init() { 
    queue<Node> que;
    que.push({ 0,0 });
    visited[0][0] = 1;

    while (!que.empty()) {
        Node now = que.front();
        que.pop();

        int flag = 0;
        for (int a = 0; a < 4; ++a) {
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];

            if (x >= N || x < 0 || y >= M || y < 0) continue;
            if (inserted[x][y] && map[x][y] == 0) continue;
            
          
          // inserted 배열은 탐색에 사용된 공간인지 확인하는 배열로 탐색된 공간이라면 1로 표시해서 
            inserted[x][y] = 1;
            if (map[x][y] == 1){
                if (flag == 0)
                    flag = 1;
            }
            else if (map[x][y] == 0) {
                que.push({ x,y });
            }
        }
        if (flag) {
            space.push({ now.x,now.y });
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen("input.txt", "r", stdin);

    cin >> N >> M;

    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < M; ++b) {
            cin >> map[a][b];
            if (map[a][b]) {
                cheese.push({ a,b });
            }
        }
    }
    init();

    cout << bfs();


    return 0;

}
