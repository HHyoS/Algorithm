#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	int *r = (int*)malloc(sizeof(int)*n);
	long long answer = 0;
	for (int a = 0; a < n; ++a) {
		int v;
		cin >> v;
		r[a] = v;
	}
	int ms, ss;
	cin >> ms >> ss;

	sort(r, r+n);
/*	for (int a = 0; a < n; ++a)
		printf("%d ", r[a]);
	printf("\n");*/
	long long max = 1;
	int a = 0;
	while(a != n){
		int temp = r[a] -= ms;
		if (temp > 0) {
			int x = r[a];
			if (x > 0) {
				while (x - (max * ss) > 0)
					++max;
				answer += max;
			}
		}
		++answer;
		++a;
	}
	printf("%ld", answer);

	return 0;
}
