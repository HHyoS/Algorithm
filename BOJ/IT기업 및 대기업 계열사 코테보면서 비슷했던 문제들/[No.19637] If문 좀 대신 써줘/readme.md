문제 사이트 : 

![image](https://github.com/user-attachments/assets/cf63d92a-a946-42f2-8df4-f2d9cde5d08b)
![image](https://github.com/user-attachments/assets/4ecf2ef4-6fd6-4e8b-8ccd-e6849de6b1e4)
![image](https://github.com/user-attachments/assets/6c76f71d-4359-4a6b-a28a-2778d3a851c7)

풀이 알고리즘

    입력값으로 "전투력"에 따른 칭호 정보와 임의의 캐릭터의 전투력이 주어질 때

    각 캐릭터들의 칭호를 출력하는 문제 "IF문 좀 대신 써줘" 입니다.

    칭호의 개수가 10만개이고, 캐릭터의 개수도 10만개 이므로 단순 for문으로 풀이 진행할 경우

    반드시 시간 초과가 발생하는 문제 유형 입니다.

    최악의 경우 시간 복잡도는 10만 * 10만 = 100억 이므로 1초 내에 통과가 불가능한데

    시간 복잡도 계산을 위한 두가지 값 중 캐릭터의 개수는 바꿀 수 없으므로 칭호를 할당하기

    위한 탐색을 최대한 줄여야 합니다.

    저는 이 문제에서 시간을 줄이는 방법으로 이진탐색을 선택했는데, 칭호의 정보가

    비내림차순(중복이 있는 오름차순)으로 주어지기 때문에 이진 탐색으로 구현할 경우

    시간 복잡도가 10만 * log2(10)[약 16] = 160만으로 시간 제한에 걸리지 않게 됩니다.

    위 내용에 더해 입력값으로 들어오는 칭호 할당에 대한 정보 중 전투력이 중복될 수 있다는
    
    내용의 예외처리로 이전 입력값을 저장하면서 동일한 값이 들어올 경우 무시하도록 구현

    진행 했습니다.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    #include <string>
    using namespace std;
    
    
    struct Node {
        string title;
        int upper_limit;
    };
    
    int N, M;
    Node info[100001];
    int  bs(int power) {
        int s = 0;
        int e = N-1;
        int ans_idx = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
    
            if (info[mid].upper_limit >= power) {
                ans_idx = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans_idx;
    }
    string Solve(int target) {
        return info[bs(target)].title;
    }
    
    void Input() {
        cin >> N >> M;
        int before_power = -1;
        int max_idx = 0;
        for (int a = 0; a < N; ++a) {
            string temp_title;
            int temp_upper_limit;
            cin >> temp_title >> temp_upper_limit;
            if (temp_upper_limit == before_power) {
                continue;
            }
            else {
                before_power = temp_upper_limit;
                info[max_idx++] = { temp_title,temp_upper_limit };
            }
        }
        N = max_idx;
        for (int a = 0; a < M; ++a) {
            int target;
            cin >> target;
            cout << Solve(target) << "\n";
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        return 0;
    }


풀이 후기

    낮잠 자고 일어났더니 알고리즘 꿀맛

![image](https://github.com/user-attachments/assets/6d822378-e9e8-4f5b-a644-7b977dc19a40)
