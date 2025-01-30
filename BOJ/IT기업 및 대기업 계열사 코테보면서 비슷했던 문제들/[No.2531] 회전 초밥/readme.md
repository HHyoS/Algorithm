문제 사이트 : https://www.acmicpc.net/problem/2531

문제 설명 :

![image](https://github.com/user-attachments/assets/c600391e-ed88-4bcc-9e1a-85930e2a5233)
![image](https://github.com/user-attachments/assets/a925227d-9a3b-4dc6-bfbe-de0637770602)
![image](https://github.com/user-attachments/assets/2f1d8b18-5d66-4629-96b6-e3bf407c6266)

풀이 알고리즘

    원형으로 이루어진 회전 초밥 정보가 주어질 때, 연속된 k개의 접시를 골라 가장 많은 종류의

    초밥을 먹을 수 있는 방법을 찾고, 그 종류가 몇 가지 인지 출력하는 문제 '회전 초밥' 입니다.

    문제에서 주어진 조건을 따라 단순히 for문을 돌린다면 시간 복잡도가 30000 * 3000 = 9000만

    으로 시간 제한에 아슬아슬한 문제 입니다.

    위와 같운 문제는 슬라이딩 윈도우라는 방법을 통해 쉽게 풀이할 수 있으며 시작 지점과 

    끝 지점만 관리하며 오른쪽으로 한칸 이동 후, 시작지점의 값을 제거, 끝 지점의 값을 추가하는

    방식으로 풀면 됩니다.

    위 문제의 경우 초기값을 세팅하여 0번 위치부터 k-1개를 고른 후 그 사이에 존재하는 초밥의

    정보를 저장하였고, 이후 한칸씩 오른쪽으로 이동하며 처음 먹는 초밥인 경우에는 종류 추가

    처음 지점의 초밥을 제외했을 때, k범위 내에 해당 초밥이 없을 경우 종류 감소 하여 문제

    풀이 진행하였습니다.

    회전 초밥 문제는 원형 회전 초밥이 문제의 개념이기 떄문에, 한칸씩 이동하면서 처음 위치가

    다시 0번 위치로 돌아온다면 불필요한 반복을 하게 되므로, 해당 케이스에서 문제 풀이를

    종료하도록 하였습니다.


풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    /*
        문제 사이트 : https://www.acmicpc.net/problem/2531
        문제 설명 :
        */
    
    int N, d, k, c;
    int sushi[30001];
    int ate[3001];
    
    int Solve() {
        int cnt = 0;
        int ans = 0;
        // 쿠폰있는 c 음식은 1 추가하고 시작
        ate[c] = 1;
        ++cnt;
        // 0번 위치부터 시작해서 k개 골라서 선택하기
        for(int a = 0; a < k; ++a) {
            if (ate[sushi[a]] == 0) {
                ++cnt;
            }
    
            ate[sushi[a]]++;
        }
    
        ans = max(ans, cnt);
        
        int tail = 0;
        int head = k;
    
        // 처음 시작 위치로 돌아오기 전까지 한 칸씩 오른쪽 초밥을 고르면서 이동하기
        // 회전 초밥이므로 계속 오른쪽으로 가다보면 처음 위치로 돌아오게 됨.
        while(head != k-1){
            --ate[sushi[tail]];
            if (ate[sushi[tail]] == 0) {
                --cnt;
            }
    
            if (ate[sushi[head]] == 0) {
                ++cnt;
            }
            ++ate[sushi[head]];
            ans = max(ans, cnt);
            tail = (tail+1)%N;
            head = (head + 1)%N;
        }
    
        return ans;
    }
    void Input() {
        cin >> N >> d >> k >> c;
        for (int a = 0; a < N; ++a) {
            cin >> sushi[a];
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        cout << Solve();
        return 0;
    }

오늘의 일기

    조금 있으면 골드로 올라가는 것 같은데... 기가차드 날 응원해줘!!!!

    황삐삐 난 할 수 있어!

![image](https://github.com/user-attachments/assets/d3ce98ae-fe7c-46bb-9563-85ba90fb0c47)

![image](https://github.com/user-attachments/assets/d9fc6430-63f0-4553-bb62-e1376ddb0aed)
