#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;


queue<long long> que[2050];
long long gop[11] = { 1,2,4,8,16,32,64,128,256,512,1024 };
long long H, K, R;
long long subNode;

void dfs(int index, int days) {
    if (index == 0) {
        return;
    }
    int end = index << 1;
    int gopgop = gop[days];
    int size = que[index].size();
    if (days % 2 == 0) {
        for (int a = index; a <= end; a += 2) {
            int target = (a - 1) / 2;
            for (int b = 0; b < size; ++b) {
                que[target].push(que[a].front());
                que[target].push(que[a+1].front());

                que[a].pop();
                que[a + 1].pop();
            }
        }
    }
    else {
        for (int a = index; a <= end; a += 2) {
            int target = (a - 1) / 2;
            for (int b = 0; b < size; ++b) {

                que[target].push(que[a + 1].front());
                que[target].push(que[a].front());

                que[a + 1].pop();
                que[a].pop();
            }
        }
    }
    dfs((index - 1) / 2, days + 1);
}
long long solve() {
    // 업무처리는 최소 H일 이후 발생되므로 H가 R과 같거나 크면 처리되는 업무 X
    if (H >= R)
        return 0;

    // 업무가 시작되는 날이 R-H 일부터이므로 R = R - H
    R -= H;
    int start = subNode - 1;
    
    dfs(start, 1);
    long long ans = 0;
    for (int a = 0; a < R; ++a) {
        if (que[0].empty())
            break;
        ans += que[0].front();
        que[0].pop();
    }
    return ans;

}
void input() {
    cin >> H >> K >> R;
    subNode = gop[H];
    long long start = subNode - 1;
    for (int a = 0; a < subNode; ++a) {
        for (int b = 0; b < K; ++b) {
            long long temp;
            cin >> temp;
            que[start + a].push(temp);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);

    input();
    cout << solve();
    return 0;
}
