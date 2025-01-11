#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;


int N;
long long leng[100010];
long long price[100010];

/*풀이 알고리즘
조건 1 : 최소 비용 사용
조건 2 : 주행 중 기름이 떨어져서는 안됨 -> 기름의 양은 현재 위치에서 다음 도시로 갈 정도는 되어야 함
조건 3 : 기름통의 양은 무제한 이므로, 저렴한 곳에서 최대한 채우는게 이득임 
*/

void Solve() {

    long long min_cost = price[0];
    long long total_cost = 0;

    for (int a = 1; a < N; ++a) {
        if (min_cost > price[a]) {
            total_cost += (min_cost * leng[a]);
            min_cost = price[a];
        }
        else {
            total_cost += (min_cost * leng[a]);
        }
    }
    cout << total_cost;
}
void Input() {
    cin >> N;
    for (int a = 1; a < N; ++a) {
        cin >> leng[a];
    }
    for (int a = 0; a < N; ++a) {
        cin >> price[a];
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
