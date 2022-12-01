#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, k;
int arr[200];
bool check[200];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);
	cin >> n >> k;
	queue<int> que;
	for (int a = 0; a < 2 * n; ++a) {
		cin >> arr[a];
	}
	int answer = 0;
	int start = 0, end = 0;
	int n_2 = n + n;
	while (k > 0) {
		start = (start + n_2 - 1) % n_2;
		end = (start + n - 1) % n_2;
		// 동작 1

		int size = que.size();
		for (int a = 0; a < size; ++a) {
			int robot = que.front();
			int one_step = (robot + 1) % n_2;
			que.pop();
			if (robot == end) {
				check[robot] = 0;
				continue;
			}
			else if ((arr[one_step] > 0) && !check[one_step]) {
				check[robot] = 0;
				if(one_step != end){
					que.push(one_step);
					check[one_step] = 1;
				}
				arr[one_step] -= 1;
				if (arr[one_step] == 0)
					--k;
			}
			else {
				que.push(robot);
			}
			// 동작 2
		}

		if (arr[start] > 0) {
			if (arr[start] == 1) {
				--k;
			}
			que.push(start);
			arr[start] -= 1;
			check[start] = 1; 
		}
		//동작 3

		++answer;
	}
	cout << answer;
	return 0;
}

