import java.io.*;
import java.util.*;

class Solve {
    int n, m;
    PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
        @Override
        public int compare(int[] o1, int[] o2) {
            return Integer.compare(o1[2], o2[2]);
        }
    });
    int[] root;
    
    private int find(int cur) {
        if(root[cur] ==  cur) {
            return cur;
        }
        return root[cur] = find(root[cur]);
    }
    
    private void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        root[rootA] = rootB;
    }
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        root = new int[n+1];
        for(int i = 0 ; i<=n ; i++) root[i] = i;
        
        m = Integer.parseInt(br.readLine( ));
        for(int i = 0 ; i<m ; i++) {
            q.offer(Arrays.stream(br.readLine( ).split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray( ));
        }
    }
    
    public void solve( ) throws IOException {
        getInput( );
        int ans = 0;
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int a = cur[0];
            int b = cur[1];
            int c = cur[2];
            
            if(find(a) == find(b))  continue;
            
            merge(a, b);
            ans += c;
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      Solve solve = new Solve( );
      solve.solve( );
    }
}