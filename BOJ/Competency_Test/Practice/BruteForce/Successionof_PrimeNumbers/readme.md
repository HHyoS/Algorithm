문제 사이트 : https://www.acmicpc.net/problem/1644

문제 설명 : 

	하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

	3 : 3 (한 가지)
	41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
	53 : 5+7+11+13+17 = 53 (두 가지)
	하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 
	
	7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 
	
	또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

	자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력

	첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력

	첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

예제 입력 1 

	20
	
예제 출력 1 

	0

코드 및 설명 

	#include <iostream>
	#include <cstring>
	using namespace std;
	bool isPrime[4000001];
	int N;

	void eratos() {
		memset(isPrime, true, sizeof(isPrime));
		isPrime[1] = false;
		for (int i = 2; i*i <= 4000000; i++) {
			if (!isPrime[i]) continue;
			for (int j = i + i; j <= 4000000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int main()
	{

		eratos();

		cin >> N;

		int lo = 2;
		int hi = 2;
		int sum = 2;
		int res = 0;

		while (lo <= hi && hi <= N) {
			if (sum < N) {
				hi++;
				while (!isPrime[hi])
					hi++;
				sum += hi;
			}
			else if (sum == N) {
				res++;
				sum -= lo;
				lo++;
				while (!isPrime[lo])
					lo++;
			}
			else if(sum > N) {
				sum -= lo;
				lo++;
				while (!isPrime[lo])
					lo++;
			}
		}

		cout << res;
	}


	우에라토스테네스의 체로 소수를 판별하고, 다음부턴 투 포인터를 이용해서 가능한 소수의 연속합의 수를 구하였습니다.

	합이 N보다 작으면 hi를 다음 소수까지 증가시킨 후 sum에 더하고, 합이 N보다 크거나 같으면 lo를 sum에서 뺀 후, lo를 다음 소수까지 증가시켜

	while이 끝날때까지 수행하면 가능한 모든 개수를 구할 수 있습니다.
