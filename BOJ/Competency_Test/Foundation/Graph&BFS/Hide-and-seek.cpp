#include <cstdio>
#include <queue>
using namespace std;
bool arr[100001];
int n, m;
int sm = 100002;
int sz;
int main() {
  //  freopen("Input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    queue<int> que;
    que.push(n);
    int count = 0;
    while (!que.empty()) {
        sz = que.size();
        for (int a = 0; a < sz; ++a) {
            int q = que.front();
            if (q == m) {
                printf("%d", count);
                return 0;
            }

            que.pop();
            arr[q] = 1;
            if (q >= 1 && !arr[q - 1])
                que.push(q - 1);
            if (q * 2 <= 100000 && !arr[q * 2])
                que.push(q * 2);
            if (q <= 99999 && !arr[q + 1])
                que.push(q + 1);
        }
        ++count;
    }
    return 0;
}
