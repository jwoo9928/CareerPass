package algorithm.week3;

import java.util.Arrays;
import java.util.Scanner;

public class second {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int max = 0;
		int n = sc.nextInt();
		int[] integers = new int[n];
		for(int i = 0; i < n; i++)
		    integers[i] = sc.nextInt();
		Arrays.sort(integers);
		
		for(int j=0;j<integers.length;j++) {
			max+=j;
		}
		System.out.println(max);
		
		for(int i=0;i<integers.length-1;i++)
			System.out.print(integers[i]+" ");
		System.out.print(integers[integers.length-1]);

	}
}
