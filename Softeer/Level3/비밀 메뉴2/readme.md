![5a97961d-ad59-4b6a-ba93-307ed6681802](https://user-images.githubusercontent.com/57944215/212687928-d37bb2dc-c2db-40e0-8a54-f58a29524bcd.jpg)


문제 사이트 : https://softeer.ai/practice/info.do?idx=1&eid=633&sw_prbl_sbms_sn=129345

문제 설명 :

    회사 식당에는 전설처럼 전해 내려오는 비밀 메뉴에 대한 소문이 있다. 
    
    소문의 내용은 대강 이러하다.

    식권 자판기의 버튼을 특정 순서대로 누르고 결제를 하면, 평소와는 다른 색깔의 식권이 나온다. 
    
    이 식권을 배식대에 제출하면, 어떤 비밀 메뉴를 받을 수 있다는 것이다.

    물론 이를 실제로 본 사람은 아무도 없어서, 
    
    어떤 메뉴가 나오는지는 커녕 눌러야 하는 버튼의 순서조차 알려져 있지 않다.

    식당의 평범한 이용객인 당신은 이 소문을 들은 순간 비밀 메뉴에 호기심이 생겼다.
    
    그 실체를 쫓아 연구를 거듭한 지도 어언 몇 달째. 당신은 자판기의 버튼을 아무렇게나 두들기면서, 
    
    비밀 메뉴가 나오는 조작법을 두 가지 찾아냈다!

    당신은 이 두 조작법을 연구해 비밀 메뉴 조작법을 찾고자 한다.

    당신은 버튼에 1 이상 K 이하의 정수로 된 번호를 매겨, 이러한 숫자의 나열로 버튼 조작을 표현했다. 
    
    당신의 직감은 둘 모두에 포함된 일련의 조작법 중 가장 긴 것을 찾아야 한다고 말하고 있다.

    일련의 조작법이란, 나열된 숫자들에 존재하는 연속된 부분 수열을 의미한다.

    길이가 각각 N과 M인 버튼 조작 과정이 주어질 때, 
    
    둘 모두에 완전히 포함되는 일련의 조작 과정 중 가장 긴 것의 길이를 출력하여라.

제약조건

    1≤N≤3,000

    1≤M≤3,000

    1≤K≤1,000,000

    각 버튼의 번호는 1 이상 K 이하이다.

입력형식

    첫째 줄에 N, M, K가 공백을 사이에 두고 주어진다.

    둘째 줄에 첫 번째 버튼 조작을 나타내는 N개의 정수가 공백을 사이에 두고 주어진다. 
    
    각 정수는 1 이상 K 이하이다.

    셋째 줄에 두 번째 버튼 조작을 나타내는 M개의 정수가 공백을 사이에 두고 주어진다. 
    
    각 정수는 1 이상 K 이하이다.

출력형식

    비밀 메뉴 조작법으로 가능한 가장 긴 것의 길이를 첫째 줄에 출력한다. 
    
    만일 겹치는 조작이 전혀 없다면 0을 출력한다.

입력예제1

    3 4 4
    2 3 1
    3 1 4 2
    
출력예제1

    2

    두 조작 모두에 등장하는 수열은 다음과 같다:



    [1],[2],[3],[3 1]



    이중 가장 긴 것은 [3 1]이며 그 길이는 2이다. 따라서 첫째 줄에 2를 출력한다.

입력예제2

    4 10 3
    2 1 3 2
    1 3 2 1 3 2 1 3 2 1

출력예제2

    4

    첫 번째 조작인 [2 1 3 2]가 두 번째 조작에 온전히 등장하므로, 그 길이인 4가 곧 답이 된다.

입력예제3

    5 4 9
    3 1 4 1 5
    9 8 7 6

출력예제3

    0

    두 조작에 겹치는 것이 하나도 없으므로 답은 0이다.
    
풀이 알고리즘 

    너무 오랫만에 풀어서 겨우겨우 풀어낸 문제 '비밀 메뉴 2' 입니다.
    
    풀이가 도저히 생각나지 않아서, 백트랙킹 문제풀이로 도전했으나 바로 시간초과로 실패해버렸습니다.
    
    그래서 dp문제임을 깨닫고 케이스를 하나하나 손으로 그려서 확인해 본 결과
    
    A배열의 i 번쨰 요소와 B배열의 j 번째 요소가 같을 때, 현재 위치에서 A와 B의 연속된 값의 갯수는
    
    A[i-1][j-1] 번쨰 배열의 길이라는것을 알게되었습니다.
    
    그래서 N*M 탐색을 돌면서 dp[N][M]배열을 채워나가며 최대 길이를 찾은 뒤 출력하여 문제를 해결하였습니다.
    
풀이 인증 샷

![image](https://user-images.githubusercontent.com/57944215/212688905-489c5353-1af1-4959-920c-f062183ba304.png)

![image](https://user-images.githubusercontent.com/57944215/212688935-39c5ee30-a524-4479-b815-c401b411962a.png)

    
