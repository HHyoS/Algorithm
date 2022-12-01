문제 사이트 : https://www.acmicpc.net/problem/1655

풀이 환경 :  Visual studio 2019

설 명 : 

    백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다.
    
    백준이가 정수를 하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다. 
    
    만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

    예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다.
    
    백준이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력

    첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다.
    
    N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 
    
    그 다음 N줄에 걸쳐서 백준이가 외치는 정수가 차례대로 주어진다.
    
    정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력

    한 줄에 하나씩 N줄에 걸쳐 백준이의 동생이 말해야 하는 수를 순서대로 출력한다.

예제 입력 1 

    7
    1
    5
    2
    10
    -99
    7
    5
    
예제 출력 1 

    1
    1
    2
    2
    2
    2
    5
    
풀이 알고리즘

    숫자 N개가 N줄에 걸쳐 입력될 때, 매 입력마다 입력된 모든 숫자들 중 가운데값을 출력하는 문제입니다.
    
    문제를 풀이할 때, 매 입력마다 sort함수를 이용하여 문제를 풀려고 했으나 
    
    해당 방법 이용시 O(N^2) 의 시간복잡도로 인해 시간초과가 발생했습니다.
    
    그래서 (1) 오름차순 우선순위 큐 (2) 내림차순 우선순위 큐 를 선언하여 매 입력마다
    
    (1)과 (2)의 큐 사이즈가 같을 경우 (1)에 아닐경우 (2)에 push하고
    
    각 큐의 상단값을 비교하여 (2) 의 큐 top값보다 (1) 의 큐 top값이 클 경우
    
    (1)과 (2) 의 top값을 교환하여 항상 (1)의 top값이 입력값의 중간값이 되도록하고
    
    위의 단계들이 끝나면 big.top()을 출력하여 중간값을 계속 출력하여
    
    O(N log N) 의 방식으로 구현해 문제를 해결하였습니다.
    
 구 현
 
    #include <iostream>
    #include <string>
    #include <queue>
    #include <stack>
    #include <algorithm>
    using namespace std;

    int N;
    int temp;
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> N;
      priority_queue<int> big;
      priority_queue<int, vector<int>, greater<int>> small;
      for (int a = 0; a < N; ++a) {
        cin >> temp;
        if (big.size() == small.size())
          big.push(temp);
        else
          small.push(temp);

        if(!big.empty() && !small.empty() && big.top()> small.top()){
          int big_num, small_num;

          big_num = big.top();
          small_num = small.top();

          big.pop();
          small.pop();

          big.push(small_num);
          small.push(big_num);
        }
        cout << big.top() << "\n";
      }
      return 0;
    }

 
