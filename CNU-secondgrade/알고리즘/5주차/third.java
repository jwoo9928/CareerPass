package algorithm.week5;

import java.util.ArrayList;
import java.util.Scanner;

public class third {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<file> ar = new ArrayList<>();
		String temp;
		while(sc.hasNextLine()) {
			temp = sc.nextLine();
			if(temp.isEmpty())
				break;
			file t = new file(temp);
			ar.add(t);
		}
		//format
		for(int i=0;i<ar.size();i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).format.toLowerCase().compareTo(ar.get(j+1).format.toLowerCase()) > 0) {
					file tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		//name
		for(int i=0;i<ar.size();i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).name.compareTo(ar.get(j+1).name) > 0 && ar.get(j).format.toLowerCase().compareTo(ar.get(j+1).format.toLowerCase()) >= 0) {
					file tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		
		for(int i=0;i<ar.size();i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).number > ar.get(j+1).number
						&&ar.get(j).name.compareTo(ar.get(j+1).name) >= 0 && ar.get(j).format.toLowerCase().compareTo(ar.get(j+1).format.toLowerCase()) >= 0) {
					file tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		for(int k=0;k<ar.size();k++)
			System.out.println(ar.get(k).strs);
	}

}

class file {
	String format;
	String name;
	int number;
	String strs;
	
	public file(String str) {
		strs = str;
		String[] temp = str.split("[.]");
		name = temp[0];
		format = temp[1];
		temp = name.split("-");
		name = temp[0];
		if(temp.length != 1)
			number = Integer.parseInt(temp[1]);
		else
			number = 0;
	}
}

