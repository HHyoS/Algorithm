#include<iostream>
#include<string>

using namespace std;
int minute[2] = {60,1};

int getTime(string info){
	int sH,eH,sM,eM;
	sH = stoi(info.substr(0,2));
	sM = stoi(info.substr(3,2));
	eH = stoi(info.substr(6,2));
	eM = stoi(info.substr(9,2));
	return (eH-sH)*60 + eM-sM;
}
void input(){
	int ans = 0;
	string sTime,eTime;
	for(int  a= 0; a < 5; ++a){
		
		cin >> sTime >> eTime;
		string workingTime = sTime + " " + eTime;
		ans += getTime(workingTime); 
	}
	cout << ans;
}
int main(int argc, char** argv)
{
	input();
	return 0;
}
