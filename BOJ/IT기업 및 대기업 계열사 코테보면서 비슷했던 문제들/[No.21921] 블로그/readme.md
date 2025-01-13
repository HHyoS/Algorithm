문제 사이트 : https://www.acmicpc.net/problem/21921

문제 설명 :

    찬솔이는 블로그를 시작한 지 벌써 N일이 지났다.
    
    요즘 바빠서 관리를 못 했다가 방문 기록을 봤더니 벌써 누적 방문 수가 6만을 넘었다.

![image](https://github.com/user-attachments/assets/1156769e-4484-41a6-8e4b-7e77f2c05e7a)

    찬솔이는 X일 동안 가장 많이 들어온 방문자 수와 그 기간들을 알고 싶다.
    
    찬솔이를 대신해서 X일 동안 가장 많이 들어온 방문자 수와 기간이
    
    몇 개 있는지 구해주자.

입력

    첫째 줄에 블로그를 시작하고 지난 일수 N와 X가 공백으로 구분되어 주어진다.

    둘째 줄에는 블로그 시작 1일차부터  N일차까지 하루 방문자 수가 공백으로 
    
    구분되어 주어진다.

출력

    첫째 줄에 X일 동안 가장 많이 들어온 방문자 수를 출력한다.
    
    만약 최대 방문자 수가 0명이라면 SAD를 출력한다.
    
    만약 최대 방문자 수가 0명이 아닌 경우 둘째 줄에 기간이 몇 개 있는지 출력한다.

제한

    1 <= X <= N <= 250,000
    0 <= 방문자 수 <= 8,000
 
예제 입력 1 

    5 2
    1 4 2 5 1

예제 출력 1 

    7
    1

예제 입력 2 

    7 5
    1 1 1 1 1 5 1

예제 출력 2 

    9
    2

예제 입력 3 

    5 3
    0 0 0 0 0

예제 출력 3 
    
    SAD

풀이 알고리즘

    N일간의 블로그 방문자수를 입력값으로 주어졌을 때, 연속된 X일간 누적 밤문자수가

    가장 큰 날을 찾아서 1) 누적 방문자 수 2) 누적 방문자 수가 가장 큰 날과 동일한

    기간 개수 두가지를 출력하는 문제 '블로그' 입니다.

    입력값이 25만개 이므로, 단순하게 for문을 돌린다면 시간초과가 겨울왕국처럼

    문을 열고 맞이해주기 때문에 시간복잡도를 생각해서 log(N)내에 정리해야하는 문제였습니다.

    위와 같은 문제의 경우 누적합 이라는 개념으로 풀이하면 되는 문제로

    X일의 시작지점 A,와 끝 지점 B를 이용하여 한 칸씩 이동하며 X일의 누적합을 최소한의

    연산으로 구하는 방법을 사용하면 됩니다.

    ex) X일간의 누적합은 A ~ A+X-1 인데, X+1일간의 누적합은 A+1 ~ A+X 임.

    A + (A+1) + (A+2) ... (A+X-1) = X 누적합

    (A+1) + (A+2) + (A+3) + ... (A+X) = X+1 누적합

    X의 누적 합에서 A를 빼고, A+X 를 더하면 X+1의 누적합이 됨.

    따라서 한칸씩 움직이면서 왼쪽을 빼고 새로운 오른쪽을 더하면 누적합 완성~

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    using namespace std;
    
    
    /*
        블로그를 운영하는 주인장 A가 있다.
        A는 N일동안 블로그를 운영했는데, 이중 연속된 X일 간 가장 많은 누적 방문자가 몇명인지
        찾아보자
    
        -> 그냥 읽자마자 슬라이딩 윈도우
        오늘은 운수 좋은 날
    
        N * 방문자수 = 최대 20억 이므로 int만 써도 가능
    */
    struct Node {
        int maxi;
        int maxi_cnt;
    };
    int blog[250001]; // 블로그 방문 인원 배열
    int N, X;
    
    Node Solve() {
        int maxi = 0;
        int total = 0;
        int left = 0;
    
        for (int a = 0; a < X; ++a) {
            total += blog[a]; // X일까지 누적 방문자 수 
        }
    
        maxi = total; // 일단 최대값
    
        int cnt = 1;
        for (int a = X; a < N; ++a) {
    
            // 한칸씩 오른쪽으로 옮기면서 누적합 구하기
            total -= (blog[left++]);
            total += (blog[a]);
    
            // 현 누적합이 이미 있던 최대 값 이라면 구간 개수 +1
            if (maxi == total) {
                cnt++;
            }
    
            // 현 누적합이 더 큰 값이라면 최대 값으로 등록 해주기
            else if (maxi < total) {
                maxi = total;
                cnt = 1;
            }
        }
        // 정답 return
        return { maxi,cnt };
    }
    void Input() {
        cin >> N >> X;
        for (int a = 0; a < N; ++a) {
            cin >> blog[a];
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Node answer = Solve();
    
        // 예외처리
        if (answer.maxi == 0) {
            cout << "SAD";
        }
        else {
            cout << answer.maxi << "\n" << answer.maxi_cnt;
        }
    
        return 0;
    }

풀이 후기

    문제를 보자마자 누적합인걸 알아버린나... 멋져

    너무 빨리 풀어서 조금 그렇지만 갓생을 살기 위해서 내 뇌가 발버둥 친 결과이므로

    만-족

    이제 책 읽어야징
    
![image](https://github.com/user-attachments/assets/2c51470e-6ad8-4272-9d54-395d8d7f35d4)
