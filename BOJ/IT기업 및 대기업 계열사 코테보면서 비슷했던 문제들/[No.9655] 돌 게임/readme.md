문제 사이트 : https://www.acmicpc.net/problem/9655

문제 설명 :

    돌 게임은 두 명이서 즐기는 재밌는 게임이다.

    탁자 위에 돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 
    
    돌은 1개 또는 3개 가져갈 수 있다. 
    
    마지막 돌을 가져가는 사람이 게임을 이기게 된다.

    두 사람이 완벽하게 게임을 했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 
    
    게임은 상근이가 먼저 시작한다.

입력

    첫째 줄에 N이 주어진다. (1 ≤ N ≤ 1000)

출력

    상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 출력한다.

예제 입력 1 

    5
예제 출력 1 

    SK

풀이 알고리즘 :

      문제에서 설명하는 돌 게임의 규칙을 따라 진행했을 때, 이기는 사람이 누구인지 출력하는 문제.
      문제의 룰에서 뜬금없이 1또는 3개를 가져갈 수 있다고 하는데, 실제로 몇가지 케이스에 대해 
      시뮬레이션 해보면 1개 혹은 3개를 가져가는 케이스에서는 같은 사람만 승리 가능.
      수학 규칙에 의해 정해진 승자가 정해지는 것으로 보임.

      아무튼 위 규칙에 따라 승리자는 찾아보면, 단순 시뮬레이션으로 풀이 가능

      1) 돌 개수가 3 이상이면 3씩 돌의 개수를 빼줌.
      2) 돌 개수가 3 미만이면 하나씩 빼주며 승리자를 찾기
          -> 위 방법의 경우 단순하게 0, 2와 1 일경우 나누어서 승리자를 찾는 것도 가능

      위 풀이에서 불필요한 연산을 더 줄여보면

      1) 돌 개수가 3 이상이면 3으로 나머지 연산을 한 뒤, 턴을 계산하여 정답 찾기

      위의 과정으로 압축 가능


정답 코드

    #include <iostream>
    #include <string>
    #include <vector>
    #include <stack>
    using namespace std;
    
    
    int stone;
    string name[2]; // 이름 저장 배열
    void Solve() {
    
    	int turn = (1 + stone / 3)%2;
     // 3이상일 경우 3개씩 돌을 가져갔다는 전재 하에 미리 계산하여 턴 정리해주기
    	stone = stone % 3;
     
        if(stone == 0 || stone == 2){ // 0또는 2일경우 현재 턴인 사람이 승리자
            cout << name[turn];
        }
        else{
            cout << name[(turn+1)%2]; // 아닐 경우 다음 턴 사람이 승리자
        }
    
    	return;
    }
    void Input() {
    	cin >> stone;
    	name[0] = "SK";
    	name[1] = "CY";
    }
    int main()
    {
    	ios::sync_with_stdio(false);
    
    	cin.tie(NULL);
    	cout.tie(NULL);
    
    	Input();
    	Solve();
        return 0;
    }


제출 현황

![image](https://github.com/user-attachments/assets/5b43803e-8e9e-48c6-8e27-a4f8e4073a45)
