package algorithm.week3;

import java.util.Scanner;

public class forth {
	
	private static int error_prevent(int front,int end,int e_front,int e_end,int[][] sum) {
		int temp = sum[e_end][e_front];
		if(front > 0 && end > 0)
			temp = temp-sum[e_end][front-1]-sum[end-1][e_front]+sum[end-1][front-1];
		else if(front >0)
			temp = temp - sum[e_end][front-1];
		else if(end > 0)
			temp = temp-sum[end-1][e_front];
		return temp;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] set = new int[n][n];
		int[][] sum = new int[n][n];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j< n; j++)
				set[i][j] = sc.nextInt();
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j< n; j++)
				sum[i][j] = 0;
		}
		for(int i=0; i<n;i++)
			sum[0][i] = set[0][i];
		
		for (int i=1;i<n;i++) { //세로
			for(int j=0;j<n;j++) {
				sum[i][j] = sum[i-1][j]+set[i][j];
			}
		}
		
		for (int i=0;i<n;i++) {//세로합의 가로
			for (int j=1;j<n;j++) {
				sum[i][j] = sum[i][j-1] + sum[i][j];
			}
		}
		int aws = -2147483648;
		for (int front=0;front<n;front++) {
			for (int end=0;end<n;end++) {
				for (int e_front=front;e_front<n;e_front++) {
					for (int e_end=end;e_end<n;e_end++) {
						int temp = error_prevent(front,end,e_front,e_end,sum);
						if(aws < temp)
							aws = temp;
					}
				}
			}
		}
		
		System.out.print(aws);
	}

}

