import java.util.*;
import java.io.*;

class Solve {
    int n, m;
    int[][] map = new int[300][300];
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] s = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        n = s[0];   m = s[1];
        for (int i = 0 ; i<n ; i++) {
            map[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        }
        br.close( );
    }
    
    private void markArea(int x, int y, boolean[][] visited) {
        Queue<int[]> q = new LinkedList<>();
        visited[x][y] = true;
        q.offer(new int[]{x, y});
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 || tx>=n || ty>=m) continue;
                
                if (!visited[tx][ty] && map[tx][ty] > 0) {
                    q.offer(new int[]{tx, ty});
                    visited[tx][ty] = true;
                }
            }
        }
    }
    
    private int cntGroups( ) {
        boolean[][] visited = new boolean[n][m];
        int cnt = 0;
        for (int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                    markArea(i, j, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    private void meltPartOfIce(int x, int y, boolean[][] visited, int[][] tmpMap) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 || tx>=n || ty>=m) continue;
                
                if (!visited[tx][ty] && map[tx][ty] == 0) {
                    q.offer(new int[]{tx, ty});
                    visited[tx][ty] = true;
                }
                else if (!visited[tx][ty] && map[tx][ty] > 0) {
                    if (tmpMap[tx][ty]>0)   tmpMap[tx][ty] -= 1;
                }
            }
        }
    }
    
    private void meltIce( ) {
        boolean[][] visited = new boolean[n][m];
        int[][] tmpMap = new int[n][m];
        
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<m ; j++) {
                tmpMap[i][j] = map[i][j];
            }
        }
        
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<m ; j++) {
                if (map[i][j] == 0 && !visited[i][j]) {
                    meltPartOfIce(i, j, visited, tmpMap);
                }
            }
        }
        map = tmpMap;
    }
    
    public int solve( ) throws IOException {
        getInput( );
        
        int pastCntGroups = cntGroups( );
        int ans = 1;
        while (pastCntGroups != 0) {
            meltIce( );
            int curCntGroups = cntGroups( );
            if (pastCntGroups < curCntGroups) {
                return ans;
            }
            ans++;
            pastCntGroups = curCntGroups;
        }
        return 0;
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      Solve solve = new Solve( );
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      bw.write(Integer.toString(solve.solve( )));
      bw.flush( );
      bw.close( );
    }
}