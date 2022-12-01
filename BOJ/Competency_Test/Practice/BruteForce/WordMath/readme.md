문제 사이트 : https://www.acmicpc.net/problem/1339

문제 설명 :

	민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

	단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 
	
	이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 
	
	같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

	예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 
	
	두 수의 합은 99437이 되어서 최대가 될 것이다.

	N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

입력

	첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 
	
	단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 
	
	서로 다른 문자는 서로 다른 숫자를 나타낸다.

출력

	첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.

예제 입력 1 

	2
	AAA
	AAA
	
예제 출력 1 

	1998

코드 및 설명 :

	#include <iostream>
	#include <algorithm>
	#include <vector>
	#include <string>
	using namespace std;

	long long ans;
	long long n, arr[27];
	vector<long long> v;
	string S;
	int main() {
		cin >> n; // 입력받을 숫자 갯수
		for (int a = 0; a < n; ++a) {
			cin >> S; // 입력받은 문자열조합
			int cnt = 1;
			for (int b = S.size() - 1; b >= 0; --b) {
				arr[S[b] - 'A'] += cnt; 
				cnt *= 10;
			}
		} // 특정 알파벳의 위치들을 찾아서 저장( ex> AABA라면 A의 위치는 0,2,3이므로 ((1 + 100) + 1000) = 1101로 저장하여 나중에 최대값을 구하는데 사용)
		for (int a = 0; a < 27; ++a)
			if (arr[a] != 0) v.push_back(arr[a]); // 특정알파벳이 사용중이라면 v배열에 저장
		sort(v.begin(), v.end());  // v배열에 저장된 값을 sort 함수를 이용하여 가장 큰값부터 사용)
		int value = 9;
		for (int a = v.size() - 1; a >= 0; a--) {
			ans += v[a] * value;
			value--;
		} // 값이 큰 순으로 9부터 0까지 입력하고 그 값을 ans값에 저장, 더하기 반복하여 값을 찾음
		cout << ans << endl;

		return 0;
	}
