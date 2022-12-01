#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


struct Node {
	int n1;
	int n2;
};
int tot;
bool check[1501][1501];
int ans = 0;
queue<Node> que;

void bfs() {


	while (!que.empty()) {
		int nums[3] = { que.front().n1, que.front().n2, tot - que.front().n1 - que.front().n2 };
		que.pop();
		for (int a = 0; a < 2; ++a) {
			for (int b = a + 1; b < 3; ++b) {
				int new_num1 = 0;
				int new_num2 = 0;
				int new_num3 = 0;
				if (nums[a] > nums[b]) {
					new_num1 = nums[b] * 2;
					new_num2 = nums[a] - nums[b];
					new_num3 = tot - new_num1 - new_num2;
				}
				else if (nums[a] < nums[b]) {
					new_num1 = nums[b] - nums[a];
					new_num2 = nums[a] * 2;
					new_num3 = tot - new_num1 - new_num2;

				}
				else
					continue;

				if (new_num1 == new_num2 && new_num2 == new_num3){
					ans = 1;
					return;
				}
				int mini = min(new_num1, min(new_num2, new_num3));
				int maxi = max(new_num1, max(new_num2, new_num3));

				if (check[mini][maxi])continue;

				check[mini][maxi] = 1;
				que.push({ mini,maxi });
			}
		}
	}

	return;
}
void input() {
	int nums[3];
	cin >>nums[0] >> nums[1] >> nums[2];

	tot = nums[0] + nums[1] + nums[2];
	if (tot % 3 != 0) {
		return;
	}
	else {
		if (nums[0] == nums[1] && nums[1] == nums[2]) {
			ans = 1;
			return;
		}
		sort(nums, nums + 3);
		check[nums[0]][nums[2]] = 1;
		que.push({ nums[0],nums[2] });
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	input();
	bfs();
	cout << ans;
}
