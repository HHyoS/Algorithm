# 문제 사이트
https://www.acmicpc.net/problem/18870

# 문제 설명
![image](https://github.com/user-attachments/assets/72ea99e0-5d8f-4762-bb8c-de860f238b41)
![image](https://github.com/user-attachments/assets/b0513bd8-bf24-4188-9ba1-a2664f4f49c1)

# 문제 풀이

## 문제 요약
- N개의 좌표가 주어질 때, 각 좌표의 "압축된" 좌표값을 출력해야함.
- 압축된 좌표는 입력 좌표들을 오름차순 정렬하여 중복을 제거한 배열에서, 각 좌표가 몇 번째로 작은 값인지를 인덱스로 표현한 값.
- 예시
  * 입력: 2 4 -10 4 -9
  * 정렬 + 중복 제거: [-10, -9, 2, 4]
  * 압축된 좌표: 2 → 2, 4 → 3, -10 → 0, 4 → 3, -9 → 1
  * 출력: 2 3 0 3 1

## 풀이 알고리즘

1) 중복 제거 + 정렬
- 좌표의 순서를 비교할 때만 필요하므로, 중복된 값은 제거 가능.
- 정렬하면 작은 값일수록 앞에 옴 → 인덱스를 압축값으로 사용 가능.
2) 좌표 → 압축값 매핑
- 정렬된 배열에서 각 좌표를 키로, 인덱스를 값으로 매핑.
- map<int, int> 또는 unordered_map<int, int> 사용 가능.
3) 출력
- 원래 좌표 순서를 유지하면서, 각 좌표의 압축값 출력.

## 풀이 코드 선 요약
1) 입력 받기
- N개 정수 입력을 vector<int> coords에 저장.

2) 정렬 + 중복 제거
- vector<int> temp = coords;
- sort(temp.begin(), temp.end());
- temp.erase(unique(temp.begin(), temp.end()), temp.end());

3) 매핑 생성
- map<int, int> mp; 또는 unordered_map<int, int>
- for (int i = 0; i < temp.size(); i++) mp[temp[i]] = i;

4) 압축 결과 출력
- for (int i = 0; i < N; i++) cout << mp[coords[i]] << ' ';

풀이 코드
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> coords(N);
    for (int i = 0; i < N; i++)
        cin >> coords[i];

    vector<int> temp = coords;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    map<int, int> compressed;
    for (int i = 0; i < temp.size(); i++)
        compressed[temp[i]] = i;

    for (int i = 0; i < N; i++)
        cout << compressed[coords[i]] << ' ';
    cout << '\n';

    return 0;
}
```
