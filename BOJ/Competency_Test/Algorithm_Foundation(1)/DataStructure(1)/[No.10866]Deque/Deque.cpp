#include <cstdio>
#include <cstring>
#define MAX_QUEUE_SIZE 10000
using namespace std;

class Hd {
private:
	int start;
	int front, back;
	int que[20010] = { 0, };
public:

	Hd() {
		start = 10005;
		front = 0;
		back = 1;
	}
	void push_front(int x) {
		if (start == 10005) {
			que[start] = x;
			start = -1;
			front = 10004;
			back = 10006;
		}
		else
			que[front--] = x;


	}

	void push_back(int x) {
		if (start == 10005) {
			que[start] = x;
			start = -1;
			front = 10004;
			back = 10006;
		}
		else
			que[back++] = x;
	}

	int pop_front() {
		if (front >= back-1) return -1;
		else return que[++front];
	}

	int pop_back() {
		if (front >= back-1) return -1;
		else return que[--back];
	}

	int size() {
		return back - front - 1;
	}

	int empty() {
		if (front >= back-1) return 1;
		else return 0;
	}

	int ft() {
		if (front >= back-1) return -1;
		else return que[front+1];
	}

	int bk() {
		if (front >= back-1) return -1;
		else return que[back-1];
	}
};

int main() {


//	freopen("Input.txt", "r", stdin);

	int n;
	Hd q;
	char command[25];
	scanf("%d", &n);
	int X;
	for (int a = 0; a < n; ++a) {
		scanf("%s", &command);
		if (command[0] == 'p') {
			if (command[1] == 'u') {
				scanf("%d", &X);
				if (command[5] == 'f') {
					q.push_front(X);
				}
				else {
					q.push_back(X);
				}
			}
			else {
				if (command[4] == 'f')	printf("%d\n", q.pop_front());
				else printf("%d\n", q.pop_back());
			}
		}
		else if (command[0] == 's') printf("%d\n", q.size());

		else if (command[0] == 'e') printf("%d\n", q.empty());

		else if (command[0] == 'f') printf("%d\n", q.ft());

		else if (command[0] == 'b') printf("%d\n", q.bk());
	}

	return 0;
}
