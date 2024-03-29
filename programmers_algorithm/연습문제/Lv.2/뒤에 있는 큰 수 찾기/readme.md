문제 사이트 : https://school.programmers.co.kr/learn/courses/30/lessons/154539

문제 설명 :

    정수로 이루어진 배열 numbers가 있습니다. 
    
    배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수라고 합니다.
    정수 배열 numbers가 매개변수로 주어질 때, 
    
    모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return 하도록 solution 함수를 완성해주세요. 
    
    단, 뒷 큰수가 존재하지 않는 원소는 -1을 담습니다.

제한사항

    4 ≤ numbers의 길이 ≤ 1,000,000
    1 ≤ numbers[i] ≤ 1,000,000

입출력 예

    numbers	            result
    [2, 3, 3, 5]	      [3, 5, 5, -1]
    [9, 1, 5, 3, 6, 2]	[-1, 5, 6, 6, -1, -1]

입출력 예 설명

입출력 예 #1

    2의 뒷 큰수는 3입니다. 
    
    첫 번째 3의 뒷 큰수는 5입니다. 
    
    두 번째 3 또한 마찬가지입니다. 5는 뒷 큰수가 없으므로 -1입니다. 
    
    위 수들을 차례대로 배열에 담으면 [3, 5, 5, -1]이 됩니다.

입출력 예 #2

    9는 뒷 큰수가 없으므로 -1입니다. 
    
    1의 뒷 큰수는 5이며, 5와 3의 뒷 큰수는 6입니다. 
    
    6과 2는 뒷 큰수가 없으므로 -1입니다. 위 수들을 차례대로 배열에 담으면 [-1, 5, 6, 6, -1, -1]이 됩니다.
    
풀이 알고리즘

    자신 오른쪽에 있는 큰 값 중 가장 가까이 있는 값을 출력하는 문제 '뒤에 있는 큰 수 찾기' 입니다.
    
    단순하게 문제풀이를 시도하면 O(n^2) 의 시간복잡도를 가지기 때문에, 효율적인 방법을 찾아 구현해야하는 문제였습니다.
    
    왼쪽부터 탐색을 시작하면, 자신보다 큰 수를 찾기위해 오른쪽을 탐색하는 반복연산이 필요하기 때문에
    
    저는 오른쪽부터 탐색을 시작하였습니다.
    
    풀이 알고리즘은 다음과 같습니다.
    
    0. stack을 선언해두기!
    
    1. 입력된 배열의 오른쪽 끝부터 탐색을 시작.
    
    2. 현재 값과 stack의 top에 존재하는 값 비교 
      2-1. 만약 stack이 비어있을 경우, answer에 -1 push_back 후 stack에 현재값 push
      
      2-2. 현재 값보다 큰 이전값이 stack의 top에 존재한다면 해당 값을 answer에 push_back, stack에 현재값 push
      
      2-3, 현재 값보다 stack의 top값이 작을경우, 큰 값이 나올 때 까지 stack.pop();
      
        2-3-1, 만약 큰 값이 존재한다면 answer에 해당 값 push_back, stack에 현재값 push
        
        2-3-2, 만약 큰 값이 없어서 stack이 empty가 된다면, answer에 -1 push_back. stack에 현재값 push
        
    3. 탐색 종료 후, answer에 든 값은 뒤에서부터 탐색한 정답이기 때문에, reverse를 사용하여 배열 뒤집기
    
    4. 끝!
    
풀이 인증샷 

![image](https://github.com/HHyoS/Algorithm/assets/57944215/83f30aa8-6414-4ed3-9101-d0c3824377f6)

    
