#include <iostream>
#include <vector>

using namespace std;

int result = 0;

const int dx[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dy[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };

struct Fish {
    int x = 0;      //물고기 x좌표
    int y = 0;      //물고기 y좌표
    int dir = 0;    //물고기 이동방향
    int fish_number = 0;    //물고기 숫자
    bool fish_live = true;  
};

void stimulation(vector<vector<int>>& v, Fish* fish, int shark_x, int shark_y, int sum) {

    vector<vector<int>> cp_v(4, vector<int>(4));
    Fish cp_fish[16];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cp_v[i][j] = v[i][j];
    }
    for (int i = 0; i < 16; i++)
        cp_fish[i] = fish[i];

    //상어가 물고기 먹음
    int n = cp_v[shark_x][shark_y];
    cp_v[shark_x][shark_y] = -1;    

    // 상어 이동방향 설정
    int shark_dir = cp_fish[n].dir;
    cp_fish[n].fish_live = false;   //물고기 죽음

    sum += cp_fish[n].fish_number;
    if (result < sum) result = sum;

    //물고기 이동
    for (int i = 0; i < 16; i++) {
        if (cp_fish[i].fish_live) {
            int x = cp_fish[i].x;
            int y = cp_fish[i].y;
            int dir = cp_fish[i].dir;

            int next_x = x + (dx[dir % 8]);
            int next_y = y + (dy[dir % 8]);

            while (next_x < 0 || next_x > 3 || next_y < 0 || next_y > 3 || 
             (shark_x == next_x && shark_y == next_y)) {
                
                dir++;
                next_x = x + (dx[dir % 8]);
                next_y = y + (dy[dir % 8]);
            }

            //물고기 swap
            if (cp_v[next_x][next_y] != -1) {
                int swap_fish = cp_v[next_x][next_y];
                cp_fish[i].x = next_x;
                cp_fish[i].y = next_y;
                cp_fish[i].dir = dir;
                cp_fish[swap_fish].x = x;
                cp_fish[swap_fish].y = y;

                cp_v[next_x][next_y] = i;
                cp_v[x][y] = swap_fish;
            }
            else {
                cp_fish[i].x = next_x;
                cp_fish[i].y = next_y;
                cp_fish[i].dir = dir;
                cp_v[next_x][next_y] = i;
                cp_v[x][y] = -1;
            }
        }
    }
    //상어 이동
    for (int i = 1; i < 4; i++) {
        int dir_x = dx[shark_dir % 8] * i;
        int dir_y = dy[shark_dir % 8] * i;
        int next_x = shark_x + dir_x;
        int next_y = shark_y + dir_y;

        if (next_x < 0 || next_x > 3 || next_y < 0 || next_y > 3)
            break;

        if (cp_v[next_x][next_y] != -1)
            stimulation(cp_v, cp_fish, next_x, next_y, sum);
    }
}

int main()
{
    vector<vector<int>> v(4, vector<int>(4));
    Fish fish[16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num, _dir;
            cin >> num >> _dir;
            num--; _dir--;
            v[i][j] = num;
            fish[num].x = i;
            fish[num].y = j;
            fish[num].dir = _dir;
            fish[num].fish_number = num + 1;
        }
    }
    stimulation(v, fish, 0, 0, 0);
    printf("%d\n", result);
    return 0;
}
