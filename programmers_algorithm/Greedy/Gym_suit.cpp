#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> loss, vector<int>reserve) {
  int answer = 0;
  vector<int> entry(n+1,1); // create a total student vector 0 student, so create n+1
  for(int a : lost)
    entry[a]--; // student settings without gym clothes
  for(int b : reserve)
    entry[b]++; // student settings with gym clothes. Use of the increment operator because the explanation of a student who has brought two gym clothes losing one is problematic.
  for(int a = 1; a <= n; ++a){
    if(entry[a] == 1)
      ++answer; // ++ for 1
    if(entry[a] == 2){ // check the number of student uniforms in front of ramen and then the student behind
      if(entry[a-1] == 0){
        ++entry[a-1];
        --entry[a];
        answer +=2;
      } // front students are not included in the calculation when they receive a new gym clothes, so +2
      else if(entry[a+1] == 0){
        ++entry[a+1];
        --entry[a];
        ++answer; // apply only ++ to the current student because the foreword turns into true for the condition entry[a] ==1
      }
      else
        ++answer; // if you have two front and back students, there's no one to give you, just ++.
      }
  }

  return answer;
}
