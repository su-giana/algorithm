import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    static int n;
    static int[][] ability = new int[40][40];

    private static int parseLongToValue(long cur)
    {
        int ans = 0;
        for(int i = 0 ; i<n-1 ; i++)
        {
            if((cur & (1L<<i)) > 0)
            {
                for(int j = i+1 ; j<n ; j++)
                {
                    if((cur & (1L<<j)) > 0)
                    {
                        ans += ability[i][j];
                    }
                }
            }
        }

        return ans;
    }

    private static int getLen(long cur)
    {
        int ans = 0;
        for(int i = 39 ; i>=0 ; i--)
        {
            if((cur & (1L<<i)) > 0)
            {
                ans++;
            }
        }

        return ans;
    }

    private static int dfs(int cur, long start, long link)
    {
        if(cur >= n)
        {
            if(getLen(start) != getLen(link))   return Integer.MAX_VALUE;
            return Math.abs(parseLongToValue(start) - parseLongToValue(link));
        }

        if(getLen(start) > n/2 || getLen(link) > n/2) return Integer.MAX_VALUE;

        long fixStart = (start | (1L<<cur));
        long fixLink = (link | (1L << cur));
        return Integer.min(dfs(cur+1, fixStart, link), dfs(cur+1, start, fixLink));
    }

    private static void solve() throws IOException
    {
        int ans = dfs(0, 0, 0);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush();
        bw.close();
    }

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for(int i = 0 ; i<n ; i++)
        {
            ability[i] = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt)
            .toArray();
        }

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                ability[i][j] += ability[j][i];
            }
        }
    }

    public static void main(String[] args) throws IOException{
        getInput();
        solve();
    }
    
}
