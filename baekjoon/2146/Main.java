import java.util.*;
import java.io.*;

class Point {
    int x;
    int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}

class Solve {
    
    int n;
    int[][] board = new int[100][100];
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private void getInput( ) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine( ));
        
        for (int i = 0 ; i<n ; i++) {
            board[i] = Arrays.stream(br.readLine( ).split(" ")).mapToInt(Integer::parseInt).toArray( );
        }
        
        br.close( );
    }
    
    private List<Point> bfs(int x, int y, int color) {
        board[x][y] = color;
        Queue<int[]> q = new LinkedList<>();
        Set<Point> s = new HashSet<>();
        q.offer(new int[]{x, y});
        
        while (!q.isEmpty( )) {
            int[] cur = q.poll( );
            int cx = cur[0];
            int cy = cur[1];
            
            for (int i = 0 ; i<4 ; i++) {
                int tx = cx + dx[i];
                int ty = cy + dy[i];
                
                if (tx<0 || ty<0 ||tx>=n || ty>=n)  continue;
                
                if (board[tx][ty] == 1) {
                    board[tx][ty] = color;
                    q.offer(new int[]{tx, ty});
                }
                else if (board[tx][ty] == 0) {
                    s.add(new Point(cx, cy));
                }
            }
        }
        
        return new ArrayList<>(s);
    }
    
    public void solve( ) throws IOException {
        getInput( );
        
        int color = 2;
        List<List<Point> > islands = new ArrayList<>();
        for (int i = 0 ; i<n ; i++) {
            for (int j = 0 ; j<n ; j++) {
                if (board[i][j] == 1) {
                    islands.add(bfs(i, j, color));
                    color++;
                }
            }
        }
        
        int ans = Integer.MAX_VALUE;
        
        for (int i = 0 ; i<islands.size() ; i++) {
            for (int j = i+1 ; j<islands.size() ; j++) {
                for (int k = 0 ; k<islands.get(i).size() ; k++) {
                    for (int l = 0 ; l<islands.get(j).size( ) ; l++) {
                        Point p1 = islands.get(i).get(k);
                        Point p2 = islands.get(j).get(l);
                        ans = Math.min(ans, Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y) - 1);
                    }
                }
            }
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush( );
        bw.close( );
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      new Solve( ).solve( );
    }
}