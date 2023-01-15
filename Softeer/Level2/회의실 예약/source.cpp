#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Info {
    string name;
    int start;
    int end;
};
bool operator<(Info a, Info b) {
    if (a.name == b.name) {
        return a.start > b.start;
    }
    return a.name > b.name;
}
priority_queue<Info> que;
vector<string> room;
int N, M;

void run(string startName) {
    int startTime = 9;
    priority_queue<Info> available;
    while (!que.empty() && que.top().name == startName) {
        Info now = que.top();
        que.pop();

        if (now.start != startTime) {
            available.push({ startName,startTime,now.start });
        }
        startTime = now.end;
    }
    if (startTime != 18) {
        available.push({ startName,startTime,18 });
    }
    cout << "Room " << startName << ":\n";
    if (available.empty()) {
        cout << "Not available\n";
    }
    else {
        cout << available.size() << " available:\n";
        while (!available.empty()) {
            if (available.top().start < 10) {
                cout << "0";
            }
            cout << available.top().start << "-";
            if (available.top().end < 10) {
                cout << "0";
            }
            cout << available.top().end << "\n";
            available.pop();
        }
    }
}
void solve() {

    for (int a = 0; a < N; ++a) {

        if(que.empty() || room[a] != que.top().name){
            cout << "Room " << room[a] << ":\n";
            cout << "1 available:\n09-18\n";
        }
        else {
            run(que.top().name);
        }
        if(a != N-1)
            cout << "-----\n";
    }
}
void input() {
    cin >> N >> M;
    for (int a = 0; a < N; ++a) {
        string temp;
        cin >> temp;
        room.push_back(temp);

    }
    sort(room.begin(), room.end());
    for (int a = 0; a < M; ++a) {
        string name;
        int start, end;
        cin >> name >> start >> end;
        que.push({ name,start,end });
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

	return 0;
}
