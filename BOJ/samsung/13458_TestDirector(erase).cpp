#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> r; 
	long long answer = 0;
	for (int a = 0; a < n; ++a) {
		int v;
		cin >> v;
		r.push_back(v);
	}
	int ms, ss;
	cin >> ms >> ss;

	int b = 0;
	for (int a = 0; a < n; ++a) {
		if (r[b] - ms > 0) {
			r[b] -= ms;
			++b;
		}
		else
			r.erase(r.begin() + b);
		answer++;
	}
	sort(r.begin(), r.end());
	long long max = 1;
	int size = r.size();
	int a = 0;
	while(a != size){
		int x = r[a];
		if(x > 0){
			while (x - (max*ss) > 0)
				++max;
			answer += max;
		}
		++a;
	}
	printf("%ld", answer);

	return 0;
