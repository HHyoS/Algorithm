문제 사이트 : https://www.acmicpc.net/problem/9663

문제 설명 : 

    N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

    N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

예제 입력 1 

    8

예제 출력 1 

    92

코드

    #include <iostream>
    using namespace std;

    int col[15];
    int n, total = 0;

    bool check(int level)
    {
        for(int i = 0; i < level; i++)
            if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)// 대각선이거나 같은 라인
                return false;
            //col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
        return true;
    }

    void nqueen(int x)
    {
        if(x == N)
            total++;
        else
        {
            for(int i = 0; i < N; i++)
            {
                col[x] = i; // 해당 위치에 퀸을 배치
                if(check(x)) // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
                    nqueen(x+1);
            }
        }
    }
    int main() {
        cin >> n;
        nqueen(0);
        cout << total;
    }
