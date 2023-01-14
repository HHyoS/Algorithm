![e1c15e21-5cb8-42f8-b3be-59fd05f88e27](https://user-images.githubusercontent.com/57944215/212464925-e77b8e11-ace1-4e5f-87d6-5e2e28255738.jpg)


문제 사이트 : https://softeer.ai/practice/info.do?idx=1&eid=408&sw_prbl_sbms_sn=126486

문제 설명 :


    현대자동차에서는 부드럽고 빠른 변속이 가능한 8단 습식 DCT 변속기를 개발하여 N라인 고성능차에 적용하였다. 
    
    관련하여 SW 엔지니어인 당신에게 연속적으로 변속이 가능한지 점검할 수 있는 프로그램을 만들라는 임무가 내려왔다.

    당신은 변속기가 1단에서 8단으로 연속적으로 변속을 한다면 ascending, 
    
    8단에서 1단으로 연속적으로 변속한다면 descending, 둘다 아니라면 mixed 라고 정의했다.

    변속한 순서가 주어졌을 때 이것이 ascending인지, descending인지,
    
    아니면 mixed인지 출력하는 프로그램을 작성하시오.

제약조건

    주어지는 숫자는 문제 설명에서 설명한 변속 정도이며, 
    
    1부터 8까지 숫자가 한번씩 등장한다.

입력형식

    첫째 줄에 8개 숫자가 주어진다.

출력형식

    첫째 줄에 ascending, descending, mixed 중 하나를 출력한다.

입력예제1

    1 2 3 4 5 6 7 8

출력예제1

    ascending 
    
풀이 알고리즘 

    주어진 입력값에 따라 기어가 1씩 증가/감소 하는 수열 혹은 섞여있는 수열인지 판단하는 문제 8단 변속기입니다.
    
    값이 N개 주어지는게 아닌 8개가 주어지는 입력값을 가지기 때문에 단순히 입력값을 받은 뒤
    
    처음값의 위치를 확인하고 1 or 8 이면 증가/감소하는 수열인지 확인하고, 1과8이 아니라면 mixed 출력
    
    증가/감소 하는 수열인지 확인할 때, 증가/감소하는 수열이 아님이 확인되면 mixed출력
    
    증가/감소하는 수열이라는 해당하는 값인 ascending / descending 을 출력하여 문제를 해결하였습니다.
    
풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/212465040-5402c62c-1b6d-47f4-9bf7-2b1ffaf6251c.png)

![image](https://user-images.githubusercontent.com/57944215/212465047-3df8fb90-50f7-4807-bc00-dce95a9af907.png)
