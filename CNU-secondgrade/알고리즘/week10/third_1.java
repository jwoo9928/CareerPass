package algorithm.week10;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

public class third_1 {

    static int V, E;

    static PriorityQueue<Edge> pq;
    static ArrayList<Edge> MST;
    static int parent[];
    static ArrayList<Integer> save = new ArrayList<>();

    public static void main(String[] args) {
    	 Scanner sc = new Scanner(System.in);
         V = sc.nextInt();
         E = sc.nextInt();
         sc.nextLine();
         HashMap<String,Integer> map = new HashMap<>();
         String nodes[] = sc.nextLine().split(" ");
         for(int i=0;i<nodes.length;i++)
         	map.put(nodes[i],i);
         ArrayList<String> tests = new ArrayList<>();
         for(int i=0; i<E; i++) {
         	String t = sc.nextLine();
         	String[] temp = t.split(" ");
         	if(!tests.contains(t) && !tests.contains(temp[1]+" "+temp[0]+" "+temp[2]))
         		tests.add(t);
         }
         
         String test[][] = new String[tests.size()][3];
         for(int i=0; i<tests.size(); i++) {
         	test[i] = tests.get(i).split(" ");
         }
         E = test.length;
         pq = new PriorityQueue<>();
         MST = new ArrayList<>();
         parent = new int[V+1];

         for(int i=0; i<=V; i++)
             parent[i] = i;
         for(int i=0; i<test.length; i++) {
        	 pq.add(new Edge(test[i][0], test[i][1], Integer.parseInt(test[i][2])));
         }
         Edge es;
         while(MST.size() < (V-1) && (es = pq.poll()) != null) {
             if(find((int) map.get(es.begin)) != find((int) map.get(es.end))) {
                 MST.add(es);
                 union((int) map.get(es.begin), (int) map.get(es.end));
             }
         }
         int min = 0;
         for(int i=0; i<MST.size(); i++) {
         	min+=MST.get(i).val;
         }
         String[] b = new String[MST.size()];
         String[] ee = new String[MST.size()];
         for(int i = 0;i<MST.size();i++) {
        	 b[i] = MST.get(i).begin;
        	 ee[i] = MST.get(i).end;
         }
         
         
         
         
         //
         for(int k=0;k<b.length;k++) {
        	 pq = new PriorityQueue<>();
             MST = new ArrayList<>();
             parent = new int[V+1];

             for(int i=0; i<=V; i++)
                 parent[i] = i;
             for(int i=0; i<E; i++) {
            	 if(b[k]==test[i][0] && ee[k] == test[i][1]) i+=1;
         		if(i == E)
         			break;
                 pq.add(new Edge(test[i][0], test[i][1], Integer.parseInt(test[i][2])));
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
             save.add(weight);
             
         }
         int imp=0;
         for(int i=0;i<save.size();i++) {
         	if(min != save.get(i))
         		imp++;
         }System.out.print(imp);
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