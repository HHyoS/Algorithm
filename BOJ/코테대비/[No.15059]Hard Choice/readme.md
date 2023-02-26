문제 사이트 : https://www.acmicpc.net/problem/15059


문제 설명 : 

     In long flights, airlines offer hot meals. Usually the flight attendants push carts containing the meals down along the aisles of the plane. When a cart reaches your row, you are asked right away: “Chicken, beef, or pasta?” You know your choices, but you have only a few seconds to choose and you don’t know how your choice will look like because your neighbor hasn’t opened his wrap yet. . .

    The flight attendant in this flight decided to change the procedure. First she will ask all passengers what choice of meal they would prefer, and then she will check if the number of meals available in this flight for each choice are enough.

    As an example, consider that the available number of meals for chicken, beef and pasta are respectively (80, 20, 40), while the number of passenger’s choices for chicken, beef and pasta are respectively (45, 23, 48). In this case, eleven people will surely not receive their selection for a meal, since three passengers who wanted beef and eight passengers who wanted pasta cannot be pleased.

    Given the quantity of meals available for each choice and the number of meals requested for each choice, could you please help the flight attendant to determine how many passengers will surely not receive their selection for a meal?

입력

    The first line contains three integers Ca, Ba and Pa (0 ≤ Ca, Ba, Pa ≤ 100), representing respectively the number of meals available for chicken, beef and pasta. The second line contains three integers Cr, Br and Pr (0 ≤ Cr, Br, Pr ≤ 100), indicating respectively the number of meals requested for chicken, beef and pasta.

출력

    Output a single line with an integer representing the number of passengers that will surely not receive their selection for a meal.

예제 입력 1 

    80 20 40
    45 23 48

예제 출력 1 

    11

예제 입력 2 

    0 0 0
    100 100 100

예제 출력 2 

    300

예제 입력 3 

    41 42 43
    41 42 43

예제 출력 3 

    0
    
풀이 알고리즘 

    뭔가 영어로 막 써져있는 문제 'Hard Choice' 입니다.
    
    항상 한글로된 문제를 풀다가, 영어로된 문제도 풀어보고 싶어서 도전한 문제였습니다.
    
    엄청난 지문의 길이에 걱정했지만, 킹파고의 도움으로 해석해본 결과 매우 간단한 문제였습니다.
    
    문제의 설명은 다음과 같습니다.
    
    1. 보유하고있는 C P B 가 주어집니다.
    
    2. 그리고 승객들이 원하는 C P B 가 주어집니다.
    
    3. 자신이 원하는 것을 얻지 못하는 승객의 수를 출력합니다.
    
    풀이 알고리즘 입니다.
    
    1. (입력) C P B와 승객들이 원하는 C P B 인 wantC wantP wnatB 를 입력받습니다.
    
    2. (풀이) 만약 want 붙은 알파뱃이 그냥 알파뱃보다 크다면 그 차이만큼 정답의 수에 추가시켜줍니다.
    
    3. (정답) 정답을 출력합니다.
    
풀이 인증샷 

![image](https://user-images.githubusercontent.com/57944215/221409911-c4f512df-4596-4a34-91b1-538cbd531bb7.png)

    
    
