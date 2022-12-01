#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int X, Y;            
long price[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("Input.txt", "r", stdin);
	cin >> price[0] >> price[1] >> price[2];
	cin >> X >> Y;

	//dfs(X, Y,0);
	long sum = 0;

	if (price[0] + price[1] > price[2] * 2) {
		if (X > Y) {

			X -= Y;
			sum = (price[2] + price[2]) * Y;

			if(price[0] > price[2] * 2)
				sum = sum +( price[2] + price[2])* X;

			else 
				sum = sum + price[0] * X;
		}
		else {

			Y -= X;
			sum = (price[2] + price[2] )* X;
			
			if (price[1] > price[2] * 2)
				sum = sum + (price[2] + price[2]) * Y;

			else
				sum = sum + price[1] * Y;
		}
	}
	else {
		sum = X * price[0] + Y * price[1];
	}
	cout << sum;

	return 0;
}

