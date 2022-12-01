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
