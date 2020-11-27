package algorithm.week6;

import java.util.Arrays;
import java.util.Scanner;

public class third {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		sc.nextLine();
		String[] ar = sc.nextLine().split(" ");
		int[] num = Arrays.stream(ar).mapToInt(Integer::parseInt).toArray();
		Arrays.sort(num);
	for(int i=0;i<num.length;i++) {
		int les = k%num[i];
		if(les==0) {
			int i2 = Arrays.binarySearch(num,k/num[i]);
			if(i2>=0)
				System.out.println(i+" "+i2);
		}
	}
	}

}
