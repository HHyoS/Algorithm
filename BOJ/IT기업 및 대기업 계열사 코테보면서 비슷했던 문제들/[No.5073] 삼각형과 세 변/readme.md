문제 사이트 : https://www.acmicpc.net/problem/5073

문제 설명 :

![image](https://github.com/user-attachments/assets/c7568949-0918-41f9-97ed-43f7ed822f87)
![image](https://github.com/user-attachments/assets/555a69b5-322c-48c2-8662-f2b133c798c2)

풀이 알고리즘

    문제에서 주어진 조건을 바탕으로 입력값으로 들어온 삼각형의 형태를 출력하는 문제 '삼각형과 세 변' 입니다.

    자세한 조건에 대해 확인이 필요한 문제로 단순하게 아래 조건만 확인하면 틀릴 수 있는 문제 였습니다.

        Equilateral :  세 변의 길이가 모두 같은 경우
        Isosceles : 두 변의 길이만 같은 경우
        Scalene : 세 변의 길이가 모두 다른 경우

    Isosceles와 Scalene의 조건 중 아래 조건 확인이 반드시 필요한 문제로
    
      '가장 긴 변의 길이보다 나머지 두 변의 길이의 합이 길지 않으면 삼각형의 조건을 만족하지 못한다.'

    해당 케이스에 만족하지 못하는 입력값을 Invalid 처리하면 됩니다.

풀이 코드

    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <unordered_map>
    using namespace std;
    
    
    void get_answer(int a, int b, int c) {
    	if (a == b && a == c) {
    		cout << "Equilateral\n";
    	}
    	else if ((a == b && a != c) || (a == c && a != b) || (b == c && a != b)) {
    
    		int total_sum = a + b + c;
    		int max_num = max(a, max(b, c));
    		if (total_sum <= max_num * 2) {
    			cout << "Invalid\n";
    		}
    		else {
    			cout << "Isosceles\n";
    		}
    	}
    	else {
    		int total_sum = a + b + c;
    		int max_num = max(a, max(b, c));
    		if (total_sum <= max_num * 2) {
    			cout << "Invalid\n";
    		}
    		else {
    			cout << "Scalene\n";
    		}
    	}
    }
    void Input_And_Solve() {
    	int a, b, c;
    
    	while (1) {
    		cin >> a >> b >> c;
    		if (a == 0 && b == 0 && c == 0) {
    			return;
    		}
    
    		get_answer(a, b, c);
    	}
    }
    
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    
    	Input_And_Solve();
    
    	return 0;
    }

풀이 후기

    문제를 잘 읽고 분기를 멋지게 쳐보자
![image](https://github.com/user-attachments/assets/c1647270-64a2-4cfd-8344-847dd3fa4afd)
