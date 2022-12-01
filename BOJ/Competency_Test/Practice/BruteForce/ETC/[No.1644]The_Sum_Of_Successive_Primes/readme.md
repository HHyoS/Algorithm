문제 사이트 : https://www.acmicpc.net/problem/1644

문제 설명 : 

    하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 
    
    몇 가지 자연수의 예를 들어 보면 다음과 같다.

    3 : 3 (한 가지)
    
    41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
    
    53 : 5+7+11+13+17 = 53 (두 가지)
    
    하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다.
    
    7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다.
    
    또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.

    자연수가 주어졌을 때, 
    
    이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력

    첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.

예제 입력 1 

    20

예제 출력 1 

    0

예제 입력 2 

    3

예제 출력 2 

    1

예제 입력 3 

    41

예제 출력 3 

    3 

예제 입력 4 


    53

예제 출력 4 

    2
    
풀이 알고리즘

    주어진 숫자 하나에 대해서 연속된 소수들의 합으로 나타낼 수 있는 방법의 갯수를 출력하는 문제였습니다.
    
    만약 주어진 숫자가 하나가 아닌 여러개일 경우 [ 에라토스테네스의 체 ] 를 사용하여
    
    미리 4,000,000 이하의 수들에 대해 소수인지 미리 판별하고 저장해 놓았겠지만, 주어진 숫자가
    
    단 하나이므로 미리 구해놓을 필요는 없었습니다.
    
    풀이 알고리즘은 다음과 같습니다.
    
    1. 소수의 합으로 나타내야하는 숫자 N이 입력되고.
    
    2. N 이하의 소수들을 찾아 배열에 저장해둡니다.
    
    3. 소수들이 모두 구해졌다면
    
      1)가장 작은 소수부터 시작하여 연속된 소수들의 합이 N이하일때 계속 더하기
      
      2) N보다 커지면 더하는 행위를 중단
      
      3) N과 같을경우 경우의 수 하나 추가
      
[ 구 현 ]

	#include <iostream>
	#include <cstring>
	#include <algorithm>
	#include <queue>
	#include <utility>

	using namespace std;
	int N;
	long long M;
	bool prime[4000001];
	int answer = 0;
	int prime_num[283146]; // 400만 이하의 소수 갯수는 283146개.(미리 계산해본 결과)

	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);


		//freopen("Input.txt", "r", stdin);

		cin >> N;
		int idx = 0;
		for (int a = 2; a <= sqrt(N); ++a) {
			if (prime[a])
				continue;
			for (int b = 2; a * b <= N; ++b) {
				prime[a * b] = 1;
			}
		}
		for (int a = 2; a <= N; ++a) {
			if (!prime[a]) {
				prime_num[idx++] = a;
			}
		}

		for (int a = 0; a < idx; ++a) {
			int sum = 0;
			if (prime_num[a] > N)
				break;
			else {
				for (int b = a; b < idx; ++b) {
					sum += prime_num[b];
					if (sum > N)
						break;
					else if (sum == N) {
						++answer;
						break;
					}
				}
			}

		}
		cout << answer;
		return 0;
	}


