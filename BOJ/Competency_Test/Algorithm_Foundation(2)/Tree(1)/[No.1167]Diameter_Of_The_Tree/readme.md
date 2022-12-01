문제 사이트 : https://www.acmicpc.net/problem/1167

문제 설명 : 

    트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.
    
    트리의 지름을 구하는 프로그램을 작성하시오.

입력

    트리가 입력으로 주어진다. 
    
    먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)둘째 
    
    줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 
    
    정점 번호는 1부터 V까지 매겨져 있다.

    먼저 정점 번호가 주어지고, 
    
    이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
    
    하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 
    
    예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고,
    
    정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 
    
    각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력

    첫째 줄에 트리의 지름을 출력한다.

예제 입력 1 

    5
    1 3 2 -1
    2 4 4 -1
    3 1 2 4 3 -1
    4 2 4 3 3 5 6 -1
    5 4 6 -1

예제 출력 1 

    11
    
풀이 알고리즘
    
    이전에 풀었던 [No.1967] 트리의 지름 - https://url.kr/z1cseu 문제와 유사한 문제였습니다.
    
    1967번과 다른점은 트리의 입력값이 순서대로 주어진다는 점 이였습니다.
    
    그래서 입력방식에 따라서 트리의 노드들을 입력하는 방법만을 수정한 뒤
    
    트리의 지름을 구하는 알고리즘은 그대로 사용해보았고, 특이사항없이 문제는 해결되었습니다.
    
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
    vector<pair<int, int>> tree[100001];
    bool check[100001];
    int big = 0;
    int node;
    void dfs(int now, int sum) {
      if (sum > big) {
        big = sum;
        node = now;
      }
      for (int a = 0; a < tree[now].size(); ++a) {
        if (!check[tree[now][a].first]) {
          check[tree[now][a].first] = 1;
          dfs(tree[now][a].first, sum + tree[now][a].second);
          check[tree[now][a].first] = 0;
        }
      }
    }
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      freopen("Input.txt", "r", stdin);

      cin >> N;
      int node_1, node_2 = 0, weight;
      for (int a = 1; a <= N; ++a) { // 입력값에 맞추어 트리 입력 수정
        cin >> node_1;
        while (node_2 != -1) {
          cin >> node_2;
          if (node_2 == -1) {
            node_2 = 0;
            break;
          }
          cin >> weight;
          tree[node_1].push_back({ node_2,weight });
        }
      }
      check[1] = 1;
      dfs(1, 0);
      check[1] = 0;

      check[node] = 1;
      dfs(node, 0);
      cout << big;
      return 0;
    }
    
