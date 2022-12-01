package org.opentutorials.java_start.eclipse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		ArrayList<Integer>[] child = new ArrayList[10001];
		int[] parent;
		
		for(int i = 0; i < T; ++i) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str," ");
			int V = Integer.parseInt(st.nextToken()), E = Integer.parseInt(st.nextToken());
			int n1 = Integer.parseInt(st.nextToken()),n2 =Integer.parseInt(st.nextToken());
			parent = new int[V+1];
			
			parent[1] = 0;
			for(int j = 1; j <= V; ++j) {
				child[j] = new ArrayList<Integer>();
			}
			str = br.readLine();
			
			st = new StringTokenizer(str," ");
			for(int j = 0; j < E; ++j) {
				int parent_node = Integer.parseInt(st.nextToken());
				int child_node = Integer.parseInt(st.nextToken());
				
				child[parent_node].add(child_node);
				parent[child_node] = parent_node;
			}
			

			ArrayList<Integer> a1 = new ArrayList<Integer>();
			ArrayList<Integer> a2 = new ArrayList<Integer>();
			//System.out.println(parent[n1]+" " +parent[n2]);
			while(parent[n1] != 0) {
				a1.add(parent[n1]);
				n1 = parent[n1];
			}
			while(parent[n2] != 0) {
				a2.add(parent[n2]);
				n2 = parent[n2];
			}
			
			//System.out.println(a1.size()+" " +a2.size());
			int target = 0;
			
			//이 부분 수정 후 문제해결
			// 두 노드 중 더 깊은 노드를 찾아 그 노드의 
			if(a1.size() > a2.size()) {
				for(int a = a2.size()-1; a >= 0; --a) {
					if(a1.contains(a2.get(a))){
						target = a2.get(a);
						continue;
					}
					else {
						break;
					}
						
				}
			}
			else {
				for(int a = a1.size()-1; a >= 0; --a) {
					if(a2.contains(a1.get(a))){
						target = a1.get(a);
						continue;
					}
					else {
						break;
					}
						
				}
			}
			
			Queue<Integer> que = new LinkedList<Integer>();
			que.offer(target);
			int answer = 1;
			
			while(!que.isEmpty()) {
				int size = que.size();
				for(int a = 0; a < size; ++a) {
					int num = que.poll();
					for(int b : child[num]) {
							que.offer(b);
							++answer;
						}
					}
				}
			}
			System.out.println("#"+(i+1)+" "+target+" " +answer);
		}
	}
}
