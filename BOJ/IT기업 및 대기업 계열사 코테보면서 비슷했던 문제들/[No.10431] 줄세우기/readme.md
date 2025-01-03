문제 사이트 : https://www.acmicpc.net/problem/10431

문제 설명 :

    초등학교 선생님 강산이는 아이들을 데리고 단체로 어떤 일을 할 때 
    
    불편함이 없도록 새로 반에 배정받은 아이들에게 키 순서대로 번호를 부여한다. 
    
    번호를 부여할 땐 키가 가장 작은 아이가 1번, 그 다음이 2번, ... , 가장 큰 아이가 20번이 된다. 
    
    강산이네 반 아이들은 항상 20명이며, 
    
    다행히도 같은 키를 가진 학생은 한 명도 없어서 시간이 조금 지나면 아이들은 
    
    자기들의 번호를 인지하고 한 줄로 세우면 제대로 된 위치에 잘 서게 된다.
    
    하지만 매년 첫 며칠간 강산이와 강산이네 반 아이들은 자기가 키 순으로
    
    몇 번째인지 잘 알지 못해 아주 혼란스럽다. 
    
    자기 위치를 찾지 못하는 아이들을 위해 강산이는 특별한 방법을 생각해냈다.
    
    우선 아무나 한 명을 뽑아 줄의 맨 앞에 세운다. 
    
    그리고 그 다음부터는 학생이 한 명씩 줄의 맨 뒤에 서면서 다음 과정을 거친다.

    
    자기 앞에 자기보다 키가 큰 학생이 없다면 그냥 그 자리에 서고 차례가 끝난다/
    자기 앞에 자기보다 키가 큰 학생이 한 명 이상 있다면 그중 가장 앞에 있는 학생(A)의 바로 앞에 선다. 
    이때, A부터 그 뒤의 모든 학생들은 공간을 만들기 위해 한 발씩 뒤로 물러서게 된다.
    이 과정을 반복하면 결국 오름차순으로 줄을 설 수가 있다.
    
    아이들의 키가 주어지고, 어떤 순서로 아이들이 줄서기를 할 지 주어진다. 
    위의 방법을 마지막 학생까지 시행하여 줄서기가 끝났을 때 학생들이 총 몇 번 뒤로 물러서게 될까?

입력

    첫 줄에 테스트 케이스의 수 P (1 ≤ P ≤ 1000) 가 주어진다.

    각 테스트 케이스는 테스트 케이스 번호 T와 20개의 양의 정수가 공백으로 구분되어 주어진다.

    20개의 정수는 줄서기를 할 아이들의 키를 줄서기 차례의 순서대로 밀리미터 단위로 나타낸 것이다.

    모든 테스트 케이스는 독립적이다.

출력

    각각의 테스트 케이스에 대해 테스트 케이스의 번호와 학생들이 뒤로 물러난 걸음 수의 총합을 공백으로 구분하여 출력한다.

예제 입력 1 

    4
    1 900 901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919
    2 919 918 917 916 915 914 913 912 911 910 909 908 907 906 905 904 903 902 901 900
    3 901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919 900
    4 918 917 916 915 914 913 912 911 910 909 908 907 906 905 904 903 902 901 900 919
    
예제 출력 1 

    1 0
    2 190
    3 19
    4 171

풀이 알고리즘

    주어진 조건에 따라 학생들이 입력될 때, 학생들이 몇 번 이동하게 될지 시뮬레이션 하는 문제.

    학생의 수가 작고, TC의 갯수 또한 작아서 단순 for문으로 정렬을 진행하거나, 

    vector의 insert를 사용해도 시간 초과에 걸리지 않을 것을 보이는 문제이다.

    (최악의 경우 20*20*1000 = 20만 정도(?)이므로 시간 제한인 1초는 넉넉스하다.)

    하지만 insert나 for문으로 풀 경우 불필요한 시간 복잡도가 발생할 수 있음.

    그래서 양방향 링크드 리스트를 사용하여 구현하면 잠자고 있던 알고리즘력을 키우는데

    도움이 될 것으로 생각되어 풀이를 진행.

    풀이 알고리즘은 아래와 같음.

    1) 새로운 학생이 생겼을 때, 줄의 맨 앞부터 시작하여 현재 학생보다 키가 작은 학생 찾기.

    2) 찾았다면 해당 위치에 새로운 학생을 넣고, 앞 뒤의 학생 연결하기

    3) 새로운 학생부터 끝 학생까지 몇번 움직영 하는지 카운팅하기


구현 코드

    #include <iostream>
    #include <vector>
    using namespace std;
    
    // Node 구조체 정의
    struct Node {
        Node* front;
        Node* back;
        int value;
    
        Node(int val) : value(val), front(nullptr), back(nullptr) {}
    };
    
    int processLineup(const vector<int>& heights) {
        Node* head = new Node(heights[0]); // 첫 번째 학생을 줄의 맨 앞에 둔다.
        int totalBackwardMoves = 0;
    
        for (size_t i = 1; i < heights.size(); ++i) {
            Node* current = head;
            Node* newNode = new Node(heights[i]);
            bool inserted = false;
    
            // 현재 줄의 학생들 사이에서 위치 탐색
            while (current) {
                if (current->value > newNode->value) { // 현재 노드의 값보다 새로운 노드의 값잉 크다면
                    // 현재 노드 앞에 삽입
                    newNode->back = current;
                    newNode->front = current->front;
    
                    if (current->front) {
                        current->front->back = newNode;
                    }
                    else {
                        head = newNode; // 새로운 노드가 맨 앞이 됨
                    }
    
                    current->front = newNode;
                    inserted = true;
                    break;
                }
                current = current->back;
            }
    
            // 끝까지 갔지만 삽입되지 않았으면 맨 뒤에 추가
            if (!inserted) {
                current = head;
                while (current->back) current = current->back; // 맨 뒤로 이동
                current->back = newNode;
                newNode->front = current;
            }
    
            // 한 칸씩 뒤로 물러난 횟수 계산
            Node* tmp = newNode->back;
            while (tmp) {
                ++totalBackwardMoves;
                tmp = tmp->back;
            }
        }
    
        // 메모리 해제
        Node* current = head;
        while (current) {
            Node* next = current->back;
            delete current;
            current = next;
        }
    
        return totalBackwardMoves;
    }
    
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        int P;
        cin >> P;
    
        while (P--) {
            int T;
            cin >> T;
    
            vector<int> heights(20);
            for (int a = 0; a < 20; ++a) {
                cin >> heights[a];
            }
    
            int result = processLineup(heights);
            cout << T << " " << result << "\n";
        }
    
        return 0;
    }

풀이 후기

    사실 맨 뒤의 학생 위치를 기억하여 풀이를 진행하는 식으로 하려고 했는데,

    마지막 while문을 안쓰려고 했는데, 구현을 진행하다 보니 별도의 관리가 필요하여

    코드가 더 복잡해질 가능성이 보였다..

    좀더 고민했으면 효율적인 코드가 나왔을 텐데... 다음에는 설계를 더 잘해서 해야겠다리.

![image](https://github.com/user-attachments/assets/4ba1f132-dcfe-4431-a3be-536e7ace4da4)

