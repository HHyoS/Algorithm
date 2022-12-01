#include <iostream>
#include <cstring>
using namespace std;

int n = 0, val = 0;
int arr[100] = { 0 };
long long before[21] = { 0 };
long long current[21] = { 0 };

int main() {
	cin >> n;
	for (int a = 0; a < n-a; ++a) {
		cin >> arr[a];
	}
	cin >> val;

	before[arr[0]] = 1; 
	for (int a = 1; a < n - 1; ++a) {
		memset(current, 0, sizeof(current));
		for (int b = 0; b <= 20; b++) {
			if (before[b] != 0){
				if ((b + arr[a]) <= 20)
					current[(b + arr[a])] += before[b];
				if((b - arr[a]) >= 0)
					current[(b - arr[a])] += before[b];
			}
		}
		for (int b = 0; b <= 20; ++b)
			before[b] = current[b];

	}

	cout << current[val] << '\n';
}
