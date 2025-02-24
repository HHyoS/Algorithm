#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    문제 사이트 : https://www.acmicpc.net/problem/1238
    문제 설명 : 
      앞에 문제 안풀고 편식까지 했는데 다른 사람보다 늦게 풀었다..
      주말에 복수 간다 딱대
      */

struct Node {
    int root;
    int location;
    int cost;
};
struct Info {
    int end;
    int cost;
};
bool operator<(Node a, Node b) {
    if (a.cost == b.cost) {
        return a.location < b.location;
    }

    return a.cost > b.cost;
}
priority_queue<Node> que;
vector<Info> v[1010];
int minCost[1010][1010];
int N, M, X;


void Find_Shortest() {
    
    for (int a = 1; a <= N; ++a) {
        que.push({ a,a,0 });
    }

    while (!que.empty()) {
        Node nNode = que.top();
        que.pop();

        int s = nNode.location;
        int cost = nNode.cost;

        for (int a = 0; a < v[s].size(); ++a) {
            int nCost = cost + v[s][a].cost;
            int e = v[s][a].end;

            if (nCost > minCost[nNode.root][e]) continue;

            minCost[nNode.root][e] = nCost;
            que.push({ nNode.root,e,nCost });
        }
    }

    for (int a = 1; a <= N; ++a) {
        minCost[a][a] = 0;
    }

}
void Solve() {

    Find_Shortest();

    int ans = 0;
    for (int a = 1; a <= N; ++a) {
        ans = max(ans, minCost[a][X] + minCost[X][a]);
    }
    cout << ans;
}


void Input() {
    cin >> N >> M >> X;
    for (int a = 0; a <= N; ++a) {
        for (int b = 0; b <= N; ++b) {
            minCost[a][b] = 21e8;
        }
    }
    for (int a = 0; a < M; ++a) {
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({ e,c });
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
