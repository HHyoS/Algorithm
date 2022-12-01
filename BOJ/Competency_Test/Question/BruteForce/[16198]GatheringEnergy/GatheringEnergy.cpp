#include <iostream>
#include <algorithm>
using namespace std;
 
int N, W[10];
bool chk[10];
int func()
{
    int ret = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        if (chk[i])    continue;
        int left = i - 1;
        int right = i + 1;
        while (chk[left])    --left;
        while (chk[right])    ++right;
        chk[i] = true;
        ret = max(ret, func() + W[left] * W[right]);
        chk[i] = false;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> W[i];
    cout << func() << '\n';
}
