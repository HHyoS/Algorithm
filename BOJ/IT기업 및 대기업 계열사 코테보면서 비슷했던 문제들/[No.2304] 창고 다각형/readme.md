문제 사이트 : https://www.acmicpc.net/problem/2304

문제 설명 :

![image](https://github.com/user-attachments/assets/37bd2990-e223-4e13-ba10-4f2eedf64ba2)
![image](https://github.com/user-attachments/assets/07c2d723-5e0a-452b-aed8-9deef9c5b7e1)

풀이 알고리즘

    특정 직사각형들의 좌표와 높이가 주어질 때, 오목한 부분이 생기지 않게 최소 넓이의

    사각형을 만들고, 해당 넓이를 출력하는 문제 '창고 다각형' 입니다.

    초기에 아이디어와 구현 부분에서 시간이 소요된 문제로 stack 풀이 유형의 문제와 유사하여

    풀이에 고민이 많이 된 문제였습니다.

    문제의 풀이 핵심 알고리즘은 단순하게 '최대 높이를 가진 좌표 기준을 왼쪽, 아래쪽 내려가기'

    입니다.

    해당 내용을 구현하기 위해서는 정말 간단하게 최고 높이 좌표를 찾은 후,

    시작 지점에서 해당 좌표까지 색칠을 칠하여 넓이 구하기, 끝 지점에서 해당 좌표까지

    색칠을 칠하며 넓이 구하기 = 정답 입니다.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    struct Node {
        int x;
        int y;
    };
    
    int N;
    
    int roof[1001];
    int max_h = 0;
    int max_x = 0;
    int start_x = 21e8;
    int end_x = -1;
    void Solve() {
    
        int area = 0;
        int max_roof = 0;
    
      // 시작 지점 부터 제일 높은 곳 까지 한칸씩 이동하면서 넓이 채워가기
        for (int a = start_x; a <= max_x; ++a) {
          // 더 높은곳이 있다면 더 큰 사각형을 채워야 하므로 값 기억
            max_roof = max(max_roof, roof[a]); 
            area += max_roof;
        }
    
        max_roof = 0;
      // 높은 지점부터 오른쪽 끝까지 탐색
        for (int a = end_x; a > max_x; --a) {
            max_roof = max(max_roof, roof[a]);
            area += max_roof;
        }
    
        cout << area;
        
    }
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            int x, y;
            cin >> x >> y;
            roof[x] = y;
            if (roof[x] > max_h) { // 최대 높이를 찾아서 해당 높이와 인덱스를 기록하자
                max_h = roof[x];
                max_x = x;
            }
          // 시작과 끝 지점도 기억하기
            start_x = min(start_x, x);
            end_x = max(end_x, x);
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

오늘의 일기

    개미는(뚠뚠) 오늘도(뚠뚠) 열심히 일을 하네(뚠 뚠)

![image](https://github.com/user-attachments/assets/420f09ef-efa7-4bd8-8ca8-714e345dc1e3)
