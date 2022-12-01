
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
