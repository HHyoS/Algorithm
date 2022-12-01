#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;
vector<int> temp;

void getPrime(bool ar[]) {
    for (int a = 2; a < 1000001; ++a)
        ar[a] = true;
 
    for (int a = 2; a <= 1000000; ++a) {
        if (ar[a]) {
            for (int b = 2; a * b <= 1000000; ++b) {
                ar[a * b] = false;
            }
        }
    }
}

bool check(int num, bool ar[]){
    int a = 0;
    int b = 0;
    for (int a = 2; a < num; ++a){
        if(ar[a]){
            b = num - a;
            if (b >= 3) {
                if (ar[b]) {
                    printf("%d = %d + %d\n", num, a , b);
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<int> ar;
    int a = 99;
    bool* map = (bool*)malloc(sizeof(bool) * 1000001);

    getPrime(map);
    while (true) {
        cin >> a;
        if (a == 0)
            break;
        ar.push_back(a);
    }
    for (int i = 0; i < ar.size(); ++i) {
        if (!check(ar[i], map))
            cout << "Goldbach's conjecture is wrong.\n" << endl;
    }
    return 0;
}
