#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct Info {
    int index;
    long long size;
    long long price;
};

struct Node {
    int index;
    long long target;
};
int N;
vector<Info> submit;
vector<Node> querys;
long long maxPrice[100001];
long long ans[100001];
bool cmp(Info a, Info b) {
    if (a.size == b.size) {
        if (a.price == b.price) {
            return a.index > b.index;
        }
        return a.price > b.price;
    }
    return a.size < b.size;
}

bool ccmp(Node a, Node b) {
    if (a.target == b.target) {
        return a.index < b.index;
    }
    return a.target < b.target;
}
void solve() {
    int idx = 0;
    long long totalGet = 0;
    for (int a = 0; a < submit.size(); ++a) {
        int index = submit[a].index;
        int size = submit[a].size;
        int price = submit[a].price;
        if (price > maxPrice[index]) {
            long long dif = price - maxPrice[index];
            maxPrice[index] = price;
            totalGet += dif;
        }
        while (querys[idx].target <= totalGet) {
            ans[querys[idx].index] = size;
            ++idx;
            if (idx >= querys.size())
                return;
        }
    }

}

void input() {
    cin >> N;
    for (int a = 0; a < N; ++a) {
        int num;
        cin >> num;
        for (int b = 0; b < num; ++b) {
            long long size, price;
            cin >> size >> price;
            submit.push_back({ a,size,price });
        }
    }
    sort(submit.begin(), submit.end(), cmp);
    int queryNum;
    cin >> queryNum;
    for (int a = 0; a < queryNum; ++a) {
        long long needSales;
        cin >> needSales;
        querys.push_back({ a,needSales });
    }
    sort(querys.begin(), querys.end(),ccmp);

    for (int a = 0; a < querys.size(); ++a) {
        ans[a] = -1;
    }
}

void print() {
    for (int a = 0; a < querys.size(); ++a) {
        cout << ans[a] << " ";
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    print();
	return 0;
}
