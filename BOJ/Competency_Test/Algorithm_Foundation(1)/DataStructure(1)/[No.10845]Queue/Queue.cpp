#include <iostream>
#include <algorithm>
#include <string>
#define MAX_QUEUE_SIZE 10000
using namespace std;

struct h_que
{
	int front = 0;
	int back = -1;
	int queue[MAX_QUEUE_SIZE];
	int size = 0;
};


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	h_que que;

	int n;

//	freopen("Input.txt", "r", stdin);

	cin >> n;
	string command = "";

	for (int a = 0; a < n; ++a) {
		cin >> command;
		if (command == "push") {
			cin >> que.queue[++(que.back)];
			++(que.size);
		}
		else {
			if (command == "size") {
				cout << que.size;
			}
			else if (command == "empty") {
				if (que.size == 0)
					cout << "1";
				else
					cout << "0";
			}
			else {
				if (que.size == 0)
					cout << -1;
				else {
					if (command == "back") {
						
						cout << que.queue[que.back];
					}
					else {
						cout << que.queue[que.front];

						if (command == "pop") {
							que.front += 1;
							--(que.size);
						}

					}
				}
			}
			cout << endl;
		}

	}

	return 0;
}
