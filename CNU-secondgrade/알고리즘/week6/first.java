package algorithm.week6;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class first {
	
	public static String[] compares(String[] ar1, String[] ar2) {
		String[] result = new String[ar1.length - ar2.length+2];
		HashMap<String, Integer> map = new HashMap<>();
		for (String element : ar1)
			map.put(element, map.getOrDefault(element,0)+1);
		for (String element : ar2)
			map.put(element, map.get(element) - 1);
		int i = 0;
		for (String key : map.keySet()) {
			if(map.get(key) != 0) {
				for (int j=0;j<map.get(key);j++) {
					i +=1;
					result[i] = key;
				}
			}
		}
		return result;
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] ar1 = sc.nextLine().split(" ");
		String[] ar2 = sc.nextLine().split(" ");
		String[] temp  = compares(ar1,ar2);
		ArrayList<String> a = new ArrayList<>();
		for(int i=0;i<temp.length;i++) {
			if(temp[i] != null)
				a.add(temp[i]);
		}
		Collections.sort(a);
		for(int i=0;i<a.size();i++)
			System.out.println(a.get(i));

	}

}
