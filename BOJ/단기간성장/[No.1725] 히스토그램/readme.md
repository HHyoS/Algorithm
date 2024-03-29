문제 사이트 : https://www.acmicpc.net/problem/1725

문제 설명 :

    히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 말한다.

![hist](https://github.com/HHyoS/Algorithm/assets/57944215/c3c95918-02a6-4300-ac07-759cc58597ff)

    각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 
    
    위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.

    이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 
    
    아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.

![histo](https://github.com/HHyoS/Algorithm/assets/57944215/f5a003d6-8c74-43bc-bd42-932cf4814e1b)

    주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.

입력

    첫 행에는 N (1 ≤ N ≤ 100,000) 이 주어진다. 
    
    N은 히스토그램의 가로 칸의 수이다. 
    
    다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 
    
    각 칸의 높이는 1,000,000,000보다 작거나 같은 자연수 또는 0이다.

출력
    
    첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.

예제 입력 1 

    7
    2
    1
    4
    5
    1
    3
    3

예제 출력 1 

    8
   
풀이 알고리즘

    히스토그램이 주어졌을 때, 히스토그램 내의 가장 큰 직사각형의 크기를 구하는 문제 '히스토그램 입니다.
    
    단순 2중 for문으로 구현할 경우 시간초과가 발생하기 때문에, 자료구조를 사용하여 구현해야합니다.
    
    저는 Stack 자료구조를 사용해서 문제풀이를 진행하였습니다.
    
    stack을 사용한 풀이 알고리즘은 다음과 같습니다.

        1. 스택에 히스토그램 인덱스값(1부터 시작)을 계속 넣는다 = 이게 이전 위치
        
        2. 만약 현재 위치(i)가 이전 위치(스택에 있음)보다 작다면
        
        3. 스택에서 현재 위치(i)보다 작은 값이 나올때 까지 계속 빼낸다
        
        4. 3을 계속 하면서 높이, 넓이를 구해 계속 max로 비교한다
        

풀이 인증샷

![image](https://github.com/HHyoS/Algorithm/assets/57944215/e61f4030-968b-44f1-9f9b-62e3cef576fa)
