#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

string gear[4];
int K;
int cursor[4];


void turn(int idx, int arrow,int type) {
	
	if (idx != 0 && (type == 0 || type ==2)) {
		int left = (cursor[idx - 1] + 2) %8;
		int now = (cursor[idx] + 6) % 8;
		if (gear[idx - 1][left] != gear[idx][now]) {
			if (arrow == 1)
				turn(idx- 1, -1, 0);
			else
				turn(idx - 1, 1, 0);
		}
	}
	if (idx != 3 && (type ==1 || type==2)) {
		int right = (cursor[idx + 1] + 6) % 8;
		int now = (cursor[idx] + 2) % 8;
		if (gear[idx][now] != gear[idx + 1][right]) {
			if (arrow == 1)
				turn(idx + 1, -1, 1);
			else
				turn(idx + 1, 1, 1);
		}
	}
	if (arrow == 1)
		cursor[idx] = (cursor[idx] + 7) % 8;
	else
		cursor[idx] = (cursor[idx] + 1) % 8;
}
void solve() {
	for (int a = 0; a < K; ++a) {
		int idx, arrow;
		cin >> idx >> arrow;
		turn(idx-1, arrow,2);

	/*	for (int b = 0; b < 4; ++b) {
			for (int c = 0; c < 8; ++c) {
				cout << gear[b][(cursor[b] + c) % 8];
			}
			cout << "\n";
		}*/
	}
}
void input() {
	
	for (int a = 0; a < 4; ++a) {
			cin >> gear[a];
	}
	cin >> K;

}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	int ans = 0;
	int point = 1;
	for (int a = 0; a < 4; ++a) {
		if (gear[a][cursor[a]] == '1')
			ans += point;
		point *= 2;
	}
	cout << ans;
	return 0;

}
