#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ll B, W, X, Y, Z;
        cin >> B >> W >> X >> Y >> Z;

        // 1) 색깔 맞춰 넣기
        ll normal = B * X + W * Y;

        // 2) 가능한 만큼 swap(흑↔백) 한 경우
        ll k = min(B, W);
        // swap한 쌍 하나당 두 개 mismatch가 생기므로 2*Z
        ll swapped = (B - k) * X
                    + (W - k) * Y
                    + 2LL * k * Z;

        // 최댓값 출력
        cout << max(normal, swapped) << "\n";
    }

    return 0;
}
