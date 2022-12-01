#include<iostream>
#include<queue>

#define MAX 2000
using namespace std;
int n;

bool arr[MAX][MAX];


int bfs()
{
    queue<pair<pair<int, int>, int> > Q;
    Q.push(make_pair(make_pair(1, 0), 0));
    arr[1][0] = true;

    while (Q.empty() == 0)
    {
        int Dis = Q.front().first.first;
        int Clip = Q.front().first.second;
        int Time = Q.front().second;
        Q.pop();

        if (Dis == n) return Time;

        if (Dis > 0 && Dis < MAX)
        {
            //1번 & 3번 조건
            if (arr[Dis][Dis] == false)
            {
                arr[Dis][Dis] = true;
                Q.push(make_pair(make_pair(Dis, Dis), Time + 1));
            }

            if (arr[Dis - 1][Clip] == false)
            {
                arr[Dis - 1][Clip] = true;
                Q.push(make_pair(make_pair(Dis - 1, Clip), Time + 1));
            }
        }

        if (Clip > 0 && Dis + Clip < MAX)
        {
            if (arr[Dis + Clip][Clip] == false)
            {
                arr[Dis + Clip][Clip] = true;
                Q.push(make_pair(make_pair(Dis + Clip, Clip), Time + 1));
            }
        }
    }
}



int main(void)
{

    //freopen("Input.txt", "r", stdin);
    scanf("%d", &n);
    printf("%d", bfs());

    return 0;
}

