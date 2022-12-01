#include<iostream>
#include<string>
#include<algorithm>
#include<queue>


using namespace std;
long long N, M;
long long arr[10001];
long long maxi;

void bs() {
	long long s = 1;
	long long e = maxi * N;
	long long ans = 0;
	long long count = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;

		long long cnt = 0;
		for (int a = 0; a < M; ++a) {
			cnt += (mid / arr[a])+1;
			if (cnt >= N)
				break;
		}

		if (cnt >= N) {
			e = mid - 1;
			ans = mid;
		}
		else {
			s = mid + 1;
		}
	}

	int idx = 0;
	ans = ans - 1;
	long long  t = 0;
	for (int a = 0; a < M; ++a) {
		t+= ans / arr[a]+1;
	}
	
	ans += 1;
	for (int a = 0; a < M; ++a) {
		if (ans % arr[a] == 0)
			++t;

		if (t == N) {
			idx = a + 1;
			break;
		}

	}

	cout << idx;
}
void input() {
	cin >> N >> M;
	for (int a = 0; a < M; ++a) {
		cin >> arr[a];
		if (maxi < arr[a])
			maxi = arr[a];
	}


}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	input();

	if (M >= N) {
		cout << N;
	}
	else
		bs();
	return 0;

}
