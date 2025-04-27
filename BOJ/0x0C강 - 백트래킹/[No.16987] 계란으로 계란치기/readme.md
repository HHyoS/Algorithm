문제 사이트 : https://www.acmicpc.net/problem/16987

문제 설명 :

![image](https://github.com/user-attachments/assets/54f059cd-8b8d-4642-a118-63d26042eafe)
![image](https://github.com/user-attachments/assets/ae1f5a7b-28b8-4fbd-af1c-8a7dda6202dd)
![image](https://github.com/user-attachments/assets/d4d9dc87-edfa-442a-889e-b6545adfbce5)

문제 개요

- N개의 계란이 일렬로 놓여 있고, 왼쪽부터 순서대로 계란을 들어 다른 계란과 한 번씩 부딪힐 수 있음.
- 각 계란은 내구도 Si와 무게 Wi를 가지며, 부딪힐 때 상대 계란의 무게만큼 내구도가 감소.
- 내구도가 0 이하가 되면 해당 계란은 깨진 것으로 간주되며, 더 이상 활용할 수 없음.
- 모든 계란에 대해 처리를 마쳤을 때 깨진 계란의 최대 개수를 출력.

풀이 알고리즘

    순서(depth) 가 0부터 N-1까지 올라가며, 각 단계에서 “현재 들고 있는 계란”을
    다른 모든 깨지지 않은 계란과 하나씩 부딪히는 모든 경우를 탐색하는 백트래킹 방법을 사용.

    1) dfs(idx) 호출 시, idx번째 계란을 듬.

    2) 기저 조건: idx == N이면 모든 계란을 한 번씩 처리한 상태이므로, 
    깨진 계란 수를 세어 정답 갱신 후 리턴.

    3) 현재 계란이 이미 깨졌다면(S[idx] ≤ 0), dfs(idx+1)로 넘겨 다음 단계만 처리. 

    4) 깨지지 않은 계란이 남아 있다면:

    모든 다른 계란 j (j ≠ idx, S[j] > 0)에 대해 서로 내구도를 감소시키고
    (S[idx] -= W[j], S[j] -= W[idx]),

    dfs(idx+1)로 재귀 후, 백트래킹(원상 복구)

    만약 부딪힐 수 있는 계란이 전혀 없다면 모든 계란이 깨진 상태이므로
    dfs(idx+1)만 호출.

    모든 계란에 대해 처리를 마쳤을 때 깨진 계란의 최대 개수를 출력.


풀이 코드

    #include <bits/stdc++.h>
    using namespace std;
    
    int N;
    vector<int> S, W;
    int ans = 0;
    
    void dfs(int idx) {
        if (idx == N) {
            // Count broken eggs
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (S[i] <= 0) cnt++;
            }
            ans = max(ans, cnt);
            return;
        }
        
        // If current egg is already broken or no other unbroken egg to hit, skip
        if (S[idx] <= 0) {
            dfs(idx + 1);
            return;
        }
        
        // Check if there is any target to hit
        bool hit = false;
        for (int j = 0; j < N; j++) {
            if (j == idx) continue;
            if (S[j] > 0) {
                hit = true;
                // Simulate hit
                int ori_si = S[idx];
                int ori_sj = S[j];
                
                S[idx] -= W[j];
                S[j]   -= W[idx];
                
                dfs(idx + 1);
                
                // Backtrack
                S[idx] = ori_si;
                S[j]   = ori_sj;
            }
        }
        
        // If no hit was possible, move to next
        if (!hit) {
            dfs(idx + 1);
        }
    }
    
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    
        cin >> N;
        S.resize(N);
        W.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i] >> W[i];
        }
    
        dfs(0);
        cout << ans;
        return 0;
    }

풀이 후기

    시간 좀 지났다고 까먹어버리기
