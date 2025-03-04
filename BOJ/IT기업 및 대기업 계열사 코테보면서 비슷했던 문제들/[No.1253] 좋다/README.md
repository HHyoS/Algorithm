문제 사이트 : https://www.acmicpc.net/problem/1253

문제 설명:

![image](https://github.com/user-attachments/assets/96fa74b9-a995-4d5f-b059-adfe2d1b35ca)

풀이 알고리즘

    N개의 수가 담긴 수열 A가 주어질 때, 임의의 수 A[i]가 자기 자신을 제외한 다른 두 수의 합으로
    표현되는지 확인하고, 그 개수를 출력하는 문제 '좋다' 입니다.

    초기에는 2중 for문으로 모든 합을 구하고, 수열의 값과 위치가 저장된 unordered_map 구조체를 사용하여
    해당 합이 구조체 안에 있고, 특정 위치에 있는 값을 사용하여 계산된 값이 아닌지 체크하는 방식으로
    구현을 진행해 시간초과가 발생했음에도 디버깅이 복잡하여 원인을 구체적으로 알아내지 못했습니다.

    그래서 단순하게 구현하기 위해 모든 합을 구하는 것이 아닌 임의의 수 A[i]를 타겟으로
    임의의 두 수의 합으로 해당 수를 만들 수 있는지 찾는 방식으로 구현 진행 했습니다.

    제가 진행한 풀이는 아래와 같습니다.

    1) 수열의 값을 vector에 저장
    2) vector의 값을 sort하여 오름차순으로 저장 -> 정렬하지 않으면 두 수의 합을 조절할 수 없기 때문에
    정렬하여 합의 증감을 예상할 수 있도록 함
    3) vector의 복사본을 만들고, 찾고자 하는 값을 복사본에서 제외시킴
    -> 복사본에서 제외하면 복사본에 존재하는 임의의 수의 합은 모두 좋은 수(자기 자신을 사용하지 않음)가 됨
    4) 수열의 특정 값 vector[i]를 찾기 위해서, 투 포인터 방식으로 
    시작 지점 s =0, 끝 지점 = 복사복 벡터의 끝을 지정하여 while(s < e)가 되는 조건 내에서 w 아래의 연산 진행
    4-1) copy_A[s] + copy_A[e] > vector[i] -> e = e-1 -> 두 수의 합이 vector[i] 보다 크므로 합을 줄여야 함
    4-2) copy_A[s] + copy_A[e] < vector[i] -> s = s+1 -> 두 수의 합이 vector[i] 보다 작으므로 합을 키워야 함
    4-3) copy_A[s] + copy_A[e] == vector[i] -> vector[i] 는 좋은 수 이므로 정답 +1 후 while문 break
    5) 3-4 과정을 vector 내의 모든 값에 대해서 진행

풀이 코드

    #include <iostream>
    #include <stack>
    #include <algorithm>
    #include <vector>
    #include <string>
    #include <queue>
    #include <unordered_map>
    using namespace std;
    
    int N;
    
    vector<int> v;
    void Solve() {
        int ans = 0;
    
    
        // 정돈된 합을 구하기 위한 정렬
        sort(v.begin(), v.end());
        for (int a = 0; a < N; ++a) {
            // 복사본 벡터 변수 할당 후 현재 찾고자 하는 값을 벡터에서 제외
            vector<int> tempv = v;
            tempv.erase(tempv.begin() + a);
    
            // two pointer s 와 e 선언하여 tempv의 처음와 끝 지정
            int s = 0;
            int e = N - 2;
      
            while (s < e) {
                int tSum = tempv[s] + tempv[e];
    
                // 합이 찾고자 하는 값보다 작으면 s를 오른쪽으로 이동시켜 합을 키우자
                if (tSum < v[a]) {
                    ++s;
                }
                // 합이 찾고자 하는 값과 같다면 정답 +1 후 while문 break
                else if(tSum == v[a]){
                    ++ans;
                    break;
                }
                // 합이 찾고자 하는 값보다 크면 e를 왼쪽으로 이동시켜 합을 줄이자
                else {
                    --e;
                }
            }
        }
        // 정답 출력
        cout << ans;
    }
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
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

    이게 복사를 했는데 시간 초과가 안나네  

![image](https://github.com/user-attachments/assets/33db18df-77b7-4e8f-b7cc-fdd621deb439)
