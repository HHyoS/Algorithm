#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
vector<string> info;
bool used[16];
int n,m;
void dfs(string input,int deep){
	if(deep == n)
		return;

	string now = input;
	string target = info[deep];
	if(used[deep] == 1){
		dfs(input,deep+1);
		return;
	}
	for(int a = 0; a < m; ++a){
		if(now[a] != target[a]){
			if(target[a] == '.'){
				target[a] = now[a];
			}
			else if(now[a] == '.'){
				now[a] = target[a];
			}
			else{
				dfs(input,deep+1);
				return;
			}
		}
	}
	
	info[deep] = target;
	used[deep] = 1;
	dfs(now,deep+1);
}
void input(){
	cin >> n >> m;
	for(int a = 0; a < n ;++a){
		string temp;
		cin >> temp;
		info.push_back(temp);
	}
	sort(info.begin(), info.end(),greater<string>());
}

void solve(){
	int cnt = 0;
	for(int a = 0; a < n; ++a){
		if(used[a] == 0){
			++cnt;
			used[a] = 1;
		}
		dfs(info[a],a+1);
	}
	cout << cnt;
}
int main(int argc, char** argv)
{
	input();
	solve();
	return 0;
}
