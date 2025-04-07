문제 사이트 : https://www.acmicpc.net/problem/20056

문제 설명 :

TBD

풀이 알고리즘

TBD

풀이 코드

    #include <bits/stdc++.h>
    using namespace std;
    
    struct Fireball {
        int r, c, m, s, d;
    };
    
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    
        int N, M, K;
        cin >> N >> M >> K;
    
        vector<Fireball> fireballs;
        fireballs.reserve(M);
        for (int i = 0; i < M; i++) {
            int r, c, m, s, d;
            cin >> r >> c >> m >> s >> d;
            // convert to 0-based
            fireballs.push_back({r-1, c-1, m, s, d});
        }
    
        // direction vectors: 0..7 as per problem diagram
        int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[8] = { 0,  1, 1, 1, 0, -1, -1, -1};
    
        // grid to hold fireballs after movement
        vector<vector<vector<Fireball>>> grid(N, vector<vector<Fireball>>(N));
    
        for (int step = 0; step < K; step++) {
            // clear grid
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    grid[i][j].clear();
    
            // 1) Move all fireballs
            for (auto &fb : fireballs) {
                int move = fb.s % N;
                int nr = (fb.r + dr[fb.d] * move + N) % N;
                int nc = (fb.c + dc[fb.d] * move + N) % N;
                grid[nr][nc].push_back({nr, nc, fb.m, fb.s, fb.d});
            }
    
            // 2) Merge & split
            vector<Fireball> newFireballs;
            newFireballs.reserve(fireballs.size());
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int cnt = grid[i][j].size();
                    if (cnt == 0) continue;
                    if (cnt == 1) {
                        // single fireball remains as is
                        newFireballs.push_back(grid[i][j][0]);
                    } else {
                        // merge
                        int sumM = 0, sumS = 0;
                        bool allEven = true, allOdd = true;
                        for (auto &fb : grid[i][j]) {
                            sumM += fb.m;
                            sumS += fb.s;
                            if (fb.d % 2 == 0) allOdd = false;
                            else allEven = false;
                        }
                        int nm = sumM / 5;
                        if (nm > 0) {
                            int ns = sumS / cnt;
                            // choose new directions
                            vector<int> ndirs;
                            if (allEven || allOdd) {
                                ndirs = {0, 2, 4, 6};
                            } else {
                                ndirs = {1, 3, 5, 7};
                            }
                            for (int d2 : ndirs) {
                                newFireballs.push_back({i, j, nm, ns, d2});
                            }
                        }
                        // if nm == 0, all new fireballs vanish
                    }
                }
            }
    
            // prepare for next step
            fireballs.swap(newFireballs);
        }
    
        // sum of masses
        long long answer = 0;
        for (auto &fb : fireballs) {
            answer += fb.m;
        }
    
        cout << answer << "\n";
        return 0;
    }


풀이 후기

    에욱
    
![image](https://github.com/user-attachments/assets/5c4aa854-c479-48cd-90a9-2b7af6635fe1)

