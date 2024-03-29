문제 사이트 : https://school.programmers.co.kr/learn/courses/30/lessons/70129

문제 설명 :

    0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

        x의 모든 0을 제거합니다.
        x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.
        예를 들어, x = "0111010"이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

    0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. 
    
    s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 
    
    이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

    s의 길이는 1 이상 150,000 이하입니다.
    s에는 '1'이 최소 하나 이상 포함되어 있습니다.

입출력 예

    s	              result
    "110010101001"	[3,8]
    "01110"	        [3,3]
    "1111111"	      [4,1]

입출력 예 설명

입출력 예 #1

"110010101001"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차 / 이진 변환 이전 / 제거할 0의 개수	/ 0 제거 후 길이 / 이진 변환 결과

1	    "110010101001"	        6	                6	            "110"

2	    "110"	                1	                2	            "10"

3	    "10"	                1	                1	            "1"

3번의 이진 변환을 하는 동안 8개의 0을 제거했으므로, [3,8]을 return 해야 합니다.

입출력 예 #2

"01110"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차	/ 이진 변환 이전 / 제거할 0의 개수 / 0 제거 후 길이 / 이진 변환 결과

1	          "01110"	          2	                3	            "11"

2	          "11"	            0	                2	            "10"

3	          "10"	            1	                1	            "1"

3번의 이진 변환을 하는 동안 3개의 0을 제거했으므로, [3,3]을 return 해야 합니다.

입출력 예 #3

"1111111"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차	/ 이진 변환 이전	/ 제거할 0의 개수	/ 0 제거 후 길이	/ 이진 변환 결과

1	        "1111111"	          0	                7	              "111"

2	        "111"	              0	                3	              "11"

3	        "11"	              0	                2	              "10"

4	        "10"	              1	                1	              "1"

4번의 이진 변환을 하는 동안 1개의 0을 제거했으므로, [4,1]을 return 해야 합니다.

풀이 알고리즘

    주어진 이진 변환 시뮬레이션의 결과를 출력하는 문제 '이진 변환 반복하기'입니다.
    
    시뮬레이션 문제이므로 문제의 조건에 따라 풀이를 진행하면 되는 문제였습니다.
    
    풀이 방법입니다.
    
        1. 초기에 입력받은 문자열을 S라고 했을 때, S가 "1"이 될때까지 모든 과정 반복
        
        2. S에 존재하는 1과 0의 갯수 카운팅, 0의 갯수는 정답으로 사용해야하므로 따로관리
        
        3. 카운팅한 1의 갯수를 바탕으로 이진법으로 표현한 새로운 문자열 S 생성
        
        4. 현재까지 변환한 횟수 1회 추가
        
        5. S가 "1"이 되었을 경우, 현재까지 제거한 0의 갯수와 변환한 횟수를 return
        
풀이 인증샷

![image](https://github.com/HHyoS/Algorithm/assets/57944215/d947aeeb-1dc3-4a9c-839d-a8eceedec48e)
