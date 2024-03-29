문제 사이트 : https://www.acmicpc.net/problem/16953

문제 설명 :

    정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

    2를 곱한다.
    1을 수의 가장 오른쪽에 추가한다. 
    A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

입력

    첫째 줄에 A, B (1 ≤ A < B ≤ 109)가 주어진다.

출력

    A를 B로 바꾸는데 필요한 연산의 최솟값에 1을 더한 값을 출력한다. 만들 수 없는 경우에는 -1을 출력한다.

예제 입력 1 

    2 162

예제 출력 1 

    5
    2 → 4 → 8 → 81 → 162

예제 입력 2 

    4 42

예제 출력 2 

    -1

예제 입력 3 

    100 40021

예제 출력 3 

    5   
    
풀이 알고리즘 

    정수 A와 B가 주어졌을 때, (1) *2 (2) *10 +1  두가지 연산을 사용하여 B를 만들 수 있는지 확인하고, 최소횟수를
    
    출력하는 문제 'A->B' 입니다.
   
    제가 생각한 풀이 방법은 top-down 방식으로 B를 A로 만드는 방법을 찾는 방법으로 다음과 같습니다.
    
    1. A와 B가 같은지 확인 -> 같을 경우 현재 횟수 출력, 만약 B가 A보다 작다면 -1 출력
    
    2. 다를경우 B의 1의자리를 확인하고
      2-1 '1' 이라면 (2)번 연산을 사용하고, B의 값을 10으로 나눈 몫을 B에 다시 저장, 연산사용횟수 +1
      2-2 '짝수' 라면 (1)번 연산을 사용하여 B의 값을 2로 나눈 몫을 B에 다시 저장
      2-3 '1'이아닌 '홀수'라면 곱하기 연산으로 만들 수 없으므로 -1 출력
      
    3. 1 ~ 2 를 반복하여 답을 출력
    
풀이 인증샷

![image](https://user-images.githubusercontent.com/57944215/220920348-ec3e75d2-239c-4726-a2c3-ff7ef6226ee3.png)
