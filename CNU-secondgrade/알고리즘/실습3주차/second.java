package algorithm.week4;

import java.util.Arrays;
import java.util.Scanner;

public class second {
	
	static int flag = 0;
	
	public static int check(int n, int[] xyz, int sum, int num) {
		if (n == sum)
			return num;
		else if(n < sum)
			return 99999;
		int m = 99999;
		for(int i=0;i<3;i++) {
			m = Math.min(m, check(n,xyz,sum+xyz[i],num+1));
		}
		return m;
	}
	


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] xyz = new int[3];
		Arrays.sort(xyz);
		for(int i = 0; i < 3; i++)
		    xyz[i] = sc.nextInt();
		
		int n = sc.nextInt();
		int c;
		if ((c = check(n,xyz,0,0)) == 99999)
			System.out.print(-1);
		else
			System.out.print(c);
		
		
		
		

	}

}
