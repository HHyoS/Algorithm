#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m;
int visit[32001];
stack <int> ans;
void dfs(vector <vector<int>>& graph, int num) {
    visit[num] = 1;
    for (int a = 0; a < graph[num].size(); ++a) {
        int des = graph[num][a];
        if (visit[des] == 0) dfs(graph, des);
    }
    ans.push(num);
}

void go(vector <vector<int>>& graph) {
    for (int a = 1; a <= n; ++a) {
        if (visit[a] == 0) {
            dfs(graph, a);
        }
    }
}


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n >> m;
    vector <vector<int>> g(n + 1);
    for (int a = 0; a < m; ++a) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    go(g);
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}
