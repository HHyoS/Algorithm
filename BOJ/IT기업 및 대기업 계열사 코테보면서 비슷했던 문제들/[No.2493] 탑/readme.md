문제 사이트 : https://www.acmicpc.net/problem/2493

문제 설명

![image](https://github.com/user-attachments/assets/8a9c5c02-049a-4d0e-83b2-6ae8366f6a97)
![image](https://github.com/user-attachments/assets/c1dfdd7a-9744-4a89-b2d5-40d142767d00)

풀이 알고리즘

    신호를 왼쪽으로 발사하며 자신보다 크거나 높은 높이를 가진 탑을 만나면 신호가 멈추는
    
    탑이 N개 입력으로 주어진다.
    
    해당 정보를 바탕으로 1-N 까지 탑이 자신이 쏜 신호가 어느 탑에서 멈췄는지 출력하는 문제
    
    "탑" 입니다.
    
    N의 개수가 50만개로 2중 for문 이상이 될 경우 반드시 시간초과가 발생하는 문제로, 각 탑마다

    탐색을 하여 자신보다 큰 위치의 탑을 찾을 경우 해결할 수 없었습니다.

    위 문제를 풀이하기 위해 제가 생각한 아이디어는 역방향 stack 입니다.

    역방향 stack 풀이 순서는 아래와 같습니다.

    0) 가장 마지막 탑의 정보(높이,위치)를 stack에 push

    1) (N-1)-(1) 탑까지 역방향 탐색을 하며 아래 내용 반복
    1-1) stack.top()의 탑 정보(높이)와 현재 위치 탑의 높이를 비교
    1-1-1) 현재 탑의 높의가 stack.top() 높이 보다 높을 경우 stack.top()의 정보(위치)는
    현재 탑의 위치에서 신호가 멈춤
    1-1-2) stack 상단 높이 값이 현재 탑의 높이보다 작거나 stack이 비어질 때 까지 반복
    1-2) 현재 탑의 정보를 stack에 push
    1-3) (1-1)-(1-2)를 1번 위치까지 반복

    저는 stack 풀이법을 생각하며 풀이 진행하여 위와 두 개의 50만 배열을 생성하였지만
                                            (1) 탑의 정보 배열 (2) 정답 출력 배열

    왼쪽부터 탐색을 진행할 경우 별도의 배열 선언 없이 아래의 프로세스를 진행하면 됩니다.

    0) 탐색은 1번부터 N번까지 정방향으로 진행
    1) 1번 위치의 값 stack에 push
    2) stack 상단 높이 값과 다음 위치의 높이 비교
    2-1) stack 상단 값이 다음 위치의 높이보다 작을 때 까지 stack 상단 값 pop
    2-2) stack에 값이 남아 있다면, 다음 위치의 신호를 받을 수 있는 탑이 있는 것 이므로
    stack 상단 값 위치 출력(현재 위치 탑의 신호를 받을 수 있는 위치)
    2-3) stack에 값이 없다면 다음 위치의 신호를 받을 수 있는 탑이 좌측에 없는 것 이므로
    0 출력

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    struct Node {
        int idx;
        int h;
    };
    
    int top[500010]; // 탑 정보 배열
    int ans[500010]; // 정답 출력 배열
    stack<Node> st;
    int N;
    void Solve() {
        for (int a = N; a >= 1; --a) {
            if (a == N) { // a가 오른쪽 끝 위치 일 경우 그냥 push
                st.push({ a,top[a] });
            }
            else { // 아니라면 stack의 상단 값과 현 위치의 높이를 비교하여
            // stack 상단의 신호 도달 위치가 현 위치 탑임을 배열에 저장
                while (!st.empty() && st.top().h <= top[a]) {
                    Node nNode = st.top();
                    st.pop();
                    ans[nNode.idx] = a;
                }
                // 이후 현재 탑 위치 정보 stack 저장
                st.push({ a,top[a] });
            }
        }
        // 정답 출력
        for (int a = 1; a <= N; ++a) {
            cout << ans[a] << " ";
        }
    }
    void Input() {
        cin >> N;
        // 탑 정보 입력
        for (int a = 1; a <= N; ++a) {
            cin >> top[a];
        }
    
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        Solve();
        return 0;
    }

풀이 코드

    코드 효율적으로 짜는 사람은 진짜 부럽다
    나도 노력해야지

![image](https://github.com/user-attachments/assets/378673a0-cfc0-4296-886a-5fe3e95cd250)
