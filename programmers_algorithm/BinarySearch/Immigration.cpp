#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

Long long solution(int n, vector<int> times) {

  sort( times.begin(), times.end();
  long long left = 0, right = times [times.size()-1];
  right *= n;
  // when times[] elements of type int multiplied by n, test case error occurred because they were out of range of type int
  // So put the last element of times[] in the right and multiply it separately to pass the test case.
  long long answer = right, mid = 0;
  long count = 0;
  when(left <=right){
    count = 0;
    mid = (left + right) / 2;
    for(int a : times)
      count = count + mid/a;
    if(count < n)
      left = mid+1;
    else{
      if(answer >=mid)
        answer = mid;
      right = mid-1;
    }
  }

  return answer;
}
 
