#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dari[300001];
vector<int> leftToright;
vector<int> rightToleft;
int leftCnt[300001];
int maxiValue[300001];
int solve() {
    
    leftToright.push_back(dari[0]);
    leftCnt[0] = 1;
    maxiValue[0] = dari[0];
    rightToleft.push_back(dari[N - 1]);
    int ans = 0;
    for (int a = 1; a < N; ++a) {
        if (dari[a] > leftToright.back())
            leftToright.push_back(dari[a]);
        else {
            int idx = lower_bound(leftToright.begin(), leftToright.end(), dari[a]) - leftToright.begin();
            leftToright[idx] = dari[a];
        }
        leftCnt[a] = leftToright.size();
        maxiValue[a] = leftToright.back();
    }
    for (int a = N-2; a >= 0; --a) {
        if (dari[a] > rightToleft.back())
            rightToleft.push_back(dari[a]);
        else {
            int idx = lower_bound(rightToleft.begin(), rightToleft.end(), dari[a]) - rightToleft.begin();
            rightToleft[idx] = dari[a];
        }
        if (maxiValue[a] == dari[a] && maxiValue[a] == rightToleft.back()) {
			int v = leftCnt[a] + rightToleft.size() - 1;
            ans = max(ans,v);
        }
    }
    if(ans == 0)
        ans = 1;
    return ans;
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
