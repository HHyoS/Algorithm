문제 사이트 : https://www.acmicpc.net/problem/9093

문제 설명 : 

	문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.

입력

	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다.
	
	단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.

출력

	각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.

예제 입력 1 

	2
	I am happy today
	We want to win the first prize

예제 출력 1 

	I ma yppah yadot
	eW tnaw ot niw eht tsrif ezirp

코드 및 풀이

	#include <iostream>
	#include <algorithm>
	#include <string>
	#include <stack>
	using namespace std;
	int n;
	int main() {
	//	freopen("Input.txt", "r", stdin);
		scanf("%d ", &n); // 라인수를 입력받음. "%d " 를 함으로써 \n 입력을 함께 처리
		char ch = ' '; // 한 알파벳씩 읽어냄
		stack<char> st; // stack을 이용해서 저장하고 ' '  혹은 '\n'을 ch에서 입력받으면 stack에서 모두다 꺼내서 처리 

		int size = 0; // st의 사이즈를 
		while(scanf("%c",&ch) != -1){ // scanf에서 eof(파일의 끝)을 입력받으면 -1을 출력하는것을 이용하여 while문의 종료조건 처리
			if ((ch != ' ') && (ch != '\n')){ // 입력받은 ch가 스페이스바 혹은 엔터가 아니라면
				st.push(ch);  // stack에 계속 쌓기
			}
			else { // ' ' or '\n' 라면
				size = st.size(); // stack의 사이즈를 저장하고
				for (int a = 0; a < size; ++a) { // // stack의 크기만큼 for문을 돌려 stack을 비워냄
					printf("%c", st.top());
					que.pop();
				}
				printf("%c",ch); // 그 후 스페이스 or 엔터 처리
			}


		}
		return 0;
	}

	찾아보니 getline 함수를 통해 라인으로 입력받고 reverse라는 함수를 이용하여 편하게 처리할 수 있다는 것을 확인햇지만 뭔가 c 같은 투박한 느낌으로 코딩해보고싶어
	하나씩 입력받아 처리하는 방식으로 구현해보았습니다. 

	/* getline(), reverse() 함수 사용 코드 */
	#include <iostream>
	#include <string>
	#include <algorithm>

	using namespace std;

	int main() {
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		int T;
		cin >> T;
	    int sz=0;
		cin.ignore();
		while (T--) {
			string str, Answer;
			getline(cin, str); // 한줄단위로 입력받고
			sz = str.length();
			int Start = 0;
			for (int i = 0; i < sz; i++)
				if (str[i] == ' ') {
					reverse(str.begin() + Start, str.begin() + i); // 입력받은 문장을 담은 변수 str에서 start ~ start +i 번쨰 위치까지의 index에 위치한 알파뱃들의 위치를 reverse
					Start = i + 1; // 다음 start 위치를 옮김
				}

			reverse(str.begin() + Start, str.end()); // eof or \n 은 str[i] == ' ' 조건에 포함되지않으므로 

			cout << str << endl;
		}
	}
