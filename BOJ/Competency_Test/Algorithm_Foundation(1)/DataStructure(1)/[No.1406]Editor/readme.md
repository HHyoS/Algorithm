문제 사이트 :  https://www.acmicpc.net/problem/1406


문제 설명:

	한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

	이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 
	
	문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 
	
	즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

	이 편집기가 지원하는 명령어는 다음과 같다.

		L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)

		D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)

		B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨) 
		삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
		
		P $	$라는 문자를 커서 왼쪽에 추가함
	
	초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 
	
	모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

입력

	첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
	이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.
	둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 
	셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 
	명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

출력

	첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.

예제 입력 1 

	abcd
	3
	P x
	L
	P y
	
예제 출력 1 

	abcdyx
	
예제 입력 2 

	abc
	9
	L
	L
	L
	L
	L
	P x
	L
	B
	P y
	
예제 출력 2 

	yxab

예제 입력 3 

	dmih
	11
	B
	B
	P x
	L
	B
	B
	B
	P y
	D
	D
	P z
	
예제 출력 3 

	yxz

코드 및 설명

프로그램 설계

	1. front, tail, value 를 저장하는 양방향 연결리스트 생성

	2. 문자열을 입력받은 후 리스트끼리 연결시킴

	3. cur의 위치는 연결리스트의 주소값을 사용하여 나타내고, cur의 위치 맨 앞과 뒤는 사용하지 않는 연결리스트[nope]와 연결
	   nope->tail 은 연결리스트의 맨 앞, nope->head = 연결리스트위 맨 뒤를 나타내게함.

	4. [ N ] 명령어와 [ D ] 명령어는 주어진 조건에 맞추어 구현하고

	5. [ B ] 명령어는 커서가 맨 앞일경우에 무시하고, 두번쨰 위치일 경우, 중간, 맨뒤 세가지 조건에 나누어 구현하고

	  두번쨰 위치일경우

		   (nope) - (list 1[사용중]) - {cur}- (list 2[사용중]) - (list 3[사용중]) - nope  일경우

		  nope->tail = list 2 , list 2->head = nope 로 연결시켜 list 1을 비사용상태로 전환

	  맨 뒤일 경우

		  (nope) - (list 1[사용중]) -  (list 2[사용중]) - (list 3[사용중]) - {cur} - nope 다음과 같은 형태가 되는데

		  nope->head = list 2 , list 2->tail = nope 로 연결시켜 list 3을 비연결 상태로 만듬

	 중앙은 일반적 방법으로 구현예정.

	6. [ P ] 명령어는 커서가 맨 앞, 맨 뒤, 중앙 세가지 조건으로 나누어 생각해야하는데

-------------------------------------------------맨앞--------------------------------------------------
  
  (nope) - cur - (list 1[사용중]) -  (list 2[사용중]) - (list 3[사용중]) - nope 일경우

 nope->tail = {list 4[생성}       list 1->head = {list 4{생성}}
     
 list4{생성}.head = nope, list4{생성}.tail = list 1 과 같이 새로운 연결리스트 list 4를 만들어
                      
                      
 (nope) -{list 4{생성} - cur- (list 1[사용중]) -  (list 2[사용중]) - (list 3[사용중]) - nope 

          
-------------------------------------------------맨앞--------------------------------------------------
  
  (nope) -  (list 1[사용중]) -  (list 2[사용중]) - (list 3[사용중]) - cur - nope 일경우

 nope->head = {list 4[생성}       list 3->tail = {list 4{생성}}
     
 list4{생성}.head = list 3, list4{생성}.tail = list nope 과 같이 새로운 연결리스트 list 4를 만들어
                      
                      
 (nope) - (list 1[사용중]) -  (list 2[사용중]) - (list 3[사용중]) - {list 4{생성} - cur - nope 
 
                                                                 
-------------------------------------------------중간--------------------------------------------------
  
  (nope) -  (list 1[사용중]) - cur - (list 2[사용중]) - (list 3[사용중]) -  nope 일경우

 list 1 ->tail = {list 4[생성}       list 2->head = {list 4{생성}}
     
 list4{생성}.head = list 1, list4{생성}.tail = list 2 과 같이 새로운 연결리스트 list 4를 만들어
                      
                      
 (nope) - cur- (list 1[사용중]) -  {list 4{생성} - cur - (list 2[사용중]) - (list 3[사용중])  - nope 

                                 
  와 같이 구현해볼 예정입니다.

------------------------------------------------------------------------------------------------------------
                                 
  위의 알고리즘을 바탕으로 실패한 코드와, 자원 과다사용 코드를 올려놓았습니다.
                                 
  실패한 코드에서는 P연산 이후 cur의 위치 선정의 실수로 인해 실패가 발생하였고, 자원 과다사용 코드는 양방향 연결리스트의 사용이 과다해서 발생한 것으로 보입니다.
                                 
  연결리스트의 최소 샤용갯수를 수정해가며 확인해본 결과, 50만개의 입력케이스에 대응하는 최소 연결리스트 갯수는 60만개정도로 보였습니다.
                                 
   다른 방법으로 구현해볼 방법을 찾아본 결과, 현재 위치를 기준으로 좌_스택, 우_스택 을 구현하고, 
   
   이를 바탕 이용하여 연산을 진행하면 실행 시간과 메모리 사용을 모두 줄일 수 있다는 사실을 확인했습니다.
                                 
  다음에 작성할 코드는 새로운 문제 대신 [ 에디터 ] 문제를 스택으로 구현하여 해결해보려고 합니다.

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ스택사용 구현완료ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
                                 
                                 
                                 
	#include <stdio.h>
	#include <algorithm>
	#include <iostream>

	using namespace std;

	char input_char[100001] = { 0, };
	char l_st[600003]; // 커서기준 왼쪽 문자열 스택
	char r_st[600003]; /// 커서기준 오른쪽 문자열 스택


	int main() {

		int n;
		freopen("Input.txt", "r", stdin);
		scanf("%s", &l_st);
		int l_index = -1, r_index = -1; 

		for (int a = 0; input_char[a]; ++a) { // 입력받은 문자열을 왼쪽 스택에 저장
			l_st[++l_index] = input_char[a];
		}
		scanf("%d", &n);
		char command;
		for (int a = 0; a < n; ++a) {
			scanf(" %c", &command);
			if ((command == 'L') && (l_index >= 0)) // 명령어가 L 이고 l_index >= 0 일경우, 즉 l_st이 빈 스택이 아닐경우
				r_st[++r_index] = l_st[l_index--]; // l_st의 값을 r_st으로 옮기고 l_st의 index 감소, r_st index 증가
			else if ((command == 'D') && (r_index >= 0 )) //  명령어가 D 이고 r_index >= 일경우, 즉 r_st이 빈 스택이 아닐경우
				l_st[++l_index] = r_st[r_index--]; // r_st의 값을 l_st으로 옮기고 r_st의 index 감소, l_st index 증가
			else if ((command == 'B') && (l_index >= 0)) // l_st 이 빈 스택이 아닐경우
					l_index--; // l_st의 값 하나 제외. 즉 l_index 값소
			else { 
				scanf(" %c", &command);
				l_st[++l_index] = command; // l_st에 입력받은 문자열 추가
			}

		}

		l_st[l_index + 1] = r_st[r_index + 1] = 0; // l_st와 r_st 의 끝에 0을 입력하여 배열의 끝을 표기해주고
		reverse(r_st, r_st + r_index + 1); // r_st의 경우 그대로 출력할경우 반대로 출력되므로
	   // ex) l_st = { 1, 2 ,3} r_st = {6 , 5 ,4] 일경우 맨 마지막값을 뽑는 stack은 r_st을 뽑을 떄  -> 5 -> 6 순으로 뽑지만 출력은 6 5 4 로 출력되므로 reverse함수를 이용하여 앞뒤를 바꿔주고  
		fprintf(stdout, "%s%s", l_st, r_st); // printf보다 빠른 fprintf 사용
		return 0;
	}
   
   
   새로운 방법으로 문제를 푸는 경험을 해서 좋은 기회였던것 같습니다. 
   
   하지만 제가 printf와 scanf 를 사용하는 이유가 cin, cout보다 빠르기떄문인데, 비슷한 방법으로 구현된 cin. cout의 코드가 위의 코드보다 실행시간이 더 오래걸림을 확인했습니다.
   
   코드를 비교해보면 169~171 line에서 입력받은 값을 l_st에 옮기는 연산을 제외하고
   
   모두 같다고 볼 수 있는 코드임에도 3배이상 속도차이가 발생했고, 왜 이런 문제가 발생하는지 알고싶었으나
   
   정확한 이유를 알지 못하였습니다. 앞으로는 cin, cout 과 printf,scanf를 비교해가며 사용해야할것같습니다. < 21,11,22 : cout, cin 사용시 사용하는 
   
	   ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		
   3줄의 문장이 사용할 경우 cin, cout이  scanf, printf 보다 더 빠른 속도를 보여주는것을 확인햇습니다.
