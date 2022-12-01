#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>


int tree[27][2];
using namespace std;
int N;
void inorder(int num) {
	if (num == -1)
		return;
	else {
		char data = num+'A';
		inorder(tree[num][0]);
		cout << data;
		inorder(tree[num][1]);
	}

}
void preorder(int num) {
	if (num == -1)
		return;
	else {
		char data = num + 'A';
		cout << data;
		preorder(tree[num][0]);
		preorder(tree[num][1]);
	}
}
void postorder(int num) {
	if (num == -1)
		return;
	else {
		char data = num + 'A';
		postorder(tree[num][0]);
		postorder(tree[num][1]);
		cout << data;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

//	freopen("Input.txt", "r", stdin);
	cin >> N;
	char dat, node_1, node_2;
	for (int a = 0; a < 27; ++a) {
		tree[a][0] = -1;
		tree[a][1] = -1;
	}
	for (int a = 0; a < N; ++a) {
		cin >> dat >> node_1 >> node_2;
		if (node_1 != '.') {
			tree[dat - 'A'][0] = node_1 - 'A';
		}
		if (node_2 != '.') {
			tree[dat - 'A'][1] = node_2 - 'A';
		}
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}
