#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

bool isCheck[100010];

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;
    int answer_count = 0;

    cin >> N >> K;
    queue<pair<int, int>> q;
    q.emplace(N, 0);

    while (!q.empty()) {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        isCheck[locate] = true;
        isCheck[K] = false;

        if (answer == 0 && locate == K) {
            answer = cost;
            answer_count++;
            continue;
        }

        if (answer != 0 && answer == cost && locate == K) {
            answer_count++;
            continue;
        }

        if (0 <= locate - 1 && !isCheck[locate - 1])
            q.emplace(locate - 1, cost + 1);


        if (locate + 1 <= K && !isCheck[locate + 1])
            q.emplace(locate + 1, cost + 1);


        if (locate * 2 <= K + 1 && !isCheck[locate * 2])
            q.emplace(locate * 2, cost + 1);

    }

    cout << answer << endl;
    cout << answer_count << endl;
    return 0;
}
