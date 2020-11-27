package algorithm.week3;

import java.util.Arrays;
import java.util.Scanner;

public class first {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String temp = sc.nextLine();
		String[] ar = temp.split(" ");

		int start, end,ans = 0;
		for(start = 0; start <=ar.length-1; start++)
		{
			int sum = 0;
			for(end = start; end<=ar.length-1;end++) {
				sum+=Integer.parseInt(ar[end]);
				if(ans < sum) ans = sum;
			}
		}
		System.out.print(ans);
	}

}
