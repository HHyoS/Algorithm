문제 사이트 : https://www.acmicpc.net/problem/12919

문제 설명 :

![image](https://github.com/user-attachments/assets/a9ab7453-3be0-42ed-a4fb-dc6154a7842c)
![image](https://github.com/user-attachments/assets/51a8b9e0-7aba-4527-bebb-7259e559947a)

풀이 알고리즘

      문자열 게임의 조건에 따라 입력된 문자열을 이용하여 게임을 진행하는 문제 '문자열 게임2' 입니다.
      문자열 게임의 핵심 조건은 두가지 입니다.
        1) 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
        2) 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로
        같은 가장 긴 연속 문자열의 길이를 구한다.

      두 가지 조건에 대해 단순 for문으로 할 경우 시간 초과가 발생하고, 슬라이딩 윈도우로 할 경우
      풀이가 불가능 합니다.

      특정 문자가 K라는 조건을 달성하기 위해서는 특정 문자가 어느 위치에 저장되었는지 모두 기록이 필요하기 때문에
      저는 알파벳 별로 위치를 저장하는 벡터를 선언하였고, 벡터 내에서 x위치아 K 번째 등장하는 위치 차이를 찾아
      그 값 중 최소, 최대값을 구하여 문제 풀이를 완료하였습니다.

      자세한 설명은 풀이 코드의 주석을 통해 확인 부탁드립니다.

풀이 코드

    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <string>
    using namespace std;
    
    int N;
    
    // 각 알파벳이 어느 위치에 등장햇는지 기록하는 벡터
    vector<int> v[27];
    void Solve(string W,int K) {
        // 최소는 가장 크게, 최대는 가장 작게
        int shortest = 21e8; 
        int longest = 0;
    
        // 알파벳 위치 기록
        for (int a = 0; a < W.size(); ++a) {
            int idx = W[a] - 'a';
            v[idx].push_back(a);
        }
    
        // 특정 알파벳이 K개 이하라면 연산 가치가 없음
        for (int a = 0; a < 27; ++a) {
            if (v[a].size() < K) {
                continue;
            }
            // K개 이상이라면
            else {
                // 현재 위치가 x라고 했을 때, x+K-1 인덱스에 존재하는 위치는 특정 알파벳을
                // K개 포함하는 최소, 최대 위치의 가능성이 있음
                for (int b = K-1; b < v[a].size(); ++b) {
                    // 해당 값을 일단 최대 최소와 비교해서 넣어주자
                    shortest = min(shortest,v[a][b] - v[a][b-K+1]+1);
                    longest = max(longest, v[a][b] - v[a][b-K+1] + 1);
                }
            }
        }
        // 최대와 최소 모두 초기값과 동일하다면 조건과 일치하는 알파벳이 없음
        if (shortest == 21e8 && longest == 0) {
            cout << "-1 \n";
        }
        // 두 조건 중 하나라도 만족하면 두 값 모두 갱신되므로 출력
        else {
            cout << shortest << " " << longest << "\n";
        }
    }
    void Input() {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            string W;
            int K;
            cin >> W >> K;
            Solve(W,K);
            // 각 벡터는 재활용 하고 있으므로 초기화 해주기
            for (int b = 0; b < 27; ++b) {
                v[b].clear();
            }
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

    쉬우면서 어렵고 풀기 싫지만 풀어야지 에욱
  
![image](https://github.com/user-attachments/assets/1397e50c-b1fd-485d-bb75-c12b36ec8f83)
