문제 사이트 : https://www.acmicpc.net/problem/11404

문제 설명 :

    n(2 ≤ n ≤ 100)개의 도시가 있다. 
    
    그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 
    
    각 버스는 한 번 사용할 때 필요한 비용이 있다.

    모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.

입력

    첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다.
    
    그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다.
    
    먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다.
    
    버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 
    
    시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.

    시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.

출력

    n개의 줄을 출력해야 한다.

    i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다.

    만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.

예제 입력 1 

    5
    14
    1 2 2
    1 3 3
    1 4 1
    1 5 10
    2 4 2
    3 4 1
    3 5 1
    4 5 3
    3 5 10
    3 1 8
    1 4 2
    5 1 7
    3 4 2
    5 2 4

예제 출력 1 

    0 2 3 1 4
    12 0 15 2 5
    8 5 0 1 1
    10 7 13 0 3
    7 4 10 6 0
    
풀이 알고리즘 

    도시와 버스의 비용이 주어졌을 때, 모든 도시에서 다른 도시로 가는 비용의 최솟값을 구하는
    
    프로그램을 구하는 문제 '플로이드'입니다.
    
    특정 노드에서 다른 노드의 최단거리를 구하는 방법은 다익스트라로 구할 수 있습니다.
    
    하지만 해당 방법을 사용할 경우 m의 크기가 10만이기 때문에 다익스트라의 복잡도 O(ElogE)

    이므로 100000 * 16 = 160만의 복잡도를 가지지만. 플로이드 알고리즘 사용할 경우
    
    100*100*100 = 100만의 복잡도를 가지므로 플로이드 알고리즘이 더 효율적으로 구현될 수 있씁니다.
    
    따라서 저는 플로이드-와샬 알고리즘을 사용해서 구현을 진행하였습니다.
    
    플로이드-와샬 알고리즘을 제외하고 구현에 필요한 부분은 다음과 같습니다.
    
        1. 중복된 버스의 코스트가 입력되므로 최소값만 사용하기.
        
        2. 버스 노선이 없는 경로는 생략하기.
  
풀이 인증샷 

![123](https://github.com/HHyoS/Algorithm/assets/57944215/b1626fe1-29b2-49aa-bc6c-09862fb8e8cc)


    
    
