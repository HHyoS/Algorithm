문제 링크 : https://www.acmicpc.net/problem/1157

문제

    알파벳 대소문자로 된 단어가 주어지면, 
    
    이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
    
    단, 대문자와 소문자를 구분하지 않는다.

입력

    첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 
    
    주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력

    첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
    
    단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

예제 입력 1 

    Mississipi

예제 출력 1 

    ?

예제 입력 2 

    zZa

예제 출력 2 

    Z

예제 입력 3 

    z

예제 출력 3 

    Z

예제 입력 4 

    baaa

예제 출력 4 

    A

풀이 알고리즘

    주어진 조건에 따라 구현하여 문제가 원하는 답을 출력하는 간단한 브롱브롱즈 문제.

    char to int 값으로 전환하는 방법만 안다면 금방 풀 수 있다.

    풀이 방법은 아래와 같음.

    1) 입력받은 문자를 처음부터 끝까지 탐색 진행
    2) 소문자라면 'a', 대문자라면 'A'를 빼주어 ASCII 코드상 0부터 시작하도록 계산
    3) 2를 진행하면서 가장 많이 사용된 알파뱃의 index를 저장해둠
    4) 1이 완료된 이후 for문을 한번 더 돌면서 최대값과 동일하게 사용된 알파벳이 있는지 확인하기
    4-1) 없다면 가장 많이 사용된 알파뱃 출력
    4-2) 있다면 ? 출력

코드

    #include <iostream>
    #include <string>
    #include <algorithm>
    using namespace std;
    
    
    int stone;
    string word;
    int cnt[30];
    void Solve() {
    	int size = word.size();
    	int first = 28;
    	int second = 29;
    	for (int a = 0; a < size; ++a) {
    		char alpa;
    		if (word[a] >= 'a' && word[a] <= 'z') {
    			alpa = word[a] - 'a';
    		}
    		else {
    			alpa = word[a] - 'A';
    		}
    		cnt[alpa]++;
    
    		if (cnt[alpa] >= cnt[first]) {
    			if (alpa != first) {
    				second = first;
    			}
    			first = alpa;
    		}
    	}
    	
    	if (cnt[first] == cnt[second])
    		cout << "?";
    	else
    		cout << char(first + 'A');
    }
    void Input() {
    	cin >> word;
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

후기

    1년 전에 못 풀었는데, 왜 못 풀었는지 몰루?

    for문 두 번 돌면 시간 복잡도가 최대 200만 이여서
    
    1) 1회 for문 2) 2회 for문 두가지 구현했는데, 시간, 메모리 모두 똑같음.. 손해봤다리
    
    ![image](https://github.com/user-attachments/assets/99a7fe16-0de5-473a-beb5-332761cfff98)
