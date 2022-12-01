import java.io.BufferedReader;
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
     
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        //BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         
        int T = Integer.parseInt(br.readLine());
        int x_mov[] = {0,0,1,-1};
        int y_mov[] = {1,-1,0,0};
        for(int i = 0; i < T; ++i) {
            int N = Integer.parseInt(br.readLine());
            int[][] arr = new int[N][N];
            int[][] dp = new int[N][N];
            for(int a = 0; a < N; ++a) {
                String str = br.readLine();
                for(int b= 0; b < N; ++b) {
                    arr[a][b] = str.charAt(b)-'0';
                }
            }
            boolean[][] check = new boolean[N][N];
            check[0][0] = true;
            dp[0][0] = arr[0][0];
            Queue<Pair> que = new LinkedList<>();
            que.offer(new Pair(0,0));
            while(!que.isEmpty()) {
                int size = que.size();
                for(int j = 0; j < size; ++j) {
                    int x = que.peek().x;
                    int y = que.peek().y;
                    que.poll();
                     
                    for(int k = 0; k < 4; ++k) {
                        int xx = x+x_mov[k];
                        int yy = y+y_mov[k];
                        if(xx >= 0 && xx < N && yy >=0 && yy < N) {
                            if(!check[xx][yy]) { // IF문 하나로 check와 dp비교를 하던 구문을 두 부분으로 나누어 구현한 결과 메모리사용 35000kb -> 33000kb
                                check[xx][yy] = true;
                                dp[xx][yy] = dp[x][y] + arr[xx][yy];
                                que.offer(new Pair(xx,yy));
                            }
                            else if(dp[x][y]+arr[xx][yy] < dp[xx][yy]) {
                                dp[xx][yy] = dp[x][y] + arr[xx][yy];
                                que.offer(new Pair(xx,yy));
                            }
                        }
                    }
                }
            }
            System.out.println("#"+(i+1)+" "+dp[N-1][N-1]);
             
        }
    }
}
