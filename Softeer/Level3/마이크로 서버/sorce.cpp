#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> microServer;

int solve(){
	sort(microServer.begin(), microServer.end());
	int server = 0;
	int start = 0;
	int end = microServer.size()-1;

	while(start <= end && microServer[end] > 600){
		++server;
		--end;
	}

	while(start <= end && microServer[start] == 300 && microServer[end] == 600){
		++server;
		++start;
		--end;
	}
	int cnt = 0;
	while(start <= end){
		if(microServer[start] == 300){
			++cnt;
			++start;
		}
		else
			break;
	}
	while(start < end){
		int sum = microServer[start] + microServer[end];
		if(sum <= 900){
			++start;
			--end;
			++server;
		}
		else if (cnt > 0){
			--cnt;
			--end;
			++server;
		}
		else{
			--end;
			++server;
		}
	}
	if(start == end){
		if(cnt > 0){
			--cnt;
			++server;
		}
		else{
			++server;
		}
	}
	server += cnt/3;
	if(cnt%3){
		++server;
	}
	return server;
}
void input(){
	int T,N;
	cin >> T;
	for(int t=1; t<= T; ++t){
		cin >> N;
		for(int a = 0; a < N; ++a){
			int tmp;
			cin >> tmp;
			microServer.push_back(tmp);
		}
		cout << solve() <<"\n";
		microServer.clear();
	}
}
int main(int argc, char** argv)
{
	input();
	return 0;
}
