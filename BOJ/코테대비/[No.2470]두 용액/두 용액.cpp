#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, T;
vector<int> arr;

int tot = -1;
int degree = 21e8;
int l_idx, r_idx;
void solve() {
	int s = 0;
	int e = arr.size() - 1;

	while (s < e) {
		int sum = arr[s] + arr[e];
		if (abs(sum) < degree) {
			degree = abs(sum);
			l_idx = s;
			r_idx = e;
		}
		if (sum == 0)
			break;
		if (sum > 0)
			--e;
		else if (sum < 0)
			++s;
	}
	cout << arr[l_idx] << " " << arr[r_idx];
}
void input() {
	cin >> N;

	int temp;
	for (int a = 0; a < N; ++a) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	return 0;

}