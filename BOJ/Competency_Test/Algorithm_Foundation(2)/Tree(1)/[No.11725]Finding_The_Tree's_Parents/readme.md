문제 사이트 : https://www.acmicpc.net/problem/11725

문제 설명 :

루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

예제 입력 1 

    7
    1 6
    6 3
    3 5
    4 1
    2 4
    4 7
    
예제 출력 1 

    4
    6
    1
    3
    1
    4
    
예제 입력 2 

    12
    1 2
    1 3
    2 4
    3 5
    3 6
    4 7
    4 8
    5 9
    5 10
    6 11
    6 12
    
예제 출력 2 

    1
    1
    2
    3
    3
    4
    4
    5
    5
    6
    6
    
풀이 알고리즘

    주어진 노드들의 연결 정보를 바탕으로 트리를 구성하고, 각 노드의 부모노드를 출력하는 문제였습니다.
    
    문제에서 1번 노드가 루트노드라는 정보가 주어졌으므로, 입력된 정보를 바탕으로 트리를 구성하고
    
    루트노드에서 시작하여 단말노드까지 탐색하여 부모노드를 찾는 방식으로 문제를 해결하였습니다.
    
    하지만 하나의 입력에 대하여 부모노드를 찾는것이 아닌 최대 10만개의 노드들에 대햐여
    
    부모노드를 찾아야하기 떄문에 모든 노드들에 대하여 부모노드를 찾는 연산을 한번 실행하며
    
    부모노드를 저장하는 배열을 이용하여 부모노드를 관리하고, 모든 연산이 종료한 뒤
    
    for문을 이용하여 부모노드를 찾는 방식으로 문제를 해결하였습니다.
    
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
    vector<int> tree[100001];
    int parent[100001];
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    //	freopen("Input.txt", "r", stdin);

      cin >> N;
      int nd_1, nd_2;
      for (int a = 0; a < N; ++a) {// 트리 구성하기
        cin >> nd_1 >> nd_2;
        tree[nd_1].push_back(nd_2);
        tree[nd_2].push_back(nd_1); 
      }
      
      parent[1] = -1; // 노드 1번은 루트노드이므로 부모노드를 찾을 필요가 없으므로 -1 입력
      queue<int> que; // 
      que.push(1); // 루트노드인 1부터 시작
      while (!que.empty()) {
        int size = que.size();
        for (int a = 0; a < size; ++a) { 
          int idx = que.front();
          que.pop();
          for (int b = 0; b < tree[idx].size(); ++b) { // 연결된 노드들에 대하여 
            if (!parent[tree[idx][b]]) { // 연결된 노드의 부모 정보가 입력되지 않았다면 = 아직 방문 하지 않았다면~
              parent[tree[idx][b]] = idx; // 현재 노드가 연결된 노드의 부모임을 입력하고
              que.push(tree[idx][b]); // 연결된 노드를 다음 탐색을 위해 queue에 push
            }
          }
        }
      }
      for (int a = 2; a <= N; ++a) {
        cout << parent[a] << "\n";
      }
      return 0;
    }
    
    
