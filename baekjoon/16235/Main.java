import java.util.*;
import java.io.*;

class Solve {
    int n, m, k;
    int[][] nutrition = new int[11][11];
    int[][] ground = new int[11][11];
    int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
        @Override
        public int compare(int[] a, int[] b) {
            return Integer.compare(a[2], b[2]);
        }
    });
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] split = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        n = split[0];
        m = split[1];
        k = split[2];
        
        for (int i = 0 ; i<n ; i++) {
            nutrition[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
            Arrays.fill(ground[i+1], 5);
        }
        
        for (int i = 0 ; i<m ; i++) {
            split = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
            pq.offer(split);
        }
    }
    
    private void theFirstHalf( ) {
        List<int[]> deads = new ArrayList<>();
        PriorityQueue<int[]> tmp = new PriorityQueue<>(new Comparator<>(){
            @Override
            public int compare(int[] a, int b[]) {
                return Integer.compare(a[2], b[2]);
            }
        });
        
        int pq_size = pq.size( );
        for (int i = 0 ; i<pq_size ; i++) {
            int[] cur = pq.poll( );
            int cx = cur[0];
            int cy = cur[1];
            int cz = cur[2];
            
            if (ground[cx][cy] >= cz) {
                ground[cx][cy] -= cz;
                tmp.offer(new int[]{cx, cy, cz+1});
            }
            else {
                deads.add(cur);
            }
        }
        
        for (int i = 0 ; i<deads.size( ) ; i++) {
            int[] cur = deads.get(i);
            int cx = cur[0];
            int cy = cur[1];
            int cz = cur[2];
            
            ground[cx][cy] += cz / 2;
        }
        
        pq = tmp;
    }
    
    private void theSecondHalf( ) {
        List<int[]> trees = new ArrayList<>(pq);
        
        for (int i = 0 ; i<trees.size( ) ; i++) {
            int[] cur = trees.get(i);
            int cx = cur[0];
            int cy = cur[1];
            int cz = cur[2];
            
            if (cz % 5 > 0)     continue;
            
            for (int j = 0 ; j<8 ; j++) {
                int tx = cx + dx[j];
                int ty = cy + dy[j];
                
                if (tx<1 || ty<1 || tx>n || ty>n)   continue;
                
                pq.offer(new int[]{tx, ty, 1});
            }
        }
        
        for (int i = 1 ; i<=n ; i++) {
            for (int j = 1 ; j<=n ; j++) {
                ground[i][j] += nutrition[i-1][j-1];
            }
        }
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        for (int i = 0 ; i<k ; i++) {
            theFirstHalf( );
            theSecondHalf( );
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(pq.size( )));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      new Solve( ).solve( );
    }
}