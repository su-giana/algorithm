import java.util.*;
import java.io.*;

class Solve {
    int n, m;
    int[][] board = new int[8][8];
    int ans = Integer.MAX_VALUE;
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] split = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        n = split[0];   m = split[1];
        
        for (int i = 0 ; i< n ; i++) {
            board[i] = Arrays.stream(br.readLine( ).split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray( );
        }
        br.close( );
    }
    
    private int getCorner() {
        int cnt = 0;
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<m ; j++) {
                if (board[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    private void continuousArrow(int x, int y, int cnt) {
        int[] dx = {0, -1, 0, 1};
        int[] dy = {-1, 0, 1, 0};
        
        for (int k = 0 ; k<4 ; k++) {
            Set<int[]> s = new HashSet<>();
            
            for (int i = 0 ; i<cnt ; i++) {
                int idx = (k + i) % 4;
                int tx = x + dx[idx];
                int ty = y + dy[idx];
                
                while (!(tx<0 || ty<0 || tx>=n || ty>=m) && board[tx][ty] != 6) {
                    if(board[tx][ty] == 0) {
                        board[tx][ty] = -1;
                        s.add(new int[]{tx, ty});
                    }
                    tx += dx[idx];
                    ty += dy[idx];
                }
            }
            backTracking(x, y+1);
            
            for(int[] xy : s) {
                board[xy[0]][xy[1]] = 0;
            }
        }
    }
    
    private void gappedArrow(int x, int y, int cnt) {
        int[] dx = {0, -1, 0, 1};
        int[] dy = {-1, 0, 1, 0};
        
        for (int k = 0 ; k<2 ; k++) {
            Set<int[]> s = new HashSet<>();
            
            for (int i = 0 ; i<=cnt ; i++) {
                if (i == 1) continue;
                
                int idx = (k + i) % 4;
                int tx = x + dx[idx];
                int ty = y + dy[idx];
                
                while (!(tx<0 || ty<0 || tx>=n || ty>=m) && board[tx][ty] != 6) {
                    if(board[tx][ty] == 0) {
                        board[tx][ty] = -1;
                        s.add(new int[]{tx, ty});
                    }
                    tx += dx[idx];
                    ty += dy[idx];
                }
            }
            backTracking(x, y+1);
            
            for(int[] xy : s) {
                board[xy[0]][xy[1]] = 0;
            }
        }
    }
    
    private void backTracking(int x, int y) {
        if (x>=n) {
            ans = Math.min(ans, getCorner());
            return;
        }
        
        if(y>=m) {
            backTracking(x+1, 0);
            return;
        }
        
        if (board[x][y] == 1)   continuousArrow(x, y, board[x][y]);
        else if (board[x][y] == 2)   gappedArrow(x, y, board[x][y]);
        else if (board[x][y] >= 3 && board[x][y] <= 5)   continuousArrow(x, y, board[x][y] - 1);
        else    backTracking(x, y+1);
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        backTracking(0, 0);
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