문제 사이트 : https://www.acmicpc.net/problem/18430

문제 설명 :

    공학자 길동이는 외부의 침략으로부터 마을을 지킬 수 있는 부메랑 무기를 개발하는 공학자다. 
    
    길동이는 부메랑 제작을 위한 고급 나무 재료를 구했다. 
    
    이 나무 재료는 NxM크기의 직사각형 형태이며 나무 재료의 부위마다 그 강도가 조금씩 다르다.

    예를 들어 나무 재료의 크기가 2x3일 때는 다음과 같이 총 6칸으로 구성된다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/206897805-8656db74-8026-4964-aa95-4b0c699daeab.jpg)


    길동이는 이처럼 넓은 사각형 형태의 나무 재료를 잘라서 여러 개의 부메랑을 만들고자 한다. 
    
    그리고 부메랑은 항상 3칸을 차지하는 ‘ㄱ’모양으로 만들어야 한다.
    
    따라서 부메랑의 가능한 모양은 다음과 같이 총 4가지다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/206897807-04805b8b-8a11-4c11-8495-f800fc7b0e61.jpg)


    이때 부메랑의 중심이 되는 칸은 강도의 영향을 2배로 받는다. 
    
    위 그림에서 노란색으로 칠한 부분이 ‘중심이 되는 칸’이다.
    
    예를 들어 앞선 예시에서는 다음과 같이 2개의 부메랑을 만들 수 있으며,
    
    이때 만들어지는 부메랑들의 강도의 합은 46으로 이보다 강도의 합이 높아지는 경우는 없다.
    
![upload acmicpc](https://user-images.githubusercontent.com/57944215/206897808-0f999306-b20b-44f5-ab88-ea340364309b.jpg)


    또한 나무 재료의 특정 위치는 아예 사용하지 않아도 괜찮다. 
    
    예를 들어 앞선 예시에서 다음과 같이 1개의 부메랑만을 만들어도 괜찮다.
    
    다만, 이렇게 만들게 되면 부메랑들의 강도의 합이 18이 되기 때문에 비효율적이다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/206897810-8e90d463-fde1-496f-a454-7b5a15fabc4a.jpg)

    나무 재료의 형태와 각 칸의 강도가 주어졌을 때, 
    
    길동이가 만들 수 있는 부메랑들의 강도 합의 최댓값을 출력하는 프로그램을 작성하시오. 

입력

    첫째 줄에는 길동이가 가지고 있는 나무 재료의 세로, 가로 크기를 의미하는 두 자연수 N, M이 주어진다.
    
    (1 ≤ N, M ≤ 5) 다음 N개의 줄에 걸쳐서, 
    
    매 줄마다 나무 재료의 각 위치의 강도를 나타내는 M개의 자연수 K가 공백을 기준으로 구분되어 주어진다. (1 ≤ K ≤ 100)

출력

    첫째 줄에 길동이가 만들 수 있는 부메랑들의 강도 합의 최댓값을 출력한다.

    단, 나무 재료의 크기가 작아서 부메랑을 하나도 만들 수 없는 경우는 0을 출력한다.

예제 입력 1 

    3 3
    32 83 75
    24 96 56
    71 88 12

예제 출력 1 

    632

예제 입력 2 

    1 1
    7

예제 출력 2 

    0

풀이 인증샷

![image](https://user-images.githubusercontent.com/57944215/206897752-f6cea033-3739-4f55-8728-c1007060f7e8.png)
