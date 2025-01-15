문제 사이트 : 

문제 설명 :

풀이 알고리즘

    1부터 N까지 이어쓴 문장이 주어지고, 임의의 숫자들이 지워졌다고 가정할 때

    N의 최소값을 구하는 문제 '수 이어 쓰기' 입니다..

    사실 이왜맞 문제이긴한데 나름의 풀이를 써보자면 아래와 같습니다.

    1) 1부터 미지의 숫자 N까지 이어쓴 문장이 있기 때문에, 일단 냅다 숫자를 들이밀어보자

    2) 숫자가 없어? 지워진거야~ 있어? 인덱스 +1

    3) 주어진 문장보다 인덱스가 커졌어? 그럼 현재 비교하고 있는 숫자가 정답인거야~

    위의 생각으로 생각없이(?) 풀었는데 맞았습니다

    핳핳
    
풀이 코드 

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    #include <string>
    using namespace std;
    
    /*
      어떻게 풀지 고민하다가 그냥 냅다 구현했는데 맞아버린 문제
      그냥 수를 들이 밀고 맞는게 있으면 하나 증가, 없으면 지워졌다 가정해서 풀이 진행
      이게 왜 맞쥬?
    */
    string sejuns;
    int Solve() {
        int num = 1;
        int idx = 0;
        int sz = sejuns.size();
        while (idx < sz) {
            string target = to_string(num);
    
            for (int a = 0; a < target.size(); ++a) {
                if (sejuns[idx] == target[a]) { // 만약 숫자가 있다면 안지워짐
                    ++idx;
                    if (idx >= sz) {
                        return num;
                    }
                }
              // 숫자가 없다며 지워짐 ㅋ
            }
            ++num;
        }
    }
    void Input() {
        cin >> sejuns;
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        cout << Solve();
        return 0;
    }

풀이 후기

    30분 고민하다가 그냥 들이 박았는데 맞아버린 문제..

    이런 유형의 문제는 아이디어가 중요한데 많이 까먹은거 같아서 많이 풀어봐야 할 듯?

![image](https://github.com/user-attachments/assets/8f2ec06a-9d4c-4c56-b03a-9916314bb0f1)
