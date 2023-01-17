#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	int x;
	int y;
};
int N;
char map[26][26];
int mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
vector<int> ans;

int bfs(int x,int y){
	queue<Node> que;
	que.push({x,y});
	map[x][y] = '0';
	int cnt = 1;
	while(!que.empty()){
		Node now = que.front();
		que.pop();

		for(int a = 0; a < 4; ++a){
			int nx = now.x + mov[a][0];
			int ny = now.y + mov[a][1];

			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(map[nx][ny] == '0') continue;

			map[nx][ny] = '0';
			que.push({nx,ny});
			++cnt;
		}
	}
	return cnt;
}
void solve(){
	
	for(int a = 0; a < N; ++a){
		for(int b = 0; b< N; ++b){
			if(map[a][b] == 'q'){
				ans.push_back(bfs(a,b));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int a = 0; a < ans.size(); ++a){
		cout << ans[a] << "\n";
	}
}

void input(){
	cin >> N;
	for(int a = 0; a<N; ++a){
		for(int b =0; b < N; ++b){
			cin >> map[a][b];
			if(map[a][b] == '1')
				map[a][b] = 'q';
		}
	}
}
int main(int argc, char** argv)
{
	input();
	solve();
	return 0;
}
