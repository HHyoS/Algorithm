문제 사이트 : https://www.acmicpc.net/problem/16964

문제 설명 :

    BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다. 
    
    스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다.
    
    오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.

    정점의 개수가 N이고, 정점에 1부터 N까지 번호가 매겨져있는 양방향 그래프가 있을 때,
    
    DFS 알고리즘은 다음과 같은 형태로 이루어져 있다.


    void dfs(int x) {
        if (check[x] == true) {
            return;
        }
        check[x] = true;
        // x를 방문
        for (int y : x와 인접한 정점) {
            if (check[y] == false) {
                dfs(y);
            }
        }
    }

    이 문제에서 시작 정점은 1이기 때문에 가장 처음에 호출하는 함수는 dfs(1)이다. DFS 방문 순서는 dfs함수에서 // x를 방문 이라고 적힌 곳에 도착한 정점 번호를 순서대로 나열한 것이다.

    트리가 주어졌을 때, 올바른 DFS 방문 순서인지 구해보자.

입력
    
    첫째 줄에 정점의 수 N(2 ≤ N ≤ 100,000)이 주어진다. 
    
    둘째 줄부터 N-1개의 줄에는 트리의 간선 정보가 주어진다. 
    
    마지막 줄에는 DFS 방문 순서가 주어진다. 
    
    DFS 방문 순서는 항상 N개의 정수로 이루어져 있으며, 1부터 N까지 자연수가 한 번씩 등장한다.

출력

    입력으로 주어진 DFS 방문 순서가 올바른 순서면 1, 아니면 0을 출력한다.

예제 입력 1 

    4
    1 2
    1 3
    2 4
    1 2 3 4

예제 출력 1 

    0

예제 입력 2 

    4
    1 2
    1 3
    2 4
    1 2 4 3

예제 출력 2 

    1

예제 입력 3 

    4
    1 2
    1 3
    2 4
    1 3 2 4

예제 출력 3 

    1
    
 풀이 알고리즘
 
    트리형태의 데이터와 방문순서가 주어질 때, dfs탐색을 했을 떄 주어진 방문순서와 동인한 dfs탐색이 가능한지를 판단하는 문제였습니다.
    
    8개월전에 이 문제를 풀었을 때는 일일이 데이터를 비교하여 옳은 탐색인지 확인하는 과정때문에 시간초과가 발생했었습니다.
    
    시간초과 발생이후 어떻게 풀어야할지 방향을 잡지못해 포기했었던 문제인데, custom sort 구현에 대해 공부하게되며 다시 문제를 풀게되었고
    
    해결할 수 있었습니다.
    
    제가 푼 문제의 풀이방법은 다음과 같습니다.
    
    데이털르 입력받고, 방문순서가 주어질 때, 주어진 방문순서를 우선순위로 보는 배열을 생성합니다.
    
    예를들어 1의 순서가 5번이면 배열을 선언하여 인덱스 1의 값을 5로 입력하여 1의 우선순위가 5번임음 표시합니다.
    
    이 배열을 사용하여 sort함수를 구현하고, 모든 노드의 자식노드들에 대하여 sort함수를 실행시켜 dfs탐색을 할 때 정해진 우선순위에 따라 탐색하도록 합니다,
    
    탐색했을 때, 정해진 순서에 맞지않는 탐색을 하게될경우 탐색을 종료하고 0을 출력하며, 끝까지 탐색했을 때 모든 순서가 맞다면 1을 출력하도록 하여
    
    문제를 해결하였습니다.
    
구 현

    #include<iostream>
    #include<vector>
    #include<queue>
    #include<algorithm>
    using namespace std;

    int N;
    int target;
    vector<vector<int>> v;
    int arr[100001];
    int start;
    bool ans;
    int idx=1;
    bool check[100001];
    bool comp(int a, int b) {
      if (arr[a] < arr[b]) return 1;
      if (arr[a] > arr[b]) return 0;

      return 1;
    }

    void dfs(int num) {
      if (idx == N) {
        ans = 1;
        return;
      }
      for (int a = 0; a < v[num].size(); ++a) {
        if (check[v[num][a]]) continue;
        if (arr[v[num][a]] != idx) return;

        ++idx;
        check[v[num][a]] = 1;
        dfs(v[num][a]);
      }
    }
    void solve() {
      check[1] = 1;
      dfs(1);

    }
    void input() {
      cin >> N;

      v.assign(N + 1, vector<int>());
      for (int a = 0; a < N - 1; ++a) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
      }

      for (int a = 0; a < N; ++a) {
        int tmp;
        cin >> tmp;
        if (a == 0) {
          start = tmp;
        }
        arr[tmp] = a;
      }

      for (int a = 1; a <= N; ++a) {
        if (v[a].size() > 1)
          sort(v[a].begin(), v[a].end(), comp);
      }


    }

    int main() {
      ios::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      input();
      solve();

      if (arr[1] != 0)
        cout << 0;
      else {
        if (ans == 0)
          cout << 0;
        else
          cout << 1;
      }
      return 0;
    }
    
 풀이 인증
 
 ![image](https://user-images.githubusercontent.com/57944215/187916670-3010818e-910a-4950-a10a-b3a616d659f5.png)
