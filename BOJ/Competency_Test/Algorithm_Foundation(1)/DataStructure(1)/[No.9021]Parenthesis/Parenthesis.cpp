#include <stdio.h>
#include <cstring>

using namespace std;


int main() {

	int n;
	char vps[51];
	//freopen("Input.txt", "r", stdin);
	int ct = 0;
	scanf("%d", &n);
	for (int a = 0; a < n; ++a) {
		ct = 0;
		scanf("%s ", &vps);
		for (int b = 0; vps[b]; ++b) {
			if (vps[b] == '(')
				++ct;
			else {
				--ct;
				if (ct < 0)
					break;
			}
		}
		if (ct == 0)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
