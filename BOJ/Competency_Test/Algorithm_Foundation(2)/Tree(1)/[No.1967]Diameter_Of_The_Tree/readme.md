문제 사이트 : https://www.acmicpc.net/problem/1967

문제 설명 : 

    트리(tree)는 사이클이 없는 무방향 그래프이다. 
    
    트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다.
    
    트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 
    
    가장 길게 늘어나는 경우가 있을 것이다. 
    
    이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다. 

![ttrrtrtr](https://user-images.githubusercontent.com/57944215/148732325-6f540f3c-b9a9-451d-894f-9c01c8998697.png)


    이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 
    
    정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.

    입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때,
    
    트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 
    
    아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.

![tttttt](https://user-images.githubusercontent.com/57944215/148732335-c923c518-642d-4e46-9793-2a7fe1ed9628.png)

    트리의 노드는 1부터 n까지 번호가 매겨져 있다.

입력

    파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. 간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

출력

    첫째 줄에 트리의 지름을 출력한다.

예제 입력 1 

    12
    1 2 3
    1 3 2
    2 4 5
    3 5 11
    3 6 9
    4 7 1
    4 8 7
    5 9 15
    5 10 4
    6 11 6
    6 12 10
    
예제 출력 1 

    45
    
풀이 알고리즘

    문제풀이에 필요한 아이디어는 [ https://blog.myungwoo.kr/112 ] 블로그에 있는 자료를 공부하였습니다.
    
    이 문제에서 말하는 트리의 지름은 가장 먼 두 정점 사이의 거리 혹은 가장 먼 두 정점을
    
    연결하는 경로를 의미합니다.
    
    지름을 구하기 위해서는 다음과 같은 단계를 거쳐야 합니다.
    
    1단계 : 임의의 원소 하나를 고른 뒤, 그 원소에서 가장 먼 원소를 찾는다.
    
    2단계 : 찾은 원소를 기준으로 가장 먼 노드를 찾는다.
    
    입니다.
    
    1단계에서 가장 먼 원소를 찾는다는 행위는 다음과 같은 상황입니다.
    
    1. [ 가장 먼 노드1] ------ [ 초기 선택 노드 ] ---------- [ 가장 먼 노드2 ]

    2. [ 초기 선택 노드 = 가장 먼 노드 1 ] -----------------------[ 가장 먼 노드2 ]
    
    1단계를 거치며 [ 초기 선택 노드 ] 에서 가장 먼 노드는
    
    찾고자 하는 [ 가장 먼 노드 1 or 2 ] 가 되게되고,
    
    그 노드에서 가장 먼노드를 찾아 가중치를 더하면 트리의 지름이 되게 됩니다.
    
[ 구 현 ] 

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <cstdio>
    #include <queue>
    #include <utility>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int N, M;
    vector<pair<int, int>> tree[10001];
    bool check[10001];
    int big = 0;
    int node;

    void dfs(int now, int sum) {
      if (sum > big) { // 현재까지의 합이 최대값 big보다 크다면
        big = sum; // big에 sum 입력 후
        node = now; // 가장 먼 노드를 now로 바꾸기.
      }
      for (int a = 0; a < tree[now].size(); ++a) {
        if (!check[tree[now][a].first]) { // 현재 노드에 연결된 노드가 아직 방문하지 않은 노드라면
          check[tree[now][a].first] = 1; // 방문 체크
          dfs(tree[now][a].first, sum + tree[now][a].second); // dfs탐색 실시
          check[tree[now][a].first] = 0; // 방문 해제
        } 
      }
    }
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> N;
      int parent, child, weight;
      for (int a = 0; a < N-1; ++a) {
        cin >> parent >> child >> weight;
        tree[parent].push_back({ child,weight });
        tree[child].push_back({ parent,weight }); // 트리의 양방향 가중치 입력
      }
      check[1] = 1; // 항상 존재하는 루트노드인 1에서 시작하면 가장 먼 노드 찾기.
      dfs(1, 0); 
      check[1] = 0;

      check[node] = 1;
      dfs(node, 0); // 가장 먼 노드인 node 기준으로 가장 먼 노드를 찾으며 가중치 더하기
      cout << big; // 트리의 지름 출력
      return 0;
    }
