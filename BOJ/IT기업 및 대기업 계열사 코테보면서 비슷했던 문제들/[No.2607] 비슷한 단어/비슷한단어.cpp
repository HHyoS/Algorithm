#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>
using namespace std;

/*
    비슷한 단어 조건
    1) 같은 구성 = 동일한 알파뱃 + 동일 횟수 사용
    2) 비슷한 구성 = 단 하나의 알파뱃만 차이 
    
    문제 풀이의 방향을 알파뱃 사용 갯수의 차이를 계산하여 풀이하는 것으로 잡는다면
    ex) DOG = D(1) O(1) G(1) 이고, DOGG = D(1) O(1) G(2) = G 한개 차이
    문자의 길이가 다르다면 위와 같이 풀이 가능하지만
    문자의 길이가 같다면
    DOG = D(1) O(1) G(1) / DOZ = D(1) O(1) Z(1) 이므로
    Z(1) G(1) 두개 차이가 발생함.
    
    따라서 하나만 차이가 난다는 것은 두가지로 나누어 생각이 필요
    [1] 동일한 길이 = 차이가 두개 발생했을 때, 유사한 단어
    [2] 다른 길이 = 차이가 하나 발생했을 때, 유사한 단어
*/
int N;
int alpha[27];
vector<string> word;
int checker[27];
void Solve() {
    int ans = 0;
    for (int a = 1; a < word.size(); ++a) {
        memset(checker, 0, sizeof(checker));
        for (int b = 0; b < word[a].size(); ++b) {
            int idx = word[a][b] - 'A';
            checker[idx]++;
        }
        int different = 0;
        for (int b = 0; b < 27; ++b) { // 알파뱃 사용 갯수 차이값 구하기
            different += abs(checker[b] - alpha[b]);
        }
        // 동일한 단어거나 or 단어의 길이가 다르지만 딱 한개만 차이나거나
        // or 동일한 길의 단어지만 알파뱃 하나가 차이나거나
        if (different == 0 || different == 1 || (word[0].size() == word[a].size() && different == 2) ){
            ++ans;
        }
    }
    cout << ans;
}
void Input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        string temp;
        cin >> temp;
        word.push_back(temp);
    }
    for (int a = 0; a < word[0].size(); ++a) {
        alpha[word[0][a] - 'A']++;
    }
}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    Solve();
    return 0;
}
