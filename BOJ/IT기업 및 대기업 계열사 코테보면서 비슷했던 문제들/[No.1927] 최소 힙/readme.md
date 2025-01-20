문제 사이트 :

문제 설명 :

![image](https://github.com/user-attachments/assets/e146166a-2b1f-433b-85e8-838027b720a3)
![image](https://github.com/user-attachments/assets/e3e375e5-db04-4fdb-9254-98c7910c6b8b)

풀이 알고리즘

    주어진 조건대로 값이 출력되는 코드를 구현하여 동작시키는 문제 '최소 힙' 입니다.

    문제에서 설명되어 있는 것 처럼 '최소 힙'이라고 불리는 자료구조를 사용하면 쉽게

    해결되는 문제로 우선순위 큐를 사용해 오름차순으로 값을 정렬하여 문제 해결이 가능 합니다.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    
    using namespace std;
    
    /*
        문제의 연산
        1) 배열에 x 추가
        2) 배열의 최소값 출력 및 배열에서 제거..
            -> 배열에 값이 없을 경우 0 출력
    
        그냥 우선순위 큐 오름차순으로 선언해서 쓰면 될 듯?
    */
    
    
    
    // 숫자가 오름차순으로 배치되는 우선순위 큐 선언
    priority_queue<int,vector<int>,greater<int>> que;
    int N;
    
    void Input_And_Solve() {
        cin >> N;
    
        for (int a = 0; a < N; ++a) {
            int command;
            cin >> command;
    
            if (command == 0) { // 최소값을 출력해야 할 때
                if (que.empty()) { // 큐가 비어있으면 0 출력
                    cout << "0\n";
                }
                else { // 큐에 숫자가 있으면 출력
                    cout << que.top() << "\n";
                    que.pop();
                }
            }
            else {
                que.push(command);
            }
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input_And_Solve();
        return 0;
    }

오늘의 일기

    오늘 자동차가 망가져따.. 오래 굴렸기 때무니다..

    수리비용이 백마넌이다... 정비소 아저씨들은 오늘 소고기를 먹겠지..?

    나는 오늘 저녁을 굶었따... 아저씨들이 먹으면....누군가는 굶어야지..

![image](https://github.com/user-attachments/assets/8efc65ac-314a-44d8-8551-79c9e1f37135)
