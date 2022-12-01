#include <iostream>
#include <vector>
using namespace std;

int n, l;
int board[100][100];

bool canGo(vector<int>& v)
{
	vector<bool> visited(n, false);
	for (int i = 1; i < n; ++i)
	{
		if (v[i - 1] != v[i]) {
			int diff = abs(v[i] - v[i - 1]);

			if (diff != 1)
				return false;

			if (v[i - 1] < v[i]) {
				for (int j = 1; j <= l; ++j) {

					if (i - j < 0)
						return false;

					if (v[i - 1] != v[i - j])
						return false;

					if (visited[i - j]) {
						return false;
					}

					visited[i - j] = true;
				}
			}
      
			else {
				for (int j = 0; j < l; ++j) {
					if (i + j >= n)
						return false;

					if (v[i] != v[i + j])
						return false;

					if (visited[i + j])
						return false;

					visited[i + j] = true;
				}
			}
		}

	}
	return true;
}
int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j]; 


	int ret = 0;
  
	for (int i = 0; i < n; ++i)
	{
		vector<int> row;
		for (int j = 0; j < n; ++j)
		{
			row.push_back(board[i][j]);
		}

		if (canGo(row)) {
			ret++;
		}
	}

	for (int j = 0; j < n; ++j)
	{
		vector<int> col;
		for (int i = 0; i < n; ++i) {
			col.push_back(board[i][j]);
		}
		if (canGo(col)) {
			ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}
