#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define RULE 100
#define max(a,b) (a>b?a:b)
using namespace std;

int test_case, T = 10, tn;
int arr[RULE][RULE];
int sum1, sum2, sum3, max_sum;

void inputArr() {
	for (int i = 0; i < RULE; i++) {
		for (int j = 0; j < RULE; j++) {
			cin >> arr[i][j];
		}
	}
}

void maxSum() {
	max_sum = 0;
	for (int i = 0; i < RULE; i++) {
		sum1 = 0, sum2 = 0, sum3 = 0;
		for (int j = 0; j < RULE; j++) {
			sum1 += arr[i][j];
			sum2 += arr[j][i];
			if (i == j) // 대각은 굳이 안 해줘도 될 듯하다.
				sum3 += arr[i][j];
		}

		max_sum = max(max_sum, sum1);
		max_sum = max(max_sum, sum2);
		max_sum = max(max_sum, sum3);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (test_case = 1; test_case <= T; test_case++) {
		cin >> tn;

		inputArr(); // 배열 입력
		maxSum(); // 가장 큰 합 찾기

		cout << "#" << test_case << " " << max_sum << "\n";
	}
	return 0;
}
