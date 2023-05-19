#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct Node{
    int x;
    int y;
};


char map[102][102];
int solution(vector<string> maps) {
    int answer = 0;
    memset(map,0,sizeof(map));
    int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool visited[101][101] = {0};
    Node lever;
    int row = maps.size();
    int col = maps[0].size();
    for(int a = 0; a <maps.size(); ++a){
        for(int b = 0; b < maps[a].size(); ++b){
            map[a][b] = maps[a][b];
            if(map[a][b] == 'L'){
                lever = {a,b};
            }
        }
    }
    queue<Node> que;
    que.push(lever);
    visited[lever.x][lever.y] = 1;
    int LeverToStart = -1;
    int LeverToEnd = -1;
    int cnt = 1;
    while(!que.empty()){
        int size = que.size();
        for(int s = 0; s < size; ++s){
            Node now = que.front();
            que.pop();
            
            for(int a= 0; a < 4; ++a){
                int x = now.x + mov[a][0];
                int y = now.y + mov[a][1];
                
                if(x < 0 || x >= row || y < 0 || y >= col)continue;
                if(map[x][y]== 'X') continue;
                if(visited[x][y]) continue;
                
                visited[x][y] = 1;
                que.push({x,y});
                if(map[x][y] == 'S'){
                    LeverToStart = cnt;
                }
                else if(map[x][y] == 'E'){
                    LeverToEnd = cnt;
                }
            }
        }
        ++cnt;
    }
    if(LeverToEnd == -1 || LeverToStart == -1){
        answer = -1;
    }
    else{
        answer = LeverToEnd + LeverToStart;
    }
    return answer;
}
