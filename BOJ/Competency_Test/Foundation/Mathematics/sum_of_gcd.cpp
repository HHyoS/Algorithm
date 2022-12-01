#include <iostream>
#include <stdlib.h>
using namespace std;

int gcd(int a, int b) {
	int r = 0;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int count;
	cin >> count;
	long x, y;
	int n;
	for (int a = 0; a < count; ++a) {
		cin >> n;
		long * d = (long*)malloc(sizeof(long)*n);
		for (int b = 0; b < n; ++b) {
			long temp = 0;
			cin >> temp;
			d[b] = temp;
		}
		long answer = 0;
		for (int b = 0; b < n - 1; ++b) {
			for(int c = b+1; c < n; ++c)
				answer += gcd(d[b], d[c]);
		}
		printf("%ld\n", answer);
		free(d);
	}
	return 0;
}
