#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A.begin(), A.end());

    int left = 0;
    long long min_diff = LLONG_MAX;

    for (int right = 0; right < N; ++right) {
        while (left < N && A[right] - A[left] >= M) {
            min_diff = min(min_diff, A[right] - A[left]);
            ++left;
        }
    }

    cout << min_diff << '\n';
    return 0;
}
