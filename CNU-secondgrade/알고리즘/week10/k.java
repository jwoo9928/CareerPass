package algorithm.week10;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

public class k {

    static int V, E;

    static PriorityQueue<Edge> pq;
    static ArrayList<Edge> MST;
    static int parent[];

    public static void main(String[] args) {
    	 Scanner sc = new Scanner(System.in);
         V = sc.nextInt();
         E = sc.nextInt();
         sc.nextLine();
         HashMap<String,Integer> map = new HashMap<>();
         String nodes[] = sc.nextLine().split(" ");
         for(int i=0;i<nodes.length;i++)
         	map.put(nodes[i],i);

        pq = new PriorityQueue<>();
        MST = new ArrayList<>();
        parent = new int[V+1];

        for(int i=0; i<=V; i++)
            parent[i] = i;
        for(int i=1; i<=E; i++) {
        	String test[] = sc.nextLine().split(" ");
            pq.add(new Edge(test[0], test[1], Integer.parseInt(test[2])));
        }
        Edge e;
        while(MST.size() < (V-1) && (e = pq.poll()) != null) {
            if(find((int) map.get(e.begin)) != find((int) map.get(e.end))) {
                MST.add(e);
                union((int) map.get(e.begin), (int) map.get(e.end));
            }
        }
        int weight = 0;
        for(int i=0; i<MST.size(); i++) {
        	weight+=MST.get(i).val;
        }
        System.out.print(weight);
    }
    
    public static int find(int n) {
        if(n==parent[n])
            return n;
        else {
            int p = find(parent[n]);
            parent[n] = p;
            return p;
        }
    }

    public static void union(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1!=p2) {
            parent[p1] = p2;
        }
    }

    public static class Edge implements Comparable<Edge>{
    	String begin;
    	String end;
        int val;
        public Edge(String b, String e, int v) {
            this.begin = b;
            this.end = e;
            this.val = v;
        }
        @Override
        public int compareTo(Edge o) {
            return this.val - o.val;
        }
    }
}