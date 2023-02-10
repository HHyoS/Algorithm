#include<iostream>
#include<string>
#include<queue>
 
#define MAX 100000
using namespace std;
 
int N, K;
int MAP[2][MAX];
bool Visit[2][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N >> K;
    for (int i = 0; i < 2; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            MAP[i][j] = Inp[j] - '0';
        }
    }
}
 
void BFS()
{
    bool Flag = false;
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(0, 0), 0));    // x, y, time
    Visit[0][0] = true;
 
    while (Q.empty() == 0 && Flag == false)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Time = Q.front().second;
        Q.pop();
 
        if (Time >= N) break;
 
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (ny >= N) Flag = true;
 
            if (nx >= 0 && ny > Time && nx < 2 && ny < N)
            {
                if (MAP[nx][ny] == 1 && Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Time + 1));
                }
            }
        }
 
        for (int i = 2; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i] + K;
            
            if (ny >= N) Flag = true;
 
            if (nx >= 0 && ny > Time && nx < 2 && ny < N)
            {
                if (MAP[nx][ny] == 1 && Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Time + 1));
                }
            }
        }
    }
 
    if (Flag == true) cout << 1 << endl;
    else cout << 0 << endl;
}
 
void Solution()
{
    BFS();
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
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
