#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int ans = numeric_limits<int>::max();

// 재귀적으로 치킨집 조합을 생성하여 도시의 치킨 거리를 계산하는 함수
void combination(vector<int>& indices, int start, int k) {
    if (k == 0) {
        int sum = 0;
        // 각 집에 대해 가장 가까운 치킨집까지의 거리를 계산
        for (auto& house : houses) {
            int d = numeric_limits<int>::max();
            for (int idx : indices) {
                int cx = chickens[idx].first;
                int cy = chickens[idx].second;
                int dist = abs(house.first - cx) + abs(house.second - cy);
                d = min(d, dist);
            }
            sum += d;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = start; i < chickens.size(); i++) {
        indices.push_back(i);
        combination(indices, i + 1, k - 1);
        indices.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            if (x == 1)
                houses.push_back({i, j});
            else if (x == 2)
                chickens.push_back({i, j});
        }
    }
    
    vector<int> indices;
    combination(indices, 0, m);
    
    cout << ans << "\n";
    return 0;
}
