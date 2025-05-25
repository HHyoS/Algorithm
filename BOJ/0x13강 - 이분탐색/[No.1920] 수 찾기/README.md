![image](https://github.com/user-attachments/assets/009501ac-fde4-4fba-a3fc-42580a9d120b)문제 사이트 : https://www.acmicpc.net/problem/1920

문제 설명

![image](https://github.com/user-attachments/assets/7c8d0082-69b1-49b7-986c-d03c7f1fdf2b)

풀이 알고리즘

    입력
      입력(1) N개의 입력이 주어지고(최대 10만), 각 값은 long long 범위 내의 양/음의 정수임.
      입력(2) 이후 M개의 입력이 주어지며 각 입력에 대해 입력(1) 내에 해당 값이 있는지 확인 필요

    출력
      입력(2) 과정에서 입력(1) 내에 해당 값이 있다면 1, 없다면 0을 출력

    풀이 알고리즘
      1) long long 범위로 N개의 입력(1)을 받음
      2) 입력(1)을 받은 후 오름차순으로 정렬
      3) M개의 입력(2)를 받으며 이분 탐색을 통해 입력(1) 내에 입력(2)가 있는지 확인
      4) 없다면 0, 있다면 1을 출력
      5) 이분탐색 코드는 아래 참조

  풀이 코드

    #include <iostream>
    #include <algorithm>
    #include <vector>
    
    using namespace std;

    int N, M;
    vector<long long> v;
    bool bs(long long target) {
    	int s = 0;
    	int e = v.size() - 1;
    
    	while (s <= e) {
    		int mid = (s + e) / 2;
    
    		// 현재 위치의 값이 목표 값보다 크다면 e를 현재 위치 -1
    		if (target < v[mid]) {
    			e = mid - 1;
    		}
    		// 현재 위치의 값이 목표 값보다 작다면 s를 현재 위치 +1
    		else if (target > v[mid]) {
    			s = mid + 1;
    		}
    		else {
    			return 1;
    		}
    	}
    	return 0;
    }
    void Input() {
    	cin >> N;
      // N개의 입력(1)
    	for (int i = 0; i < N; ++i) {
    		long long tmp;
    		cin >> tmp;
    		v.push_back(tmp);
    	}
      // 오름차순 정렬
    	sort(v.begin(), v.end());

      // M개의 입력
    	cin >> M;
    	for (int i = 0; i < M; ++i) {
    		long long tmp;
    		cin >> tmp;
        // 입력(1)에 있는지 확인 및 출력
    		cout << bs(tmp) << "\n";
    	}
    }
    int main(int argc, char** argv)
    {
    	ios::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    	Input();
    	return 0;
    }
  
풀이 후기

    기본적일 이분탐색 문제.
    다음에는 어려운거 풀어야지

![image](https://github.com/user-attachments/assets/0543867c-d1d9-4db6-8a48-51eaeb36585f)

