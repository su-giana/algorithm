import java.util.*;
import java.io.*;

class Solve {
    int n, m;
    int[][] board = new int[100][100];
    boolean[][] visited = new boolean[100][100];
    int[][] dp = new int[100][100];
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] split = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        n = split[0];   m = split[1];
        
        for (int i = 0 ; i<m ; i++) {
            String line = br.readLine( );
            for (int j = 0 ; j<n ; j++) {
                board[i][j] = line.charAt(j) - '0';
            }
            Arrays.fill(dp[i], -1);
        }
    }
    
    private void dijkstra( ) {
        PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare (int[] a, int[] b) {
                return Integer.compare(a[2], b[2]);
            }
        });
        q.offer(new int[]{0, 0, 0});
        dp[0][0] = 0;
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cnt = cur[2];
            int x = cur[0];
            int y = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx>=m || ty>=n || tx<0 ||ty<0)  continue;
                
                if (dp[tx][ty] == -1 || dp[tx][ty] > dp[x][y] + board[tx][ty]) {
                    dp[tx][ty] = dp[x][y] + board[tx][ty];
                    q.offer(new int[]{tx, ty, dp[tx][ty]});
                }
            }
        }
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        dijkstra( );
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(dp[m-1][n-1]));
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