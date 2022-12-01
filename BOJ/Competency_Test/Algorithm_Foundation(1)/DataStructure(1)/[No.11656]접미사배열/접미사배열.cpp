#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	string temp[1000];
	cin >> str;
	int l = str.length();
	for(int a=0; a<l; ++a){
		temp[a] = str.substr(a, l); 
	}
	sort(temp, temp+l); //오름차순 
	for(int a=0; a<l; ++a){
		cout << temp[a] << endl;
	}
    
    return 0;
}
