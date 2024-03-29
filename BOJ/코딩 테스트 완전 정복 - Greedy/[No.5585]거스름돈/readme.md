문제 사이트 : https://www.acmicpc.net/problem/5585

문제 설명 :

    타로는 자주 JOI잡화점에서 물건을 산다. 
    
    JOI잡화점에는 잔돈으로 500엔, 100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 개수가 가장 적게 잔돈을 준다. 
    
    타로가 JOI잡화점에서 물건을 사고 카운터에서 1000엔 지폐를 한장 냈을 때, 
    
    받을 잔돈에 포함된 잔돈의 개수를 구하는 프로그램을 작성하시오.

입력

    입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져있다.

출력

    제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 매수를 출력하시오.

예제 입력 1 

    380

예제 출력 1 

    4

예제 입력 2 

    1

예제 출력 2 

    15
    
풀이 알고리즘 

    문제에서 제시하는 물건의 가격이 주어졌을 때, 1000엔을 낸 이후 거스름돈의 최소 갯수를 출력하는 문제 '거스름돈' 입니다.
    
    거스름돈의 단위는 500엔, 100엔, 50엔, 10엔, 5엔, 1엔 입니다.
    
    문제의 풀이는 단순합니다.
    
    1) 물건의 가격이 X라고 했을 때, 거스름돈의 총액은 1000-X 입니다.
    
    2) 거스름돈의 총 갯수가 가장 적어야 하므로 가장 큰 비용인 500부터 시작해서 나누어 해당 거스름돈이 남은 잔액보다 작을경우
    
    해당 거스름돈으로 최대한 지불한 후 나머지는 작은 단위의 거스름돈으로 처리하고, 거스름돈의 잔액이 0원이 될때까지
    
    반복해주면 문제가 해결됩니다.
    
풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/222452060-53c15a07-b67a-489c-a832-37b684da647a.png)
