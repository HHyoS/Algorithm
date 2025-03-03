문제 사이트 : 

문제 설명

![image](https://github.com/user-attachments/assets/9a04d1e9-7b12-44ae-80fa-6cbdbffd894e)
![image](https://github.com/user-attachments/assets/6fd2865e-ea14-49d5-b8ca-74ce06de8a3f)
![image](https://github.com/user-attachments/assets/c5659215-ad81-423c-ac34-32b4e0462817)

풀이 알고리즘

    N개의 건물이 주어지고, 가희 왼쪽, 단비가 오른쪽에 서있다.
    그리고 가희와 단비가 볼 수 있는 건물의 조건이 주어질 때, 사전순으로 가장 앞서는
    건물들의 높이를 출력하는 문제 '가희와 탑' 입니다.

    단순하게 손으로 풀이해보면 쉬운 문제이지만, 실제로 코드로 구현할 때는
    사이드 케이스와 구현에 대한 아이디어가 필요한 문제 였습니다.

    제가 생각한 접근법은 다음과 같습니다.

    1. 볼수 있는 건물의 갯수가 Q개 라면, 건물들 중 제일 높은 건물의 높이는 Q여야 한다.
    2. 최고 높이 건물을 기준으로 왼쪽에 건물을 최대한 몰아 넣는다(사전순을 위해)
    3. (가희 빌딩)-최고 높이 빌딩-(단비 빌딩)  순으로 배치 될 때
    (xx 빌딩) 의 구조는 ( 1, 1, 1, 1.....(a-a+2), (a-a+3) 과 같아야한다.
    ex) 가희 3개, 단비 4개 건물의 개수 = 10개 라면
            1 1 1 1 1 2 4(최고 높이) 3 2 1

        가희 1개, 단비 4개 건물의 개수 = 10개 라면
            4(최고 높이) 1 1 1 1 1 1 3 2 1
    4. 문제에서 -1이 출력되는, 구현이 불가능한 케이슨느 가희와 단비가 볼 수 있는 건물의합이
    N보다 1 큰 경우의 수 이므로, 해당 케이스는 예외 처리
    
    위의 설명을 구현한 코드는 아래를 확인 부탁 드립니다.

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    int N;
    int aa, bb;
    stack<int> l;
    queue<int> r;
    void Solve() {
    
        if (aa + bb > N + 1) {
            cout << -1;
            return;
        }
        int maxH = max(aa,bb);
        int center = 0;
        int left_cnt = N - bb;
        
        // 제일 높은 곳의 위치는 maxH로 정해졌고, 볼 수 있는 건물 중 하나는 이미 maxH임
        // 따라서 가희가 볼 수 있는 건물의 수는 이제 a -1개, 단비는 b-1개
        int taa = aa - 1 ;
        int tbb = bb - 1; 
    
        // 제일 높은 곳 기준 왼쪽부터 해보자
        if (taa == 0) { // 가희가 볼 수 있는 건물의 수가 1개이면, 제일 높은 건물 제외하고 못 봄
            left_cnt = N - 1;
        }
        else {
            /* 제일 높은 높인느 maxH이고, 사전 순으로 가장 낮은 값을 사용하려면
           다른 빌딩은 모두 최소값으로 세팅 되어야함. 만약 제일 높은 건물을 제외하고 3개를 볼 수 있다면
            사용 되는 높이는 1 2 3 이 되어야함(다른 수는 사전 순으로 봤을 때 가장 앞이 아님). */
            for (int a = taa; a > 0; --a) {
                if (left_cnt > 0) {
                    l.push(a);
                    --left_cnt;
                }
                else {
                    break;
                }
            }
            /*사전 순으로 가장 앞 서려면 가희가 보는 건물 쪽에 최대한 많은 건물을, 최소 높이로
            세팅해야 함.
            따라서 가희가 1개만 볼 수 있는 케이스를 제외하고 모두 가희 쪽으로 빌딩을 몰아야 함.
            */
    
            // 가희 쪽으로 높이 1짜리를 최대한 세팅하여 사전 순으로 앞서게 만들기
            while (left_cnt > 0) {
                l.push(1);
                --left_cnt;
            }
            left_cnt = tbb;
        }
    
       // 만약 가희 쪽으로 세팅하고도 단비가 볼 수 있는 b개 이상의 빌딩을 세팅해야 한다면
        // 1로 미리 채워넣어서 사전 순으로 앞서게 만들고
        while (left_cnt != tbb) {
            r.push(1);
            --left_cnt;
        }
        // b개만큼 높이 세팅하기
        for (int a = tbb; a > 0; --a) {
            r.push(a);
        }
    
        // 정답 출력 
        // 가희 -> 최고 높이 -> 단비
        while (!l.empty()) {
            cout << l.top() << " ";
            l.pop();
        }
        cout << maxH << " ";
        while (!r.empty()) {
            cout << r.front() << " ";
            r.pop();
        }
        
    
    }
    
    
    void Input() {
        cin >> N >> aa >> bb;
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

    출근 시러
![image](https://github.com/user-attachments/assets/41d6225b-4be2-4bec-8124-f8bac56b0557)
