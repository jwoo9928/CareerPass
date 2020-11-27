package algorithm.week5;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class first {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		ArrayList<String> ar = new ArrayList<>();
		String temp;
		while(sc.hasNextLine()) {
			temp = sc.nextLine();
			if(temp.isEmpty())
				break;
			ar.add(temp);
		}
		Collections.sort(ar);

		Iterator iter = ar.iterator();
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
	}
}
