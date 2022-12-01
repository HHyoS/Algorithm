#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int **nm;
vector<pair<pair<int, int>, int>> v;
bool vb[6];
int ans = 987654321;
int **spin(int a, int b, int c, int **p)
{
    int **temp;
    temp = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        temp[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            temp[i][j] = p[i][j];
        }
    }
    for (int i = 1; i <= c; i++)
    {
        int tp = temp[a - i][b - i];
        for (int x = a - i; x < a + i; x++)
        {
            temp[x][b - i] = temp[x + 1][b - i];
        }
        for (int x = b - i; x < b + i; x++)
        {
            temp[a + i][x] = temp[a + i][x + 1];
        }
        for (int x = a + i; x > a - i; x--)
        {
            temp[x][b + i] = temp[x - 1][b + i];
        }
        for (int x = b + i; x > b - i; x--)
        {
            temp[a - i][x] = temp[a - i][x - 1];
        }
        temp[a - i][b - i + 1] = tp;
    }
    return temp;
}
void f(int c, int **p)
{
    if (c >= k)
    {
        for (int i = 1; i <= n; i++)
        {
            int sum = 0;
            for (int j = 1; j <= m; j++)
            {
                sum += p[i][j];
            }
            if (ans > sum)
                ans = sum;
        }
        return;
    }
    int **temp;
    temp = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        temp[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            temp[i][j] = p[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (!vb[i])
        {
            vb[i] = true;
            f(c + 1, spin(v[i].first.first, v[i].first.second, v[i].second, temp));
            vb[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    nm = new int *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        nm[i] = new int[m + 1];
        for (int j = 1; j <= m; j++)
        {
            cin >> nm[i][j];
        }
    }
    fill(vb, vb + 6, false);
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    f(0, nm);
    cout << ans;
}
