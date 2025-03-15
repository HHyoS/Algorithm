#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<char> v;

unordered_map <string, bool> mp;


int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
char arr[5][5];
bool visited[5][5];
int ans = 0;
void dfs(int deep,int x, int y) {
	if (deep == 7) {
		string tmp = "";
		for (int a = 0; a < v.size(); ++a) {
			tmp = tmp + v[a];
		}
		if (mp.count(tmp) == 0) {
			++ans;
			mp[tmp] = 1;
		}
		return;
	}
	for (int a = 0; a < 4; ++a) {
		int nx = x + mov[a][0];
		int ny = y + mov[a][1];

		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;

		v.push_back(arr[nx][ny]);
		dfs(deep + 1, nx, ny);
		v.pop_back();
	}
}

int Solve(){
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			v.push_back(arr[a][b]);
			dfs(1, a, b);
			v.pop_back();
		}
	}

	return ans;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		for (int a = 0; a < 4; ++a) {
			for (int b = 0; b < 4; ++b) {
				cin >> arr[a][b];
			}
		}
		cout << "#"<<test_case<< " " << Solve()<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
