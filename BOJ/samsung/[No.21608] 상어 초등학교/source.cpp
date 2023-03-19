#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;



struct Node {
    int x;
    int y;
};
int N;
int classRoom[21][21];
int student[21][21];
bool isSeat[401];
vector<int>likeInfo[401];
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int majokdo[5] = { 0,1,10,100,1000 };
bool likeCheck(int me) {
    for (int a = 0; a < likeInfo[me].size(); ++a) {
        if (isSeat[likeInfo[me][a]] == 1)
            return 1;
    }
    return 0;
}

void closeLike(int target) {

    int maxiCnt = -1;
    int emptyCnt = -1;
    Node chair = { 0,0 };
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            int cnt = 0;
            int empty = 0;
            if (student[a][b] != 0) continue;
            for (int c = 0; c < 4; ++c) {
                int x = a + mov[c][0];
                int y = b + mov[c][1];
                if (x <= 0 || x > N || y <= 0 || y > N) continue;
                if (student[x][y] == 0) {
                    ++empty;
                    continue;
                }
                for (int d = 0; d < likeInfo[target].size(); ++d) {
                    if (student[x][y] == likeInfo[target][d]) {
                        ++cnt;
                        break;
                    }
                }
            }
            if (cnt > maxiCnt) {
                maxiCnt = cnt;
                emptyCnt = empty;
                chair = { a,b };
            }
            else if (cnt == maxiCnt && emptyCnt < empty) {
                emptyCnt = empty;
                chair = { a,b };
            }
        }
    }
    for (int a = 0; a < 4; ++a) {
        int x = chair.x + mov[a][0];
        int y = chair.y + mov[a][1];

        if (x <= 0 || x > N || y <= 0 || y > N) continue;
        if (classRoom[x][y] == 0) continue;

        classRoom[x][y]--;
    }
    classRoom[chair.x][chair.y] = 0;
    student[chair.x][chair.y] = target;
    isSeat[target] = 1;
}
void choiceChair(int target) {
    int maxi = -1;
    Node maxiChair = { 0,0 };
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (classRoom[a][b] == 0) continue;
            if (maxi < classRoom[a][b]) {
                maxi = classRoom[a][b];
                maxiChair = { a,b };
            }
        }
    }
    for (int a = 0; a < 4; ++a) {
        int x = maxiChair.x + mov[a][0];
        int y = maxiChair.y + mov[a][1];

        if (x <= 0 || x > N || y <= 0 || y > N) continue;
        if (classRoom[x][y] == 0) continue;

        classRoom[x][y]--;
    }
    classRoom[maxiChair.x][maxiChair.y] = 0;
    isSeat[target] = 1;
    student[maxiChair.x][maxiChair.y] = target;
}
void solve(int target) {
    int ans=0;
    if (likeCheck(target)) {
        closeLike(target);
    }
    else {
        choiceChair(target);
    }

    
}
void input() {
    cin >> N;
    int ans = 0;
    int total = N * N;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            for (int c = 0; c < 4; ++c) {
                int x = a + mov[c][0];
                int y = b + mov[c][1];
                if (x <= 0 || x > N || y <= 0 || y > N) continue;
                classRoom[x][y]++;
            }
        }
    }

    for (int a = 0; a < total; ++a) {
        int target;
        cin >> target;
        for (int b = 0; b < 4; ++b) {
            int like;
            cin >> like;
            likeInfo[target].push_back(like);
        }
        solve(target);
    }




    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            int index = student[a][b];
            int cnt = 0;
            for (int c = 0; c < 4; ++c) {
                int x = a + mov[c][0];
                int y = b + mov[c][1];
                if (x <= 0 || x > N || y <= 0 || y > N) continue;
                for (int d = 0; d < likeInfo[index].size(); ++d) {
                    if (student[x][y] == likeInfo[index][d]) {
                        ++cnt;
                        break;
                    }
                }
            }
            ans += majokdo[cnt];
        }
    }
    cout << ans;
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);

    input();
    return 0;
}
