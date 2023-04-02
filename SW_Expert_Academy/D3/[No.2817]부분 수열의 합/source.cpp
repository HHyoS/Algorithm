#include <iostream>
 
using namespace std;
 
int N, K;
int arr[20];
int answer;
 
void makeSum(int idx, int sum) {
 
    //합이 K를 넘는 경우 -> 더 이상 더할 필요없으므로 종료
    if (sum > K) {
        return;
    }
 
    //합이 K인 경우 -> answer갱신 후 종료
    if (sum == K) {
        answer++;
        return;
    }
 
    //자신보다 뒤에 있는 원소 더해보기(중복 제거 위해)
    for (int i = idx; i < N; i++) {
        makeSum(i + 1, sum + arr[i]);
    }
}
 
int main() {
 
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; test_case++) {
 
        //초기화
        N = 0, K = 0;
        answer = 0;
 
        //입력
        cin >> N >> K;
        for (int a = 0; a < N; ++a) {
            cin >> arr[a];
        }
 
        //해법
        /*
        모든 원소 다 더해보기
        */
        makeSum(0, 0);
 
        //출력
        cout << "#" << test_case << " " << answer << "\n";
    }
 
    //종료
    return 0;
}
