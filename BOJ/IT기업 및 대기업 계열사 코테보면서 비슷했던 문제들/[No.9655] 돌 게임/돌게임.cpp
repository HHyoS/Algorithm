#include <iostream>
#include <string>
using namespace std;


int stone;
string name[2];
void Solve() {

	int turn = (1 + stone / 3)%2;
	stone = stone % 3;
    if(stone == 0 || stone == 2){
        cout << name[turn];
    }
    else{
        cout << name[(turn+1)%2];
    }

	return;
}
void Input() {
	cin >> stone;
	name[0] = "SK";
	name[1] = "CY";
}
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
    return 0;
}
