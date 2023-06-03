#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef struct
{
	long long s;
	string process;
} Node;

map<long long, bool> visited;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long s, t;
	cin >> s >> t;

	if (s == t)
	{
		cout << 0 << "\n";

		return 0;
	}

	queue<Node> q;
	q.push({ s, "" });

	bool flag = true;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			Node node = q.front();
			q.pop();

			if (node.s == t)
			{
				cout << node.process << "\n";

				return 0;
			}

			long long temp = node.s * node.s;
			
			if (temp <= t && visited.count(temp) == false)
			{
				q.push({ temp, node.process + '*' });

				visited[temp] = true;
			}

			temp = node.s * 2;

			if (temp <= t && visited.count(temp) == false)
			{
				q.push({ temp, node.process + '+' });
			}

			if (flag)
			{
				q.push({ 1, node.process + '/' });
				
				flag = false;
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}
