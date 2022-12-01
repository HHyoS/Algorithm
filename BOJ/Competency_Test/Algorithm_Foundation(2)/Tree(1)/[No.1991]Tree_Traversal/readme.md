문제 사이트 : https://www.acmicpc.net/problem/1991

문제 설명 : 

    이진 트리를 입력받아 전위 순회(preorder traversal),
    
    중위 순회(inorder traversal), 
    
    후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

![trtr](https://user-images.githubusercontent.com/57944215/148215579-78a093d4-1041-4c65-83fd-88e382b52164.png)

예를 들어 위와 같은 이진 트리가 입력되면,

    전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
    
    중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
    
    후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
    
    가 된다.

입력

    첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 
    
    둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
    
    노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
    
    자식 노드가 없는 경우에는 .으로 표현한다.

출력

    첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

예제 입력 1 

    7
    A B C
    B D .
    C E F
    E . .
    F . G
    D . .
    G . .

예제 출력 1 

    ABDCEFG
    DBAECFG
    DBEGFCA
    
풀이 알고리즘 

    주어진 입력값을 바탕으로 알파벳을 트리 노드의 데이터로 하는 이진트리를 작성하고
    
    (1) 전위 순회 (2) 중위 순회 (3) 후위 순회
    
    순으로 트리를 순회한 결과를 출력하는 문제였습니다.
    
    이 문제를 풀이할 때 생각해야했던 점은, 주어진 데이터를 바탕으로 트리를 구현하는것이였습니다.
    
    데이터가 알파뱃으로 주어지기떄문에 트리를 만드는 방법이 어려웠는데
    
    여러 방법을 찾아보다 'A' 를 0, 'Z' = 26 으로 생각하여 tree[27][2] 의 배열을 생성하였고,
    
    tree[x][0] = 데이터가 x인 노드의 왼쪽노드, tree[x][1] = 데이터가 x인 노드의 오른쪽 노드
    
    로 생각하여 트리를 작성하였습니다.
    
    그 이후 재귀문을 사용하여 전위, 중위 , 후위 순회의 동작을 구현하여 문제를 해결하였습니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>


    int tree[27][2];
    using namespace std;
    int N;
    
    void inorder(int num) { // 중위 순회
      if (num == -1)
        return;
      else {
        char data = num+'A';
        inorder(tree[num][0]); // 왼쪽 노드부터 탐색하고
        cout << data; // 왼쪽노드 탐색이 끝나면 데이터 출력 후
        inorder(tree[num][1]); // 오른쪽 노드 탐색
      }

    }
    
    void preorder(int num) { // 전위 순회
      if (num == -1)
        return;
      else {
        char data = num + 'A';
        cout << data; // 데이터부터 출력하고
        preorder(tree[num][0]); // 왼쪽 노드 탐색
        preorder(tree[num][1]); // 오른쪽 노드 탐색
      }
    }
    
    void postorder(int num) {//후위 순회
      if (num == -1)
        return;
      else {
        char data = num + 'A';
        postorder(tree[num][0]);// 왼쪽 노드 탐색
        postorder(tree[num][1]);// 오른쪽 노드 탐색
        cout << data; // 데이터 출력
      }
    }
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

    //	freopen("Input.txt", "r", stdin);
      cin >> N;
      char dat, node_1, node_2; 
      for (int a = 0; a < 27; ++a) { // 재귀문 탈출조건을 위한 초기값 세팅으로
        tree[a][0] = -1; // 재귀문에서 -1을 만나면 재귀를 종료하기위한 세팅.
        tree[a][1] = -1;
      }
      for (int a = 0; a < N; ++a) {
        cin >> dat >> node_1 >> node_2;
        if (node_1 != '.') { // 왼쪽 노드
          tree[dat - 'A'][0] = node_1 - 'A'; // 숫자값으로 데이터를 저장하기위해 
        } // 'A' = 0, 'Z' = 26 으로 생각하여 배열을 설정 및 데이터를 입력
        if (node_2 != '.') {// 오른쪽 노드
          tree[dat - 'A'][1] = node_2 - 'A';
        }
      }
      preorder(0); // 전위 순회
      cout << "\n";
      inorder(0);// 중위 순회
      cout << "\n";
      postorder(0);// 위 순회
      return 0;
    }

    
