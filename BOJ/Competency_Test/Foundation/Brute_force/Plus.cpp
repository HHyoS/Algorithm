#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

void bfs(int target, int answer, queue<int> que) {
    int size = que.size();
    for (int a = 0; a < size; ++a) {
        int temp = que.front();
            if (temp + 1 < target)
                que.push(temp + 1);
            else if (temp + 1 == target) {
                ++answer;
            }
            if (temp + 2 < target)
                que.push(temp + 2);
            else if (temp + 2 == target) {
                ++answer;
            }
            if (temp + 3 < target)
                que.push(temp + 3);
            else if (temp + 3 == target) {
                ++answer;
            }
        que.pop();
    }
    if(!que.empty())
        bfs(target, answer, que);
    else
        printf("%d\n", answer);
}
int main() {
    int n;
    cin >> n;
    queue<int> que;
    que.push(0);
  //  freopen("input.txt", "r",stdin);
    for (int a = 0; a < n; ++a) {
        int target;
        cin >> target;
        bfs(target, 0, que);
    }
    
    return 0;
}
