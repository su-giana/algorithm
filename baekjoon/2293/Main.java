import java.util.*;
import java.io.*;
import java.util.stream.IntStream;

class Solve {
    int n, k;
    int[] coins;
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine( ).split(" ");
        this.n = Integer.parseInt(split[0]);
        this.k = Integer.parseInt(split[1]);
        
        this.coins = new int[n];
        
        for(int i = 0 ; i<n ; i++) {
            coins[i] = Integer.parseInt(br.readLine( ));
        }
        Arrays.sort(coins);
        br.close( );
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int[][] dp = new int[100][10001];
        dp[0][0] = 1;
        
        for(int i = 1 ; i<=k ; i++) {
            for(int j = 0 ; j<n ; j++) {
                int coin = coins[j];
                if(coin > i)    break;
                
                for(int l = 0 ; l<=j; l++) {
                    dp[j][i] += dp[l][i - coin];
                }
            }
        }

        bw.write(Integer.toString(IntStream.range(0, n).map(i -> dp[i][k]).sum( )));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException{
        Solve solve = new Solve();
        solve.solve();
    }
}