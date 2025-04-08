#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> expected(N);
    for (int i = 0; i < N; ++i) {
        cin >> expected[i];
    }

    // 예상 등수 정렬
    sort(expected.begin(), expected.end());

    // 불만도 계산
    long long dissatisfaction = 0;
    for (int i = 0; i < N; ++i) {
        int actual_rank = i + 1;
        dissatisfaction += abs(expected[i] - actual_rank);
    }

    cout << dissatisfaction << '\n';

    return 0;
}
