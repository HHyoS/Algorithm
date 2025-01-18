문제 사이트 : https://www.acmicpc.net/problem/22233

![image](https://github.com/user-attachments/assets/0c702674-1287-4f39-b3a7-501b4cf8cc41)
![image](https://github.com/user-attachments/assets/05926b87-6ea0-4574-ac7b-9b6abfc49788)
![image](https://github.com/user-attachments/assets/46fbe641-000d-4f44-a895-32c7ff6183db)

풀이 알고리즘

    주어진 조건에 따라 문제 풀이를 진행하면 쉽게 풀 수 있는 문제 "가희와 키워드" 입니다.

    위 문제에서 주어지는 입력 값은 두 종류료 1) 메모장 키워드 2) 블로그 키워드 입니다.

    메모장 키워드는 초기에 입력되는 값으로, 이후 블로그 키워드에 의해 지워지는 값입니다.

    블로그 키워드는 메모장 키워드를 지우는 값들로, 블로그 키워드에 메모장 키워드가 포함되어

    있다면 메모장 키워드에서 블로그 키워드가 지워지게 됩니다.

    블로그 키워드는 중복되거나 메모장 키워드에 없는 값이 들어올 수 있습니다.

    문제 풀이입니다.

    입력값은 모두 string 타입으로 메모장 키워드 - 블로그 키워드 가 되어야 하므로

    unordered_map 구조체를 사용하여 메모장 키워드 입력값을 저장하였고,

    블로그 키워드가 입력되었을 때 , 기준을 파싱하여 메모장 키워드에 블로그 키워드가 있는지

    체크하고 있다면 메모장 키워드를 삭제하는 식으로 구현 진행 했습니다.

    남아있는 메모장 키워드를 블로그 키워드 입력시마다 탐색하여 정답을 출력하는 것은

    불필요한 연산이라고 생각되었고, 전역변수에서 메모장 키워드의 개수를 저장하고

    메모장 키워드가 지워졌을 때 해당 값을 줄여가며 추가 탐색 없이 해당 값만 출력하여

    문제 해결 하였습니다.

풀이 코드

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <memory.h>
    #include <string>
    #include <unordered_map>
    using namespace std;
    
    
    
    unordered_map<string, int> mp;
    int N, M;
    int ans_cnt = 0;
    
    bool del(string keyword, int s, int e) {
    
        if (e == -1) {
            string target_keyword = keyword.substr(s);
            if (mp.count(target_keyword) != 0 && mp[target_keyword] > 0) {
                mp[target_keyword]--;
                --ans_cnt;
            }
            return 0;
        }
        else {
            int sz = keyword.size();
            string target_keyword = keyword.substr(s, e-s);
            if (mp.count(target_keyword) != 0 && mp[target_keyword] > 0) {
                mp[target_keyword]--;
                --ans_cnt;
            }
            return 1;
        }
        
    }
    void blog(string keyword) {
    
    
        int idx = 0;
        while (1) {
            int target = keyword.find(",", idx);
            if (del(keyword,idx, target)==0) {
                return;
            }
            else {
                idx = target + 1;
            }
        }
    
    }
    
    void Input() {
        cin >> N >> M;
        for (int a = 0; a < N; ++a) {
            string temp;
            cin >> temp;
            mp[temp]++;
            ++ans_cnt;
        }
        for (int a = 0; a < M; ++a) {
            string keyword;
            cin >> keyword;
            blog(keyword);
            cout << ans_cnt << "\n";
            //  cout << blog(keyword) << "\n";
        }
    }
    int main() {
        ios::sync_with_stdio(false);
    
        cin.tie(NULL);
        cout.tie(NULL);
        Input();
        return 0;
    }

풀이 후기

    파싱하다가 잘못 구현해서 당황했다리~

![image](https://github.com/user-attachments/assets/a756e984-1129-4eb2-84ec-fa2d6db86434)
