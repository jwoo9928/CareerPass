package algorithm.week6;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class second {

	public static void test (ArrayList<Integer> a, int num, int k) {
		if(num <= k)
			a.add(num);
		else {
			int temp1 = num/3;
			int temp2 = num*2/3;
			test(a, temp1, k);
			test(a,temp2,k);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		sc.nextLine();
		String[] ar = sc.nextLine().split(" ");
		int[] num = Arrays.stream(ar).mapToInt(Integer::parseInt).toArray();
		ArrayList<Integer> a =new ArrayList<>();
		for(int i=0;i<num.length;i++)
			test(a,num[i],k);
		System.out.print(a.size() - num.length);

	}

}
