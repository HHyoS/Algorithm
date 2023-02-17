#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Eat {
    int x;
    int y;
    int state;
};
Eat info[10100];
bool used[22][22];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int maxi;
int useCnt = 0;
int N, M, Q;


bool cross(int x, int y) {
    for (int a = 0; a < 4; ++a) {
        int nx = x + mov[a][0];
        int ny = y + mov[a][1];
        if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
        if (used[nx][ny] == 1) return 1;
    }

    return 0;
}

int getLeng(int x, int y) {
    int leng = 21e8;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= M; ++b) {
            if (a == x && b == y) continue;
            if (used[a][b] == 1) {
                int xx = a - x;
                int yy = b - y;
                leng = min(leng,xx * xx + yy * yy);
            }
        }
    }
    return leng;
}
Eat Find() {
    int nextX = -1;
    int nextY = -1;
    int leng = -1;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= M; ++b) {
            if (used[a][b] == 0) {
                if (cross(a, b)) continue;
                int nLeng = getLeng(a, b);
                if (nLeng > leng) {
                    leng = nLeng;
                    nextX = a;
                    nextY = b;
                }
            }
        }
    }
    if (nextX != -1 && nextY != -1) {
        used[nextX][nextY] = 1;
    }
    return { nextX,nextY,1 };
}
void out(int idx) {
    if (info[idx].state==0) {
        cout << idx << " didn't eat lunch.\n";
    }
    else if (info[idx].state == 2) {
        cout << idx << " already left seat.\n";
    }
    else{
        cout << idx << " leaves from the seat (" << info[idx].x << ", " << info[idx].y << ").\n";
        info[idx].state = 2;
        used[info[idx].x][info[idx].y] = 0;
        --useCnt;
    }
}
void in(int idx) {
    if (info[idx].state == 0) {
        if(useCnt == 0){
            used[1][1] = 1;
            info[idx] = { 1,1,1 };
            cout << idx << " gets the seat (1, 1).\n";
            ++useCnt;
        }
        else {
            Eat temp = Find();
            if (temp.x == -1 && temp.y == -1) {
                cout << "There are no more seats.\n";
            }
            else {
                info[idx] = temp;
                cout << idx << " gets the seat ("<<temp.x<<", "<<temp.y<<").\n";
                ++useCnt;
            }
        }
    }
    else if (info[idx].state == 1) {
        cout << idx << " already seated.\n";
    }
    else if (info[idx].state == 2) {
        cout << idx << " already ate lunch.\n";
    }
}

void input() {
    cin >> N >> M >> Q;
    maxi = N * M;
    for (int a = 0; a < Q; ++a) {
        string query;
        int idx;
        cin >> query >> idx;
        if (query[0] == 'I') {
            in(idx);
        }
        else if (query[0] == 'O') {
            out(idx);
        }
    }
}

int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
	return 0;
}
