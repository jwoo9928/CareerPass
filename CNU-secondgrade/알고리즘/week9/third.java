package week9;

import java.util.*;


public class third {
	
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
	public third(String[] test) {
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
	
	static String ar = "";
	
	public static void dfs(Node node) {
		ar += node.data + " ";
		node.marked = true;
		sort(node.edge);
		for(Node j : node.edge) {
			if(j.marked == false)
				dfs(j);
		}
	}
	
	
	public static void sort(LinkedList<Node> edge) {
		String temp_data;
		LinkedList<Node> temp_edge;
		boolean temp_marked;
		for(int i = 0 ; i < edge.size() ; i ++) {
			for(int j = 0 ; j < edge.size() -i -1 ; j ++) {
				if(edge.get(j).data.compareTo(edge.get(j+1).data) > 0) {
					temp_data = edge.get(j).data;
					temp_edge = edge.get(j).edge;
					temp_marked = edge.get(j).marked;
					edge.get(j).data = edge.get(j+1).data;
					edge.get(j).edge = edge.get(j+1).edge;
					edge.get(j).marked = edge.get(j+1).marked;
					edge.get(j+1).data = temp_data;
					edge.get(j+1).edge = temp_edge;
					edge.get(j+1).marked = temp_marked;
				}
			}
		}
	}
	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		String[] test = sc.nextLine().split(" ");
		
		third t= new third(test);
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
		dfs(nodes[index]);
		System.out.printf("%s",ar.trim());
		

	}

}
