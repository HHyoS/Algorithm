#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;
map<int, int> check;
vector<int> temp;

void dfs(int chance, int index, vector<int> ck, int deep) {
    if (index != -1)
        ck[index] = 1;
    if (ck.size() - deep == 1) {
        for (int a = 0; a < ck.size(); ++a) {
            if (ck[a] == 0) {
                check[temp[a]] = 1;
                return;
            }
        }
    }
    else {
        ++deep;
        for (int a = 0; a < temp.size() - 1; ++a) {
            if (ck[a] == 0) {
                for (int b = a + 1; b < temp.size(); ++b) {
                    if (ck[b] == 0) {
                        if (temp[a] > temp[b]) {
                            dfs(chance, a, ck, deep);
                            if (chance == 1) {
                                dfs(0, b, ck, deep);
                            }
                        }
                        else {
                            dfs(chance, b, ck, deep);
                            if (chance == 1) {
                                dfs(0, a, ck, deep);
                            }
                        }
                        break;
                        }
                    }
                }
            }
        }
    }
int solution(vector<int> n) {
    int answer = 0;
    temp.assign(n.begin(), n.end());
    vector<int> a(n.size(), 0);
    dfs(1,-1,a,0);
    for (int a : n) {
        if (check[a] == 1)
            ++answer;
    }
    return answer;

}

int main() {
    vector<int> a = { -9,-2,-3,-1,25,22,14,-8,16,37 };
    time_t start, end;
    printf("start\n");
    start = time(NULL);
    printf("%d", solution(a));
    end = time(NULL);
    double result = (double)(end - start);
    printf("time = %f", result);
    return 0;
}
