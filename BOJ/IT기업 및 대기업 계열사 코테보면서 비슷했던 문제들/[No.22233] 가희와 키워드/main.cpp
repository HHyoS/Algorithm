#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
#include <unordered_map>
using namespace std;


/*
  메모장에 작성된 최대 20만개의 입력이 주어지고, 최대 20만개의 블로그 키워드가 입력될 때
  블로그 키워드에 작성되지 않은 메모장의 키워드 개수를 출력하는 문제 "가희와 키워드" 입니다.

  int형 값 일 경우 단순하게 배열 값을 사용하면 되지만 string 으로 입력되기 때문에

  hash를 사용하여 string 타입도 저장이 가능한 map 자료형을 사용 해야 합니다.

  저는 그 중 데이터 접근의 복잡도가 1인 unordered_map 이라는 자료형을 사용하여 구현했습니다.

  본 문제에서는 정렬의 유무가 크게 중요하지 않기 때문에
  
  map 자료형과 같이 정렬로 인한 시간 복잡도가 발생하는 자료형의 사용이 필요하지 않다고

  생각 됩니다.

*/

unordered_map<string, int> mp; // 메모장 키워드가 몇 번 작성되었는지 저장하는 변수
int N, M;
int ans_cnt = 0; // 정답 개수


// 단어를 파싱하여 unordered_map 구조체에서 지울 키워드가 있는지 확인 후
// 지울 수 있다면 정답 개수 -1 해주는 함수
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

  // 블로그 키워드는 ,로 구분되므로 , 기준으로 파싱하여 메모장에서 삭제 가능한지 확인
  // 만약 ,을 찾지 못했다면 더 이상 단어를 찾을 필요가 없으므로 return
  // 아닐 경우 다음 단어를 찾기 위해 while문 진행
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

  // 메모장에 작성된 키워드들의 개수를 카운팅하는 for문
  // 메모장에 같은 키워드가 작성되지 않는다는 조건이 없으므로 개수를 카운티함
    for (int a = 0; a < N; ++a) {
        string temp;
        cin >> temp;
        mp[temp]++;
        ++ans_cnt;
    }
  // 블로그에 작성된 키워드를 받아 메모장에서 키워드를 지우는 for문
  // 정답의 출력은 블로그에 작성된 키워드들을 입력받을 때마다 해주어야 하므로
  // 매번 출력
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
