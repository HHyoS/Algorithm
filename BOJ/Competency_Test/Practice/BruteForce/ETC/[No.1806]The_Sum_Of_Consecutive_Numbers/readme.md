문제 사이트 : https://www.acmicpc.net/problem/1806

문제 설명 :

    10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다.
    
    이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 
    
    가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 
    
    둘째 줄에는 수열이 주어진다. 
    
    수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

출력

    첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 
    
    만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

예제 입력 1 

    10 15
    5 1 3 5 10 7 4 9 2 8

예제 출력 1 

    2
    
풀이 알고리즘

    부분합은 길이가 N인 수열( Q )이 주어질 떄 목표 값 S를 만들 수 있는 부분 합 중 가장 짧은
    
    길이의 부분합을 찾는 문제입니다.
    
    여기서 말하는 부분합은  Q가 Q[0] ~ Q[N-1] 까지 수열을 이루고 있을 때
    
    Q[a] ~ Q[b] 까지의 원소들을 더한 값을 부분 합 이라고 합니다.
    
    ( 조건 :  a <= b <= N-1  )
    
    처음에는 이러한 부분합 들 중 가장 짧은 길이를 갖는 부분합을 찾기 위해서 2중 for문을 이용하여
    
    모든 케이스에 대해 부분합을 찾아보고 가장 짧은것을 출력하는 방식으로 구현했으나
    
    해당 방식으로는 시간초과가 발생하였고 다른 방법을 찾아야했습니다.
    
    생각한 방식은 다음과 같습니다.
    
    1. 부분합의 시작과 끝을 의미하는 두개의 변수 left, right를 선언하여 사용.
    
    2. 부분합의 합은 sum이라는 변수로 관리하고, 초기값은 Q[0].
    
    3. left <= right, right < N-1 일떄 계속 반복되는 while문을 사용.
    
    4. left > right 가 되는 경우는 원소 하나만으로 목표값 S에 달성하는 경우 
    
    5. right > N 이 되는 경우는, 
    
    현재 부분합에서 right를 배열의 끝까지 증가시켜도 목표값 도달 불가능한 경우
    
    6. sum이 목표값 S보다 작다면 right를 +1 하여 부분합의 길이를 오른쪽으로 늘림
    
    7. sum이 목표값보다 크거나 같다면 구해놓은 가장 짧은 부분합의 길이와 비교하여 작은값 저장
    
    8. 저장 후 Q[left] 값은 sum에서 뺀 후 left를 하나 증가.
    
    9. left를 뺀 후 증가시키는 이유는, 현재 상태에서 오른쪽으로 부분합을 늘려도 
    
    길이가 더 짧은 값을 찾을수 없으므로, left의 값을 증가시켜 새로운 부분합을 찾기
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <queue>
    #include <utility>

    using namespace std;
    int N;
    long long S;
    int num[100000];
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);


      freopen("Input.txt", "r", stdin);

      cin >> N >> S;
      long long sum = 0;
      
      for (int a = 0; a < N; ++a) {
        cin >> num[a];
        sum += num[a];
      }
      
      if (sum < S) {
        cout << "0"; // 모든 원소의 합을 구했을 때 목표값에 달성하지 못하면 0출력 후
        return 0; // 프로그램 종료
      }
      
      int left = 0, right = 0;
      
      sum = num[0];
      
      int leng = N; // 부분합 중 가장 짧은 값을 의미하는 leng의 초기값은 N
      
      
      while ((left <= right) && (right < N)) {
        if (sum < S) {
          sum += num[++right]; // 현재 부분합이 S보다 작다면 부분합 길이 증가
        }
        else if (sum >= S) { // 현재 부분합이 S보다 크거나 같다면
          leng = min(leng,right - left + 1); // leng과 현재 부분합의 길이 중 짧은값 leng 저장
          sum -= num[left++]; 
          // sum에서 num[left]값을 뺴고 left를 증가시켜 새로운 부분합 찾기
        }
      }
      cout << leng; // while문 종료 이후 길이의 최소값 출력
      return 0;
    }

    
    
