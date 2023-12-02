import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

class Solve {
    int[][] sdoku = new int[9][9];
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        IntStream.range(0, 9)
            .forEach(i -> {
                try {
                    sdoku[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray( );
                }
                catch (Exception e) {
                    // continue;
                }
            });
            
        br.close( );
    }
    
    private int[] getAvailableNumbers(int x, int y) {
        boolean[] available = new boolean[10];
        
        for(int i = 0 ; i<9 ; i++) {
            available[sdoku[x][i]] = true;
            available[sdoku[i][y]] = true;
        }
        
        for(int i = 3 * (x / 3) ; i<3 * (x / 3) + 3 ; i++) {
            for(int j = 3 * (y / 3) ; j<3 * (y / 3) + 3 ; j++) {
                available[sdoku[i][j]] = true;
            }
        }
        
        return IntStream.range(1, 10).filter(i -> !available[i])
            .toArray( );
    }
    
    private boolean dfs(int x, int y) {
        if(x>=8 && y>8) return true;
        
        if(y>8) return dfs(x+1, 0);
        
        if(sdoku[x][y] == 0) {
            int[] available = getAvailableNumbers(x, y);
            
            for(int i = 0 ; i<available.length ; i++) {
                sdoku[x][y] = available[i];
                if(dfs(x, y+1)) return true;
                sdoku[x][y] = 0;
            }
        }
        else {
            return dfs(x, y+1);
        }
        
        return false;
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        dfs(0, 0);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i = 0 ; i<9 ; i++) {
            for(int j = 0 ; j<9 ; j++) {
                bw.write(Integer.toString(sdoku[i][j]) + " ");
            }
            bw.write("\n");
        }
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