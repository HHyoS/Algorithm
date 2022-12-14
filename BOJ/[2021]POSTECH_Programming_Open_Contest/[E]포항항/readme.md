문제 사이트 : https://www.acmicpc.net/problem/23817

문제 설명 : 

![upload acmicpc](https://user-images.githubusercontent.com/57944215/146167971-22fe63a8-d3cf-4611-a532-3eb4fc77b044.jpg)

    이 글을 보고 공포에 사로잡힌 당신은 주변에 과메기를 파는 식당에 달려가기로 하였다.
    
    하지만 요즘 과메기가 인기가 많아 식당에서는 1인분씩만 팔고 있다.
    
    따라서 당신은 총 다섯 식당을 찾아가 과메기를 먹어야 한다. 
    
    슬슬 포항항항 하며 웃음이 나오려고 한다. 최대한 빨리 과메기를 먹고 저주를 풀자!

     $N \times M$ 크기의 지도가 주어진다. 
     
     지도에서 당신의 위치는 'S', 식당의 위치는 'K'로 주어진다. 
     
     또한, 지도 중간중간에 장애물이 존재하며, 장애물은 'X'로 주어진다. 
     
     당신은 지도 상에서 한 칸씩 상하좌우로 움직일 수 있고, 한 칸을 이동하는데 1분이 걸린다. 
     
     장애물이 있는 칸으로는 이동할 수 없다.

    5개의 식당을 방문하는 데 필요한 최소한의 시간을 출력하자.

입력

    첫째 줄에 $N, M \, (4 \leq N, M \leq 1,000)$이 주어진다.

    그 이후 $N$개의 줄에 걸쳐 각 줄에 길이 $M$의 문자열이 주어진다.

    '.'은 빈 칸, 'X'는 장애물, 'S'는 현재 위치, 'K'는 식당을 의미한다 ($1 \leq$ 식당의 수 $\leq 20$).

출력

    'S'에서 출발하여 주어진 식당 중 5개의 식당을 방문하는 데 걸리는 최소한의 시간을 출력하여라. 만약 5개의 식당을 방문할 수 없는 경우 $-1$을 출력한다.

예제 입력 1 

    4 4
    SKKK
    X..X
    X..X
    K..K

예제 출력 1 

    11

예제 입력 2 

    4 4
    SKKK
    XXXX
    KKKK
    KKKK
    
예제 출력 2 

  -1
  
풀이 알고리즘

    1. S에서 출발하여 최대 20개의 K 중 5개를 거치는 최단거리를 찾는 문제입니다.
    
    2. 이를 위해서는 s에서 출발해서 n(K)개의 기본값을 설정하고, 각 K에서 다른 K로 가는 값을 구하여 테이블을 생성합니다.
    
    3. 테이블 생성 후, 5개를 걸칠 떄 최단거리를 구하면 문제 해결이 가능합니다,
    
    ex)  n(k) = 5이상 일 떄 만약 아래와 같은 테이블이 있다면.   k = 6이라면
        가능한 경로 선택은 (1,2,3,4,5) or (1,2,3,4,6) or (1,2,3,5,6) or (1,2,4,5,6) or (1,3,4,5,6) or (2,3,4,5,6) 이 됩니다. (6c5 = 6) 
        이 가능한 경로 선택에 대해 최소값을 찾는 연산은 6! = 6*5*4*3*2 가 되고, 이 과정을 거쳐 나온 최소값이 정답이 되게됩니다.
         도착 
    출발       
        |  0    |    1  |    2  |    3  |    4  |    5  |   6  .... 7 . ... 8
        |_______|_______|_______|_______|_______|_______|   
      0 |   0   |    3  |   4   |   5   |   6   |   7   |
        |_______|_______|_______|_______|_______|_______|
      1 |   -   |   0   |   3   |   4   |   5   |   6   |       
        |_______|_______|_______|_______|_______|_______|
      2 |   -   |   -   |   0   |   3   |   4   |   5   |       
        |_______|_______|_______|_______|_______|_______|
      3 |   -   |   -   |   -   |   0   |   3   |   4   |       
        |_______|_______|_______|_______|_______|_______|
      4 |   -   |   -   |   -   |   -   |   0   |   5   |       
        |_______|_______|_______|_______|_______|_______|
      5 |   -   |   -   |   -   |   -   |   -   |   0   |       
        |_______|_______|_______|_______|_______|_______|  
        
      4. 풀이에 대한 알고리즘은 생각해냈으나, 구현에 실패한 상태로 계속 풀어볼예정입니다.
