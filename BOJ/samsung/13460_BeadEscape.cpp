#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;
pair<int, int> r;
pair<int, int> b;
pair<int, int> g;
int answer = -1;
pair<pair<int,int>,pair<int,int>> left(map<pair<int, int>, char> fd, pair<pair<int,int>, pair<int,int>> rb){
	int r_x = rb.first.first, r_y = rb.first.second;
	int b_x = rb.second.first, b_y = rb.second.second;
	if (r_x < b_x) {
		while (!(fd[{r_x-1, r_y}] == '#') && !(g.first == r_x && g.second == r_y)) {
			--r_x;
		}
		while (!(fd[{b_x-1, b_y}] == '#') && !(b_x -1 == r_x && b_y==r_y) && !(g.first == b_x && g.second == b_y)) {
			--b_x;
			if (g.first == b_x-1 && g.second == b_y)
				return { {r_x,r_y},{r_x,r_y} };
		}
	}
	else {
		while (!(fd[{b_x-1, b_y}] == '#') &&  !(g.first == b_x && g.second == b_y)) {
			--b_x;
			if(g.first == b_x && g.second == b_y)
				return { {b_x,b_y},{b_x,b_y} };
		}
		while (!(fd[{r_x-1, r_y}] == '#') && !(r_x -1 == b_x && r_y == b_y) && !(g.first == r_x && g.second == r_y)) {
			--r_x;
			if ((r_x - 1 == b_x && b_y == r_y) && (g.first == r_x-1 && g.second == r_y))
				return { {b_x,b_y},{b_x,b_y} };
		}

	}
		return { {r_x,r_y},{b_x,b_y} };
}
pair<pair<int, int>, pair<int, int>> right(map<pair<int, int>, char> fd, pair<pair<int, int>, pair<int, int>> rb) {
	int r_x = rb.first.first, r_y = rb.first.second;
	int b_x = rb.second.first, b_y = rb.second.second;
	if (r_x < b_x) {
		while (!(fd[{b_x+1, b_y}] == '#') && !(g.first == b_x && g.second == b_y)) {
			++b_x;
			if (g.first == b_x && g.second == b_y)
				return { {b_x,b_y},{b_x,b_y} };
		}
		while (!(fd[{r_x+1, r_y}] == '#') && !(r_x+1== b_x && r_y==b_y) && !(g.first == r_x && g.second == r_y)) {
			++r_x;
		}
	}
	else {
		while (!(fd[{r_x+1, r_y}] == '#') && !(g.first == r_x && g.second == r_y)) {
			++r_x;
		}
		while (!(fd[{b_x+1, b_y}] == '#') && !(b_x + 1 == r_x && b_y == r_y) && !(g.first == b_x && g.second == b_y)) {
			++b_x;
			if (g.first == b_x+1 && g.second == b_y)
				return { {b_x,b_y},{b_x,b_y} };
		}
	}
	return { {r_x,r_y},{b_x,b_y} };
}
pair<pair<int, int>, pair<int, int>> up(map<pair<int, int>, char> fd, pair<pair<int, int>, pair<int, int>> rb) {
	int r_x = rb.first.first, r_y = rb.first.second;
	int b_x = rb.second.first, b_y = rb.second.second;
	if (r_y < b_y) {
		while (!(fd[{b_x, b_y+1}] == '#') && !(g.first == b_x && g.second == b_y)) {
			++b_y;
			if (g.first == b_x && g.second == b_y)
				return { {b_x,b_y},{b_x,b_y} };
		}
		while (!(fd[{r_x, r_y+1}] == '#') && !(r_y + 1 == b_y && r_x == b_x) && !(g.first == r_x && g.second == r_y)) {
			++r_y;
		}
	}
	else {
		while (!(fd[{r_x, r_y+1}] == '#') && !(g.first == r_x && g.second == r_y)) {
			++r_y;
		}
		while (!(fd[{b_x, b_y+1}] == '#') && !(b_y + 1 == r_y && b_x == r_x) && !(g.first == b_x && g.second == b_y)) {
			++b_y;
			if (g.first == b_x && g.second == b_y+1)
				return { {b_x,b_y},{b_x,b_y} };
		}
	}
	return { {r_x,r_y},{b_x,b_y} };
}
pair<pair<int, int>, pair<int, int>> down(map<pair<int, int>, char> fd, pair<pair<int, int>, pair<int, int>> rb) {
	int r_x = rb.first.first, r_y = rb.first.second;
	int b_x = rb.second.first, b_y = rb.second.second;
	if (r_y > b_y) {
		while (!(fd[{b_x, b_y-1}] == '#')) {
			--b_y;
			if (g.first == b_x && g.second == b_y)
				return { {b_x,b_y},{b_x,b_y} };
		}
		while (!(fd[{r_x, r_y-1}] == '#') && !(r_y-1  == b_y && r_x == b_x) && !(g.first == r_x && g.second == r_y)) {
			--r_y;
		}
	}
	else {
		while (!(fd[{r_x, r_y-1}] == '#') && !(g.first == r_x && g.second == r_y)) {
			--r_y;
		}
		while (!(fd[{b_x, b_y-1}] == '#') && !(b_y - 1 == r_y && b_x == r_x)) {
			--b_y;
			if (g.first == b_x && g.second == b_y-1)
				return { {b_x,b_y},{b_x,b_y} };
		}
	}
	return { {r_x,r_y},{b_x,b_y} };
}
void bfs(int count, map<pair<int, int>, char> fd, queue<pair<pair<int, int>, pair<int, int>>> que){
	if (count > 10 || (answer != -1 && answer <= count))
		return;

	pair<pair<int, int>, pair<int, int>> temp;
	int r_x, r_y;
	int b_x, b_y;
	int size = que.size();
	for (int a = 0; a < size; ++a) {
		if (que.front().first == g) {
			if (answer > count || answer == -1)
				answer = count;
			return;
		}
		temp = left(fd, que.front());
		if (temp != que.front() && temp.first != temp.second) {
			que.push(temp);
		}
		temp = right(fd, que.front());
		if (!(temp == que.front()) && temp.first != temp.second){
			que.push(temp);
		}
		temp = up(fd, que.front());
		if (temp != que.front()&& temp.first != temp.second){
			que.push(temp);
		}
		temp = down(fd, que.front());
		if (temp != que.front() && temp.first != temp.second){
			que.push(temp);
		}
		que.pop();
	}
	++count;
	if(!que.empty())
		bfs(count, fd, que);
}
int main() {
	int limit = 11;
	int x, y;
	map<pair<int, int>, char> fd;
	//freopen("Input.txt", "r", stdin);
	cin >> y >> x;
	char value;
	queue<pair<pair<int, int>, pair<int, int>>> que;
	for (int a = y; a > 0; --a) {
		for (int c = 1; c <= x; ++c) {
			cin >> value;
			if (value == 'R')
				r = { c,a };
			else if (value == 'B')
				b = { c,a };
			else if (value == 'O') {
				g = { c,a };
			}
			else
				fd[{c,a}] = value;
		}
	}
	que.push({ r,b });
	bfs(0, fd, que);
	printf("%d", answer);
	return 0;
}
