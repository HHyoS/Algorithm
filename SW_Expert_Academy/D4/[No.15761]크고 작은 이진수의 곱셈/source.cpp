#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt", "r", stdin);

    int Tc;
    cin >> Tc;
    register unsigned int A;
    register unsigned int B;
    for (register unsigned int t = 1; t <= Tc; ++t) {
        cin >> A >> B;
        if(B ==1){
            if(A==1)
                cout << "#" << t << " " << A<< "\n";
            else if(A==2){
                cout << "#" << t << " " << (A<<1)<< "\n";
            }
            else
                cout << "#" << t << " " << A+1<< "\n";
        }
        else if ( A == 1 || A > B) {
            cout << "#" << t << " " << A << "\n";
        }
        else 
            cout << "#" << t << " " << (A<<1) << "\n";
    }
}
