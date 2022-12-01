import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		int[][] arr = new int[15][15];
		
		for(int i = 0; i < T; ++i) {
			int answer = 0;
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str, " ");
			
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			
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
			System.out.println("#"+ (i+1) + " "+answer);
		}
	}

}
