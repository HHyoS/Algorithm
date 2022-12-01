#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(int n, vector<int> weak, vector<int> dist) {
 
    int answer = dist.size()+1;
 
    sort(dist.begin(), dist.end()); // next_permutation을 이용하기 위해서는 오름차순 되어있어야함
 
    for (int a = 0; a < weak.size(); a++) {
 
        int temp = weak[0] + n;
        for (int b = 1; b < weak.size(); b++) {
            weak[b - 1] = weak[b];
        }
        weak[weak.size() - 1] = temp; // 원형으로 배열되어있는 취약점 weak들을 직선으로 바꾸어 탐색하는 방법

        do {
            int w = 0;
            int d = 0;
            for (d = 0; d < dist.size(); d++) {
                int leng = weak[w] + dist[d];
                while (leng >= weak[w]) {
                    w++;
                    if (w == weak.size()) {
                        break;
                    }
                }
                if (w == weak.size()) {
                    break;
                }
                if(d == answer -1)
                    break;
            }
 
            if (w == weak.size()) {
                if (d + 1 < answer) {
                    answer = d + 1;
                }
            }
 
        } while (next_permutation(dist.begin(), dist.end())); // next_permutation을 이용하여 직선으로 만들어진 weak[]를 탐색하고, 가장 적게 탐색하는 인원을 찾아냄
    }
    if(answer == dist.size()+1)
        return -1;
    return answer;
}
