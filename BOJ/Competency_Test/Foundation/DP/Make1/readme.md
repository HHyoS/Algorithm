문제 사이트 : https://www.acmicpc.net/workbook/view/3939

설명 :

	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

		X가 3으로 나누어 떨어지면, 3으로 나눈다.
		X가 2로 나누어 떨어지면, 2로 나눈다.
		1을 뺀다.

설명

	  저는 이 문제를 풀 때 우선순위 큐를 사용하여 문제를 해결하였습니다.
	  우선 우선순위 큐 pq를 선언하여 연산횟수가 작은 수를 우선하여 연산을 진행해 문제를 해결했습니다.


코드

	#include <iostream>
	#include <vector>
	#include <queue>
	#include <algorithm>

	using namespace std;

	bool check[1000001]; // 해당수를 방문했었는지 확인하는 check배열
	int main(void) {
		int n;

		scanf("%d", &n);
		priority_queue<pair<int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 연산횟수 기준 우선순위 큐
		pq.push({0,n });
		if (n == 1) { // 입력된 수가 1일경우 연산 0회
			printf("0");
			return 0;
		}
		while (!pq.empty()) {
			int count = pq.top().first + 1; // 연산횟수
			int value = pq.top().second; // 연산 할 값
			pq.pop();
			if (value % 3 == 0 && !check[value /3]) {
				if (value / 3 == 1) { 
					printf("%d", count);
					break;
				}
				else {
					check[value / 3] = 1;
					pq.push({ count,value / 3 });
				}
			}
			if (value % 2 == 0 && !check[value / 2]) {
				if (value / 2 == 1) {
					printf("%d", count);
					break;
				}
				else {
					check[value / 2] = 1;
					pq.push({ count, value / 2 });
				}
			}
			if (value  >= 2 && !check[value-1]) {
				if (value == 2) {
					printf("%d", count);
					break;
				}
				else {
					check[value - 1] = 1;
					pq.push({ count, value - 1 });
				}
			}

		}
		return 0;
	}


