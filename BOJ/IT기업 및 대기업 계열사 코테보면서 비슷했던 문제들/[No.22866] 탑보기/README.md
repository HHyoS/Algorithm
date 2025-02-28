문제 사이트 : https://www.acmicpc.net/problem/22866

문제 설명

![image](https://github.com/user-attachments/assets/0c00b279-7321-4fae-bea2-c03a28576ea0)
![image](https://github.com/user-attachments/assets/eb0fcc43-890d-4a17-bc87-99e56e08ad16)

풀이 알고리즘

    문제에서 주어진 조건 내에서 자신보다 큰 건물의 개수를 구하고, 그 중 가장 가깝고 번호가 작은
    건물의 번호를 출력하는 문제 '탑 보기' 입니다.

    건물의 개수가 10만개로 2중 for문 사용시 반드시 시간초과가 발생하여 최소한의 탐색으로
    답을 구해야 합니다.

    제가 생각한 풀이는 아래와 같습니다.

    1) 좌 -> 우 / 우 -> 좌 탐색을 두 번 진행하여 왼쪽 높은 건물과 오른쪽 높은 건물을 개수와 번호 찾기
    2) 탐색에는 자신보다 낮은 값만 담는 stack을 사용하여 stack에 담긴 건물의 개수는
    stack.top의 건물 높이보다 작은 건물들 입장에서는 stack의 사이즈가 자신이 볼 수 있는
    건물의 개수가 됨.
    3) 2) 과정을 진행하며 stack.top에 있는 건물(자신보다 큰 건물 중 가까운)의 
    번호와 이미 저장되어 있는 가장 가까운 건물의 번호를 비교하여 더 가깝고 작은 번호의 건물 저장하기

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    
    struct Node {
        int idx;
        int h;
    };
    Node building[100010];
    int ans_cnt[100010];
    int ans_idx[100010];
    int N;
    void Solve() {
        stack<Node> st;
    
        st.push(building[1]);
        
        // 나보다 작은거만 기억하는 stack -> 특정 건물 기준으로 왼쪽에 보이는 건물들
        for (int a = 2; a <= N; ++a) {
            // st.top에 있는 빌딩이 대상 빌딩보다 더 크다면 상대 입장에서는 숫자가 가장 작은
            // 볼 수있는 빌딩이고. 현재 st에 있는 모든 빌딩은 내림차순 이므로 대상 빌딩이 볼 수 있음
            if (st.top().h > building[a].h) {
                ans_idx[a] = min(ans_idx[a], st.top().idx);
                ans_cnt[a] += st.size();
                st.push(building[a]);
            }
            // st.top의 빌딩보다 더 크다면, st.top의 값이 빌딩보다 더 커질떄 까지 pop
            else {
                while (!st.empty() && st.top().h <= building[a].h) {
                    st.pop();
                }
    
                // stack이 비어잇다면 그냥 넣어주고
                if (st.empty()) {
                    st.push(building[a]);
                }
    
                // 없다면 현재 건물에서 볼 수 있는 건물의 개수가 stack에 있는 값 이므로 넣어주고
                // 이미 저장한 가까운 건물의 위치와 비교하여 더 작은은 값 넣어주기
                // ans_idx의 값을 20만으로 설정했기 때문에 현재 for문에서는 항상
                // st.top().idx가 ans_idx[a]의 값으로 저장됨
                else {
                    ans_idx[a] = min(ans_idx[a], st.top().idx);
                    ans_cnt[a] += st.size();
                    st.push(building[a]);
                }
            }
        }
    
        while (!st.empty()) {
            st.pop();
        }
    
        st.push(building[N]);
        // 나보다 작은거만 기억하는 stack -> 특정 건물 기준 오른쪽으로 보이는 건물들
        for (int a = N-1; a > 0; --a) {
            // st.top에 있는 빌딩이 대상 빌딩보다 더 크다면 상대 입장에서는 숫자가 가장 작은
            // 볼 수있는 빌딩이고. 현재 st에 있는 모든 빌딩은 내림차순 이므로 대상 빌딩이 볼 수 있음
            if (st.top().h > building[a].h) {
                if (ans_idx[a] == 200000) {
                    ans_idx[a] = st.top().idx;
                }
                else {
                    int temp_a = abs(ans_idx[a] - a);
                    int temp_b = abs(a - st.top().idx);
                    // 만약 이전에 볼 수 있던 건물의 위치와 현재 볼 수 있는 건물의 위치 거리가
                    // 동일하거나, 이전에 볼 수 있는 건물의 위치가 더 가깝다면
                    // 이전에 볼 수 있던 건물의 위치 값 그대로 사용하고
                    // 아니라면 아래 if문을 통해 현재 보이는 건물 위치로 값 갱신
                    if (temp_a > temp_b) {
                        ans_idx[a] = st.top().idx;
                    }
                }
                ans_cnt[a] += st.size();
                st.push(building[a]);
            }
            // st.top의 빌딩보다 더 크다면, st.top의 값이 빌딩보다 더 커질떄 까지 pop
            else {
                while (!st.empty() && st.top().h <= building[a].h) {
                    st.pop();
                }
    
                if (st.empty()) {
                    st.push(building[a]);
                }
                else {
                    int temp_a = abs(ans_idx[a] - a);
                    int temp_b = abs(a - st.top().idx);
                    // 만약 이전에 볼 수 있던 건물의 위치와 현재 볼 수 있는 건물의 위치 거리가
                    // 동일하거나, 이전에 볼 수 있는 건물의 위치가 더 가깝다면
                    // 이전에 볼 수 있던 건물의 위치 값 그대로 사용하고
                    // 아니라면 아래 if문을 통해 현재 보이는 건물 위치로 값 갱신
                    if (temp_a > temp_b) {
                        ans_idx[a] = st.top().idx;
                    }
                    ans_cnt[a] += st.size();
                    st.push(building[a]);
                }
            }
        }
        for (int a = 1; a <= N; ++a) {
            if (ans_cnt[a] == 0) {
                cout << ans_cnt[a] << "\n";
            }
            else {
                cout << ans_cnt[a] << " " << ans_idx[a] << "\n";
            }
        }
    }
    
    
    void Input() {
        cin >> N;
        for (int a = 1; a <= N; ++a) {
            int temp;
            cin >> temp;
            building[a] = { a,temp };
            ans_idx[a] = 200000;
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

    야근 시러 두통 치통 나는야 통통이
![image](https://github.com/user-attachments/assets/b40fa0ec-1475-462d-a292-637c61534530)

