문제 사이트 : https://www.acmicpc.net/problem/14658

문제 설명

![image](https://github.com/user-attachments/assets/0ccc2bf8-aea3-4dd5-92ab-dded0044487c)
![image](https://github.com/user-attachments/assets/577504e1-5ac5-421e-91d3-d64be03668b4)

풀이 알고리즘

    1) 지구의 크기 2) 떨어지는 별동별들의 좌표 3) 별동별을 튕겨낼 수 있는 트램펄린의 크기

    세가지 정보가 주어질 때, 믹을 수 없는 트램펄린의 개수를 출력하는 문제 '하늘에서 별똥별이 빗발친다' 입니다.

    지구의 크기는 최대 50만 x 50만으로 트램펄린 설치 좌표를 완전탐색 진행 시 반드시 시간초과가 발생하는 문제 입니다.

    따라서 다른 방법으로 트램펄린의 좌표를 지정 해야하며 제가 생각한 방법은 아래와 같습니다.

    1) 트램펄린의 좌표 x와 y 중 하나는 반드시 떨어지는 별의 좌표와 동일한 값이다
    -> 트램펄린이 설치되어 별을 튕겨내기 위해서는 반드시 트램펄린 범위 내에 별이 떨어져야 하며
    그를 위해서는 x와 y 값 중 하나는 떨어진 별과 같은 값을 가져야 합니다.
    ex - x좌표는 동일 - y 좌표를 상이하면 y좌표가 달라도 트럼펄린의 크기로 커버 가능
    x와 y좌표가 모두 동일하지 않다면 별을 튕겨낼 수 있다는 보장이 없음

    2) 따라서 최대 100개인 별의 두가지 값 x와 y값을 기준으로 2중 for문을 진행하면 최대
    10000번의 for문으로 탐색 가능하며, 해당 값을 바탕으로 100개의 별이 팅겨지는 확인하는데는 100만번의 연산만으로 처리 가능

    3) 1-2 과정을 모든 좌표에 대해 반복하여 지구에 떨어지는 별들의 최소값 출력

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    
    struct star {
        int x;
        int y;
    };
    vector<star> stars;
    vector<int> xs; // x 좌표에 있는 별들
    vector<int> ys; // y 좌표에 있는 별들
    int N, M, L, K;
    
    void Solve() {
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int ans = 0;

        // 별들의 x, y 좌표 기준 2중 for문 진행
        for (int a = 0; a < xs.size(); ++a) {
            for (int b = 0; b < ys.size(); ++b) {
                int cnt = 0;

                // 모든 별들을 탐색하여 트램펄린 범위 내인지 확인
                for (int c = 0; c < stars.size(); ++c) {
                    int sx = xs[a];
                    int sy = ys[b];
                    int ex = sx + L;
                    int ey = sy + L;

                    // 범위 내에 들어가지 않는다면 스킵!
                    if (stars[c].x < sx || stars[c].x > ex)
                        continue;
    
                    if (stars[c].y < sy || stars[c].y > ey)
                        continue;
    
                    ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
        // 전체 별의 개수에서 팅겨낸 별의 개수 빼주기
        cout << K - ans;
    }
    
    
    void Input() {
        cin >> N >> M >> L >> K;
        for (int a = 0; a < K; ++a) {
            int x, y;
            cin >> x >> y;
            stars.push_back({ x, y });
            xs.push_back(x);
            ys.push_back(y);
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Solve();
        return 0;
    }


풀이 후기

![image](https://github.com/user-attachments/assets/74752caf-b425-4002-9739-5d3d4ba6462d)

    늦은 풀이 후기... 어케 이걸 3주전에 품? 시간 녹아버렸따
