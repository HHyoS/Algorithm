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
	int x, y;
	for (int a = 0; a < count; ++a) {
		cin >> x >> y;
		printf("%d\n",x*y/gcd(x, y));
	}
	return 0;
}
