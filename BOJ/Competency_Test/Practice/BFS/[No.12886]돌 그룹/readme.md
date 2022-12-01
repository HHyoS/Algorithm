문제 사이트 :https://www.acmicpc.net/problem/12886

문제 설명 :

    오늘 강호는 돌을 이용해 재미있는 게임을 하려고 한다. 먼저, 돌은 세 개의 그룹으로 나누어져 있으며 각각의 그룹에는 돌이 A, B, C개가 있다. 강호는 모든 그룹에 있는 돌의 개수를 같게 만들려고 한다.

    강호는 돌을 단계별로 움직이며, 각 단계는 다음과 같이 이루어져 있다.

    크기가 같지 않은 두 그룹을 고른다. 그 다음, 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 그 다음, X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

    A, B, C가 주어졌을 때, 강호가 돌을 같은 개수로 만들 수 있으면 1을, 아니면 0을 출력하는 프로그램을 작성하시오.

입력

    첫째 줄에 A, B, C가 주어진다. (1 ≤ A, B, C ≤ 500)

출력

    돌을 같은 개수로 만들 수 있으면 1을, 아니면 0을 출력한다.

예제 입력 1 

    10 15 35

예제 출력 1 

    1

예제 입력 2 

    1 1 2

예제 출력 2 

    0
    
 
 풀이 알고리즘
 
    BFS탐색을 이용하여 세 개의 돌이 모두 같아지는 경우의 수가 있는지 확인하는 문제였습니다.
    
    제가 푼 방법은 3차원 배열에 세가지 수의 상태를 저장하여 중복케이스를 제거하고 가능한지 확인하는 방법이였는데,
    
    해당 방법으로는 메모리초과 발생으로 인해 문제가 해결되지 않았습니다.
    
    그래서 다른사람읲 풀이를 보면서 문제를 풀었씁니다. 
    ( 코드 사이트 : https://gusdnr69.tistory.com/289)
    
    해당 코드를 보면서 저는 첫번째수와 두번쨰 수 중 어떤수를 배열의 값으로 넣어 사용할 지에대해 생각하면서
    
    sort를 사용하여 가장작은수를 찾아 계산하는 방법만을 생각하였고, 그렇게 해서는 문제가 풀리지 않았습니다.
    
    지금도 문제의 이해가 완벽하게 되지 않은 상태여서 이 문제를 다시 풀면서 완전이 이해가되면 저만의 코드로
    
    재업로드 할 예정입니다.
    
    위의 내용과는 별개로 문제의 풀이는 다음과 같습니다.
    
    세개의 돌이 주어지고, 연산이 진행될 때, 세 돌의 합 T는 변하지 않습니다.
    
    그렇기 때문에 돌1, 돌2 가 주어진다면 돌 3의 값을 찾을 수 있고, 3차원 배열이 아닌 2차원 배열을 사용해도
    
    돌의 상태를 관리할 수 있습니다.
    
    그리고 저는 돌의 최소값을 찾아 해맸지만, 코드를 참조한 블로그에서는 주어진 세 돌의 가능성 중복이 허용되지않는 조합
    
    6가지의 경우에 대해 연산하면서 세 수 중 최소, 최대값을 찾아 해당 수를 이용하여 방문확인을 하는 방법으로 문제를
    
    풀이하였습니다.
    
    그리고 실행속도 계선을 위해 어떤 연산을 진행하더라도 모든 돌의 수가 같아질 수 없는 T%3 != 0 인 케이스는 입력 시
    
    처리하여 불필요한 연산을 하지않도록 하였습니다,.
    

2022.09.11 풀이완성!
---------------------------------------------------------------------------------------------------------------------------------------------------------------------


구 현

        #include <iostream>
        #include <algorithm>
        #include <queue>

        using namespace std;


        struct Node {
            int n1;
            int n2;
        };
        int tot;
        bool check[1501][1501];
        int ans = 0;
        queue<Node> que;

        void bfs() {


            while (!que.empty()) {
                int nums[3] = { que.front().n1, que.front().n2, tot - que.front().n1 - que.front().n2 };
                que.pop();
                for (int a = 0; a < 2; ++a) {
                    for (int b = a + 1; b < 3; ++b) {
                        int new_num1 = 0;
                        int new_num2 = 0;
                        int new_num3 = 0;
                        if (nums[a] > nums[b]) {
                            new_num1 = nums[b] * 2;
                            new_num2 = nums[a] - nums[b];
                            new_num3 = tot - new_num1 - new_num2;
                        }
                        else if (nums[a] < nums[b]) {
                            new_num1 = nums[b] - nums[a];
                            new_num2 = nums[a] * 2;
                            new_num3 = tot - new_num1 - new_num2;

                        }
                        else
                            continue;

                        if (new_num1 == new_num2 && new_num2 == new_num3){
                            ans = 1;
                            return;
                        }
                        int mini = min(new_num1, min(new_num2, new_num3));
                        int maxi = max(new_num1, max(new_num2, new_num3));

                        if (check[mini][maxi])continue;

                        check[mini][maxi] = 1;
                        que.push({ mini,maxi });
                    }
                }
            }

            return;
        }
        void input() {
            int nums[3];
            cin >>nums[0] >> nums[1] >> nums[2];

            tot = nums[0] + nums[1] + nums[2];
            if (tot % 3 != 0) {
                return;
            }
            else {
                if (nums[0] == nums[1] && nums[1] == nums[2]) {
                    ans = 1;
                    return;
                }
                sort(nums, nums + 3);
                check[nums[0]][nums[2]] = 1;
                que.push({ nums[0],nums[2] });
            }
        }
        int main() {
            ios::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);


            input();
            bfs();
            cout << ans;
        }
        
        
 풀이 인증
 
 ![image](https://user-images.githubusercontent.com/57944215/189525801-30717713-ff75-4db9-99fc-11b41f89d0d4.png)


