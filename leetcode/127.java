import java.io.*;
import java.util.*;

class Solution {
    List<List<Integer> > graph = IntStream.range(0, 5001)
                        .mapToObj(i -> new ArrayList<Integer>())
                        .collect(Collectors.toList( ));

    private int bfs(int begin, int end) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[5001];
        int cnt = 1;
        
        visited[begin] = true;
        q.offer(begin);

        while (!q.isEmpty( )) {
            int q_size = q.size( );
            for (int k = 0 ; k<q_size ; k++) {
                int cur = q.poll( );

                if (cur == end) return cnt;

                for (int next : graph.get(cur)) {
                    if (!visited[next]) {
                        q.offer(next);
                        visited[next] = true;
                    }
                }
            }
            cnt++;
        }
        return 0;
    }

    private boolean singleDifference(String fst, String snd) {
        int cnt = 0;
        for (int i = 0 ; i<fst.length( ) ; i++) {
            if (fst.charAt(i) != snd.charAt(i)) cnt++;
        }

        return cnt == 1;
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int begin = 0;
        int end = -1;
        
        for (int j = 0 ; j<wordList.size( ) ; j++) {
                String next = wordList.get(j);

                if (singleDifference(beginWord, next)) {
                    graph.get(0).add(j+1);
                    graph.get(j+1).add(0);
                }
            }

        for (int i = 0 ; i<wordList.size( ) ; i++) {
            String cur = wordList.get(i);

            if (endWord.equals(cur))    end = i+1;

            for (int j = i+1 ; j<wordList.size( ) ; j++) {
                String next = wordList.get(j);

                if (singleDifference(cur, next)) {
                    graph.get(i+1).add(j+1);
                    graph.get(j+1).add(i+1);
                }
            }
        }

        return bfs(begin, end);
     }
}