#include <cstdio>

int a[1000][8];
int t, k, ans;

void rotate(int n, int d) {
    int t[8];
    if (d == 1) {
        for (int i=0; i<8; i++) {
            t[(i+1)%8] = a[n][i];
        }
    } else {
        for (int i=0; i<8; i++) {
            t[i] = a[n][(i+1)%8];
        }
    }
    for (int i=0; i<8; i++) {
        a[n][i] = t[i];
    }
}

void solve() {
    while (k--) {
        int n, d;
        scanf("%d %d", &n, &d); n--;
        int direct[1000] = {0};
        direct[n] = d;
        int x=n, y=n+1;
        for (int i=n; i<t-1; i++) {
            if (a[i][2] != a[i+1][6]) direct[i+1] = -direct[i];
            else {
                y = i;
                break;
            }
        }
        for (int i=n; i>0; i--) {
            if (a[i][6] != a[i-1][2]) direct[i-1] = -direct[i];
            else {
                x = i+1;
                break;
            }
        }
        for (int i=x; i<y; i++) {
            if (direct[i]) {
                rotate(i, direct[i]);
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        for (int j=0; j<8; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    scanf("%d", &k);
    solve();
    for (int i=0; i<t; i++) {
        if (a[i][0]) ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}

