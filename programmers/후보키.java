import java.util.*;
import java.io.*;
import java.util.stream.*;

class Solution {
    List<List<Integer> > candidateKeys = new ArrayList<>( );
    
    public void backTracking(String[][] relation, int cur, int depth, List<Integer> past) {
        if (depth == 0) {
            Set<List<String> > s = new HashSet<>( );
            Arrays.stream(relation)
                .forEach(rel -> {
                    List<String> partOfTuple = new ArrayList<>( );
                    past.stream( )
                        .forEach(ele -> partOfTuple.add(rel[ele]));
                    s.add(partOfTuple);
                });
            
            if (s.size( ) == relation.length) {
                List<Integer> val = new ArrayList<>( );
                for (int p : past) {
                    val.add(p);
                }
                candidateKeys.add(val);
            }
            
            return;
        }
        
        if (cur >= relation[0].length)	return;
        
        backTracking(relation, cur+1, depth, past);
        past.add(cur);
        backTracking(relation, cur+1, depth-1, past);
        past.remove(past.size( ) - 1);
    }
    
    
    public int solution(String[][] relation) {
        for (int i = 1 ; i<=relation[0].length ; i++) {
            backTracking(relation, 0, i, new ArrayList<>( ));
        }
        
        candidateKeys.sort(new Comparator<List<Integer> > () {
            @Override
            public int compare(List<Integer> a, List<Integer> b) {
                return Integer.compare(a.size( ), b.size( ));
            }
        });
        
        int answer = 0;
        for (int i = 0 ; i<candidateKeys.size( ) ; i++) {
            boolean violateMinimality = false;
            for (int j = 0 ; j<i ; j++) {
                if (candidateKeys.get(i).containsAll(candidateKeys.get(j))) {
                    violateMinimality = true;
                    break;
                }
            }
            
            if (violateMinimality)	continue;
            
            answer++;
        }
        
        return answer;
    }
}