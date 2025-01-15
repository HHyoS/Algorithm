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
