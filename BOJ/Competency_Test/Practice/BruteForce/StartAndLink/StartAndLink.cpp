#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int n;
bool is_used[21];
int s[21][21];
int ans = 987654321;

void Dfs(int curr_player, int cnt)
{
    if (cnt == n / 2)
    {
        vector<int> team_link, team_start;

        for (int i = 0; i < n; i++)
        {
            if (is_used[i]) team_start.push_back(i);
            else team_link.push_back(i);
        }

        int stat_start = 0, stat_link = 0;
        for (int i = 0; i < team_start.size(); i++)
        {
            for (int j = i+1; j < team_start.size(); j++)
            {
                int start_x = team_start[i], start_y = team_start[j];
                int link_x = team_link[i], link_y = team_link[j];
                stat_start += s[start_x][start_y] + s[start_y][start_x];
                stat_link += s[link_x][link_y] + s[link_y][link_x];
            }
        }

        ans = min(ans, abs(stat_start - stat_link));
        return;
    }

    for (int i = curr_player+1; i < n; i++)
    {
        if (is_used[i] == false)
        {
            is_used[i] = true;
            Dfs(i, cnt + 1);
            is_used[i] = false;
        }
    }

}


int main()
{
  scanf("%d",&n);
    // 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&s[i][j]);
        }
    }

    dfs(0,0);
    printf("%d",ans);

    return 0;
}
