#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<memory.h>
using namespace std;

vector<int> nums;
int N;
bool used[10001];
int solve() {
	vector<int> num;
    num.push_back(0);
    for(int a = 0; a < nums.size(); ++a){
        int size = num.size();
		for(int b = 0; b < size; ++b){
			int sum = num[b] +nums[a];
            if(used[sum] == 0){
                used[sum ] =1;
                num.push_back(sum);
            }
        }
    }
    return num.size(); ;
}
void input() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int a = 0; a < N; ++a) {
            int point;
            cin >> point;
            nums.push_back(point);
        }
        cout << "#"<<t<<" "<< solve()<<"\n";
        nums.clear();
        memset(used, 0, sizeof(used));
    }
    

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt", "r", stdin);

    input();


    return 0;
}
