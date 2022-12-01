문제 사이트 : https://www.acmicpc.net/problem/13913

문제 :

    수빈이는 동생과 숨바꼭질을 하고 있다. 
    
    수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
    
    수빈이는 걷거나 순간이동을 할 수 있다. 
    
    만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
    
    순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

    수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력

    첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력

    첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

    둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

예제 입력 1 

    5 17

예제 출력 1 

    4
    5 10 9 18 17

예제 입력 2 

    5 17

예제 출력 2 

    4
    5 4 8 16 17


전체 코드

    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<queue>
    #include<stack>
    using namespace std;
    typedef pair<int, int>P;
    int n, k;
    queue<P>q;
    int visited[200001];
    int dx[] = { 1,-1,2 };

    void print(int cnt) {
        cout << cnt << "\n";
        stack<int>res;
        for (int i = k; ; i = visited[i]) {
            res.push(i);
            if (visited[i] == -1) {
                res.push(0);
                break;
            }
            if (visited[i] == -11)
                break;
        }
        while (!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
    }

    void bfs() {
        while (!q.empty()) {
            int now = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (now == k)
                print(cnt);
            for (int i = 0; i < 3; i++) {
                int next;
                if (i == 2)
                    next = now * 2;
                else
                    next = now + dx[i];
                if (next < 0 || next > 200000)
                    continue;
                if (visited[next])
                    continue;
                if (now == 0)
                    visited[next] = -1;
                else
                    visited[next] = now;
                q.push({ next, cnt + 1 });
            }
        }
    }

    int main() {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cin >> n >> k;
        q.push({ n,0 });
        visited[n] = -11;
        bfs();
        return 0;
    }
    
설명

    BFS를 이용하여 문제를 해결하였습니다.

    마지막에 경로를 출력하는 부분이 살짝 까다로웟는데 방문을 확인하는 배열에서
    다음으로 가야할 곳에 현재 번호를 입력하여 print함수에서 stack에 역으로 쌓아서
    순서대로 출력될 수 있게 작성하여 해결하였습니다.
