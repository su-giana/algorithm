import java.util.*;
import java.io.*;

class Solve {
    int n;
    int[][] board = new int[500][500];
    int[][] dp = new int[500][500];
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        
        for (int i = 0 ; i<n ; i++) {
            board[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
            Arrays.fill(dp[i], -1);
        }
    }
    
    private int dfs(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        
        dp[x][y] = 1;
        
        for (int i = 0 ; i<4 ; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if (tx<0 || ty<0 || tx>=n || ty>=n) continue;
            
            if (board[tx][ty] > board[x][y]) {
                dp[x][y] = Math.max(dp[x][y], 1+dfs(tx, ty));
            }
        }
        
        return dp[x][y];
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<n ; j++) {
                if (dp[i][j] == -1) {
                    dfs(i, j);
                }
            }
        }
        
        int ans = Arrays.stream(dp)
                .flatMapToInt(Arrays::stream)
                .max( )
                .orElse(Integer.MIN_VALUE);
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      new Solve( ).solve( );
    }
}