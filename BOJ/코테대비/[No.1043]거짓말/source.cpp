#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int N, M, K;
vector<int> know;
vector<int>infomation[51];


int parent[51];
int target;
int Find(int idx) {
    if (idx == parent[idx])
        return idx;

    return parent[idx] = Find(parent[idx]);
}

void Union(int A, int B) {
    int pA = Find(A);
    int pB = Find(B);

    parent[pB] = pA;
}

bool check(int idx) {
    for (int a = 0; a < infomation[idx].size(); ++a) {
        for (int b = 0; b < know.size(); ++b) {
            if (Find(know[b]) == Find(infomation[idx][a]))
                return 0;
        }
    }
    return 1;
}
int getAnswer() {

    for (int a = 0; a <= N; ++a) {
        parent[a] = a;
    }
    for (int a = 0; a < K; ++a) {
        int temp;
        cin >> temp;
        know.push_back(temp);
    }
    for (int a = 0; a < M; ++a) {
        int size;
        cin >> size;
        for (int b = 0; b < size; ++b) {
            int temp;
            cin >> temp;
            infomation[a].push_back(temp);
            if (b > 0) {
                if (Find(infomation[a][0]) == Find(infomation[a][b]))continue;
                Union(infomation[a][0], infomation[a][b]);
            }
        }
    }

    int ans = 0;
    for (int a = 0; a < M; ++a) {
        if (check(a)) {
            ++ans;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  //  freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;
    if (K == 0) {
        int temp;
        while (cin >> temp);

        cout << M;
    }
    else {
        cout << getAnswer();
    }

    return 0;

}
