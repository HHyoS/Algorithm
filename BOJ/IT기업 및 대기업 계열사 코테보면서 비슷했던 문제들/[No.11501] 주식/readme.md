문제 사이트 : https://www.acmicpc.net/problem/11501

문제 설명 :

![image](https://github.com/user-attachments/assets/7de3358e-92f5-4bd1-929f-a61967a1a8e9)
![image](https://github.com/user-attachments/assets/b0be84ed-206a-4c9e-bf0b-d27fa1848377)

풀이 알고리즘

    문제의 주인공인 홍준이의 행동 방식 세가지와 N일동안 주식 정보가 주어졌을 때,

    홍준이가 최대 이득을 얻게하여 해당 이득을 출력하는 문제 '주식' 입니다.

    단순하게 앞의 인덱스부터 비교를 진행하면 1+2+3+...N-1 번 비교 연산을 진행하여

    시간복잡도 O(N^2)를 갖게 되는데, 해당 방법으로는 N <= 1,000,000 의 범위에 의해

    시간 초과가 발생하게 됩니다.

    단순한 방법 대신 아이디어를 생각하면, 최대 이득 = 현재 구매하여 제일 비싼 날 팔면 됨

    이므로, 뒤에서부터 탐색을 시작하여 최대값을 저장하고, 해당 날의 앞에 존재하는 일자에는

    가장 비싼날에 판것으로 계산하여 이득을 계산하면 됩니다.

    아이디어를 정리하면 아래와 같습니다.

    1) 탐색의 방향은 마지막날 -> 첫날

    2) 마지막 날 부터 시작하여 주식의 가치가 최대인 날만 저장하여 기록해둠

    3) 최대인 날보다 앞의 날 중에 최대보다 싼 주식 가격을 갖는 날에는 비싼 날에 팔았다고

    가정하고 이득을 더함

    4) 앞의 날 중에 더 비싼 주가를 가진 날이 있다며 해당 날을 최대인 날로 설정하고 

    2~3 을 반복.

    5) 문제의 조건 중 64bit 숫자 내에서 표현된다고 하였으므로 long long으로 게산 해주기

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    int T, N;
    long long stock[1000001];
    void Solve() {
    }
    void Input() {
        cin >> T;
        for (int a = 0; a < T; ++a) {
            cin >> N;
            for (int b = 0; b < N; ++b) {
                cin >> stock[b];
            }
            long long max_profit = 0;
            int max_idx = N - 1;
            // 모든 날의 정보를 알고 있으므로 뒷날부터 최대 값을 확인해보자
    
            // 최대값을 저장하며, 해당 값보다 낮은 주가를 가진 날은 해당 날에 파는게 제일 이득
            // 최대값이 앞 날에 존재한다면 해당 날로 최대값 위치를 변경하여 더 앞의 날들은
            // 해당 날에 주식을 판매한 것으로 처리
            for (int b = N-2; b >= 0; --b) {
                if (stock[max_idx] > stock[b]) {
                    max_profit = max_profit + stock[max_idx] - stock[b];
                }
                else if (stock[max_idx] < stock[b]) {
                    max_idx = b;
                }
            }
            cout << max_profit << "\n";
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
       // Solve();
       return 0;
    }

오늘의 일기

    회식은 쉽지 않다.. 음주 알고리즘 쉽지 않다..

    사회 생활 넘나 힘든 것

![image](https://github.com/user-attachments/assets/08535204-6207-42ad-87a2-6d0f7f9adc48)

