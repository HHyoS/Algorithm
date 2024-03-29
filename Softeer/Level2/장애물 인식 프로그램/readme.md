![defaultImage](https://user-images.githubusercontent.com/57944215/212909613-c91b8f9d-a34a-40b1-a37f-744f64b5e09a.png)

문제 사이트 : https://softeer.ai/practice/info.do?idx=1&eid=409&sw_prbl_sbms_sn=135014

문제 설명 :


    자율주행팀 SW 엔지니어인 당신에게 장애물과 도로를 인식할 수 있는 프로그램을 만들라는 업무가 주어졌다.




![20210908_185443092_92369](https://user-images.githubusercontent.com/57944215/212909799-7c7a3096-337a-4f59-9f26-435d26277611.jpg)


    [그림 1] 지도 예시




    우선 [그림 1]과 같이 정사각형 모양의 지도가 있다. 1은 장애물이 있는 곳을, 0은 도로가 있는 곳을 나타낸다.




    당신은 이 지도를 가지고 연결된 장애물들의 모임인 블록을 정의하고, 불록에 번호를 붙이려 한다.
    
    여기서 연결되었다는 것은 어떤 장애물이 좌우, 혹은 아래위로 붙어 있는 경우를 말한다. 
    
    대각선 상에 장애물이 있는 경우는 연결된 것이 아니다.




![20210908_185526817_72681](https://user-images.githubusercontent.com/57944215/212909808-2f22ce97-0563-4ed6-a2f7-a3f2febf8736.jpg)


    [그림 2] 블록 별 번호 부여




    [그림 2]는 [그림 1]을 블록 별로 번호를 붙인 것이다. 




    지도를 입력하여 장애물 블록수를 출력하고, 각 블록에 속하는 장애물의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

제약조건

    N은 정사각형임으로 가로와 세로의 크기는 같으며 5 ≤ N ≤ 25

입력형식

    입력 값의 첫 번째 줄에는 지도의 크기 N이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력형식

    첫 번째 줄에는 총 블록 수를 출력 하시오.


    그리고 각 블록 내 장애물의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

입력예제1

    7
    1110111
    0110101
    0110101
    0000100
    0110000
    0111110
    0110000

출력예제1

    3
    7
    8
    9

풀이 알고리즘 

    bfs탐색으로 연결되지 않은 장애물의 갯수와 크기를 출력하는 문제 '장애물 인식 프로그램 입니다.
    
    이 문제는 배열 안에서 장애물을 의미하는 값들이 뭉쳐진 더미의 갯수와 크기를 출력하는 문제로, 장애물의 위치를 찾은 뒤
    
    해당 장애물과 연결된 모든 장애물들의 갯수를 찾고, 찾은 장애물들은 다시 방문하지 않게 처리하면 쉽게 풀리는
    
    문제입니다.
    
    풀이 방법은 다음과 같습니다.
    
    1. 배열의 정보를 입력받는다.
    
    2. 배열을 탐색하면서 장애물을 만나면 그 장애물을 기준으로 bfs탐색을 진행한다.
    
    3. 2를 진행하면서 탐색한 장애물은 방문처리 or 없어진 장애물 처리를 통해 재방문하지 않도록 한다.
    
    4. 2~3 을 진행하며 처리한 장애물의 갯수를 count 해두었다가 연결된 모든 장애물을 처리하면 해당 값을 return
    
    5. 4에서 return 받은 값을 정답 vector에 저장하고, 배열의 끝까지 2~4 를 반복.
    
    6. 모든 배열방문이 끝낫다면 정답 vector를 정렬한뒤 값을 출력
    
    7. vector의 사이즈는 문제에서 요구하는 총 블록수, 정렬된 벡터는 오름차순이므로 해당 값들을 모두 출력
    
풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/212909717-dd8f704a-c30c-4220-b8dc-15f6e5a9c8c7.png)

![image](https://user-images.githubusercontent.com/57944215/212909689-3b4ad3af-1f2a-43f1-8722-b687c78f1da4.png)

