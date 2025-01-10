문제 사이트 : https://www.acmicpc.net/problem/17266

문제 설명 :

    인하대학교 후문 뒤쪽에는 어두운 굴다리가 있다.
    
    겁쟁이 상빈이는 길이 조금이라도 어둡다면 가지 않는다.
    
    따라서 굴다리로 가면 최단거리로 집까지 갈수 있지만, 
    
    굴다리는 어둡기 때문에 빙빙 돌아서 집으로 간다.
    
    안타깝게 여긴 인식이는 굴다리 모든 길 0~N을 밝히게 가로등을 설치해 달라고
    
    인천광역시에 민원을 넣었다.
    
    인천광역시에서 가로등을 설치할 개수 M과 각 가로등의 위치 x들의 결정을 끝냈다.
    
    그리고 각 가로등은 높이만큼 주위를 비출 수 있다.
    
    하지만 갑자기 예산이 부족해진 인천광역시는 가로등의 높이가 높을수록 
    
    가격이 비싸지기 때문에 최소한의 높이로 굴다리 모든 길 0~N을 밝히고자 한다.
    
    최소한의 예산이 들 높이를 구하자. 
    
    단 가로등은 모두 높이가 같아야 하고, 정수이다.
    
    다음 그림을 보자.

![image](https://github.com/user-attachments/assets/6a4060b6-201f-4744-8888-c1fd9760dfad)


    가로등의 높이가 H라면 왼쪽으로 H, 오른쪽으로 H만큼 주위를 비춘다.
    
    다음 그림은 예제1에 대한 설명이다.

![image](https://github.com/user-attachments/assets/32748f05-1164-49eb-baa7-95aca4ea14d3)


    가로등의 높이가 1일 경우 0~1사이의 길이 어둡기 때문에 상빈이는 지나가지 못한다.
    
    아래 그림처럼 높이가 2일 경우 0~5의 모든 길이 밝기 때문에 상빈이는 지나갈 수 있다.

![image](https://github.com/user-attachments/assets/b65c10fa-fa27-4506-a6a6-025eb825fbae)


입력

    첫 번째 줄에 굴다리의 길이 N 이 주어진다. (1 ≤ N ≤ 100,000)
    
    두 번째 줄에 가로등의 개수 M 이 주어진다. (1 ≤ M ≤ N)
    
    다음 줄에 M 개의 설치할 수 있는 가로등의 위치 x 가 주어진다. (0 ≤ x ≤ N)
    
    가로등의 위치 x는 오름차순으로 입력받으며 가로등의 위치는 중복되지 않으며, 정수이다.

출력

    굴다리의 길이 N을 모두 비추기 위한 가로등의 최소 높이를 출력한다.

예제 입력 1 

    5
    2
    2 4

예제 출력 1 

    2

예제 입력 2 

    3
    1
    0

예제 출력 2 

    3

풀이 알고리즘

    주어진 조건에 따라 굴다리 전체를 빛출 수 있는 가로등의 최소 높이를 구하는 문제

    '어두운 굴다리' 입니다.

    문제에서 조건이 매우 직관적으로 제시하였으며, 그림으로 설명되어 이해가 빠른 문제 였습니다.

    문제의 풀이 조건은 단 한가지로 아래와 같습니다.

    1) 가로등의 높이는 모든 길을 빛출 수 있는 높이 중, 최소값으로 세팅 해야한다.

    위 조건을 만족하기 위해서는 아래 두가지를 고려하여 구현하면 됩니다.

    1) 가로등 사이의 길을 모두 빛추기

    2) 시작 지점-첫번째 가로등 / 마지막 가로등-끝 지점 부분도 모두 빛추기

    조건 1의 경우 (가로등(1)-가로등(2)) / 2 가 필요한 가로등 높이입니다.

    그리고 가로등의 높이는 반드시 정수이므로, /2 했을 때 나머지가 있다면 빛추지 못하는 

    부분이 생기므로 해당 케이스에는 필요한 높이에 +1을 해줘야 합니다.

    조건 2는 간단하게 max(첫번째 가로등 위치,굴다리 길이 - 마지막 가로등 위치) 의 값을 사용하면

    값을 구할 수 있습니다.

    위의 내용들은 구현한 코드는 아래와 같습니다.

풀이 알고리즘

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    using namespace std;
    
    
    int N;
    int M;
    
    void Input_And_Solve() {
        cin >> N >> M;
        int first_lamp;
        cin >> first_lamp;
        int need_H = first_lamp; // 시작지점부터 첫번째 램프 사이의 거리
        int before_lamp = first_lamp;
        int last_lamp = 0;
        for (int a = 1; a < M; ++a) {
            int lamp;
            cin >> lamp;
            int now_need_H = lamp - before_lamp; // 각 램프 사이의 거리
            int plus_one = 0;
            if (now_need_H % 2) // 만약 램프 사이의 거리 /2 가 소수점이 있다면,
                plus_one = 1; // 높이는 정수이므로 +1 해주기
    
          // 현재까지 필요한 최대 높이와 지금 램프 사이의 거리로 확인한 필요한 높이 중 더 큰거
            need_H = max(need_H, now_need_H / 2 + plus_one);
            before_lamp = lamp;
            if (a == M - 1) { // 만약 마지막 램프라면 값 체크해주고
                last_lamp = lamp;
            }
        }
        // 마지막 램프와 굴다리 끝 거리 확인하여 현재까지 필요한 높이와 비교해주기
        need_H = max(need_H, N - last_lamp);
        cout << need_H; // 최대값 출력
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input_And_Solve();
    
    
        return 0;
    }

풀이 후기

    아.. 문제좀 잘 읽어보자... 가로등 높이는 '정수'다.

    그리고 불필요한 for문은 낭비를 발생시킨다...

    입력과 동시에 처리할 경우 메모리 2020KB / 입력을 받은 후 다시 접근하여 처리할 경우 2916KB

    고민해서 잘 구현하자

![image](https://github.com/user-attachments/assets/40e89ed6-b368-4009-adc4-0d013152a7ef)
