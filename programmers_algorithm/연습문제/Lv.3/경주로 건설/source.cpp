#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node{
    int x;
    int y;
    int cost;
    int arrow; // 0은 세로, 1은 세로
};

int minCost[26][26][2];
int map[26][26];
int N;
void bfs(){
    queue<Node> que;
    int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    minCost[0][0][0] = 0;
    minCost[0][0][1] = 0;
    que.push({0,0,0,0});
    que.push({0,0,0,1});
    while(!que.empty()){
        Node now = que.front();
        que.pop();
        
        for(int a=0; a < 4; ++a){
            int x = now.x + mov[a][0];
            int y = now.y + mov[a][1];
            int arrow = a%2;
            int cost = now.cost;
            
            if(x >= N || x < 0 || y >= N || y < 0) continue;
            if(map[x][y] == 1) continue;
            
            
            if(now.arrow == 0){
                if(a == 0 || a==2)
                    cost = cost + 100;
                else
                    cost = cost + 600;
            }
            else{
                if(a==0 || a==2)
                    cost = cost + 600;
                else
                    cost = cost + 100;
            }
            
            if(cost >= minCost[x][y][arrow]) continue;
            
            minCost[x][y][arrow] = cost;
            que.push({x,y,cost,arrow});
        }
    }
}
int solution(vector<vector<int>> board) {
    int size = board.size();
    N = size;
    for(int a = 0; a < size; ++a){
        for(int b =0; b < size; ++b){
            map[a][b] = board[a][b];
            for(int c= 0; c < 2; ++c){
                minCost[a][b][c] = 21e8;
            }
        }
    }
    bfs();
    int answer= min(minCost[N-1][N-1][0],minCost[N-1][N-1][1]);
    return answer;
}
