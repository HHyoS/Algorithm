#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;
int n = 0;
int big = 0;
int size = 0;
map<pair<int, int>, int> up(map<pair<int, int>, int> map) {
	for (int a = 1; a <= n; ++a) { // 구슬이동
		for (int b = n; b > 1; --b) {
			if (map[{a, b}] != 0) {
				for (int c = b - 1; c > 0; --c) {
					if (map[{a, c}]!= 0) {
						if (map[{a, b}] == map[{a, c}]) {
							map[{a, b}] *= 2;
							map[{a, c}]= 0;
							b = c;
							break;
						}
						else {
							b = c + 1;
							break;
						}
					}
				}
			}
		}
	} 
	for (int a = 1; a <= n; ++a) { // 구슬병합
		for (int b = n; b > 1; --b) {
			if (map[{a, b}] == 0) {
				for (int c = b - 1; c > 0; --c) {
					if (map[{a, c}] != 0) {
						map[{a, b}] = map[{a, c}];
						map[{a, c}] = 0;
						break;
					}
				}
			}
		}
	}
	return map;
}
map<pair<int, int>, int> down(map<pair<int, int>, int> map) {
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b < n; ++b) {
			if (map[{a, b}] != 0) {
				for (int c = b + 1; c <= n; ++c) {
					if (map[{a, c}] != 0) {
						if (map[{a, b}] == map[{a, c}]) {
							map[{a, b}] *= 2;
							map[{a, c}] = 0;
							b = c;
							break;
						}
						else {
							b = c - 1;
							break;
						}
					}
				}
			}
		}
	}
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b < n; ++b) {
			if (map[{a, b}] == 0) {
				for (int c = b + 1; c <= n; ++c) {
					if (map[{a, c}] != 0) {
						map[{a, b}] = map[{a, c}];
						map[{a, c}] = 0;
						break;
					}
				}
			}
		}
	}
	return map;
}
map<pair<int, int>, int> left(map<pair<int, int>, int> map) {
	for (int b = 1; b <= n; ++b) {
		for (int a = 1; a < n; ++a) {
			if (map[{a, b}] != 0) {
				for (int c = a + 1; c <= n; ++c) {
					if (map[{c, b}] != 0) {
						if (map[{a, b}] == map[{c, b}]) {
							map[{a, b}] += map[{c, b}];
							map[{c, b}] = 0;
							a = c;
							break;
						}
						else {
							a = c - 1;
							break;
						}
					}
				}
			}
		}
	}
	for (int b = 1; b <= n; ++b) {
		for (int a = 1; a < n; ++a) {
			if (map[{a, b}] == 0) {
				for (int c = a + 1; c <= n; ++c) {
					if (map[{c, b}] != 0) {
						map[{a, b}] = map[{c, b}];
						map[{c, b}] = 0;
						break;
					}
				}
			}
		}
	}
	return map;
}
map<pair<int, int>, int> right(map<pair<int, int>, int> map) {
	for (int b = 1; b <= n; ++b) {
		for (int a = n; a  > 1; --a) {
			if (map[{a, b}] != 0) {
				for (int c = a -1; c > 0; --c) {
					if (map[{c, b}] != 0) {
						if (map[{a, b}] == map[{c, b}]) {
							map[{a, b}] *= 2;
							map[{c, b}] = 0;
							a = c;
							break;
						}
						else {
							a = c +1;
							break;
						}
					}
				}
			}
		}
	}
	for (int b = 1; b <= n; ++b) {
		for (int a = n; a > 1; --a) {
			if (map[{a, b}] == 0) {
				for (int c = a - 1; c > 0; --c) {
					if (map[{c, b}] != 0) {
						map[{a, b}] = map[{c, b}];
						map[{c, b}] = 0;
						break;
					}
				}
			}
		}
	}
	return map;
}
void dfs(map<pair<int, int>, int> map, int count) {
	if (count == 5) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b) {
				if (map[{a,b}] > big)
					big = map[{a, b}];
			}
		}
		return;
	}

	count++;
	dfs(up(map), count);
	dfs(down(map), count);
	dfs(left(map), count);
	dfs(right(map), count);
}
int main() {
	freopen("Input.txt", "r", stdin);
	cin >> n;
	map<pair<int, int>, int> mp;
	int value = 0;
	for (int b = n; b > 0 ; --b) {
		for (int a = 1; a <= n; ++a) {
			cin >> value;
			mp[{a, b}] = value;
		}
	}

	dfs(mp, 0);
	printf("%d", big);
	return 0;
}
