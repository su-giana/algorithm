import java.io.*;
import java.util.*;

class Solve {
    int n;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    List<String> record = new ArrayList<>();
    
    private void getInput( ) throws IOException {
        n  = Integer.parseInt(br.readLine( ));
        br.close( );
    }
    
    private int hannoi(int cur, int start, int end, int via) {
        if(cur==1) {
            record.add(start + " " + end);
            return 1;
        }
        
        int pre = hannoi(cur-1, start, via, end);
        record.add(start + " " + end);
        return pre + 1 + hannoi(cur-1, via, end, start);
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        
        bw.write(Integer.toString(hannoi(n, 1, 3, 2)) + "\n");
        for(int i = 0 ; i<record.size() ; i++) {
            bw.write(record.get(i) + "\n");
        }
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
