문제 사이트 : https://www.acmicpc.net/problem/17025

문제 설명 :

    Farmer John is going into the ice cream business! He has built a machine that produces blobs of ice cream but unfortunately in somewhat irregular shapes, 
    
    and he is hoping to optimize the machine to make the shapes produced as output more reasonable.

    The configuration of ice cream output by the machine can be described using an 
    
    $N \times N$ grid (
    $1 \leq N \leq 1000$) as follows:

        ##....
        ....#.
        .#..#.
        .#####
        ...###
        ....##

    Each '.' character represents empty space and each '#' character represents a 
    $1 \times 1$ square cell of ice cream.

    Unfortunately, the machine isn't working very well at the moment and might produce multiple disconnected blobs of ice cream (the figure above has two).
    
    A blob of ice cream is connected if you can reach any ice cream cell from every other ice cream cell in the blob by repeatedly 
    
    stepping to adjacent ice cream cells in the north, south, east, and west directions.

    Farmer John would like to find the area and perimeter of the blob of ice cream having the largest area. 
    
    The area of a blob is just the number of '#' characters that are part of the blob. 
    
    If multiple blobs tie for the largest area, he wants to know the smallest perimeter among them. 
    
    In the figure above, the smaller blob has area 2 and perimeter 6, and the larger blob has area 13 and perimeter 22.

    Note that a blob could have a "hole" in the middle of it (empty space surrounded by ice cream). 
    
    If so, the boundary with the hole also counts towards the perimeter of the blob. Blobs can also appear nested within other blobs,
    
    in which case they are treated as separate blobs. For example, this case has a blob of area 1 nested within a blob of area 16:

        #####
        #...#
        #.#.#
        #...#
        #####
        
    Knowing both the area and perimeter of a blob of ice cream is important, 
    
    since Farmer John ultimately wants to minimize the ratio of perimeter to area, 
    
    a quantity he calls the icyperimetric measure of his ice cream. When this ratio is small, 
    
    the ice cream melts slower, since it has less surface area relative to its mass.

입력

    The first line of input contains 
    $N$, and the next 
    $N$ lines describe the output of the machine. At least one '#' character will be present.

출력

    Please output one line containing two space-separated integers, 
    
    the first being the area of the largest blob, and the second being its perimeter.
    
    If multiple blobs are tied for largest area, print the information for whichever of these has the smallest perimeter.

예제 입력 1 

    6
    ##....
    ....#.
    .#..#.
    .#####
    ...###
    ....##
    
예제 출력 1 

    13 22
    
풀이 알고리즘 

    뭔가 있어보이는 문제를 풀고싶어서 도전한 문제 'Icy Perimeter'입니다.
    
    영어로 된 문제여서 접근하기에 거부감이 조금 있지만 문제에 대한 요약은.

        1. '.'은 외부공간 '#'은 얼음

        2. 정답으로 구하고 싶은건 상,하,좌,우로 연결된 얼음의 갯수가 가장 많은 얼음덩이의 크기,둘레길이

        3. 얼음은 표면적이 넓을수록 빨리 녹으므로, 가장 큰 크기가 같을경우, 둘레가 작은것 찾기

    로 세줄요약 가능합니다.
    
    위의 조건에 따라 제가 생각한 풀이 알고리즘은 다음과 같습니다.

        1. 얼음은 방문한 얼음, 방문하지 않은 얼음 두가지로 구분
        
        2. 전체 맵에 대해 탐색하며, 방문하지 않은 얼음 방문 시 해당 얼음을 기준으로 bfs탐색
        
        3. 2과정을 진행하며 dy,dx 를 체크할 때, 외부공간 or 맵 외부를 나타내는 위치라면
        
           얼음덩이의 최외각 부분이므로 길이 +1
           
        4. 2과정에서 새로운 얼음을 queue에 넣을경우 얼음갯수 +1
        
        5. 2 ~ 4 과정에서 구한 얼음의 크기가 가장크면 현재 크기,둘레를 답으로 저장
        
        6. 만약 현재까지 큰 얼음의 크기와 같다면, 둘레의 길이를 비교하고 작은값 저장
        
        7. 정답출력 뿜뿜
        
풀이 인증샷 

![image](https://github.com/HHyoS/Algorithm/assets/57944215/403c1eb1-354e-4887-bd61-c509b9f40674)

        
