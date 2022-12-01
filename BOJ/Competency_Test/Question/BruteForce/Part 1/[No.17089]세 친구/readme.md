문제 사이트 : https://www.acmicpc.net/problem/17089

문제 설명 :

    N명의 사람이 있고, 여기서 세 사람 A, B, C를 고르려고 한다. 
    
    세 사람은 모두 친구여야 한다.

    세 사람을 고르는 방법은 매우 많이 있을 수 있다. 
    
    이때, A의 친구 수 + B의 친구 수 + C의 친구 수가 최소가 되어야 한다. 
    
    친구 수의 합을 계산할 때, 세 사람은 빼고 계산해야 한다. 
    
    즉, A의 친구 수를 계산할 때, B와 C는 빼고 계산해야 하고, 
    
    B의 친구 수를 계산할 때는 A와 C, C의 친구 수를 계산할 때는 A와 B를 빼고 계산해야 한다.

입력

    첫째 줄에 사람의 수 N(3 ≤ N ≤ 4,000), 친구 관계의 수 M(0 ≤ M ≤ 4,000)이 주어진다.
    
    둘째 줄부터 M개의 줄에는 친구 관계를 의미하는 두 정수 A, B가 주어진다.
    
    친구 관계는 A와 B, 그리고 B와 A가 친구라는 것을 의미한다.

    사람은 1번부터 N번까지 번호가 매겨져 있다. 
    
    같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

출력

    첫째 줄에 A의 친구 수 + B의 친구 수 + C의 친구 수의 최솟값을 출력한다.
    
    만약, 문제 조건대로 세 사람을 고를 수 없는 경우에는 -1을 출력한다.

예제 입력 1 

    5 6
    1 2
    1 3
    2 3
    2 4
    3 4
    4 5

예제 출력 1 

    2

예제 입력 2 

    7 4
    2 1
    3 6
    5 1
    1 7

예제 출력 2

    -1
    
[ 풀이 알고리즘 ]

    친구 관계에 대한 정보가 입력으로 주어졌을 떄, 친구관계인 세 사람을 뽑고, 세 사람의 친구 수의
    
    최소값을 찾는 문제였습니다.
    
    제가 생각한 친구 수의 최소값을 찾는 알고리즘은 다음과 같습니다.
    
    1. vector 로 주어진 친구 관계를 입력받습니다.
    
    2. 만약 입력이 [ 1 2 ] 로 입력받는다면 vector[1].push_back(2), vector[2].push_back(1) 을 하여
    
    1의 친구관계에 2, 2의 친구관계에 1 을 추가하고, check배열을 사용하여 서로 친구관계인
    
    사람 간의 정보를 저장합니다.
    
    3. 모두 입력을 받은 후 3중 for문을 이용하여 세 명이 친구관계인 경우를 찾습니다.
    
      1] 첫번쨰 for문 = 1 ~ N 사이의 사람 하나[ A ] 를 골라서 for문 반복 실시
      
      2] 두번쨰 for문 = A 와 친구관계인 사람을 찾아서 [ B ] 로 설정
      
      3] 세번쨰 for 문 = B와 친구 관계인 C를 찾고, C와 A가 친구관계일 경우
      
      A B C 의 친구수를 합하여 현재까지 구한 최소값과 비교. 
      
      각 사람의 친구수를 F(A) , F(B), F(C) 라고 했을 때, 
      
      F(A) = { B, C, ....}
      
      F(B) = { A, C, ....}
      
      F(C) = { A, B, ....} 이므로 F(A) + F(B) + F(C) 에는 {A + A} + {B + B} +{C + C}가 존재하는데
      
      문제의 설명에서 A, B,C는 제외하라고 쓰여있으므로 답은
      
      F(A) + F(B) + F(C) - 6 이 답이 되게됩니다.
      
      
[ 구 현 ]

    #include <iostream>
    #include <vector>
    #include <stack>
    using namespace std;
    int N, M;
    vector<int> frnd[4001];
    bool check[4001][4001];

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        //freopen("Input.txt", "r", stdin);
        cin >> N >> M;
        int x, y;

        for (int a = 0; a < M; ++a) { // 친구관계 입력
            cin >> x >> y;
            frnd[x].push_back(y);
            frnd[y].push_back(x);
            check[x][y] = 1;
            check[y][x] = 1;
        }
        int answer = -1;
        
        for (int a = 1; a <= N; ++a) {
            for (int b = 0; b < frnd[a].size(); ++b) {
                if (frnd[a][b] <= a) // A의 친구는 A보다 큰 수 여야함(반복 최소화를 위해) 아니라면 스킵
                    continue;
                else { // A보다 큰 수라면
                    int bb = frnd[a][b]; // bb에 친구 B를 입력하고
                    for (int c = 0; c < frnd[bb].size(); ++c) { 
                        if (frnd[bb][c] <= bb) // B의 친구 C( frnd[bb][c] ) 가 B보다 큰 수가 아니라면
                            continue; // 스킵
                        else{ // 아니라면
                            int cc = frnd[bb][c]; // cc에 친구 C를 입력하고
                            if (check[a][cc]) { // 친구 A와 C가 친구인지 확인 후 친구라면
                                if ((answer == -1) || (frnd[a].size() + frnd[bb].size() + frnd[cc].size() - 6 < answer)) {
                                    answer = frnd[a].size() + frnd[bb].size() + frnd[cc].size() - 6; // answer와 비교하여 최소값 
                                }
                            }
                        }
                    }
                }

            }
        }
        cout << answer;
        return 0;
    }
