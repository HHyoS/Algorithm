문제 사이트 : https://www.acmicpc.net/problem/2467

문제 설명

![image](https://github.com/user-attachments/assets/52223675-e133-444f-b3bf-a68de4e1646e)
![image](https://github.com/user-attachments/assets/8082a7be-23c8-4ada-8aaa-68d4aa31af16)

풀이 알고리즘

        엘레베이터의 최대 층수 N, 디스플레이의 자리 수 K, 바꿀 수 있는 LED 개수 P
        현재 층 X가 주어질 때, LED를 1개 이상 변화시켜 N 이하의 숫자로 바꾸는
        경우의 수를 출력하는 문제 '빌런 호석' 입니다.

        문제 풀이에 필요한 아이디어는 두 가지로

        1) 숫자 a를 숫자 b로 바꾸는데 필요한 led 개수 미리 구하기
        2) 어떤 케이스에 경우의 수에 포함시킬지, back tracking으로 불필요 연산을 제거할 지 고려

        두 가지 입니다.

        저는 1)의 케이스를 일일히 구하는 것이 어려워 숫자 별 led 사용 위치 배열을 선언한 뒤
        각 숫자 별 2중 for문을 동작하여 상태가 다른 led의 개수(켜짐 vs 꺼짐)을 카운트하여 동적으로
        사용했습니다.

        2)의 경우 dfs로 가장 큰 자리수 부터 변화시키며 아래 케이스에 만족하면 경우의 수 혹은 return 처리하여 구현했습니다
        2-1) 1개 이상 led를 변화시키고 + N보다 작고 + 0이 아니며 처음 방문한 층 이면 경우의 수 +1
        2-2) 현재 바꾸려는 자리수 이전의 자리 수 값이 N의 이전 자리수 위치 값보다 크면 return
        -> 2-2의 경우 이전 자리수가 N보다 크면 이후 자리를 어떻게 수정해도 N보다 커지므로 의미가 조건에 의해
        의미가 없어집니다.
        ex) N = 141, 현재 층 = 151, 바꾸려는 자리수 = 10의 자리 일 경우 현재 층은 141 -> 140이 될 가능성이 있습니다
        하지만 N = 141, 현재 층 = 151, 바꾸려는 자리수 = 1의 자리 일 경우, 1의 자리를 어떻게 변화시켜도
        항상 N보다 커지므로 경우의 수에 포함될 수 없습니다.

        위의 두가지를 구현하면 무리없이 문제 풀이 가능합니다.


풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    using namespace std;
    
    int N, K, P, X;
    string real_N; // N을 string화 하여 특정 자리수의 숫자 비교
    int ans;
    int convert[10][10]; // 특정 수를 다른 수로 바꿀 때 필요한 led 개수
    bool used[1000000]; // 경우에 수에 포함되었는지 확인 배열
    bool num[10][7] = { // 각 숫자 별 LED 위치 사용 여부 배열 
        {1,1,1,0,1,1,1},
        {0,0,1,0,0,1,0},
        {1,0,1,1,1,0,1},
        {1,0,1,1,0,1,1},
        {0,1,1,1,0,1,0},
        {1,1,0,1,0,1,1},
        {1,1,0,1,1,1,1},
        {1,0,1,0,0,1,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
    };
    
    
    void dfs(int idx, string now_num, int remain_display) {
    
        int now_floor = stoi(now_num);
        // 현재 바꿀 위치가 맨 앞자리가 아니고, 이미 바꾼 후의 자리수가 N보다 크다면
        if (idx > 0 && now_floor > N && now_num[idx-1] > real_N[idx-1]) {
            return;
        }
    
        // 만든 적이 없는 층이고, 하나 이상 led를 변화시켰고, 0층이 아니고, N보다 작다면 경우의 수 1 추가
        if (used[now_floor] == 0 && remain_display != P && now_floor != 0 && now_floor <= N) {
            used[now_floor] = 1;
            ++ans;
        }
    
        // 더 이상 led를 바꿀 수 없거나, 바꾸려는 위치가 범위 밖 이라면 return
        if (remain_display == 0 || idx == K) {
            return;
        }
    
        // 바꾸려고 하는 자리 수의 숫자를 int로 변환
        int target = now_num[idx]-'0';
    
        // target을 a로 변화시키는데 필요한 코스트와 남은 코스트 비교하여 변화 가능하다면 변화 시작
        for (int a = 0; a < 10; ++a) {
            if (remain_display - convert[target][a] >= 0) {
                dfs(idx + 1, now_num.substr(0, idx) + to_string(a) + now_num.substr(idx+1),remain_display - convert[target][a]);
            }
        }
    }
    void Solve() {
        string floor = to_string(X);
        int add_zero = K - floor.size(); // 자리수 K에 맞게 현재 층 앞에 0 더해주기
        for (int a = 0; a < add_zero; ++a) {
            floor = "0" + floor;
        }
    
        // N은 int형 이므로 K자리로 만든 N을 만들어 자리수 비교하자
        real_N = to_string(N);
        add_zero = K - real_N.size();
        for (int a = 0; a < add_zero; ++a) {
            real_N = "0" + real_N;
        }
        dfs(0, floor,P);
    
        cout << ans;
    }
    void Input() {
        cin >> N >> K >> P >> X;
        for (int a = 0; a < 10; ++a) { // 변환 코스트 계산 2중 for문
            for (int b = a + 1; b < 10; ++b) {
                int cnt = 0;
                for (int c = 0; c < 7; ++c) {
                    if (num[a][c] != num[b][c]) {
                        ++cnt;
                    }
                }
    
                convert[a][b] = cnt;
                convert[b][a] = cnt;
            }
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

![image](https://github.com/user-attachments/assets/232c78b1-c692-4fde-b42e-e52d7d4131d5)
