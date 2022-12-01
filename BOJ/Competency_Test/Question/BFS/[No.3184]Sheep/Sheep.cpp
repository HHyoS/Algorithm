#include<iostream>
#include<queue>
 
#define endl "\n"
#define MAX 250
using namespace std;
 
int R, C, Total_Wolf, Total_Sheep;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void BFS(int a, int b)
{
    int Wolf, Sheep;
    Wolf = Sheep = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        if (MAP[x][y] == 'v') Wolf++;
        if (MAP[x][y] == 'o') Sheep++;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < R && ny < C)
            {
                if (MAP[nx][ny] != '#' && Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
 
    if (Sheep > Wolf) Total_Sheep = Total_Sheep + Sheep;
    else Total_Wolf = Total_Wolf + Wolf;
}
 
void Solution()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (Visit[i][j] == false)
            {
                BFS(i, j);
            }
        }
    }
 
    cout << Total_Sheep << " " << Total_Wolf << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}

