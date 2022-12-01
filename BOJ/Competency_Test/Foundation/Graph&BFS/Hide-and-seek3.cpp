#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100000 + 1;
bool arr[MAX];


int main(void){
    int n, m;
    scanf("%d%d", &n, &m);



    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;


    que.push(make_pair(0, n));

    arr[n] = 1;



    while (!que.empty()){

        int sec = que.top().first;
        int loc = que.top().second;
        que.pop();

        if (loc == m) {
            printf("%d", sec);
            return 0;
        }

        if (loc * 2 < MAX && !arr[loc * 2]){
            que.push(make_pair(sec, loc * 2));
            arr[loc * 2] = 1;
        }

        if (loc + 1 < MAX && !arr[loc + 1]){
            que.push(make_pair(sec + 1, loc + 1));
            arr[loc + 1] = 1;
        }

        if (loc - 1 >= 0 && !arr[loc - 1]){
            que.push(make_pair(sec + 1, loc - 1));
            arr[loc - 1] = 1;
        }
    }

    return 0;

}


