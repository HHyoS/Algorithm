#include <iostream>


int main(void) {
	int n;
	int arr[1001] = { 0, };
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 3;
	for (int a = 3; a <= n; ++a)
		arr[a] = (arr[a - 1] + arr[a - 2]*2)%10007;
	printf("%d", arr[n]);
	return 0;
}


