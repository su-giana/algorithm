import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

class Gear {
    Deque<Integer> upper = new ArrayDeque<>();
    Deque<Integer> lower = new ArrayDeque<>();
    
    public Gear(String gear) {
        for(int i = 0 ; i<2 ; i++) {
            upper.addFirst(gear.charAt(i) - '0');
        }
        for(int i = 2 ; i<6 ; i++) {
            lower.addFirst(gear.charAt(i) - '0');
        }
        for(int i = 6 ; i<8 ; i++) {
            upper.addLast(gear.charAt(i) - '0');
        }
        upper.addFirst(gear.charAt(7) - '0');
        upper.addFirst(gear.charAt(6) - '0');
    }
    
    public int returnWest( ) {
        return upper.peekFirst( );
    }
    
    public int returnEast( ) {
        return lower.peekFirst( );
    }
    
    public void turn(int direction, boolean[] visited) {
        if (direction == -1) {
            lower.addLast(upper.pollFirst( ));
            upper.addLast(lower.pollFirst( ));
        }
        else {
            upper.addFirst(lower.pollLast( ));
            lower.addFirst(upper.pollLast( ));
        }
    }
    
    public int top( ) {
        upper.pollFirst( ); upper.pollFirst( );
        return upper.pollFirst( );
    }
}

class Gears {
    private List<Gear> gears;
    
    public Gears(List<String> gears) {
        this.gears = gears.stream()
                    .map(gear -> new Gear(gear))
                    .collect(Collectors.toList());
    }
    
    public void turnEachGear(int idx, int direction) {
        boolean[] visited = new boolean[4];
        visited[idx] = true;
        gears.get(idx).turn(direction, visited);
        
        if(idx>0 && gears.get(idx-1).returnEast( ) == gears.get(idx).returnWest( ) && !visited[idx-1]) {
            visited[idx-1] = true;
            gears.get(idx-1).turn(direction * -1, visited);
        }
        if(idx<4 && gears.get(idx+1).returnWest( ) == gears.get(idx).returnEast( ) && !visited[idx+1]) {
            visited[idx+1] = true;
            gears.get(idx+1).turn(direction * -1, visited);
        }
    }
    
    public int calculate( ) {
        int score = 1;
        int ans = 0;
        
        for(int i = 0 ; i<4 ; i++) {
            int val = gears.get(i).top( );
            if(val == 1) {
                ans += score;
            }
                
            score *= 2;
        }
        
        return ans;
    }
}

class Solve {
    private int n;
    private Gears gears;
    
    public void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        List<String> gearsInput = IntStream.range(0, 4)
                                .mapToObj(i -> {
                                    try {
                                        return br.readLine( );
                                    }
                                    catch (IOException e) {
                                        return null;
                                    }
                                })
                                .collect(Collectors.toList());
        this.gears = new Gears(gearsInput);
        
        n = Integer.parseInt(br.readLine( ));
        
        for(int i = 0 ; i<n ; i++) {
            String input = br.readLine( );
            int idx = Integer.parseInt(input.split(" ")[0]);
            int direction = Integer.parseInt(input.split(" ")[1]);
            this.gears.turnEachGear(idx, direction);
        }
        
        br.close( );
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(this.gears.calculate( )));
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