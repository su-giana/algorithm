import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static int n;
    static long k;

    private static void getInput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        n = Integer.parseInt(br.readLine());
        k = Long.parseLong(br.readLine());
        br.close();
    }

    private static int getIndexOfSameOrLesser(int row, long target)
    {
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            long product = (long) mid * row;
            
            if(product <= target)
            {
                left = mid + 1;
                ans = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }

    private static long getPosition(long curPos)
    {
        long ans = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            ans += getIndexOfSameOrLesser(i, curPos);
        }

        return ans;
    }

    private static void solve() throws IOException
    {
        long left = 1;
        long right = (long) n * n;
        long ans = -1;

        while(left <= right)
        {
            long mid = left + (right - left) / 2;
            
            long currentIdx = getPosition(mid);

            if(currentIdx < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                ans = mid;
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(Long.toString(ans));
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        getInput();
        solve();
    }
}
