import java.util.*;
import java.io.*;

class Solve {
    int n;
    int[][] dragonCurve = new int[20][4];
    int[][] board = new int[101][101];
    List<Integer> ans = new ArrayList<>();
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        
        for (int i = 0 ; i<n ; i++) {
            dragonCurve[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        }
        br.close( );
    }
    
    private void dc(int dir, int gen, int cur) {
        if (gen < cur)  return;
        
        if (cur == 0) {
            ans = new ArrayList<>(List.of(dir));
        }
        else {
            for (int i = ans.size( ) - 1 ; i>=0 ; i--) {
                ans.add((ans.get(i) + 1) % 4);
            }
        }
        
        dc(dir, gen, cur+1);
    }
    
    private void markBoard(int x, int y, int dir, int gen) {
        dc(dir, gen, 0);
        
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, -1, 0, 1};
        
        board[x][y] = 1;
        for (int i = 0 ; i<ans.size( ) ; i++) {
            int d = ans.get(i);
            int tx = x + dx[d];
            int ty = y + dy[d];
            
            board[tx][ty] = 1;
            x = tx;
            y = ty;
        }
    }
    
    private int countSquare( ) {
        int cnt = 0;
        int[] dx = {0, 1, 0, 1};
        int[] dy = {0, 0, 1, 1};
        
        for (int i = 0 ; i<100 ; i++) {
            for (int j = 0 ; j<100 ; j++) {
                boolean curved = true;
                for (int k = 0 ; k<4 ; k++) {
                    if (board[i + dx[k]][j + dy[k]] == 0)   curved = false;
                }
                if (curved) cnt++;
            }
        }
        return cnt;
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        for (int i = 0 ; i<n ; i++) {
            int[] cur = dragonCurve[i];
            
            markBoard(cur[0], cur[1], cur[2], cur[3]);
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(countSquare( )));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException{
      Solve solve = new Solve( );
      solve.solve( );
    }
}