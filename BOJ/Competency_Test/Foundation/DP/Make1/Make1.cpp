#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1000001];
int main(void) {
	int n;

	scanf("%d", &n);
	priority_queue<pair<int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,n });
	if (n == 1) {
		printf("0");
		return 0;
	}
	while (!pq.empty()) {
		int count = pq.top().first + 1;
		int value = pq.top().second;
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


