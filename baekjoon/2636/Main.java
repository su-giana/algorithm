import java.util.*;
import java.io.*;

class Solve {
    int n, m;
    int[][] cheese = new int[100][100];
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] tmp = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        n = tmp[0];
        m = tmp[1];
        
        for (int i = 0 ; i<n ; i++) {
            cheese[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        }
        
        br.close( );
    }
    
    private boolean allMelt( ) {
        return Arrays.stream(cheese)
                .mapToInt(c -> {
                    return Arrays.stream(c).sum( );
                }).sum( ) == 0;
    }
    
    private int meltCheese(int x, int y, int[][] tmpCheese, boolean[][] visited) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        int cnt = 0;
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 || tx>=n || ty>=m) continue;
                
                if (!visited[tx][ty] && cheese[tx][ty] == 0) {
                    q.offer(new int[]{tx, ty});
                    visited[tx][ty] = true;
                }
                else if (!visited[tx][ty] && cheese[tx][ty] == 1) {
                    visited[tx][ty] = true;
                    cnt++;
                    tmpCheese[tx][ty] = 0;
                }
            }
        }
        return cnt;
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        int cnt = 0;
        int prev = 0;
        while (!allMelt( )) {
            int now = 0;
            int[][] tmpCheese = new int[100][100];
            for (int i = 0 ; i<n ; i++) {
                for(int j = 0 ; j<m ; j++) {
                    tmpCheese[i][j] = cheese[i][j];
                }
            }
            boolean[][] visited = new boolean[100][100];
            for (int i = 0 ; i<n ; i++) {
                for(int j = 0 ; j<m ; j++) {
                    if ((i==0 || j == 0 || i==n-1 || j==m-1) && !visited[i][j]) {
                        now += meltCheese(i, j, tmpCheese, visited);
                    }
                }
            }
            prev = now;
            cheese = tmpCheese;
            cnt++;
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(cnt) + "\n" + Integer.toString(prev));
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