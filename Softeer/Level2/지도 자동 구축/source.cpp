#include<iostream>


using namespace std;
int N;
long long gop[17];

void init() {
    gop[0] = 1;
    for (int a = 1; a <= N; ++a) {
        gop[a] = gop[a - 1] * 2;
    }
}
long long solve() {
    long long point = gop[N] + 1;
    return point * point;
}
void input() {
    cin >> N;
    init();
}
int main(int argc, char** argv)
{

    input();
    cout << solve() << "\n";
	return 0;
}
