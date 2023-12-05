import java.util.*;
import java.io.*;
import java.util.stream.IntStream;
import java.util.stream.*;

class Solve {
    int t;
    int n;
    int[][] dp = new int[501][501];
    int[] nums;
    int[] sum = new int[501];
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    private void getEachInput( ) throws IOException {
        n = Integer.parseInt(br.readLine( ));
        nums = Arrays.stream(br.readLine( ).split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
    }
    
    private int prefix_sum(int start, int end) {
        if (start == end) {
            return 0;
        }
        
        if (dp[start][end] != -1)    return dp[start][end];
        
        int ans = Integer.MAX_VALUE;
        for(int i = start ; i<end ; i++) {
            ans = Integer.min(ans, prefix_sum(start, i) + prefix_sum(i+1, end)
                    + sum[end] - sum[start-1]);
        }
        
        dp[start][end] = ans;
        return ans;
    }
    
    private int solveEach( ) throws IOException {
        getEachInput( );
        dp = new int[501][501];
        sum = new int[501];
        for(int i = 1 ; i<=n ; i++) {
            for(int j = 1 ; j<=n ; j++) {
                dp[i][j] = -1;
            }
        }
        
        for(int i = 0 ; i<n ; i++) {
            sum[i+1] = sum[i] + nums[i];
        }
        
        return prefix_sum(1, n);
    }
    
    public void solve( ) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine( ));
        
        IntStream.range(0, t)
            .forEach(x -> {
                try {
                    bw.write(Integer.toString(solveEach( )) + "\n");
                }
                catch (IOException e) {
                    
                }
            });
            
        br.close( );
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