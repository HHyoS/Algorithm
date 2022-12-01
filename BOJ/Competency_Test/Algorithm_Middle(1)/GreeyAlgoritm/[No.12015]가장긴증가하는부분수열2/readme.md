문제 사이트 : https://www.acmicpc.net/problem/16928

개발 환경 :  Visual Studio 2019

설 명 :

    수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

    예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력

    첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

    둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력

    첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1 

    6
    10 20 10 30 20 50

예제 출력 1 

    4
    
풀이 알고리즘 

    가장 긴 증가하는 부분수열을 구하는 문제였습니다. 
    
    하지만 일반적인 O(N^2)의 방법으로는 N의 갯수가 최대 1,000,000 개 이므로 시간제한인 1초에 의해 시간초과가 발생할 수 있었습니다.
    
    그래서 시간제한 내에 문제를 해결하기위해 lower_bound를 이용하여 문제를 해결하였습니다.
    
    1. 수를 입력받을 배열을 선언한 이후, 값이 입력됬을 때, 배열을 끝 값보다 큰값이 들어올 경우 배열에 push
    
    2. 배열의 끝값보다 작은값이 들어올 경우 배열의 값 중 해당 값이 들어갈 수 있는 위치를 lower_bound를 이용하여 찾은 뒤 넣을 수 있는 위치에 입력
    
    3. 해당 1~2를 N개의 수를 모두 입력받을떄까지 반복
    
    4. 배열의 길이 출력
    


구 현

    #include <iostream>
    #include <string>
    #include <queue>
    #include <stack>
    #include <algorithm>
    using namespace std;

    int big = 0;
    int N;
    vector<int> arr = { 0 };
    int main() {

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> N;

      for (int a = 0; a < N; ++a) {
        int temp;
        cin >> temp;
        if (temp > arr.back())
          arr.push_back(temp);
        else {
          int idx = lower_bound(arr.begin(), arr.end(), temp) - arr.begin();
          arr[idx] = temp;
        }
      }
      cout << arr.size()-1;
      return 0;
    }
