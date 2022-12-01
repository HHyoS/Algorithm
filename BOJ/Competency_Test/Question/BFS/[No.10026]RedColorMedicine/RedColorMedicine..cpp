#include <iostream>
#include <cstdio>
#include<string.h>

using namespace std;

char ar[101][101];
bool ck[101][101] = {  0, };
int xy[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int n;
void bfs(int x,int y,char w){
	if (ar[x][y] == 'R')
		ar[x][y] = 'G';
	for (int a = 0; a < 4; ++a) {
		if ((x + xy[a][0] > 0) && (x + xy[a][0] <= n) && (y + xy[a][1] > 0) && (y + xy[a][1] <= n)) {
			if ((ar[x + xy[a][0]][y + xy[a][1]] == w) && (ck[x + xy[a][0]][y + xy[a][1]] == 0)) {
				ck[x + xy[a][0]][y + xy[a][1]] = 1;
				bfs(x + xy[a][0], y + xy[a][1], w);
			}
		}
	}
	return;
}

int main(){
	
//	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	int map_1 = 0;
	int map_2 = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			scanf(" %c", &ar[a][b]);
		}
	}

	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (ck[a][b] == 0) {
				ck[a][b] = 1;
				bfs(a, b, ar[a][b]);
				++map_1;
			}
		}
	}

	for (int a = 1; a <= 100; ++a)
		memset(ck[a], 0, sizeof(bool) * 101);
	
/*	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			printf("%c", ar[a][b]);
		}
		printf("\n");
	}*/
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (ck[a][b] == 0) {
				ck[a][b] = 1;
				bfs(a, b, ar[a][b]);
				++map_2;
			}
		}
	}
	printf("%d %d", map_1, map_2);
	return 0;
}
