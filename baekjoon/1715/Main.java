import java.util.*;
import java.io.*;
import java.util.stream.*;

class Solve {
    int n;
    long[] cards = new long[100001];
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        
        IntStream.range(0, n)
                .forEach(i -> {
                    try {
                        cards[i] = Long.parseLong(br.readLine( ));
                    }
                    catch (IOException e) {
                        
                    }
                });
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        PriorityQueue<Long> q = new PriorityQueue<>();
        
        for(int i = 0 ; i<n ; i++) {
            q.offer(cards[i]);
        }
        
        long ans = 0;
        while(q.size() > 1) {
            long cur = q.poll( ) + q.poll( );
            ans += cur;
            q.offer(cur);
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Long.toString(ans));
        bw.flush();
        bw.close();
    }
}

public class Main {
    public static void main(String args[]) throws IOException{
      Solve solve = new Solve( );
      solve.solve( );
    }
}