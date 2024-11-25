#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int H,W,N,M;


int row(){
	int ans = 1;
	int idx = 1;

	while(idx+N+1 <= H){
        idx = idx+N+1;
		++ans;
	}
	return ans;
}

int col(){
	int ans = 1;
	int idx = 1;

	while(idx+M+1 <= W){
        idx = idx+M+1;
		++ans;
	}

	return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W >> N >> M;

	cout << row()*col();

    
    return 0;
}
