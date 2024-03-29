문제 사이트 : https://www.acmicpc.net/problem/1926

문제 설명 :

    어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
    
    단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
    
    가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다.
    
    그림의 넓이란 그림에 포함된 1의 개수이다.

입력

    첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다.
    
    두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
    
    (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력

    첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 
    
    단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.

예제 입력 1 

    6 5
    1 1 0 1 1
    0 1 1 0 0
    0 0 0 0 0
    1 0 1 1 1
    0 0 1 1 1
    0 0 1 1 1

예제 출력 1 

    4
    9

풀이 알고리즘

    약 일주일간 쉰 알고리즘 재활의 시작문제 '그림' 입니다.

    '그림' 문제는 기본적인 BFS문제로, 주어진 정보에서 상,하,좌,우 이동을 통해 연결된 1 들의 집합을

    '그림'으로 칭하고있습니다.

    그림 문제에서 문제 해결을 위해 필요한 값을 두가지입니다.

    1) 그림의 갯수 2) 그림 중 1을 가장 많이 포함하고 있는(크기가 큰) 그림의 크기

    위의 두가지를 얻기위해 다음과 같은 풀이를 사용하여 문제를 해결하였습니다.

    1. 2중 for문으로 주어진 정보의 모든 인덱스를 방문

    2. 만약 방문한 인덱스의 정보가 1이고, 방문한적이 없다면 BFS 탐색 실시 ( 그림의 갯수 1추가)

    3. BFS팀색을 하며 상,하,좌,우 연결된 모든 인덱스를 방문하며 1의 갯수 카운팅 및 방문처리

    4. BFS탐색이 종료되었을 때, 1들의 갯수가 현재까지 최대값보다 크다면 최대값 갱신

    5. 2 ~ 4 의 프로세스가 종료되었을 때, 그림의 갯수와 최대 그림의 크기 출력

풀이 인증샷

![image](https://github.com/HHyoS/Algorithm/assets/57944215/e5224ae9-576a-4969-92ee-edfa608b4546)

