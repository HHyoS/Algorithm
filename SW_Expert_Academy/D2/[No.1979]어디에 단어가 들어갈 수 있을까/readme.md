문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq

풀이 환경 : eclipse

언 어 : Java

설 명 :

    N X N 크기의 단어 퍼즐을 만들려고 한다. 
    
    입력으로 단어 퍼즐의 모양이 주어진다.

    주어진 퍼즐 모양에서 특정 길이 K를 갖는 단어가 들어갈 수 있는 자리의 수를
    
    출력하는 프로그램을 작성하라.

[예제]

    N = 5, K = 3 이고, 퍼즐의 모양이 아래 그림과 같이 주어졌을 때
 
![캡처](https://user-images.githubusercontent.com/57944215/177123381-4f1fd299-8a28-4313-9e6c-1a17d44c32c3.png)



    길이가 3 인 단어가 들어갈 수 있는 자리는 2 곳(가로 1번, 가로 4번)이 된다.
 
![캡처2](https://user-images.githubusercontent.com/57944215/177123389-8cf44ec2-ba0e-4c50-b7b2-acfcecc33fe5.png)


[제약 사항]

    1. N은 5 이상 15 이하의 정수이다. (5 ≤ N ≤ 15)

    2. K는 2 이상 N 이하의 정수이다. (2 ≤ K ≤ N)


[입력]

    입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.

    다음 줄부터 각 테스트 케이스가 주어진다.

    테스트 케이스의 첫 번째 줄에는 단어 퍼즐의 가로, 세로 길이 N 과, 단어의 길이 K 가 주어진다.

    테스트 케이스의 두 번째 줄부터 퍼즐의 모양이 2차원 정보로 주어진다.

    퍼즐의 각 셀 중, 흰색 부분은 1, 검은색 부분은 0 으로 주어진다.


[출력]

    테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력

    10
    5 3
    0 0 1 1 1
    1 1 1 1 0
    0 0 1 0 0
    0 1 1 1 1
    1 1 1 0 1
    5 3
    1 0 0 1 0
    1 1 0 1 1
    1 0 1 1 1
    0 1 1 0 1
    0 1 1 1 0
    …
 
출력

    #1 2
    #2 6
    ...
    
풀이 알고리즘

    주어진 0과 1로 이루어진 N*N 배열과, 단어의 길이 K가 주어질 떄, 단어 길이에 딱맞는 빈공간의 갯수를 출력하는 문제였습니다.
    
    문제를 처음 풀 때, K=3 일경우 빈공간이 네개연속 있어도 가능하지 않나? 라는 생각을 했지만, 문제의 예시 입출력을 통해 빈공간이 정확이 K의 크기와
    
    일치해야만 정답의 갯수에 포함된다는 것을 알 수 있었습니다.
    
    풀이 알고리즘입니다.
    
    탐색은 가로, 세로 방향으로 탐색을 진행합니다.
    
    // 풀이에서 사용된 대표 변수는 1. answer - 현재 배열에서 단어를 넣을 수 있는 공간의 갯수 2. cnt - 연속된 빈 공간의 크기를 count하는 변수
    [ 가로 탐색 ]
    
    가로 탐색은 배열이 입력될 때 진행되며, 
    
    1-1 빈 공간을 의미하는 1이 입력될 경우 cnt를 1 올려줍니다.
    
    1-2 입력된 위치가 배열의 끝이라면 빈공간 카운트와 K를 비교하여 둘이 같을경우 answer을 1 줍니다.
    
    2 채워진 공간을 의미하는 0이 입력될 경우 K와 cnt를 비교하여 cnt==K 일경우 answer를 1 올려주고 cnt를 0으로 초기화합니다.
    
    
    [ 세로 탐색 ]
    
    세로 탐색은 가로탐색과 동일한 알고리즘으로 동작하기 때문에 기술하지 않지만, 가로탐색과 다른점은 배열이 이미 모두 입력되었기 때문에 따로 입력받지는 않고
    
    배열의 값만을 확인하여 동작한다는 것 입니다.
    
    [ 정답 출력 ]
    
    탐색이 모두 끝났다면 answer를 출력하여 현재 배열에 대한 정답을 출력하고 다음 테스트케이스를 진행합니다.
    
구 현 

    import java.io.BufferedReader;
    import java.io.FileReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.StringTokenizer;
    public class Solution {

      public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        //BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int[][] arr = new int[15][15]; // N의 최대 크기가 15이므로, 미리 15크기의 배열 선언.

        for(int i = 0; i < T; ++i) {
          int answer = 0;
          String str = br.readLine();
          StringTokenizer st = new StringTokenizer(str, " ");

          int N = Integer.parseInt(st.nextToken());
          int K = Integer.parseInt(st.nextToken());

          // 가로탐색 실시
          for(int j = 0; j < N; ++j) {
            int cnt = 0;
            str = br.readLine();
            st = new StringTokenizer(str, " ");
            for(int k = 0; k < N; ++k) {
              arr[j][k] = Integer.parseInt(st.nextToken());
              if(arr[j][k] == 1) {
                ++cnt;
                if((k == (N-1)) && (cnt == K)) {
                  ++answer;
                }
              }
              else {
                if(cnt == K) {
                  ++answer;
                  cnt = 0;
                }
                else
                  cnt = 0;

              }
            }

          }
          
          // 세로탐색 실시
          for(int j = 0; j < N; ++j) {
            int cnt = 0;
            for(int k = 0; k < N; ++k) {
              if(arr[k][j] == 1) {
                ++cnt;
                if((k==(N-1)) && (cnt == K)) {
                  ++answer;
                }
              }
              else {
                if(cnt == K) {
                  ++answer;
                  cnt = 0;
                }
                else
                  cnt = 0;
              }
            }
          }
          
          // 정답 출력
          
          System.out.println("#"+ (i+1) + " "+answer);
        }
      }

    }

    
    
    
    
    
    
