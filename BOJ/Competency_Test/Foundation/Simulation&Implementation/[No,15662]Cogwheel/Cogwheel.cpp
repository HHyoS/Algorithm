#include <iostream>

using namespace std;
#define MAX 100000
int n,k;
bool arr[1000][8];
int book[1000];

void left(int num, int turn,int l) {
	if ((num > 0) && (l != arr[num - 1][(book[num - 1] + 2) % 8])) {
		if (turn == 1) {
			left(num - 1, -1, arr[num - 1][(book[num - 1] + 6) % 8]);
			book[num - 1] = (book[num - 1] + 1) % 8;
		}
		else {
			left(num - 1, 1, arr[num - 1][(book[num - 1] + 6) % 8]);
			book[num - 1] = (book[num - 1] + 7) % 8;
		}
	}
}
void right(int num, int turn,int r) {
	if ((num + 1 < n) && (r != arr[num + 1][(book[num + 1] + 6) % 8])) {
		if (turn == 1) {
			right(num + 1, -1, arr[num + 1][(book[num + 1] + 2) % 8]);
			book[num + 1] = (book[num + 1] + 1) % 8;
		}
		else {
			right(num + 1, 1, arr[num + 1][(book[num + 1] + 2) % 8]);
			book[num + 1] = (book[num + 1] + 7) % 8;
		}
	}
}
int main() {


//	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int a = 0; a < n; ++a){
		for (int b = 0; b < 8; ++b) {
			scanf("%1d", &arr[a][b]);
		}
	}
	scanf("%d", &k);
	int answer = 0;
	for (int a = 0; a < k; ++a) {
		int num, turn;
		scanf("%d %d", &num, &turn);
		--num;
		int l = arr[num][(book[num] + 6) % 8];
		int r = arr[num][(book[num] + 2) % 8];
		if ((num > 0) && (l != arr[num-1][(book[num-1]+2)%8])) {
			if (turn == 1) {
				left(num - 1, -1, arr[num - 1][(book[num - 1] + 6) % 8]);
				book[num - 1] = (book[num - 1] + 1) % 8;
			}
			else {
				left(num - 1, 1, arr[num - 1][(book[num - 1] + 6) % 8]);
				book[num - 1] = (book[num - 1] + 7) % 8;
			}
		}
		if ((num + 1 < n) && (r != arr[num+1][(book[num+1]+6)%8])) {
			if (turn == 1) {
				right(num + 1, -1, arr[num + 1][(book[num + 1] + 2) % 8]);
				book[num + 1] = (book[num + 1] + 1) % 8;
			}
			else {
				right(num + 1, 1, arr[num + 1][(book[num + 1] + 2) % 8]);
				book[num + 1] = (book[num + 1] + 7) % 8;
			}

		}
		if (turn == 1)
			book[num] = (book[num] + 7) % 8;
		else
			book[num] = (book[num] + 1) % 8;
		
	}

	for (int a = 0; a < n; ++a) {
		if (arr[a][book[a]])
			++answer;
	}
	printf("%d", answer);
	return 0;
}
