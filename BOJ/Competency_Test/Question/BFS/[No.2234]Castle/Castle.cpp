#include <iostream>
#include <cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int mp[51][51];
bool ar[51][51];


int n, m;
int biggerst = 0;
int ck = 0;
int arr[4] = { 1,2,4,8 };
bool able = 0;
void bfs1(int x,int y){
	++ck;
	for (int a = 0; a < 4; ++a) {
		if ((mp[x][y] & arr[a]) != arr[a]) {
			if ((arr[a] == 1) && (y > 1)){
				if (!ar[x][y-1]) {
					ar[x][y-1] = 1;
					bfs1(x, y-1);
				}

			}
			else if ((arr[a] == 2) && (x > 1)) {
				if (!ar[x-1][y]) {
					ar[x - 1][y] = 1;
					bfs1(x - 1, y);
				}

			}
			else if ((arr[a] == 4) && (y < n)) {
				if (!ar[x][y+1]) {
					ar[x][y+1] = 1;
					bfs1(x, y+1);
				}

			}
			else if ((arr[a] == 8) && (x < m)) {
				if (!ar[x + 1][y]) {
					ar[x + 1][y] = 1;
					bfs1(x + 1, y);
				}
			}
		}
	}
}

int main(){
	
	freopen("Input.txt", "r", stdin);
	cin >> n >> m ;


	for (int a = 1; a <= m; ++a) {
		for (int b = 1; b <= n; ++b) {
			cin >> mp[a][b];
		}
	}
	int room = 0;
	for (int a = 1; a <= m; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (!ar[a][b]) {
				ck = 0;
				ar[a][b] = 1;
				bfs1(a, b);
				if (ck > biggerst)
					biggerst = ck;
				++room;
			}
		}	
	}
	cout << room << " " << biggerst;
	for (int a = 1; a <= m; ++a) {
		for (int b = 1; b <= n; ++b) {
			for (int c = 0; c < 4; ++c) {
				if ((mp[a][b] & arr[c]) == arr[c]) {
					memset(ar, 0, sizeof(ar));
					ck = 0;
					ar[a][b] = 1;
					mp[a][b] -= arr[c];
					bfs1(a, b);
					if (ck > biggerst)
						biggerst = ck;
					mp[a][b] += arr[c];
				}
			}
		}
	}
	cout << " "<< biggerst;
	return 0;
}
