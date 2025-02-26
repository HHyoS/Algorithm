문제 사이트 : https://www.acmicpc.net/problem/1863

문제 설명

![image](https://github.com/user-attachments/assets/9e0a7295-644c-41d8-ae94-60650e63ce72)
![image](https://github.com/user-attachments/assets/d38880fd-954d-4d1a-aeba-5df0745da64e)

풀이 알고리즘

    빌딩의 그림자에 해당하는 값이 주어질 때, 그림자를 바탕으로 빌딩이 최소 몇 개 있는지
    유추하는 문제 '스카이라인 쉬운거' 입니다.

    입력값의 개수 n = 5만, x = 100만, y = 50만으로 배열을 사용하거나 체크하는 방식으로 풀이를
    진행하면 메모리 초과가 발생할 수 있는 문제입니다.

    문제에서 빌딩의 구분을 할 수 있는 방법은 오직 높이 밖에 없고, 아무리 멀리 떨어져
    있어도 이전에 존재했던 특정 높이를 유지하고 있다면 하나의 빌딩이 있다고 가정할 수 있습니다.

    그래서 제가 생각한 풀이는 다음과 같습니다.

    1) N개의 입력값에 대해 stack을 사용하여 높이의 변곡점을 기록한다.
    2-1) 다음 변곡점이 나보다 높은 곳이면 stack에 push한다.
    2-2-1) 다음 변곡점이 나보다 낮은 곳 이라면 stack의 top 값이 변곡점 높이보다 낮을 때가지 pop한다
    pop 연산은 하나의 빌딩을 의미하는 연산으로, 한번 수행할 때 마다 빌딩의 개수 +1
    2-2-2) 2-2-1 연산이 종료 된 이후 변곡점이 stack top과 동일한 값 이라면-> 특정 빌딩의 높이 유지 중
    스킵하고, 0이 아니고 top 값과 다르다면 stack에 push한다
     -> 0은 빌딩이 될 수 없음
    3) 위의 과정을 완료한 후 stack의 값이 남아있다면 모든 값을 pop하며 빌딩 개수 +1
    -> stack의 값이 남아있다는 것은 변곡점 마지막 값이 모든 빌딩을 pop 할 만 큼 작지 않았다는 의미로
    수동으로 모든 빌딩 높이를 pop 해주어야 함

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    using namespace std;
    
    int N;
    stack<int> st;
    struct Node {
        int x;
        int y;
    };
    
    Node building[50001];
    
    bool ssort(Node a, Node b) {
        return a.x < b.x;
    }
    void Solve() {
        int ans = 0;
        for (int a = 0; a < N; ++a) {
            if (st.empty()) { // stack이 비어있고, 변곡점 높이가 0이 아니라면 push
                if (building[a].y != 0) {
                    st.push(building[a].y);
                }
            }
            else {
                // stack의 top 값보다 변곡점 높이가 높을 경우 push!
                if (st.top() < building[a].y) {
                    st.push(building[a].y);
                }
                else {
                    // top보다 낮은 높이라면 stack에서 해당 값보다 낮은 값이 나올 떄 까지 pop
                    while (!st.empty()) { 
                        if (st.top() > building[a].y) {
                            st.pop();
                            ++ans;
                        }
                        else {
                            break;
                        }
                    }
    
                    // stack이 비어있지 않고, stack의 top 값과 다르다면 push!
                    if (!st.empty() && building[a].y != st.top()) {
                        st.push(building[a].y);
                    }
                    else if (st.empty()) { // stack이 비어있다면 그냥 넣어도 되지만
                        if (building[a].y != 0) { // 0은 빌딩이 될 수 없으므로 넣지 말자
                            st.push(building[a].y);
                        }
                    }
    
                }
            }
        }
    
        // 모든 탐색이 종료됬지만 stack에 값이 남아있다면 임의로 빼주자
        while (!st.empty()) {
            st.pop();
            ++ans;
        }
        cout << ans;
    }
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            int tx, ty;
            cin >> tx >> ty;
            building[a] = { tx,ty };
        }
        // 입력값 장난질 방지용
        sort(building, building + N, ssort);
        Solve();
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        return 0;
    }

풀이 후기

    야근시러

![image](https://github.com/user-attachments/assets/0bd8d071-02f9-4c01-a6e0-e34596583235)
