#include <iostream>

using namespace std;

struct pos {
    int x,y;
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pos a,b,c;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;

    long long temp = a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);

    if (temp < 0)
        cout<<"-1";
    else if (temp > 0)
        cout<<"1";
    else
        cout<<"0";

    return 0;
}
