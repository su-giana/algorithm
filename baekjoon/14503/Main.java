import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static int n, m, r, c, dir;
    static int[][] map = new int[50][50];
    static boolean[][] visited = new boolean[50][50];
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);

        String[] rcdir = br.readLine().split(" ");
        r = Integer.parseInt(rcdir[0]);
        c = Integer.parseInt(rcdir[1]);
        dir = Integer.parseInt(rcdir[2]);

        for(int i = 0 ; i<n ; i++)
        {
            String[] row = br.readLine().split(" ");
            for(int j = 0 ; j<m ; j++)
            {
                map[i][j] = Integer.parseInt(row[j]);
            }
        }

        br.close();
    }

    public static int dfs(int x, int y, int d)
    {
        int ans = 0;
        if(!visited[x][y])
        {
            ans++;
            visited[x][y] = true;
        }

        boolean isNotClean = false;
        for(int i = 1 ; i<=4 ; i++)
        {
            int td = (d + i) % 4;
            int tx = x + dx[td];
            int ty = y + dy[td];

            if(!visited[tx][ty] && map[tx][ty] == 0)
            {
                isNotClean = true;
                return ans + dfs(tx, ty, td);
            }
        }

        if(!isNotClean)
        {
            int tx = x + -1 * dx[d];
            int ty = y + -1 * dy[d];

            if(map[tx][ty] == 0)
            {
                return ans + dfs(tx, ty, d);
            }
        }

        return ans;
    }

    public static void solve() throws IOException
    {
        if(dir == 1)    dir = 3;
        else if(dir == 3)   dir = 1;

        int ans = dfs(r, c, dir);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush();
        bw.close();
    }


    public static void main(String[] args) throws IOException{
        getInput();
        solve();
    }
}
