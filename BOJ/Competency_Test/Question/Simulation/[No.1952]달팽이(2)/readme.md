문제 사이트 : https://www.acmicpc.net/problem/1952

문제 설명 :

    M줄 N칸으로 되어 있는 표 위에, 달팽이 모양으로 선을 그리려고 한다.
	 	 
 	 	 
![11](https://user-images.githubusercontent.com/57944215/151530398-84e7289e-edce-42e1-b627-08986421a80d.GIF)

    위의 그림은 M=5, N=3의 예이다. 이제 표의 왼쪽 위 칸(ㅇ)에서 시작하여, 오른쪽으로 선을 그려 나간다. 
    
    표의 바깥 또는 이미 그려진 칸에 닿아서 더 이상 이동할 수 없게 되면, 시계방향으로 선을 꺾어서 그려나간다.

![22](https://user-images.githubusercontent.com/57944215/151530485-5743428d-87a8-44c1-8e5b-13ba5d310ab3.GIF)

    위의 표는 선을 그려 나간 모양을 나타낸 것이다. 선이 꺾어진 부분은 대각선으로 나타내었다. 표의 모든 칸이 채워질 때까지, 선을 몇 번 꺾게 될까?

입력

    첫째 줄에 M과 N이 빈 칸을 사이에 두고 주어진다. (2 ≤ M, N ≤ 100)

출력

    첫째 줄에 표의 모든 칸이 채워질 때까지 선이 꺾어지는 횟수를 출력한다.

예제 입력 1 

    5 3

예제 출력 1 

    5
    
[ 풀이 알고리즘 ]

    주어진 규칙에 따라 시뮬레이션이 끝날 때 선이 꺽인 횟수를 출력하는 문제였습니다.
    
    위 문제에서 요구하는 답을 찾기위해 그림을 그려본 결과, 이 시뮬레이션의 답이 원하는 값의
    
    규칙이 있었습니다.
    
    N과 M이 주어졌을 때 선이 꺽이기까지 움직이는 횟수는 다음과 같습니다.
    
    M -> N-1 -> M-1 -> N-2 -> M-2 ... 0
    
    M과 N 하나라도 0이되면 시뮬레이션이 종료되고, M과 N이 한번씩 등장할때마다 횟수가 1회 증가됩니다.
    
    만약 M = 4, N = 3이라면
    
    4 -> 2 -> 3 -> 1 -> 2 -> 0 으로 5회 꺽이고, 6번쨰 꺽이는 경우에서 시뮬레이션이 종료됩니다.
    
    그러므로 (N,M-1) 을 이용하여 위의 알고리즘대로 시뮬레이션을 돌리고 1를 빼면 위 문제의 답이 됩니다.
    
[ 구 현 ]
    
    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>
    #include <vector>

    using namespace std;
    int mov[2];
    int main(void)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        //freopen("Input.txt", "r", stdin);
        int answer = 0;
        cin >> mov[0] >> mov[1];
        mov[0] -= 1; // M-1 시키기.
        while (1) {
            if (mov[1] != 0) { // M부터 시작하는 시뮬레이션 시작
                ++answer;
                mov[1] -= 1;  // M-1
            }
            else
                break;

            if (mov[0] != 0) { // N 시뮬레이션
                ++answer;
                mov[0] -= 1; // N-1
            }
            else
                break;
        } 
        cout << answer-1; // 모든 시뮬레이션이 종료되었다면 1을 
        return 0;
    }
