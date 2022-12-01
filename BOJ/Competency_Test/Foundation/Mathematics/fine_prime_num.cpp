#include <iostream>
#include <stdlib.h>
using namespace std;

bool prime(int a) {
	int n = 2;
	if (a < 2)
		return false;
	for (int b = 2; b <= a; ++b)
		if (a % b == 0) {
			if (a == b)
				return true;
			else
				return false;
		}
}
int main() {
	int count;
	int answer = 0;
	cin >> count;
	int* ar = (int*)malloc(sizeof(int) * count);
	for (int a = 0; a < count; ++a) {
		cin >> ar[a];
		if (prime(ar[a]))
			++answer;
	}
	printf("%d", answer);
	return 0;
}
