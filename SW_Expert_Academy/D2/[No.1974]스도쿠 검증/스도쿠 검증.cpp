package org.opentutorials.java_start.eclipse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Solution {
	public static boolean check(int [][] arr) {
		boolean[][] result1 = new boolean[10][10];
		boolean[][] result2 = new boolean[10][10];
		
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				if(!result1[i][arr[i][j]]) {
					result1[i][arr[i][j]] = true;
				}
				else
					return false;
			}
		}
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				if(!result2[i][arr[j][i]]) {
					result2[i][arr[j][i]] = true;
				}
				else
					return false;
			}
		}
		for(int i = 0; i < 9; i += 3) {
			for(int j = 0; j < 9; j+=3) {
				boolean[] t = new boolean[10];
				for(int a = 0; a < 3; ++a) {
					for(int b = 0; b < 3; ++b) {
						if(!t[arr[i+a][j+b]]) {
							t[arr[i+a][j+b]] = true;
						}
						else
							return false;
					}
				}
			}
		}
		return true;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt")); // 파일 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 키보드 입력
		
		int T = Integer.parseInt(br.readLine());

		int[][] arr = new int[15][15];
		
		for(int i = 0; i < T; ++i) {
			for(int j = 0; j < 9; ++j) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str, " ");
				for(int k = 0; k < 9; ++k) {
					arr[j][k] = Integer.parseInt(st.nextToken());
				}
			}
			System.out.println("#"+(i+1)+" "+ (check(arr) ? 1 : 0));
		}
	}
}
