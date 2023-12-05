import java.util.*;
import java.io.*;
import java.util.stream.IntStream;

class Solve {
    int n, m;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    int[][] board = new int[500][500];
    long[][] dp = new long[500][500];
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] split = br.readLine( ).split(" ");
        n = Integer.parseInt(split[0]);
        m = Integer.parseInt(split[1]);
        
        IntStream.range(0, n).forEach(i -> {
            try {
                board[i] = Arrays.stream(br.readLine( ).split(" "))
                    .mapToInt(Integer::parseInt).toArray( );
            }
            catch(IOException e) {
                e.printStackTrace( );
            }
        });
        br.close( );
    }
    
    private void dfs(int x, int y, boolean[][] visited) {
        if (x == n-1 && y == m-1) {
            if (dp[x][y] == -1) {
                dp[x][y] = 1;
            }
            else {
                dp[x][y]++;
            }
            return;
        }
        
        if(dp[x][y] == -1) {
            dp[x][y] = 0;
        }
        for (int i = 0 ; i<4 ; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if (tx<0 || ty<0 || tx>=n || ty>=m)  continue;
            if (visited[tx][ty]) continue;
            if (board[x][y] <= board[tx][ty])    continue;
            
            visited[tx][ty] = true;
            if(dp[tx][ty] == -1) {
                dfs(tx, ty, visited);
            }
            dp[x][y] += dp[tx][ty];
            visited[tx][ty] = false;
        }
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                dp[i][j] = -1;
            }
        }
        
        boolean[][] visited = new boolean[500][500];
        visited[0][0] = true;
        dfs(0, 0, visited);
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Long.toString(dp[0][0]));
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