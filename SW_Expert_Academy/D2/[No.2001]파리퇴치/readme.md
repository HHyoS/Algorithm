문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do

풀이 환경 : eclipse 22-6

언 어 : Java

설 명 :

    N x N 배열 안의 숫자는 해당 영역에 존재하는 파리의 개수를 의미한다.

    아래는 N=5 의 예이다.
 

![캡처](https://user-images.githubusercontent.com/57944215/177988934-9164ad86-8fbd-4671-98d8-45c69076f59f.png)


    M x M 크기의 파리채를 한 번 내리쳐 최대한 많은 파리를 죽이고자 한다.

    죽은 파리의 개수를 구하라!

    예를 들어 M=2 일 경우 위 예제의 정답은 49마리가 된다.
 

![캡처2](https://user-images.githubusercontent.com/57944215/177988943-601347bb-e804-4d3f-aabd-a4a690a3564a.png)


[제약 사항]

    1. N 은 5 이상 15 이하이다.

    2. M은 2 이상 N 이하이다.

    3. 각 영역의 파리 갯수는 30 이하 이다.


[입력]

    가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

    각 테스트 케이스의 첫 번째 줄에 N 과 M 이 주어지고,

    다음 N 줄에 걸쳐 N x N 배열이 주어진다.


[출력]

    출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

    (t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

입력

    10
    5 2
    1 3 3 6 7
    8 13 9 12 8
    4 16 11 12 6
    2 4 1 23 2
    9 13 4 7 3
    6 3
    29 21 26 9 5 8
    21 19 8 0 21 19
    9 24 2 11 4 24
    19 29 1 0 21 19
    10 29 6 18 4 3
    29 11 15 3 3 29
    ...

출력

    #1 49
    #2 159
    
풀이 알고리즘

    N*N크기의 배열에 존재하는 파리르 대상으로 M*M 크기의 파리채를 이용해서 가장 많은 파리를 죽이고, 그 수를 출력하는 문제였습니다.
    
    N*N 배열에서 M*M배열이 움직일 수 있는 범위는 (0,0)에서 시작한다 했을떄 (0,0) 부터 (N-M,N-M)까지 입니다.
    
    그래서 2중 for문을 이용하여 방문 가능한 배열의 위치에서 M*M크기의 공간에 파리의 수 중 최대값을 찾아 출력하는 방식으로 문제를 해결하였습니다.
    

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
            int[][] arr = new int[15][15];

            for(int i = 0; i < T; ++i) {
                String str = br.readLine();
                StringTokenizer st = new StringTokenizer(str, " ");

                int N = Integer.parseInt(st.nextToken());
                int M = Integer.parseInt(st.nextToken());

                for(int j = 0; j < N; ++j) {
                    int cnt = 0;
                    str = br.readLine();
                    st = new StringTokenizer(str, " ");
                    for(int k = 0; k < N; ++k) {
                        arr[j][k] = Integer.parseInt(st.nextToken());
                    }
                }
                int answer = 0;
                for(int j = 0; j <= N-M; ++j) {
                    for(int k = 0; k <= N-M; ++k) {
                        int tot = 0;
                        for(int jj = 0; jj < M; ++jj) {
                            for(int kk = 0; kk < M; ++kk) {
                                tot += arr[j+jj][k+kk];
                            }
                        }
                        if(answer < tot)
                            answer = tot;
                    }
                }
                System.out.println("#"+ (i+1) + " "+answer);
            }
        }

    }
    
    
    
    
