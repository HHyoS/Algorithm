#include<iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;


int n,m;
int s,t;
vector<int> path[2][100001];

bool info[4][100001];

void dfs(int idx,int numbering,int pathNumbering){
	if(info[numbering][idx]==1)
		return;
	
	info[numbering][idx] = 1;
	for(int a = 0; a < path[pathNumbering][idx].size(); ++a){
		if(info[numbering][path[pathNumbering][idx][a]]== 1)
			continue;
		dfs(path[pathNumbering][idx][a],numbering,pathNumbering);
	}
}
void solve(){
	info[0][t] = 1;
	dfs(s,0,0);
	info[1][s] = 1;
	dfs(t,1,0);

	dfs(s,2,1);
	dfs(t,3,1);
	int cnt = 0;

	for(int a = 1; a <= n; ++a){
		int check = 0;
		for(int b= 0; b < 4; ++b){
			if(info[b][a]==0){
				check = 1;
				break;
			}
		}
		if(check ==1)
			continue;
		++cnt;
	}
	cout << cnt-2;
}
void input(){
	cin >> n >> m;
	for(int a = 0; a < m; ++a){
		int from,to;
		cin >> from >> to;
		path[0][from].push_back(to);
		path[1][to].push_back(from);
	}
	cin >> s>>t;
}
int main(int argc, char** argv)
{
	input();
	solve();
	return 0;
}
