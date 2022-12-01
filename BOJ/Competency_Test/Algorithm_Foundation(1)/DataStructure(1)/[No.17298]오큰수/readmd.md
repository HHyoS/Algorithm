문제 사이트 : https://www.acmicpc.net/problem/17298

개발 환경 : Visual Studio 2019

설 명 :

    크기가 N인 수열 A = A1, A2, ..., AN이 있다. 
    
    수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
    
    Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 
    
    그러한 수가 없는 경우에 오큰수는 -1이다.

    예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. 
    
    A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력

    첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
    
    둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력

    총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

예제 입력 1 

    4
    3 5 2 7

예제 출력 1 

    5 7 7 -1

예제 입력 2 

    4
    9 5 4 8

예제 출력 2 

    -1 8 8 -1
    
풀이 알고리즘

    주어진 조건에 맞추어 오큰수를 출력하는 문제였습니다.
    
    일반적인 2중 for문 [ O(N^2) ] 으로는 시간초과가 발생하기때문에 O(N) 의 복잡도는 가진 알고리즘으로 구현해야했습니다.
    
    제가 생각한 풀이 알고리즘은 다음과 같습니다.
    
    1. 큰수를 저장하는 stack과 입력된 N개의 수를 저장할 int 배열, 정답을 저장할 int 배열을 선언합니다.
    
    2. N개의 수가 저장된 int 배열을 위치 x(초기값 = N-1)에 탐색하여 스택이 비거나, 스택.top()의 값이 배열의 값보다 클떄까지 pop 연산을 실행합니다.
    
    3.  2단계가 끝났을 떄 
        (1) stack 이 비어있으면 -1을 출력하여 현재 배열의 위치의 오큰수는 없음으로 -1을 정답배열의 x 인덱스에 -1을 저장시킵니다
        (2) stack 이 비어있지 않다면 stack.top()값을 정답 배열의 x 인덱스에 저장시킵니다.
        
    4. 현재 위치의 오큰수를 3단계에서 저장했으므로 stack에 현재 배열의 x 인덱스 값을 저장합니다.(다음 탐색에서 x-1 위치의 값과 비교될 숫자)
    
    5. x의 값을 하나 감소시킵니다.(x의 값이 0보다 작다면 반복 X)
    
    6. 2단계로 돌아가 반복합니다.
    
    7. 정답출력
    


구 현
    
            #include <iostream>
        #include <string>
        #include <queue>
        #include <stack>
        #include <algorithm>
        using namespace std;

        long long N;
        int arr[1000001];
        int answer[1000001];
        int main() {

            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            //freopen("Input.txt", "r", stdin);

            cin >> N;
            int temp;
            stack<int> st;
            for (int a = 0; a < N; ++a) {
                cin >> arr[a];
            }
            for (int a = N - 1; a >= 0; --a) {
                while(!st.empty() && (arr[a] >= st.top())) {
                    st.pop();
                }  
                if (st.empty())
                    answer[a] = -1;
                else
                    answer[a] = st.top();
                st.push(arr[a]);
            }
            for (int a = 0; a < N; ++a) {
                cout << answer[a] << " ";
            }
            return 0;
        }

