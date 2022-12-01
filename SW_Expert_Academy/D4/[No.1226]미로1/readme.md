문제 사이트 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15B1cKAKwCFAYD

풀이 환경 : eclipse 22-6

풀이 언어 : Java

문제 설명 :

    아래 그림과 같은 미로가 있다. 
    
    16*16 행렬의 형태로 만들어진 미로에서 흰색 바탕은 길, 노란색 바탕은 벽을 나타낸다.

    가장 좌상단에 있는 칸을 (0, 0)의 기준으로 하여, 가로방향을 x 방향, 세로방향을 y 방향이라고 할 때, 
    
    미로의 시작점은 (1, 1)이고 도착점은 (13, 13)이다.

    주어진 미로의 출발점으로부터 도착지점까지 갈 수 있는 길이 있는지 판단하는 프로그램을 작성하라.

    아래의 예시에서는 도달 가능하다.
 
![SW문제해결+기본 +7일차+-+미로+1_그림1](https://user-images.githubusercontent.com/57944215/178127599-17848298-725a-43d2-b146-ccc16879197b.png)
  

    아래의 예시에서는 출발점이 (1, 1)이고, 도착점이 (11, 11)이며 도달이 불가능하다.

![SW문제해결+기본 +7일차+-+미로+1_그림2](https://user-images.githubusercontent.com/57944215/178127603-59c20199-517d-40f9-86ff-ca77d55c7b4f.png)


[입력]

    각 테스트 케이스의 첫 번째 줄에는 테스트 케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.

    총 10개의 테스트케이스가 주어진다.

    테스트 케이스에서 1은 벽을 나타내며 0은 길, 2는 출발점, 3은 도착점을 나타낸다.

[출력]

    #부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도달 가능 여부를 1 또는 0으로 표시한다 (1 - 가능함, 0 - 가능하지 않음).

입력

    1
    1111111111111111
    1210000000100011
    1010101110101111
    1000100010100011
    1111111010101011
    1000000010101011
    1011111110111011
    1010000010001011
    1010101111101011
    1010100010001011
    1010111010111011
    1010001000100011
    1011101111101011
    1000100000001311
    1111111111111111
    1111111111111111
    2
    1111111111111111
    1200000010000011
    1011111011111011
    1000001010000011
    1110101010111011
    1010101010100011
    1011111010111111
    1000001010000011
    1011101011111011
    1010101010000011
    1010101010111111
    1010100000130011
    1010111111111011
    1000000000000011
    1111111111111111
    1111111111111111
    ...

출력

    #1 1
    #2 1
    ...
    
풀이 알고리즘

    주어진 조건 내에서 미로를 탈출할 수 있는지 확인하고 가능할 경우 1, 아닐경우 0을 출력하는 문제였습니다
    
    D4라는 난이도를 보고 걱정했는데, 크게 문제없이 bfs탐색으로 해결하였습니다.
    
    풀이 알고리즘은 다음과 같습니다.
    
    1. 미로 데이터를 입력받고, 시작점 =2 , 목적지 =3 으로 입력이 주어지기 때문에, 해당 위치를 변수를 이용하여 기억합니다.
    
    2. 시작점을 기준으로 bfs탐색을 실시하며, 방문했던 위치들은 check배열을 사용하여 관리합니다.
    
    3. bfs탐색을 처음 실시할 때에는 시작점을 queue에 넣은 후 탐색을 시작하고, 상,하,좌,우 탐색을 할 때 방문을 안했고, 벽이 아닌 곳으로 이동합니다.
    
    4. 이동한 위치가 목적지와 같다면 1을 return 하여 bfs를 종료하고, 아니라면 queue에 현재 방문한 위치를 저장, check에도 방문표시
    
    5.   2 ~3 사이클을 반복하여 목적지에 도착하지 못하면, 미로탈출이 불가능하므로 0을 return해줍니다.
    


구 현

    import java.io.BufferedReader;
    import java.io.FileReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.LinkedList;
    import java.util.Queue;

    class Pair{
      int x;
      int y;

      Pair(int x, int y){
        this.x = x;
        this.y = y;
      }
    }
    public class Solution {

      static int[][] arr = new int[16][16];
      static int x_mov[] = {0,0,1,-1};
      static int y_mov[] = {1,-1,0,0};
      static Pair start, end;

      public static boolean bfs(boolean[][] check) {
        check[start.x][start.y] = true;
        Queue<Pair> que = new LinkedList<>();
        que.offer(start);
        while(!que.isEmpty()) {
          int size = que.size();
          for(int j = 0; j < size; ++j) {
            int x = que.peek().x;
            int y = que.peek().y;
            que.poll();

            for(int k = 0; k < 4; ++k) {
              int xx = x+x_mov[k];
              int yy = y+y_mov[k];
              if(xx >= 0 && xx < 16 && yy >=0 && yy < 16) {
                if(!check[xx][yy] && arr[xx][yy] !=1) {
                  if(xx == end.x && yy == end.y) {
                    return true;
                  }

                  check[xx][yy] = true;
                  que.offer(new Pair(xx,yy));
                  }
                }

              }
            }
          }
        return false;
      }
      public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        //BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < 10; ++i) {
          int N = Integer.parseInt(br.readLine());
          boolean[][] check = new boolean[16][16];
          for(int a = 0; a < 16; ++a) {
            String str = br.readLine();
            for(int b= 0; b < 16; ++b) {
              arr[a][b] = str.charAt(b)-'0';
              if(arr[a][b] ==1 || arr[a][b] == 0)
                continue;
              else if(arr[a][b] == 2)
                start = new Pair(a,b);
              else {
                end = new Pair(a,b);
              }
            }
          }
          System.out.println("#"+N+" "+ (bfs(check) ? 1 : 0));

        }
      }
    }
