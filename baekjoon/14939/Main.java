import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main
{
    static int[] map = new int[10];
    static int[] copiedMap = new int[10];

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0 ; i<10 ; i++)
        {
            String bulbLine = br.readLine();
            int bitmask = 0;
            for (int j = 0 ; j<10 ; j++)
            {
                if (bulbLine.charAt(j) == 'O')
                {
                    bitmask |= (1<<j);
                }
            }

            map[i] = bitmask;
        }

        br.close();
    }

    private static void copyMap()
    {
        for(int i = 0 ; i<10 ; i++)
        {
            copiedMap[i] = map[i];
        }
    }

    private static void toggleBulb(int x, int y)
    {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        copiedMap[x] ^= (1<<y);

        for(int i = 0 ; i<4 ; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if(tx<0||ty<0||tx>=10||ty>=10)  continue;

            copiedMap[tx] ^= (1<<ty);
        }
    }

    private static boolean isSolved()
    {
        for(int i = 0 ; i<10 ; i++)
        {
            if (copiedMap[i] > 0)
            {
                return false;
            }
        }

        return true;
    }

    private static void solve() throws IOException
    {
        int ans = Integer.MAX_VALUE;
        for(int k = 0 ; k<1024 ; k++)
        {
            copyMap();
            int cnt = 0;

            for(int i = 0 ; i<10 ; i++)
            {
                if ((k & (1<<i)) > 0)
                {
                    toggleBulb(0, i);
                    cnt++;
                }
            }

            for (int i = 0 ; i<9 ; i++)
            {
                for(int j = 0 ; j<10 ; j++)
                {
                    if((copiedMap[i] & (1<<j)) > 0)
                    {
                        toggleBulb(i+1, j);
                        cnt++;
                    }
                }
            }

            if(isSolved())  ans = Math.min(ans, cnt);
        }

        if(ans == Integer.MAX_VALUE)    ans = -1;

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Integer.toString(ans));
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        getInput();
        solve();
    }
}