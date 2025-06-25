#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> coords(N);
    for (int i = 0; i < N; i++)
        cin >> coords[i];

    vector<int> temp = coords;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    map<int, int> compressed;
    for (int i = 0; i < temp.size(); i++)
        compressed[temp[i]] = i;

    for (int i = 0; i < N; i++)
        cout << compressed[coords[i]] << ' ';
    cout << '\n';

    return 0;
}
