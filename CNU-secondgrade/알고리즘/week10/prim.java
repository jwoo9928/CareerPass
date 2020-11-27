package algorithm.week10;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

 

public class prim {

    static int V,E;
    static boolean visit[];
    static ArrayList<Edge>[] graph;
    static ArrayList<Edge> MST;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        V = sc.nextInt();
        E = sc.nextInt();
        sc.nextLine();
        HashMap<String,Integer> map = new HashMap<>();
        String nodes[] = sc.nextLine().split(" ");
        for(int i=0;i<nodes.length;i++)
        	map.put(nodes[i],i);
        visit = new boolean[V+1];
        graph = new ArrayList[V+1];
        for(int i=0; i<=V; i++) 
                graph[i] = new ArrayList<>();
        MST = new ArrayList<>();
        for(int i=1; i<=E; i++) {
        	String test[] = sc.nextLine().split(" ");
        	graph[map.get(test[0])].add(new Edge(test[0], test[1], Integer.parseInt(test[2])));
        	graph[map.get(test[1])].add(new Edge(test[1], test[0], Integer.parseInt(test[2])));
        }
        int point = 1;
        solve(point, map);
        int weight = 0;
        for(int i=0; i<MST.size(); i++) {
        	weight+=MST.get(i).value;
        	
        }
        if(MST.size()!= map.size()-1)
        	System.out.print(0);
        else
        	System.out.print(weight);
    }

    private static void solve(int P, HashMap map) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        Queue<Integer> queue = new LinkedList<>();        
        queue.add(P);
        while(!queue.isEmpty()) {
                int now = queue.poll();
                visit[now] = true;
                for(Edge e : graph[now]) {
                    if(!visit[(int) map.get(e.end)])
                        pq.add(e);
                }

                while(!pq.isEmpty()) {
                    Edge e = pq.poll();
                    if(!visit[(int) map.get(e.end)]) {
                        queue.add((int) map.get(e.end));
                        visit[(int) map.get(e.end)] = true;
                        MST.add(e);
                        break;
                    }
                }
        }
    }

    public static class Edge implements Comparable<Edge>{
    	String begin;
    	String end;
        int value;
        public Edge(String b, String e, int v) {
            this.begin = b;
            this.end = e;
            this.value = v;
        }
        @Override
        public int compareTo(Edge o) {
            // TODO Auto-generated method stub
            return this.value - o.value;

        }
    }
}