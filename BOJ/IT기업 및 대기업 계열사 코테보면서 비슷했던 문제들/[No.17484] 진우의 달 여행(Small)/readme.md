문제 사이트 : https://www.acmicpc.net/problem/17484

문제 설명 :

    우주비행이 꿈이였던 진우는 음식점 '매일매일싱싱'에서 열심히 일한 결과 달 
    
    여행에 필요한 자금을 모두 마련하였다!
    
    지구와 우주사이는 N X M 행렬로 나타낼 수 있으며 각 원소의 값은 우주선이 
    
    그 공간을 지날 때 소모되는 연료의 양이다.

[예시]

![image](https://github.com/user-attachments/assets/e79904f4-7a45-4fb4-b94d-4bab9d3f1563)


    진우는 여행경비를 아끼기 위해 조금 특이한 우주선을 선택하였다. 
    
    진우가 선택한 우주선의 특징은 아래와 같다.

    1. 지구 -> 달로 가는 경우 우주선이 움직일 수 있는 방향은 아래와 같다.

![image](https://github.com/user-attachments/assets/cf40a8d3-d5a8-4215-983e-5c3162bb8df4)

    2. 우주선은 전에 움직인 방향으로 움직일 수 없다. 
    
    즉, 같은 방향으로 두번 연속으로 움직일 수 없다.

    진우의 목표는 연료를 최대한 아끼며 지구의 어느위치에서든 출발하여
    
    달의 어느위치든 착륙하는 것이다.
    
    최대한 돈을 아끼고 살아서 달에 도착하고 싶은 진우를 위해 달에 도달하기 위해 필요한
    
    연료의 최소값을 계산해 주자.

입력

    첫줄에 지구와 달 사이 공간을 나타내는 행렬의 크기를 나타내는
    
    N, M (2≤ N, M ≤ 6)이 주어진다.
    
    다음 N줄 동안 각 행렬의 원소 값이 주어진다. 
    
    각 행렬의 원소값은 100 이하의 자연수이다.

출력

    달 여행에 필요한 최소 연료의 값을 출력한다.

예제 입력 1 

    6 4
    5 8 5 1
    3 5 8 4
    9 77 65 5
    2 1 5 2
    5 98 1 5
    4 95 67 58

예제 출력 1 

    29

풀이 알고리즘

    각 공간을 지나는데 필요한 비용이 주어질 때, 최소 비용으로 지구 -> 달로 이동하는 비용을

    구하는 문제 '진우의 달 여행' 입니다.

    단순하게 최소값을 구하는 문제가 아니라 이전 방향도 체크하는 조건이 있기 때문에

    해당 부분을 인지하고 풀이가 필요한 문제입니다.

    위 조건을 제외하고는 크게 어려운 부분은 없으며, 입력값의 크기 또한 작은 값으로

    구현만 한다면 크게 제한되는 부분이 없습니다.

풀이 코드 

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    #include <string>
    using namespace std;
    
    int N, M;
    int arr[7][7];
    int min_v[7][7][3];
    int ans = 21e8;
    
    
    void dfs(int x, int y,int now_sum,int before) {
        if (x == N-1) {
            ans = min(ans, now_sum);
            return;
        }
        for (int a = -1; a < 2; ++a) {
            if (before == a) continue;
            int nx = x + 1;
            int ny = y + a;
            if (ny < 0 || ny >= M)continue;
    
            int total_sum = now_sum + arr[nx][ny];
    
            dfs(nx, ny, total_sum,a);
        }
    }
    void Solve() {
    
        for (int a = 0; a < M; ++a) {
            dfs(0, a,arr[0][a],-2);
        }
    
    }
    void Input() {
        cin >> N >> M;
    
        for (int a = 0; a < N; ++a) {
            for (int b = 0; b < M; ++b) {
                cin >> arr[a][b];
            }
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Solve();
        cout << ans;
        return 0;
    }

풀이 후기

    아.. 풀이가 조금 아쉬운 문제... 진우 녀석..

    풀이방법을 고민할 때 단순 dfs와 이전 방향을 기억해서 단순 for문으로 구현하는 dp

    두가지에 대해 고민했는데, dp의 경우 풀이가 복잡해져서 포기했따..

    포기하면 지는거라고 했는데 나는 알고리즘에게 패배 해버렸다..

    주말에 시간내서 DP로 풀어봐야겠다.

![image](https://github.com/user-attachments/assets/a4b0be60-31de-4088-a1ef-81060f99f1a0)
