#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

char input_char[100001] = { 0, };
char l_st[600003];
char r_st[600003];


int main() {

	int n;
	freopen("Input.txt", "r", stdin);
	scanf("%s", &l_st);
	int l_index = -1, r_index = -1;

	for (int a = 0; input_char[a]; ++a) {
		l_st[++l_index] = input_char[a];
	}
	scanf("%d", &n);
	char command;
	for (int a = 0; a < n; ++a) {
		scanf(" %c", &command);
		if ((command == 'L') && (l_index >= 0))
			r_st[++r_index] = l_st[l_index--];
		else if ((command == 'D') && (r_index >= 0 )) 
			l_st[++l_index] = r_st[r_index--];
		else if ((command == 'B') && (l_index >= 0))
				l_index--;
		else { 
			scanf(" %c", &command);
			l_st[++l_index] = command;
		}

	}

	l_st[l_index + 1] = 0;
	r_st[r_index + 1] = 0;
	reverse(r_st, r_st + r_index + 1);
	fprintf(stdout, "%s%s", l_st, r_st);
	return 0;
}
