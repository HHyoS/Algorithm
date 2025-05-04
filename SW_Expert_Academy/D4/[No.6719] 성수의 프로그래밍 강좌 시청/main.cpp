#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N, K;
        cin >> N >> K;
        vector<int> lectures(N);
        for (int i = 0; i < N; ++i) {
            cin >> lectures[i];
        }

        // 수준 높은 K개 선택
        sort(lectures.begin(), lectures.end());
        vector<int> selected(lectures.end() - K, lectures.end());

        // 낮은 순으로 시청
        sort(selected.begin(), selected.end());

        double skill = 0.0;
        for (int level : selected) {
            skill = (skill + level) / 2.0;
        }

        cout << "#" << test_case << " " << fixed << setprecision(6) << skill << endl;
    }
    return 0;
}
