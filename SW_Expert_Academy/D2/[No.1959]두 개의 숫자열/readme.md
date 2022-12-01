문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpoFaAS4DFAUq

풀이 환경 : eclipse

언 어 : Java

설 명 : 

N 개의 숫자로 구성된 숫자열 Ai (i=1~N) 와 M 개의 숫자로 구성된 숫자열 Bj (j=1~M) 가 있다.

아래는 N =3 인 Ai 와 M = 5 인 Bj 의 예이다.

![캡처](https://user-images.githubusercontent.com/57944215/177040383-f809f739-b1ab-4e37-9113-34655503da7a.png)


Ai 나 Bj 를 자유롭게 움직여서 숫자들이 서로 마주보는 위치를 변경할 수 있다.

단, 더 긴 쪽의 양끝을 벗어나서는 안 된다.
 

![캡처2](https://user-images.githubusercontent.com/57944215/177040386-c4370897-e201-4772-afb1-647f8bd12430.png)


서로 마주보는 숫자들을 곱한 뒤 모두 더할 때 최댓값을 구하라.

위 예제의 정답은 아래와 같이 30 이 된다.
 
![캡처3](https://user-images.githubusercontent.com/57944215/177040389-abc6e8df-1221-4b0e-82c9-34f5abe3b889.png)


[제약 사항]

N 과 M은 3 이상 20 이하이다.


[입력]

    가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 
    
    그 아래로 각 테스트 케이스가 주어진다.

    각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,

    두 번째 줄에는 Ai,

    세 번째 줄에는 Bj 가 주어진다.

[출력]

    출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력

    10
    3 5
    1 5 3
    3 6 -7 5 4
    7 6
    6 0 5 5 -1 1 6
    -4 1 8 7 -9 3
    ...

출력

    #1 30
    #2 63
    ...

풀이 알고리즘

  두 배열이 입력될 때, 배열의 이동을 통해 마주보는 두 배열의 숫자의 곱들의 합이 최대가 되는 값을 찾는 문제였습니다.
  
  이 문제를 해결할 때 중요한 것은, N > M or N < M 두 케이스에 따라 연산이 달라진다는 것 입니다.
  
  case 1. N > M 
  
    N이 M보다 크므로 M 배열을 이동시키면서 N배열값과 곱연산을 통해 최대값 찾기
    
  case 2. N < M
  
    M이 N보다 크므로 M 배열을 이동시키면서 N배열값과 곱연산을 통해 최대값 찾기
 
 
구 현
  
    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.StringTokenizer;

    class Solution
    {
      public static void main(String args[]) throws Exception
      {

        //BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        long[] arr1 = new long[20];
        long[] arr2 = new long[20];
        for(int i = 0; i < T; ++i) {
          String str = br.readLine();
          StringTokenizer st = new StringTokenizer(str, " ");

          int N = Integer.parseInt(st.nextToken());
          int M = Integer.parseInt(st.nextToken());

          str = br.readLine();
          st = new StringTokenizer(str, " ");
          if(N < M) {
            for(int j = 0; j < N; ++j) {
              arr1[j] = Long.parseLong(st.nextToken());
            }
            str = br.readLine();
            st = new StringTokenizer(str, " ");
            for(int j = 0; j < M; ++j) {
              arr2[j] = Long.parseLong(st.nextToken());
            }
          }
          else {
            for(int j = 0; j < N; ++j) {
              arr2[j] = Long.parseLong(st.nextToken());
            }
            str = br.readLine();
            st = new StringTokenizer(str, " ");
            for(int j = 0; j < M; ++j) {
              arr1[j] = Long.parseLong(st.nextToken());
            }
          }

          long big = Long.MIN_VALUE;
          for(int j = 0; j <= Math.abs(M-N); ++j) {
            long total = 0;
            if(N < M) {
              for(int k =0; k < N; ++k) {
                total += (arr1[k]*arr2[k+j]);
              }
            }
            else {
              for(int k =0; k < M; ++k) {
                total += (arr1[k]*arr2[k+j]);
              }
            }
            if(total > big)
              big = total;
          }
          System.out.println("#"+ (i+1) + " "+big);
        }
      }
    }
