package algorithm.week5;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class second {
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<ssd> ar = new ArrayList<>();
		String temp;
		while(sc.hasNextLine()) {
			temp = sc.nextLine();
			if(temp.isEmpty())
				break;
			ssd t = new ssd(temp);
			ar.add(t);
		}
		//size;
		for(int i=0;i<ar.size()-1;i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).size <ar.get(j+1).size) {
					ssd tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		//speed
		for(int i=0;i<ar.size()-1;i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).speed.compareTo(ar.get(j+1).speed) > 0 && ar.get(j).size <= ar.get(j+1).size) {
					ssd tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		//price
		for(int i=0;i<ar.size()-1;i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).price>ar.get(j+1).price && ar.get(j).size <= ar.get(j+1).size
						&& ar.get(j).speed.compareTo(ar.get(j+1).speed) >= 0) {
					ssd tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		//name
		for(int i=0;i<ar.size()-1;i++) {
			for(int j = 0;j<ar.size()-i-1;j++) {
				if(ar.get(j).name.compareTo(ar.get(j).name) > 0 &&ar.get(j).price>=ar.get(j+1).price 
						&& ar.get(j).size <= ar.get(j+1).size
						&& ar.get(j).speed.compareTo(ar.get(j+1).speed) >= 0) {
					ssd tp = ar.get(j);
					ar.add(j,ar.get(j+1));
					ar.remove(j+1);
					ar.add(j+1,tp);
					ar.remove(j+2);
				}
			}
		}
		
		for(int k=0;k<ar.size();k++)
			System.out.println(ar.get(k).name);
	}

}
class ssd {
	String name;
	int size;
	String speed;
	int price;
	
	public ssd(String str) {
		String[] temp = str.split(" ");
		name = temp[0];
		size = Integer.parseInt(temp[1]);
		speed =temp[2];
		price = Integer.parseInt(temp[3]);
	}
	
}
