package algorithm.week4;

import java.util.Scanner;

public class first {
	
	public static int fibo(int n) {

		if (n<=2)
			return 2;

		return fibo(n-1) + fibo((n-2))/2;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.print(fibo(n));

	}

}
