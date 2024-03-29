![b8a0157a-9c8b-4094-8d70-f93cdd23715b](https://user-images.githubusercontent.com/57944215/216769487-118d6fea-d7b7-4608-ad57-c19e25d154cd.jpg)

문제 사이트 : https://softeer.ai/practice/info.do?idx=1&eid=413&sw_prbl_sbms_sn=143137

문제 설명 :

    현대자동차그룹이 레벨3 자율주행차 상용화 목표에 발맞춰 총력을 다하고 있는 가운데,

    국내 최고 수준의 지도 구축 기술력을 보유한 현대엠엔소프트는 자율주행에 필요한 정밀지도를 제작해 배포하고,

    기술 고도화를 위한 연구에 매진하고 있다.

    최근에는 도로 데이터를 기반으로 자동으로 정밀지도를 구축하는 ‘지도 자동 구축(Map Auto Creation, 이하 MAC)’ 기술을 

    개발해 지도 제작 시간을 단축하고 정밀도를 향상시키는 데 성공했다.

    자율주행차용 정밀 지도에 관한 궁금증으로 인터넷 검색을 해보니, Diamond-Square-Algorithm이라는 것을 찾게 되었다.

    이 알고리즘은 정사각형을 이루는 점 4개를 고르고 그 후에는 다음과 같은 과정을 거쳐 모양이 만들어진다.

    정사각형의 각 변의 중앙에 점을 하나 추가한다.

    정사각형의 중심에 점을 하나 추가한다.

![20210908_190326973_12643](https://user-images.githubusercontent.com/57944215/216769507-a71d156a-5821-4777-8ad0-a6aa21f066ac.jpg)

    [그림]은 0단계(start)에서 2단계(2 iterations)까지 수행한 결과이다. 

    각 단계(N)가 계속해서 커져갈수록 점의 수가 커져간다.

제약조건

    1 ≤ N ≤ 15

입력형식

    첫째 줄에 N이 주어진다.

출력형식

    첫째 줄에 N단계를 거친 점의 개수를 출력한다.

입력예제1

    1

출력예제1

    9   
    
풀이 알고리즘 

    수학으로 해결할 수 있는 문제 '지도 자동 구축' 입니다.
    
    위 문제에서 한 줄에 존재하는 점의 갯수는 2 -> 3 -> 5 -> 9 순으로 증가하고, 그에따라 전체 점의 갯수는
    
    2*2 -> 3*3 -> 5*5 -> 9*9 로 증가합니다.
    
    여기서 사용되는 숫자인 2,3,5,9는 단계의 증가에 따라 규칙적으로 증가하는데 그 규칙은 다음과 같습니다.
    
    N단계일때 점의 개수 f(N) =  2^(n-1) +1
    
    그래서 정답을 구할떄는 Answer = f(N)*f(N)이 답이 됩니다.
    
    풀이 알고리즘입니다.
    
    1. (입력과 기본 세팅) N이 입력되면 2^(N-1) 까지 값을 미리구해둔다.
    
    2. 구해둔 값에 +1을 한뒤, 해당 값을 제곱하여 답을 출력
    
풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/216769716-6f70b7f0-6880-4124-8f23-4395d09d8590.png)


![image](https://user-images.githubusercontent.com/57944215/216769735-302bf397-8487-46f3-a83f-dd9316fff642.png)

    
