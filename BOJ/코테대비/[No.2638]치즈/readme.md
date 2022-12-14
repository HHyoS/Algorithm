문제 사이트 : https://www.acmicpc.net/problem/2638

문제 설명 :

    N×M의 모눈종이 위에 아주 얇은 치즈가 <그림 1>과 같이 표시되어 있다. 
    
    단, N 은 세로 격자의 수이고, M 은 가로 격자의 수이다. 
    
    이 치즈는 냉동 보관을 해야만 하는데 실내온도에 내어놓으면 공기와 접촉하여 천천히 녹는다. 
    
    그런데 이러한 모눈종이 모양의 치즈에서 각 치즈 격자(작 은 정사각형 모양)의 4변 중에서 
    
    적어도 2변 이상이 실내온도의 공기와 접촉한 것은 정확히 한시간만에 녹아 없어져 버린다. 
    
    따라서 아래 <그림 1> 모양과 같은 치즈(회색으로 표시된 부분)라면 C로 표시된 모든 치즈 격자는 한 시간 후에 사라진다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/209157751-f669f16c-dcbc-45e1-815c-fa4ff4257711.png)


<그림 1>

    <그림 2>와 같이 치즈 내부에 있는 공간은 치즈 외부 공기와 접촉하지 않는 것으로 가정한다. 

    그러므 로 이 공간에 접촉한 치즈 격자는 녹지 않고 C로 표시된 치즈 격자만 사라진다. 

    그러나 한 시간 후, 이 공간으로 외부공기가 유입되면 <그림 3>에서와 같이 C로 표시된 치즈 격자들이 사라지게 된다.

![upload acmicpc](https://user-images.githubusercontent.com/57944215/209157759-79c2544a-c0db-4dbd-8fe8-828b777823d2.png)


<그림 2>

![upload acmicpc](https://user-images.githubusercontent.com/57944215/209157770-5e1dd3af-1684-4679-a098-ac1d01300b56.png)


<그림 3>

    모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다. 
    
    입력으로 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 구하는 프로그램을 작성하시오.

입력

    첫째 줄에는 모눈종이의 크기를 나타내는 두 개의 정수 N, M (5 ≤ N, M ≤ 100)이 주어진다.
    
    그 다음 N개의 줄에는 모눈종이 위의 격자에 치즈가 있는 부분은 1로 표시되고,
    
    치즈가 없는 부분은 0으로 표시된다. 또한, 각 0과 1은 하나의 공백으로 분리되어 있다.

출력

    출력으로는 주어진 치즈가 모두 녹아 없어지는데 걸리는 정확한 시간을 정수로 첫 줄에 출력한다.

예제 입력 1 

    8 9
    0 0 0 0 0 0 0 0 0
    0 0 0 1 1 0 0 0 0
    0 0 0 1 1 0 1 1 0
    0 0 1 1 1 1 1 1 0
    0 0 1 1 1 1 1 0 0
    0 0 1 1 0 1 1 0 0
    0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0

예제 출력 1 

    4
    
풀이 알고리즘

    시뮬레이션을 통해 치즈가 사라지는 정답으로 시간을 출력하는 문제입니다.
    
    문제를 풀면서 제가 생각한 풀이 순서는 다음과 같습니다.
    
    0. 필요한 요소들 
    
            (1) 탐색할 공간을 저장할 queue 
            (2) 치즈의 위치를 저장한 queue 
            (3) 탐색공간으로 활용되었음을 확인하는 배열 
            (4) 치즈를 몇번 건들였는지 확인한느 배열
            (5) 추가된 공간을 통해 연결된 공간을 확인할 임시 queue
            
    1. 가장자리가 치즈가 없다는 조건이 있으므로 0,0부터 시작하여 bfs탐색을 하며 인접한 위치에 치즈가 있는 공간을 찾아 저장해두기
    
       이 방법으로 탐색을 하면 치즈 내부 공간을 탐색할 수 없으므로 내부 공간을 제외한 외부 공간 중 빈 공간만 저장해 둘 수 있습니다.
       
    2. 치즈 위치 저장해두기. 초기 치즈 위치를 저장해두면 치즈 위치를 지정해서 치즈의 상태를 확인할 수 있습니다.
    
    3. 1 과 2 가 준비되었다면 탐색을 시작합니다.
    
    4. 1 의 결과로 저장해둔 공간의 인접 공간을 확인하며 치즈가 있다면 해당 치즈를 방문했음을 확인하는 배열에 1을 추가시켜 준 후,
        다시 탐색공간 queue 에 저장합니다.
    
       단 인접한 공간에 치즈가 없다면 해당 공간을 더이상 인접공간을 확인할 필요가 없으므로 저장하지 않습니다.
       
    5. 2의 결과로 나온 치즈의 위치를 탐색하여 치즈 방문 횟수를 저장하는 배열의 값을 확인하여 
        2 이상이면 해당 위치의 치즈를 없앤 후 해당 위치를 (5) 임시큐에 추가합니다.
       치즈 방문횟수가 2회 이하 일경우 다시 치즈위치를 저장하는 queue에 추가해줍니다.
    
    6. 
       [1] 5의 결과로 나온 임시큐를 탐색하며 나온 위치들의 인접한 위치를 탐색하며 빈 공간을 찾고, 
       [2] 해당 빈 공간이 (3) 배열을 확인 했을 때 한번도 탐색공간으로 활용된 적이 없는 위치라면,
       [3] 해당 위치를 (1) 에 추가시켜 준 뒤 다시 (5)에 추가 한뒤 탐색을 이어나갑니다.
       [4] (5)의 모든 요소 탐색이 끝나면 다시 (2)의 size가 0이 될 때 까지 4 ~ 6 을 반복하고,
       [5] 0이 되었다면 4 ~ 6 을 반복한 횟수를 정답으로 출력해줍니다. 

풀이 인증샷

![image](https://user-images.githubusercontent.com/57944215/209157658-5a2f7d1d-3a5e-4398-b27d-c51d4ff9c51e.png)
