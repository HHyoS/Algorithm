![defaultImage](https://user-images.githubusercontent.com/57944215/214215053-2c647cae-f66d-4cec-9930-571052424731.png)

문제 사이트 : https://softeer.ai/practice/result.do?eventIdx=1&submissionSn=SW_PRBL_SBMS_136032&psProblemId=391#hold

문제 설명 :

    수퍼바이러스가 숙주의 몸속에서 0.1초당 P배씩 증가한다.

    처음에 수퍼바이러스 K마리가 있었다면 N초 후에는 총 몇 마리의 수퍼바이러스로 불어날까?

    N초 동안 죽는 수퍼바이러스는 없다고 가정한다.

    수퍼바이러스는 일반 바이러스에 비해서 훨씬 오래 생존할 수 있기 때문에 N이 매우 클 수 있다.

제약조건

    1 ≤ K ≤ 108 인 정수

    1 ≤ P ≤ 108 인 정수

    1 ≤ N ≤ 1016 인 정수

입력형식

    첫 번째 줄에 처음 바이러스의 수 K, 증가율 P, 총 시간 N(초)이 주어진다.

출력형식

    최종 바이러스 개수를 1000000007로 나눈 나머지를 출력한다.

입력예제1

    1 2 1

출력예제1

    1024
    
풀이 알고리즘

    수학문제의 기출변형(?)을 알수있었던 문제 '수퍼바이러스' 입니다.
    
    단순하게 수학적 계산으로 접근할 경우 N의 최대값인 N^16 에 의해 시간초과가 발생하는 문제였습니다.
    
    구현과정에서 자잘한 실수가 많아서 '틀렸습니다.'를 너무많이봐서 멘탈이 깨질뻔 했지만! 결국 풀어냈습니다.
    
    풀이는 다음과 같습니다.
    
    1. N의 숫자가 매우 크므로 이분탐색으로 접근해야한다.
    
    2. 모듈러 연산의 특징에 의해 특정 나머지 연산은 N번 연산 = 1번 연산과 같으므로 지속적으로 연산을 한다.
    
    3. 1~2의 연산은 다음과 같은 특징을 갖는다 F(x)가 연산의 결과라고 했을 떄
    
    4. F(x) = (F(x/2)%1000000007)*(F(x/2)%1000000007)
    
    5. 그러므로 바이러스가 N초 퍼졌을 때의 바이러스 갯수를 출력하기 위해서는 X가 N보다 작은 범위내에서
    
    P^X ( 1 <= X <= N ) P의 제곱값들을 미리 구해두면 된다.
    
    6. 그렇게되면 top-down 방식으로 N이 0이 될떄까지 미리 구한 제곱값들의 곱을 구한 뒤 (1000000007 나누기연산은 계쏙)
    
    7. 마지막에 K와 구한 값을 곱해주고(1000000007나누기연산도) 출력하면 답이 됩니다.


풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/214215121-67282aee-ef66-4bcf-9fdf-03fa7d5d073f.png)

![image](https://user-images.githubusercontent.com/57944215/214215098-f7cb4f7d-d261-4c68-b0a8-dc302d1db46f.png)
