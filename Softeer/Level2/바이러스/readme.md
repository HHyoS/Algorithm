![defaultImage](https://user-images.githubusercontent.com/57944215/213617055-6ef91a3a-c34f-44fe-9486-baa2c4dc1581.png)

문제 사이트 : https://softeer.ai/practice/result.do?eventIdx=1&submissionSn=SW_PRBL_SBMS_135471&psProblemId=407#hold

문제 설명 :

    바이러스가 숙주의 몸속에서 1초당 P배씩 증가한다.

    처음에 바이러스 K마리가 있었다면 N초 후에는 총 몇 마리의 바이러스로 불어날까?
    
    N초 동안 죽는 바이러스는 없다고 가정한다.

제약조건

    1 ≤ K ≤ 108인 정수

    1 ≤ P ≤ 108인 정수

    1 ≤ N ≤ 106인 정수

입력형식

    첫 번째 줄에 처음 바이러스의 수 K, 증가율 P, 총 시간 N(초)이 주어진다.

출력형식

    최종 바이러스 개수를 1000000007로 나눈 나머지를 출력하라.

입력예제1

    2 3 2

출력예제1

    18
    
풀이 알고리즘

    주어진 조건에 맞는 수학적 계산을 통해 결과값을 출력하는 문제 '바이러스' 입니다.
    
    해당 문제는 단순 수학문제이지만 주의해야할 점은 K P N 의 값이 모두 10^8 으로 매우 큰 값이라는 것 입니다.
    
    단순히 K개의 바이러스가 1초 지났을 떄 증가한 수치를 구해도 10^8 * 10^8 = 10^16 의 값이 나오므로
    
    long long 값으로 처리하고, 나머지 연산 공식에 (X ^ 3)%Y = ((X*X)%Y)*X%Y 와 같으므로 매 초마다 1000000007로 나누어
    
    long long값의 범위를 초과하지 않도록하여 문제를 해결하였습니다.

풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/213617130-4b2dc0e0-3e03-4782-9d5c-9bf91c3dc5a6.png)

![image](https://user-images.githubusercontent.com/57944215/213617109-0127440a-6723-4cb8-a167-d9a3eb413ded.png)
