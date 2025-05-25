#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<long long> v;
bool bs(long long target) {
	int s = 0;
	int e = v.size() - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		// 현재 위치의 값이 목표 값보다 크다면 e를 현재 위치 -1
		if (target < v[mid]) {
			e = mid - 1;
		}
		// 현재 위치의 값이 목표 값보다 작다면 s를 현재 위치 +1
		else if (target > v[mid]) {
			s = mid + 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}
void Input() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; ++i) {
		long long tmp;
		cin >> tmp;
		cout << bs(tmp) << "\n";
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	return 0;
}
