#include<iostream>
#include <vector>

using namespace std;

char map[11][11];
int num;
vector<int> v;

bool possible(int idx)
{
    int sum = 0;

    for (int i = idx; i >= 0; i--)
    {
        sum += v[i];

        if (map[i][idx] == '+' && sum <= 0)	return false;
        if (map[i][idx] == '-' && sum >= 0)	return false;
        if (map[i][idx] == '0' && sum != 0)	return false;
    }
    return true;
}

void solve(int idx)
{
    if (idx == num)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        exit(0);
    }

    for (int i = -10; i <= 10; i++)
    {
        v.push_back(i);

        if (possible(idx))
            solve(idx + 1);

        v.pop_back();
    }
}

int main(void)
{
    cin >> num;
    string s;
    cin >> s;

    int idx = 0;

    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            map[i][j] = s[idx++];
        }
    }

    solve(0);

}
