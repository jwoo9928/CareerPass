package week9;

import java.util.LinkedList;
import java.util.Scanner;


import java.util.*;


public class first {
	
	class Node {
		boolean marked = false;
		String data;
		LinkedList<Node> edge;
		
		public Node(String data) {
			this.data = data;
			edge = new LinkedList<Node>();	
		}
	}
	static Node[] nodes;
	public first(String[] test) {
		nodes = new Node[test.length];
		nodes = create(test);
	}
	public static Node[] getNode() {
		return nodes;
	}
	
	public Node[] create(String[] test) {
		Node[] nodes = new Node[test.length];
		for(int i=0;i<test.length;i++) { 
			nodes[i] = new Node(test[i]);
		}
		return nodes;
	}
	
	
	static void addEdge(Node n1, Node n2) {
		if(!n1.edge.contains(n2)) {
			n1.edge.add(n2);
		}
		if(!n2.edge.contains(n1)) {
			n2.edge.add(n1);
		}
	}
	
	static int searches(Node[] nodes,String data) {
		for(int i=0;i<nodes.length;i++) {
			if(nodes[i].data.equals(data)) {
				return i;
			}
		}
		return -1;
	}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		String[] test = sc.nextLine().split(" ");
		
		first t= new first(test);
		Node[] nodes = t.getNode();
		
		String[][] edge = new String[m][2];
		for(int i=0;i<m;i++)
			edge[i] = sc.nextLine().split(" ");
		for(int i=0;i<m;i++) {
			int n1 = searches(nodes,edge[i][0]);
			int n2 = searches(nodes,edge[i][1]);
			addEdge(nodes[n1],nodes[n2]);
		}
		String search = sc.next();
		int index = searches(nodes,search);
		System.out.print(nodes[index].edge.size());
		

	}

}
