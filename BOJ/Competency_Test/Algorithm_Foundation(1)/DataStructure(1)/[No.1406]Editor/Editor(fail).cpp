#include <stdio.h>
#include <cstring>

using namespace std;

int giho_index = 0;
char input_char[200000];
struct edt {
	char wd;
	struct edt *head;
	struct edt *tail;
};

edt giho[700000];
int main() {

	int n;

	int size = 0;
	edt head;
	edt tail;
	freopen("Input.txt", "r", stdin);
	scanf("%s", &input_char);
	for (int a = 0; input_char[a]; ++a) {
		++size;
		giho[a + 1].head = &giho[a];
		giho[a + 1].tail = &giho[a + 2];
		giho[a + 1].wd = input_char[a];
	}
	int lof = size;
	
	giho[1].head = &head;
	giho[size].tail = &tail;
	
	head.tail = &giho[1];
	tail.head = &giho[size];

	edt* cur = &giho[size];

	scanf("%d", &n);

	char command;
	edt* start;
	for (int a = 0; a < n; ++a) {
		scanf(" %c", &command);
		if (command == 'L') {
			if (cur != &head)
				cur = cur->head;
		}
		else if (command == 'D') {
			if (cur->tail != &tail)
				cur = cur->tail;
		}
		else if (command == 'B') {
			if (cur != &head) {
				if (cur->head == &head) {
					head.tail = cur->tail;
					cur->tail->head = &head;
					cur = &head;
				}
				else if (cur->tail == &tail) {
					tail.head = cur->head;
					cur->head->tail = &tail;
					cur = tail.head;
				}
				else {
					cur->head->tail = cur->tail;
					cur->tail->head = cur->head;
					cur = cur->head;
				}
				--lof;
			}
		}
		else {
			++lof;
			scanf(" %c", &command);
			giho[++size].wd = command;
			if (cur == &head) {
				giho[size].head = &head;
				giho[size].tail = head.tail;

				head.tail->head = &giho[size];
				head.tail = &giho[size];

				cur = &giho[size];

			}
			else if (cur->tail == &tail) {
				giho[size].tail = &tail;
				giho[size].head = cur;

				tail.head = &giho[size];

				cur->tail = &giho[size];

				cur = &giho[size];
			}
			else {
				giho[size].tail = cur->tail;
				giho[size].head = cur;

				cur->tail->head = &giho[size];
				cur->tail = &giho[size];

			}
		}
	}
	start = head.tail;
	for (int b = 0; b < lof; ++b) {
		printf("%c", start->wd);
		start = start->tail;
	}
	return 0;
}
