import java.util.*;
import java.io.*;

class Node {
    public int val;
    public int animal;
    public List<Node> child;
    
    public Node(int val, int animal) {
        this.val = val;
        this.animal = animal;
        child = new ArrayList<>( );
    }
}

class Solution {
    Node[] nodes = new Node[17];
    
    public List<List<Integer> > dfs(Node cur, List<Integer> visited) {
        List<List<Integer> > stackedPath = new ArrayList<>( );
        stackedPath.add(new ArrayList<>(visited));
        
        if (cur == null) {
            return stackedPath;
        }
        
        if (!visited.contains(cur.val)) {
            visited = new ArrayList<>(visited);
            visited.add(cur.val);
            
            int sheep = 0;
            int wolf = 0;
            
            for (int spot : visited) {
                if (nodes[spot].animal == 0) {
                    sheep++;
                }
                else {
                    wolf++;
                }
            }
            
            if (wolf >= sheep) {
            	return new ArrayList<>( );
        	}
            
            stackedPath = new ArrayList<>( );
	        stackedPath.add(new ArrayList<>(visited));
        }
        
        int len;
        while (true) {
            len = stackedPath.size( );
			List<List<Integer> > newPath = new ArrayList<>( );
            for (List<Integer> history : stackedPath) {
               	for (Node next : cur.child) {
                    for (List<Integer> executed : dfs(next, history)) {
                    	if (stackedPath.stream( )
                       		.allMatch(i -> !i.containsAll(executed))) {
                        	newPath.add(new ArrayList<>(executed));
                    	}
                	}
                }
            }
            
            stackedPath.addAll(newPath);
            
            if (len == stackedPath.size( ))	break;
        }
        
        return stackedPath;
    }
    
    
    public int solution(int[] info, int[][] edges) {
        for (int i = 0 ; i<info.length ; i++) {
            int cur = info[i];
            
            nodes[i] = new Node(i, cur);
        }
        
        for (int[] edge : edges) {
            int parent = edge[0];
            int child = edge[1];
            
            nodes[parent].child.add(nodes[child]);
        }
        
        int answer = dfs(nodes[0], new ArrayList<>( )).stream( )
            		.mapToInt(i -> {
                        int sheep = 0;
            			int wolf = 0;
            
			            for (int spot : i) {
            			    if (nodes[spot].animal == 0) {
			                    sheep++;
            			    }
			                else {
            			        wolf++;
			                }
            			}
                        
                        return sheep;
                    })
            		.max( )
            		.orElse(0);
        return answer;
    }
}