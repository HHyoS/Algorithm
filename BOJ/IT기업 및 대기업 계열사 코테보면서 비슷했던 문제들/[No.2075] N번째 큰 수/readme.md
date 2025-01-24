문제 사이트 : https://www.acmicpc.net/problem/2075

문제 설명 :

![image](https://github.com/user-attachments/assets/9b2f569b-3e54-473d-b618-264f0c07ccc3)
![image](https://github.com/user-attachments/assets/37316bbf-b7ca-4d45-8b64-3e17f15ef8f9)

풀이 알고리즘

    문제의 설명이 아무 의미없는 문제 'N번째 큰 수' 입니다.

    문제의 조건인 '모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것' 을 이용하려고 했으나

    아무 의미 없는 설명이였고, 적절한 sort나 priority_queue를 사용하면 풀 수 있는 문제 였습니다.

    문제의 풀이 조건인 N번쨰 큰수를 찾으면 되므로 배열을 선언한 후 데이터를 넣어 1) sort하거나

    2) priority_queue를 구현하여 N번째 큰 수를 출력하도록 구현하면 됩니다.

    1)의 경우 배열의 정해진 크기 만큼만 할당 되지만, vector는 사이즈가 늘어날 때 마다 실제 사용

    크기보다 더 큰 사이즈의 메모리를 미리 준비하므로 메모리 초과가 발생할 수 있으니 반드시 

    배열로 선언하여 풀이가 필요합니다.

    2)의 경우에도 단순하게 push push 하면 메모리가 초과가 발생하고, 데이터를 넣을 때 마다 

    내부적으로 sort가 발생하기 때문에 내부 데이터를 최소로 유지해야 합니다.

    priority_queue안에 데이터를 일단 넣고, N보다 커지면(N+1번쨰 숫자까지 queue안에 있으면)

    queue의 맨 앞의 값(가장 작은 값)을 pop 해주어 queue의 크기를 N으로 유지합니다.

    모든 입력에 대해 처리하고나면 queue의 가장 위(top)에 존재하는 값이 N번째 큰 수 입니다.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    
    int N;
    priority_queue<int, vector<int>, greater<int>> que;
    void Solve() {
    
        
    }
    void Input() {
        cin >> N;
        int maxi = N * N;
        for (int a = 0; a < maxi; ++a) {
            int temp;
            cin >> temp;
            que.push(temp);
    
            if (que.size() > N) { // 위에서 N번째 수만 알면 되므로 일단 넣고
                que.pop(); // que 사이즈가 N보다 크면 가장 작은수(맨 앞의 수)를 pop
            }
        }
        cout << que.top();
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
      //  Solve();
        return 0;
    }

풀이 후기

    아니 딱봐도 sort인데 문제 설명 낚시 뭔데~

![image](https://github.com/user-attachments/assets/c218d76c-c431-43f8-9277-a0b9f5c70a11)
