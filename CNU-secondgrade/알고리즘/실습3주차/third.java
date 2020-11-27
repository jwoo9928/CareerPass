package algorithm.week4;

import java.util.Arrays;
import java.util.Scanner;

public class third {
	static int check = 0;
	static char[] save = new char[9999];
	
	public static void test(int n, int m, char[] a, int num) {
		if(n == 0 && check < num) {
			for(int i=0;i<m;i++) {
				a[0] +=1;
				check+=1;
				if(check == num) {
					for(int j=0;j<a.length;j++)
						save[j] = a[j];
		}	}	}		
		
		else {
			for(int i=0;i<m && check< num;i++) {
				if(n>0 && a[n-1] == 'a'+(m-1))
					a[n-1] = 'a'-1;
				a[n] +=1;
				test(n-1,m,a, num);	
	}	}	}

	public static void main(String[] args) {
		Scanner sc  = new Scanner(System.in);
		int[] nm = new int[2];
		for(int i = 0; i < 2; i++)
		    nm[i] = sc.nextInt();
		int num = sc.nextInt();
		char[] set = new char[nm[0]+1];
		int length;
		if(nm[0]%2 == 0)
			length = nm[0]/2;
		else
			length = nm[0]/2+1;
		char[] a = new char[length];
		for(int i=0;i<a.length;i++)
			a[i] = 'a'-1;
		test(length-1,nm[1],a,num);
		if(nm[0]%2 == 0)
			length -=1;
		for(int k=0;k<a.length;k++)
			set[k] = save[length-k];
		for(int j=0;j<a.length;j++)
			set[a.length+j] = save[j];
		String str = new String(set);
		System.out.print(str.trim());
	}

}
