문제 사이트 : https://www.acmicpc.net/problem/15235

문제 설명

![image](https://github.com/user-attachments/assets/8a2e9c09-049b-434b-b1f7-dcd4fb0fb0a1)
![image](https://github.com/user-attachments/assets/76073cee-9566-4302-9036-7e6cbf1247a6)

풀이 알고리즘

    N명의 참가자들이 먹는 피자 양이 주어질 때, 각 참가자가 피자를 먹는데 필요한 시간을 출력하는 문제
    'Olympiad pizza'입니다.

    N명의 참가자가 피자를 먹는 방식이 Round Robbin 방식임으로, queue를 사용시 편하게 구현할 수 있는 문제입니다.

    제가 생각한 풀이 방식은 아래와 같습니다.
    
    1) 초기 입력시 각 참가자가 필요한 양에 대해 배열로 저장 후, queue에 모든 참가자를 넣어줍니다.
    2) queue의 front에서 참가자를 하나씩 빼내며 먹은 피자양을 +1 해주고, +1 했을 때, 해당 참가자가 필요한 양을
    다 먹었다면 해당 참가자가 먹은 시간을 기록합니다.
    3) 모든 참가자에 대해 2 과정이 완료되었다면 정답 출력!

    자세한 설명은 아래 코드 주석을 바탕으로 이해 부탁 드립니다.

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    struct Info {
        int idx;
        int eat;
    };
    int participant[1010];
    int ans[1010];
    queue<Info> pizza;
    int N;
    
    void Solve() {
    
      // 현재까지 참가자가 먹은 피자 양 기록용 queue
      // 초기에는 아무것도 먹지 않으니 0을 넣어준다
        for (int a = 0; a < N; ++a) {
            pizza.push({ a,0 });
        }
        int nTime = 0; // queue를 한 번 돌 때마다 1씩 추가해 줄 시간.
        while (!pizza.empty()) {
            ++nTime;
            Info nParticipant = pizza.front();
            pizza.pop();
    
            // 먹은 양 +1 해주고
            nParticipant.eat += 1;
    
          // 해당 참가자가 먹어야 하는 양을 충족했다면
            if (participant[nParticipant.idx] == nParticipant.eat) {
                ans[nParticipant.idx] = nTime; // 정답 저장
            }
            else { // 아니라면 다시 queue에 넣어주기
                pizza.push(nParticipant);
            }
        }
    
      // 탐색 종료되면 정답 출력
        for (int a = 0; a < N; ++a) {
            cout << ans[a] << " ";
        }
    }
    
    
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            cin >> participant[a]; // 참가자가 먹어야 하는 피자 양 저장
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

    이번 주는... 초큼 힘들어요... 주말에 보충하겠슴돠..
![image](https://github.com/user-attachments/assets/8714a0cc-9ee7-413a-ab33-6f105e66a57a)

