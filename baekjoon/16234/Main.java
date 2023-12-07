import java.util.*;
import java.io.*;
import java.util.stream.*;

class Solve {
    int n, l, r;
    int[][] countries = new int[50][50];
    int[][] visited;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] split = Arrays.stream(br.readLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray( );
        n = split[0];
        l = split[1];
        r = split[2];
        
        IntStream.range(0, n).forEach(i -> {
            try {
                countries[i] = Arrays.stream(br.readLine( ).split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray( );
            }
            catch (IOException e) {
                
            }
        });
        br.close( );
    }
    
    private void bfs(int x, int y, int col) {
        Queue<int[]> q = new LinkedList<>();
        visited[x][y] = col;
        q.offer(new int[]{x, y});
        int total = countries[x][y];
        int cnt = 1;
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 || tx>=n || ty>=n)  continue;
                
                if (visited[tx][ty] == 0) {
                    int gap = Math.abs(countries[tx][ty] - countries[cx][cy]);
                    
                    if (gap>=l && gap<=r) {
                        visited[tx][ty] = col;
                        total += countries[tx][ty];
                        cnt++;
                        q.offer(new int[]{tx, ty});
                    }
                }
            }
        }
        
        visited[x][y] = -1;
        countries[x][y] = total / cnt;
        q.offer(new int[]{x, y});
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 || tx>=n || ty>=n)  continue;
                
                if (visited[tx][ty] == col) {
                    countries[tx][ty] = total / cnt;
                    visited[tx][ty] = -1;
                    q.offer(new int[]{tx, ty});
                }
            }
        }
    }
    
    public void solve( ) throws IOException {
        getInput( );
        int ans = 0;
        
        while (true) {
            int cnt = 0;
            visited = new int[100][100];
            for (int i = 0 ; i<n ; i++) {
                for (int j = 0 ; j<n ; j++) {
                    if (visited[i][j] == 0) {
                        bfs(i, j, ++cnt);
                    }
                }
            }
            if (cnt == n*n) break;
            ans++;
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