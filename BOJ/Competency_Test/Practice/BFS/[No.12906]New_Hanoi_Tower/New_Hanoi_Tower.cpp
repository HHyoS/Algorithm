#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int n;
set<pair<pair<string,string>,string>> mp;

bool check(string st1, string st2, string st3) {
	for (int a = 0; a < st1.length(); ++a) {
		if (st1[a] != 'A')
			return 0;
	}
	for (int a = 0; a < st2.length(); ++a) {
		if (st2[a] != 'B')
			return 0;

	}
	for (int a = 0; a < st3.length(); ++a) {
		if (st3[a] != 'C')
			return 0;
	}

	return 1;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("Input.txt", "r", stdin);
	int n_1,n_2,n_3;
	string ha, no, ee;
	queue <pair<pair<string,string>, string>> que;
	
	cin >> n_1;
	if (n_1 > 0)
		cin >> ha;
	cin >> n_2;
	if (n_2 > 0)
		cin >> no;
	cin >> n_3;
	if (n_3 > 0)
		cin >> ee;
	que.push({{ha,no},ee});
	mp.insert({{ha,no},ee });
	int answer = 0;
	if (check(ha, no, ee))
		cout << "0";
	while (!que.empty()) {
		int size = que.size();
		for (int a = 0; a < size; ++a) {
			string st1 = que.front().first.first;
			string st2 = que.front().first.second;
			string st3 = que.front().second;
			que.pop();

			int size_1 = st1.length();
			int size_2 = st2.length();
			int size_3 = st3.length();

			char wd;
			if (size_1 > 0) {
				wd = st1.at(size_1 - 1);
				string temp = st1.substr(0,size_1 - 1);
				if (mp.find({ {temp,st2+wd},st3 }) == mp.end()) {
					if (check(temp, st2 + wd, st3)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {temp,st2 + wd},st3 });
						mp.insert({{temp,st2 + wd},st3 });
					}
				}
				if (mp.find({ {temp,st2 },st3 + wd }) == mp.end()) {
					if (check(temp, st2 , st3+wd)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {temp,st2},st3 + wd });
						mp.insert({{temp,st2},st3+wd });
					}
				}
			}

			if (size_2 > 0) {
				wd = st2.at(size_2 - 1);
				string temp = st2.substr(0,size_2 - 1);
				if (mp.find({ {st1+wd,temp},st3 }) == mp.end()) {
					if (check(st1+wd, temp, st3)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {st1+wd,temp},st3 });
						mp.insert({{st1+wd,temp},st3 });
					}
				}
				if (mp.find({ {st1,temp },st3 + wd }) == mp.end()) {
					if (check(st1, temp, st3 + wd)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {st1,temp},st3 + wd });
						mp.insert({{st1,temp},st3 + wd });
					}
				}
			}

			if (size_3 > 0) {
				wd = st3.at(size_3 - 1);
				string temp = st3.substr(0,size_3 - 1);
				if (mp.find({ {st1 + wd,st2},temp }) == mp.end()) {
					if (check(st1 + wd, st2, temp)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {st1 + wd,st2},temp });
						mp.insert({{st1 + wd,st2},temp });
					}
				}
				if (mp.find({ {st1, st2+wd },temp}) == mp.end()) {
					if (check(st1,st2+wd,temp)) {
						cout << answer + 1;
						return 0;
					}
					else {
						que.push({ {st1,st2+wd},temp });
						mp.insert({{st1,st2+wd},temp });
					}
				}
			}
		}
		++answer;
	}
	return 0;
}

