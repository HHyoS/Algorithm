문제 사이트 : https://www.acmicpc.net/problem/14225

문제 설명 :

    수열 S가 주어졌을 때, 
    
    수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 프로그램을 작성하시오.

    예를 들어, S = [5, 1, 2]인 경우에 
    
    1, 2, 3(=1+2), 5, 6(=1+5), 7(=2+5), 8(=1+2+5)을 만들 수 있다.
    
    하지만, 4는 만들 수 없기 때문에 정답은 4이다.

입력

    첫째 줄에 수열 S의 크기 N이 주어진다. (1 ≤ N ≤ 20)

    둘째 줄에는 수열 S가 주어진다.
    
    S를 이루고있는 수는 100,000보다 작거나 같은 자연수이다.

출력

    첫째 줄에 수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 출력한다.

예제 입력 1 

    3
    5 1 2

예제 출력 1 

    4

예제 입력 2 

    3
    2 1 4

예제 출력 2 

    8

예제 입력 3 

    4
    2 1 2 7

예제 출력 3 

    6
    
풀이 알고리즘

    주어진 수열 S를 이루는 원소 조합으로 숫자를 만들고, 조합으로 만들 수 없는 
    
    최소값의 자연수를 구하는 문제였습니다. 
    
    문제 해결을 위해서 조합을 할 때 가장 작은수를 찾을 방법을 구해야했습니다.
    
    정렬된 수열의 특징은 다음과 같습니다.
    
    S = {a , b , c , d} 라는 수열이 존재할 때, 가능한 수의 조합은 다음과 같습니다.
    
    a, b, c ,d , a+b, a+c, a+d, b+c, b+d, c+d, a+b+c , a+b+d, b+c+d, a+b+c+d
    
    이 조합들은 1부터 값을 채워나가는데 a가 1이 아니면 수를 만드는것이 시작될 수 없으므로 
    
    a는 1이라는 가정하에 최소값찾기가 진행됩니다.
    
    최소값을 찾는 중, 찾으려는 숫자보다 다음으로 찾아볼 수열의 값이 크면 해당 수는 만들 수 없으므로 해당수가 답이됩니다.
    
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    int n,m;
    int num[20];
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> n;
      for (int a = 0; a < n; ++a) {
        cin >> num[a]; // 수열 입력받기
      }
      sort(num, num + n); // 수열 정렬 
      int answer = 1; // 처음으로 찾을 숫자는 1
      
      for (int a = 0; a < n; ++a) {
        if (num[a] > answer) // 찾으려는 숫자보다 현재 비교하려고하는 수열의 원소가 크다면, 찾으려는 숫자를 찾을 수 없음
          break; // 탈출
        else // 아니라면
          answer += num[a]; // 해당 숫자는 만들 수 있고, 현재 타겟과, 수열의 원소를 더하여 다음 타겟설정
      }
      cout << answer;
      return 0;
    }

