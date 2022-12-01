#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int N, Answer;
int Weight[8];
int Duration[8];


void dfs(int Idx)
{
    if (Idx >= N)
    {
        int Cnt = 0;
        for (int a = 0; a < N; ++a)
        {
            if (Duration[a] <= 0) Cnt++;
        }
        if (Answer < Cnt) {
            Answer = Cnt;
            return;
        }
    }

    if (Duration[Idx] <= 0) DFS(Idx + 1);
    else
    {
        bool Flag = 0;       
        for (int a = 0; a < N; ++a)
        {
            if (a == Idx || Duration[a] <= 0) 
                continue;

            Duration[Idx] = Duration[Idx] - Weight[a];
            Duration[a] = Duration[a] - Weight[Idx];
            Flag = 1;
            dfs(Idx + 1);
            Duration[a] = Duration[a] + Weight[Idx];
            Duration[Idx] = Duration[Idx] + Weight[a];
        }
        if (!Flag)
            dfs(N);
    }
}




int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("Input.txt", "r", stdin);

    cin >> N;
    for (int a = 0; a < N; ++a){
        cin >> Duration[i] >> Weight[i];
    }

    dfs(0);
    cout << answer;
    return 0;
}
