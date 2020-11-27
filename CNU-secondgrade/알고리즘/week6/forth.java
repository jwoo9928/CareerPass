package algorithm.week6;

import java.util.Arrays;
import java.util.Scanner;

public class forth {
	
	

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] ar1 = sc.nextLine().split(" ");
		String[] ar2 = sc.nextLine().split(" ");
		int[] num1 = Arrays.stream(ar1).mapToInt(Integer::parseInt).toArray();
		int[] num2 = Arrays.stream(ar2).mapToInt(Integer::parseInt).toArray();
		int i = 1;
		int [] temp = num2.clone();
		boolean result = true;
		while(result) {
			temp = num2.clone();
			for(int j=0;j<num1.length;j++) {
				temp[j]*=i;
				if(temp[j] > num1[j])
					result = false;
			}
			i++;
		}
		
		String test = Integer.toString(num2[0]*(i-2));
		for(int j=1;j<num2.length;j++)
			test+=" "+Integer.toString(num2[j]*(i-2));
		System.out.println(test);
	}

}
