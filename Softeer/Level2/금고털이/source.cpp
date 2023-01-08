#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;


struct Bosuc{
	int kg;
	int value;
};

bool operator<(Bosuc a, Bosuc b){
	if(a.value == b.value){
		return a.kg < b.kg;
	}
	return a.value < b.value;
}
priority_queue<Bosuc> que;
int N,W;

int solve(){
	int bagSize = 0;
	int size = que.size();
	int totalPrice = 0;
	while(!que.empty()){
		Bosuc now = que.top();
		que.pop();

		if(now.kg+bagSize > W){
			int ableSize = W - bagSize;
			totalPrice = totalPrice + now.value*ableSize;
			break;
		}
		bagSize = bagSize + now.kg;
		totalPrice = totalPrice + now.kg*now.value;
	}
	while(!que.empty()){
		que.pop();
	}
	return totalPrice;
}
void input(){
	cin >> W >> N;
	for(int a = 0; a < N; ++a){
		int M,P;
		cin >> M >> P;
		que.push({M,P});
	}
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
