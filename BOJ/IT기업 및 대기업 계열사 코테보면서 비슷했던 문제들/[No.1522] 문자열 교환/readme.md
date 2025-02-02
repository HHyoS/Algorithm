문제 사이트 : https://www.acmicpc.net/problem/1522

문제 설명 :

![image](https://github.com/user-attachments/assets/cc6e6075-817b-4bb9-81fd-bc937bf6eb5b)
![image](https://github.com/user-attachments/assets/ce62efcd-f5ad-4819-b619-8e6047e1e2d8)

풀이 알고리즘

    a와 b로 이루어진 문자열이 주어질 때, 모든 a를 연속으로 만들고,, 그 최소 교환 회수를

    출력하는 문제 '문자열 교환' 입니다.

    주어진 문자열 중 a만 모으면 되는 문제로 단순하게 a를 모으는 최소 회수를 구하면 됩니다.

    a를 모으기 위해서는 a의 전체 개수 x를 확인하여 특정 위치에서 시작했을 때 a가 연속 x개가
    
    나오도록 만들면 되는데, 문자열의 길이가 1000이므로 모든 위치에서 for문을 돌려도

    시간 초과가 발생하지 않습니다.

    풀이 방법은 아래와 같습니다.

    1) a의 개수(x) 확인하기

    2) 모든 위치에서 x개를 탐색하여 사이의 b 개수 확인하기
      - 사이의 b 개수가 교환이 필요한 a의 개수임

    3) 2의 연산은 모든 위치에서 반복하여 최소 교환 회수 확인

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    string ab;
    int sz = ab.size();
    int a_cnt = 0;
    int SSolve(int idx) {
    int mov_cnt = 0;
    int aa_cnt = 0;
    int used_b = 0;
    for (int a = 0; a < sz; ++a) {
      int next_idx = (idx + a) % sz;
      if (ab[next_idx] == 'b') {
          ++used_b;
          ++mov_cnt;
      }
      ++aa_cnt;
    
      if (aa_cnt == a_cnt)
          break;
    }
    return mov_cnt;
    }
    
    int Solve() {
    int ans = 21e8;
    for (int a = 0; a < sz; ++a) {
      ans = min(ans,SSolve(a));
    }
    
    if (a_cnt == 0)
      ans = 0;
    
    return ans;
    }
    void Input() {
    cin >> ab;
    sz = ab.size();
    for (int a = 0; a < sz; ++a) {
      if (ab[a] == 'a')
          ++a_cnt;
    }
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

    ez
![image](https://github.com/user-attachments/assets/a989850e-6ab0-4cc6-8336-91b8449ec2ef)

    ez
