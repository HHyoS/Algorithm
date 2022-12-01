문제 사이트 : https://www.acmicpc.net/problem/11047

풀이 환경 : Visual Studio 2019

설명 :

		준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

		동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다.
		
		이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력

		첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

		둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. 
		
		(1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력

		첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

예제 입력 1 

		10 4200
		1
		5
		10
		50
		100
		500
		1000
		5000
		10000
		50000

예제 출력 1 

		6

예제 입력 2 

		10 4790
		1
		5
		10
		50
		100
		500
		1000
		5000
		10000
		50000

예제 출력 2 

		12
		
풀이 알고리즘 

		가치가 다른 동전 N개가 주어질 떄, 동전을 이용하여 목표값 K를 만족시키는 동전의 최소갯수를 구하는 문제였습니다.
		
	  제가 생각한 풀이방법은 다음과 같습니다.
		
		1. 가장 가치가 큰 동전부터 작은동전 순으로 사용하여 사용 동전 갯수를 최소화하고, 사용된 동전의 가치만큼 K값 빼기
		
		2. 동전의 가치가 남은 K보다 클경우 넘어가기
		
		3.  (1~2)과정을 하며 사용된 동전 수만큼 count하기
		
구 현 

		#include <iostream>
		#include <string>
		#include <queue>
		#include <stack>
		#include <algorithm>
		using namespace std;

		int N;
		int K;
		int coin[10];
		int main() {

			ios::sync_with_stdio(0);
			cin.tie(0);
			cout.tie(0);
			freopen("Input.txt", "r", stdin);

			cin >> N >> K;
			for (int a = 0; a < N; ++a) {
				cin >> coin[a]; // 동전 입력
			}
			int answer = 0;
			for (int a = N-1; a >= 0; --a) { // 가치가 가장 큰 동전부터 탐색 시작
				if (K < coin[a]) // 동전의 가치가 현재 K보다 클경우 생략
					continue;
				else { // 작다면
					answer += K/coin[a]; // 동전이 사용된 횟수만큼 answer에 더해주고
					K %= coin[a]; // 사용된 동전의 가치만큼 K뺴주기
				}
			}
			cout << answer; // 정답출력
			return 0;
		}
