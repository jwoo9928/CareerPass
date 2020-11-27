package algorithm.week4;

import java.util.Scanner;

public class fourth {
	
	public static int fac(int n) {
		if(n == 1)
			return 1;
		return n*fac(n-1);
	}
	
	public static int cal2(int n, int n2) {
		if(n == n2)
			return n2;
		return n*cal2(n-1,n2);
	}
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] abc = new int[3];
		for(int i = 0; i < 3; i++)
		    abc[i] = sc.nextInt();
		int n = abc[0]+abc[1]+abc[2];
		System.out.print(cal2(2*n,n+2)/(fac(abc[0])*fac(abc[1])*fac(abc[2])));

	}
}
