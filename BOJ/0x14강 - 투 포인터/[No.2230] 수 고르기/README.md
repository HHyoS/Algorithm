# 문제 사이트
https://www.acmicpc.net/problem/2230

# 문제 설명

![image](https://github.com/user-attachments/assets/0738f53e-ee6f-435e-9f50-53666fc8f1e7)
![image](https://github.com/user-attachments/assets/9737a299-8e69-4638-bbed-cb9510be6137)

# 풀이 알고리즘
## 입력 처리
- 수열의 크기 N, 최소차이 M, 수열 A를 입력 받음
  
## 정렬
- 수열 A를 오름차순 정렬
  
## 투 포인터
- 두 포인터 left와 right를 사용하여 수열 탐색
- A[right] - A[left]가 M이상인 경우, 그 차이를 min_diff와 비교하여 더 작은 값을 저장
- 조건을 만족하면 left를 증가시켜 다음 가능한 쌍을 확인

## 결과
- min_diff 출력

# 풀이 코드

```cpp
#include <iostream> 
#include <vector>
#include <queue> 
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const long long int INF = 1e10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long int n, m, ans = INF;
    cin >> n >> m;
    vector<long long int> v(n);

    for (int i=0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int left = 0, right = 0;
    while (right < n){
        long long int diff = v[right] - v[left];
        if (diff >= m){
            if (diff < ans)
                ans = diff;
            left++;
        } else{
            right++;
        }
        if (left > right)
            right = left;

    }

    cout << ans;
    
    return 0;
}
```

# 풀이 후기

    마크다운 재밌다
    
![image](https://github.com/user-attachments/assets/c0deef57-4c1a-4ee9-bf6c-23fbbd462180)

