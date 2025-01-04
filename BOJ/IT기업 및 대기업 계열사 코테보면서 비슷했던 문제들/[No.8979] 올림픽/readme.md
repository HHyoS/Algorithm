문제 사이트 : https://www.acmicpc.net/problem/8979

문제 설명 :

    올림픽은 참가에 의의가 있기에 공식적으로는 국가간 순위를 정하지 않는다.
    
    그러나, 많은 사람들이 자신의 국가가 얼마나 잘 하는지에 관심이 많기 때문에 
    
    비공식적으로는 국가간 순위를 정하고 있다. 
    
    두 나라가 각각 얻은 금, 은, 동메달 수가 주어지면, 
    
    보통 다음 규칙을 따라 어느 나라가 더 잘했는지 결정한다.

        1. 금메달 수가 더 많은 나라
        2. 금메달 수가 같으면, 은메달 수가 더 많은 나라
        3. 금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라
        
    각 국가는 1부터 N 사이의 정수로 표현된다. 
    
    한 국가의 등수는 (자신보다 더 잘한 나라 수) + 1로 정의된다.
    
    만약 두 나라가 금, 은, 동메달 수가 모두 같다면 두 나라의 등수는 같다. 
    
    예를 들어, 1번 국가가 금메달 1개, 은메달 1개를 얻었고, 
    
    2번 국가와 3번 국가가 모두 은메달 1개를 얻었으며, 
    
    4번 국가는 메달을 얻지 못하였다면, 1번 국가가 1등,
    
    2번 국가와 3번 국가가 공동 2등, 4번 국가가 4등이 된다.
    
    이 경우 3등은 없다.
    
    각 국가의 금, 은, 동메달 정보를 입력받아서, 
    
    어느 국가가 몇 등을 했는지 알려주는 프로그램을 작성하시오.

입력

    입력의 첫 줄은 국가의 수 N(1 ≤ N ≤ 1,000)과 등수를 알고 싶은
    
    국가 K(1 ≤ K ≤ N)가 빈칸을 사이에 두고 주어진다.
    
    각 국가는 1부터 N 사이의 정수로 표현된다. 
    
    이후 N개의 각 줄에는 차례대로 각 국가를 나타내는 정수와 이 국가가
    
    얻은 금, 은, 동메달의 수가 빈칸을 사이에 두고 주어진다. 
    
    전체 메달 수의 총합은 1,000,000 이하이다.

출력

    출력은 단 한 줄이며, 입력받은 국가 K의 등수를 하나의 정수로 출력한다. 
    
    등수는 반드시 문제에서 정의된 방식을 따라야 한다.


예제 입력 1 

    4 3
    1 1 2 0
    2 0 1 0
    3 0 1 0
    4 0 0 1
    
예제 출력 1 

    2
    
예제 입력 2 

    4 2
    1 3 0 0
    3 0 0 2
    4 0 2 0
    2 0 2 0

예제 출력 2 

    2

풀이 알고리즘

    주어진 조건에 따라 나라들을 정렬하고, 입력에서 주어진 특정 국가의 순위를 출력하는 문제.

    간만에 풀어보는 정렬 문제..  operator 사용법을 잊어버려서 구글의 힘을 조금 빌려버렷다..

    operator만 사용할 줄 안다면 가볍게 풀이 시작 가능!

    1) 우선순위 큐에 문제의 조건대로 우선순위 설정(금..은..동..)

    2) 나라의 모든 정보를 입력한 뒤 모든 나라의 정보는 큐에 push

    3) 큐의 top부터 하나하나 빼면서 순의를 체크해주기

    4) 순위 체크시 금=은=동 메달의 개수가 같다면 같은 등수임
      따라서 랭킹=rank과 현재까지 나온 나라의 개수=cnt를 따로 관리하여 등수 매기기 진행

    4-1) 만약 큐에서 앞에 뽑힌 나라와 금=은=동 이라면 현재 나라의 등수는 rank, cnt +1

    4-2) 만약 앞에 뽑힌 나라와 다르다면 현재 나라의 등수는 cnt/ 이후 cnt+1,rank=cnt

    5) 뽑힌 나라가 등수를 알고싶은 나라라면 등수를 출력하면 문제 풀이 끝

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    using namespace std;
    
    struct Node {
        int idx;
        int gold;
        int silver;
        int bronze;
    };
    bool operator<(Node a, Node b) {
        if (a.gold == b.gold) {
            if (a.silver == b.silver) {
                return a.bronze < b.bronze;
            }
            return a.silver < b.silver;
        }
        return a.gold < b.gold;
    }
    
    priority_queue<Node> que;
    Node arr[1001];
    int answer[1001];
    int N;
    int target;
    
    bool Same_Or_Different(Node before, Node now) {
        if (before.gold == now.gold && before.silver == now.silver && before.bronze == now.bronze) {
            return 1;
        }
        return 0;
    }
    int Solve() {
        
        Node before = { 0,0,0,0 };
        int rank = 1;
        int cnt = 1;
        while (!que.empty()) {
            Node now = que.top();
            que.pop();
            if (Same_Or_Different(before, now)) {
                answer[now.idx] = rank;
            }
            else {
                answer[now.idx] = cnt;
                rank = cnt;
            }
            before = now;
            ++cnt;
    
            if (now.idx == target) {
                return answer[now.idx];
            }
        }
        
    }
    void Input() {
        cin >> N >> target;
        for (int a = 1; a <= N; ++a) {
            int idx, g, s, b;
            cin >> idx >> g >> s >> b;
            arr[a] = { idx, g, s, b };
            que.push(arr[a]);
            // cout test for debugging
            // cout << arr[a].idx << " " << arr[a].gold << " " << arr[a].silver << " " << arr[a].bronze << "\n";
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

풀이 후기

    머리로는 설계가 되는데 구현이 어렵다...

    나란사람 금붕어 였떤것...

    실버 문제 빨리 정리하고 골드 풀면서 알고리즘 근육 찢어야겠다.
    
![image](https://github.com/user-attachments/assets/5c044a75-876c-47c3-8411-6aaea8305c08)
