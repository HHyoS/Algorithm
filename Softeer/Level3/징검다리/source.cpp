#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int dari[300001];
vector<int> maxi;
int N;
int solve() {
    maxi.push_back(dari[0]);

    for (int a = 1; a < N; ++a) {
        if (dari[a] > maxi.back())
            maxi.push_back(dari[a]);
        else {
            int idx = lower_bound(maxi.begin(), maxi.end(), dari[a]) - maxi.begin();
            maxi[idx] = dari[a];
        }
    }
    return maxi.size();
}
void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        cin >> dari[a];
    }

}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
    cout << solve();
	return 0;
}
