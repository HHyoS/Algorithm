#include <iostream>
#include<algorithm>
using namespace std;

int building[1005];
int ans = 0;

void check(int idx) {

    int high = max(building[idx - 1], max(building[idx - 2], max(building[idx + 1], building[idx + 2])));
    if (building[idx] > high)
        ans += (building[idx] - high);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    for (int a = 1; a <= 10; ++a) {
        ans = 0;
        int n;
        cin >> n;
        for (int b = 0; b < n; ++b) {
            cin >> building[b];
        }
        for (int b = 2; b < n - 2; ++b) {
            if (building[b] != 0) {
                check(b);
            }
        }
        cout << "#"<<a<<" "<<ans << "\n";
    }

    return 0;
}
