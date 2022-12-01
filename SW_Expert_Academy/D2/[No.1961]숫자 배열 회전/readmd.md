문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq

풀이 환경 : eclipse

언어 : java

설명 :

    N x N 행렬이 주어질 때,

    시계 방향으로 90도, 180도, 270도 회전한 모양을 출력하라.


[제약 사항]

    N은 3 이상 7 이하이다.

[입력]

    가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

    각 테스트 케이스의 첫 번째 줄에 N이 주어지고,

    다음 N 줄에는 N x N 행렬이 주어진다.

[출력]

    출력의 첫 줄은 '#t'로 시작하고,

    다음 N줄에 걸쳐서 90도, 180도, 270도 회전한 모양을 출력한다.

    입력과는 달리 출력에서는 회전한 모양 사이에만 공백이 존재함에 유의하라.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력

    10
    3
    1 2 3
    4 5 6
    7 8 9
    6
    6 9 4 7 0 5
    8 9 9 2 6 5
    6 8 5 4 9 8
    2 2 7 7 8 4
    7 5 1 9 7 9
    8 9 3 9 7 6
    …
 
출력

    #1
    741 987 369
    852 654 258
    963 321 147
    #2
    872686 679398 558496
    952899 979157 069877
    317594 487722 724799
    997427 894586 495713
    778960 562998 998259
    694855 507496 686278
    …
    
 풀이 알고리즘
 
    N*N 길의 배열 A가 주어졌을 떄, A를 90,180,270 회전시킨 배열의 값을 출력하는 문제였습니다
    
    (출력조건 A_90, A_180, A_270 을 출력하는 방법)
    
    A_90 A_180 A_270 을 가로로 동에 출력
    
    A_90[0][0],A_90[0][1]  A_180[0][0],A_180[0][1] A_270[0][0],A_270[0][1]
    ....
    
    
    이런식으로 출력
    
    배열을 하나하나 출력하는 방식이라면, 기존배열 A를 회전시킨 배열 A_90 .,,, 으로 변하는 배열 인덱스를
    
    찾아서 출력하려고 했으나, 동시에 출력해야 하기 떄문에, 회전하는 배열한 배열을 저장하는 배열을 선언하여
    
    순서대로 출력하여 문제를 해결하였습니다.
    
    
 구 현

    import java.io.BufferedReader;
    import java.io.FileReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.StringTokenizer;
    public class Solution {
      public static int[][] rolling(int N,int [][] arr) {
        int[][] result = new int[N][N];

        for(int i = 0; i < N; ++i) {
          for(int j = 0; j < N; ++j) {
            result[i][j] = arr[N-j-1][i];
          }
        }
        return result;
      }
      public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        int[][] arr = new int[15][15];

        for(int i = 0; i < T; ++i) {
          String str = br.readLine();
          StringTokenizer st = new StringTokenizer(str, " ");

          int N = Integer.parseInt(st.nextToken());

          for(int j = 0; j < N; ++j) {
            str = br.readLine();
            st = new StringTokenizer(str, " ");
            for(int k = 0; k < N; ++k) {
              arr[j][k] = Integer.parseInt(st.nextToken());
            }
          }
          int[][] arr_90 = rolling(N,arr);
          int[][] arr_180 = rolling(N,arr_90);
          int[][] arr_270 = rolling(N,arr_180);

          System.out.println("#"+ (i+1));

          for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
              System.out.print(arr_90[j][k]);
            }
            System.out.print(" ");

            for(int k = 0; k < N; ++k) {
              System.out.print(arr_180[j][k]);
            }
            System.out.print(" ");

            for(int k = 0; k < N; ++k) {
              System.out.print(arr_270[j][k]);
            }
            System.out.println();
          }
        }
      }

    }


