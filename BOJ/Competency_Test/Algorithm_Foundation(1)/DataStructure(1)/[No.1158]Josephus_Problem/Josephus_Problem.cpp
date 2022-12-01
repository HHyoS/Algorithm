#include <cstdio>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Node {
	int value = 0;
	struct Node *tail = NULL;
};

Node nd[5001];
int main() {

	int n, k;
//	freopen("Input.txt", "r", stdin);
	scanf("%d %d", &n,&k);
	for (int a = 1; a <= n; ++a) {
		nd[a].value = a ;
		nd[a].tail = &nd[a + 1];
	}

	nd[n].tail = &nd[1];

	
	Node* ptr = &nd[n];
	printf("<");
	for (int a = 1; a < n; ++a) {
		for (int b = 0; b < k-1; ++b) {
			ptr = ptr->tail;
		}
		printf("%d, ", ptr->tail->value);
		ptr->tail = ptr->tail->tail;
	}
	printf("%d>", ptr->value);
	return 0;
}
