문제 사이트 : https://www.acmicpc.net/problem/10799

문제 설명 : 

    여러 개의 쇠막대기를 레이저로 절단하려고 한다. 
    
    효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고,
    
    레이저를 위에서 수직으로 발사하여 쇠막대기들을 자른다. 
    
    쇠막대기와 레이저의 배치는 다음 조건을 만족한다.

    쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다. 
    
    - 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
    
    각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
    
    레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다. 
    
    아래 그림은 위 조건을 만족하는 예를 보여준다. 
    
    수평으로 그려진 굵은 실선은 쇠막대기이고, 
    
    점은 레이저의 위치, 수직으로 그려진 점선 화살표는 레이저의 발사 방향이다.

<img width="267" alt="1" src="https://user-images.githubusercontent.com/57944215/149329922-30fdb4d5-cad7-4b15-9ae5-7ab36411d406.png">


    이러한 레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있다.

    레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 
    
    또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
    
    쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다. 
    
    위 예의 괄호 표현은 그림 위에 주어져 있다.

    쇠막대기는 레이저에 의해 몇 개의 조각으로 잘려지는데, 
    
    위 예에서 가장 위에 있는 두 개의 쇠막대기는 각각 3개와 2개의 조각으로 잘려지고, 
    
    이와 같은 방식으로 주어진 쇠막대기들은 총 17개의 조각으로 잘려진다. 

    쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 주어졌을 때, 
    
    잘려진 쇠막대기 조각의 총 개수를 구하는 프로그램을 작성하시오.

입력

    한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다. 괄호 문자의 개수는 최대 100,000이다. 

출력

    잘려진 조각의 총 개수를 나타내는 정수를 한 줄에 출력한다.

예제 입력 1 

    ()(((()())(())()))(())

예제 출력 1 

    17

예제 입력 2 

    (((()(()()))(())()))(()())

예제 출력 2 

    24
    
[ 풀이 알고리즘 ]

    주어진 문자열을 조건에 맞추어 막대와 레이저로 구분하고, 레이저가 막대를 몇조각으로 나누는지
    
    출력하는 문제였습니다.
    
    이 문제에서 발생하는 상태를 총 세가지입니다.
    
    1. 막대가 생성
    2. 막대의 끝
    3. 레이저 발사
    
    생성 케이스는 '(' 문자열이 나온 후 다음 문자열 조합이 '(' + ')' 가 아닌 경우 막대가 생성됩니다.
    
    끝 케이스는 ')' 문자열이 나오기 전 문자열 조합이 '(' + ')' 가 아닐경우 막대가 끝납니다.
    
    발사 케이스는 '(' 이후 문자열이 ')' 일 경우 레이저가 발사됩니다.
    
    이를 알고리즘으로 구현하였고 그 알고리즘은 다음과 같습니다.
    
    [ 생성 케이스 ]

        문자열을 S라고 할 떄

        현재 인덱스가 a 이고, S[a] = '(' 라면, S[a+1] != ')' 라면 막대가 생성 
    
    [ 발사 케이스 ]
      
        현재 인덱스가 a 이고. S[a] = ')'라면, S[a+1] == ')' 일떄 발사.
        
    [ 끝 케이스 ]
    
        if 문으로 [ 생성 ], [ 발사 ] 케이스가 모두 처리된 이후에는 S[a] = ')' 일떄
        
        막대의 끝을 나타내는 케이스.
        
    [ 막대 증가 케이스 ]
    
        1. 레이저가 발사될 떄 
          
          막대는 레이저가 발사될 떄현재 존재하는 막대만큼 증가합니다.
        
          만약 현재 존재하는 막대가 세개라면, 레이저가 발사됬을 때 조각난 막대가 세개 증가하고
        
          존재하는 막대가 네개라면, 조각난 막대가 네개 증가합니다.
       
        2. 막대가 끝날 떄.
        
          막대의 끝을 알리는 ')' 문자열이나오면, 해당 막대는 더이상 이어지지 않고 종료되게 됩니다.
          
          이렇게 되면 해당 막대가 종료되며 하나의 막대가 조각난 막대로 판단되어 조각난 막대에 +1이 됩니다.
        
        
[ 구 현 ]

    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <cstdio>
    #include <queue>
    #include <utility>
    #include <vector>
    #include <algorithm>
    using namespace std;

    char stick[100010];
    int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      //freopen("Input.txt", "r", stdin);

      cin >> stick;
      int answer = 0;
      int count = 0;
      for (int a = 0; stick[a]; ++a) {
        if (stick[a] == '(') { // 1. 생성케이스 2. 레이저 케이스 구분
          if (stick[a + 1] == ')') { // 레이저 발사 케이스
            answer += count; // 레이저 발사 케이스이므로, 막대갯수만큼 증가시키고
            ++a; // 다음칸의 ')' 까지 땡겨서 사용한 것이므로 a를 하나 증가시켜 두칸점프 
          }
          else {
            ++count; // 막대 증가 케이스 이므로 막대증가
          }
        }
        else { // 막대의 끝 케이스
          ++answer; // 막대의 끝을 나타내므로, 조각난 막대 하나 증가 후
          --count; // 막대 갯수 감소
        }
      }
      cout << answer; // 조각난 막대기 갯수 
      return 0;
    }
