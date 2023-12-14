import java.util.*;
import java.io.*;

class Solve {
    int n, m;
    int[][] board = new int[200][200];
    int[] plan = new int[1000];
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        m = Integer.parseInt(br.readLine( ));
        
        for (int i = 0 ; i<n ; i++) {
            board[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
            
            for (int j = 0 ; j<n ; j++) {
                if (board[i][j] == 0)   board[i][j] = 100000000;
            }
        }
        
        for (int i = 0 ; i<n ; i++) board[i][i] = 0;
        
        plan = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        
        br.close( );
    }
    
    private void floydWarshall( ) {
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<n ; j++) {
                if (i==j)   continue;
                for (int k = 0 ; k<n ; k++) {
                    if (i==k || j==k)   continue;
                    if (board[i][j] == 1)   continue;
                    board[i][j] = Math.min(board[i][j], board[i][k] + board[k][j]);
                    if (board[i][j] < 100000000) {
                        board[j][i] = 1;
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
    
    public String solve( ) throws IOException {
        getInput( );
        floydWarshall( );
        
        for (int i = 1 ; i<m ; i++) {
            if (board[plan[i-1]-1][plan[i]-1] >= 100000000) {
                return "NO";
            }
        }
        return "YES";
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      Solve solve = new Solve( );
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      bw.write(solve.solve( ));
      bw.flush( );
      bw.close( );
    }
}