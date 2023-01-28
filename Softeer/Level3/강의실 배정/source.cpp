#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Info {
    int start;
    int end;
};
int N;
vector<Info> Course;

bool cmp(Info a, Info b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}
int solve() {
    int time = 0;
    int cnt = 0;
    for (int a = 0; a < N; ++a) {
        if (time <= Course[a].start) {
            time = Course[a].end;
            ++cnt;
        }
    }
    return cnt;
}

void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int start, end;
        cin >> start >> end;
        Course.push_back({ start,end });
    }

    sort(Course.begin(), Course.end(), cmp);
    
}
int main(int argc, char** argv)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << solve();
	return 0;
}
