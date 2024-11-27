#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


// 주어진 메모리가 넉넉하므로 unordered_map으로 처리해버리자
unordered_map<string, bool> checker;
string word;
void InputData() {
    cin >> word;
    
}

void Solve() {
    int ans = 0;
    int sz = word.size();

  // 모든 케이스를 확인하는 2중 for문을 돌면서
    for (int a = 0; a < sz; ++a) {
        for (int b = 1; b <= sz-a; ++b) {
          // a인덱스부터 b의 길이를 갖는 부분 문자열 자르기
            string temp = word.substr(a, b);

          // 현재 만들어진 부분 문자열이 이전에 사용되었는지 확인
            if (checker.count(temp) == 0) {
                //사용 안되었다면 경우의 수 1 추가
                ++ans;
                checker[temp] = 1;
            }
        }
    }

  // 정답 출력
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    Solve();
    return 0;
}
