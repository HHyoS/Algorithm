
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
		//BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
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
